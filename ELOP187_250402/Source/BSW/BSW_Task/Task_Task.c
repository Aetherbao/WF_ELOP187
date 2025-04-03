/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "DIAG_Handle.h"
#include "ADC_Meas.h"
#include "timer2x_defines.h"
#include "PWM_Clac.h"
#include "Task_Task.h"
#include "BDRV_BDRV.h"

#include "linmain.h"
#include "Lintask.h"
#include "MID_Interface.h"

#include "ComIf_Task.h"




/*******************************************************************************
**                          Private Type Declarations                         **
*******************************************************************************/
/** Type defining a Task object with its configuration and useful information */
typedef struct
{
  // const uint16 Delay;     /**< Start delay compared to the system startup */
  const uint16 Period;    /**< Defines the task period in timer ticks */
  uint32 LastTick;       /**< Stores the last tick task was ran  */
  void (*Func)(void);       /**< Function pointer to the task  */
  // uint8 Enabled;          /**< Flag to enable/disable a task (not used yet) */
}ST_TASK_TASKTYPE;

typedef enum 
{ 
  TASK_1MS_TASK,
  TASK_10MS_TASK,
  // TASK_20MS_TASK,
  TASK_100MS_TASK,
  TASK_1000MS_TASK,
  TASK_NUM_OF_PER_TASKS
}ENM_TASK_TIMER;

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
/** Max value for the System counter. Reset it each 30 seconds */
#define TASK_MAX_CNT_VAL                (30u * TASK_SYSTICK_FREQUENCY)//

#define TASK_SYSTICK_FREQUENCY          2000u//1s

// #define TASK_2KHZ_FREQ                  2000u//500us
#define TASK_1KHZ_FREQ                  1000u//1ms
#define TASK_100HZ_FREQ                 100u//10ms
// #define TASK_50HZ_FREQ                  50u//20ms
#define TASK_10HZ_FREQ                  10u//100ms
#define TASK_1HZ_FREQ                   1u//100ms

// #define TASK_500US_PER_CNT        ((uint16)(TASK_SYSTICK_FREQUENCY/TASK_2KHZ_FREQ))
#define TASK_1MS_PER_CNT          ((uint16)(TASK_SYSTICK_FREQUENCY/TASK_1KHZ_FREQ))
#define TASK_10MS_PER_CNT         ((uint16)(TASK_SYSTICK_FREQUENCY/TASK_100HZ_FREQ))
// #define TASK_20MS_PER_CNT         ((uint16)(TASK_SYSTICK_FREQUENCY/TASK_50HZ_FREQ))
#define TASK_100MS_PER_CNT        ((uint16)(TASK_SYSTICK_FREQUENCY/TASK_10HZ_FREQ))
#define TASK_1000MS_PER_CNT       ((uint16)(TASK_SYSTICK_FREQUENCY/TASK_1HZ_FREQ))

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/
static void Task_1msTask(void);
static void Task_10msTask(void);
static void Task_20msTask(void);
static void Task_100msTask(void);
static void Task_1000msTask(void);

static void Task_10msBasicTask(void);
// static void Task_20msBasicTask(void);
static void Task_100msBasicTask(void);
static void Task_1000msBasicTask(void);
/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/
/** System tick counter (frequency 1kHz) */
static volatile uint16 Su16_TaskTickCnt = 0u;// this place for example

static ST_TASK_TASKTYPE SstTask_Tasks[TASK_NUM_OF_PER_TASKS]  = 
{ //        Period,          LastTick,        *Func,         
  {    TASK_1MS_PER_CNT,         0u,       &Task_1msTask,      },
  {    TASK_10MS_PER_CNT,        0u,       &Task_10msTask,     },
  {    TASK_100MS_PER_CNT,       0u,       &Task_100msTask,    },
  {    TASK_1000MS_PER_CNT,      0u,       &Task_1000msTask,   },
};

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
void Task_StartupTask(void)
{
  // Call before PWM_CalcStart for offset evaluation with bridge off
  // PWM_SSM_Init();

  PWM_CalcStart();
  
  Interface_StartupTask();//should be rename 'Interface_StartupTask'

}



void Task_TaskRun(void)
{
  uint32 u32_TaskId = 0u;
  uint32 u32_Diff = 0u;
		
  // Loop through all the tasks
  for(u32_TaskId = 0u; u32_TaskId < (uint32)TASK_NUM_OF_PER_TASKS; u32_TaskId++)
  {
    // sysTickCnt_u16 is reset each 30 seconds, manage this case
    if (Su16_TaskTickCnt >= SstTask_Tasks[u32_TaskId].LastTick)
    {
      u32_Diff = Su16_TaskTickCnt - SstTask_Tasks[u32_TaskId].LastTick;
    } 
    else // SysTick ISR counter has been reset
    {
      u32_Diff = (TASK_MAX_CNT_VAL + (uint32)Su16_TaskTickCnt - SstTask_Tasks[u32_TaskId].LastTick);
    }
      
    // Compare the counter with the task Period 
    if( u32_Diff >= SstTask_Tasks[u32_TaskId].Period )
    { 
      // Time elapsed, run  the task
      SstTask_Tasks[u32_TaskId].LastTick = Su16_TaskTickCnt;
      SstTask_Tasks[u32_TaskId].Func();
    }
    else
    {
      ;
    }
  }
}

void Task_500usTask_ISR(void)
{

  //PORT->P1_DATA.bit.P0 = 1u;
//	PORT->P1_DATA.bit.P0 = 0u;
  
  Interface_500usTask();//Interface_500usTask

  
  DIAG_PosSCD_Com();
  DIAG_VSDFault_Handle();
  
   l_cyclic_com_task();
	BDRV_StateSwitch();
}


/*******************************************************************************
**                         Private Function Definitions                        **
*******************************************************************************/





static void Task_1msTask(void)
{
   ComIf_1msTask();
   Interface_1msTask();

  // if (1 == PORT->P1_DATA.bit.P0)
  // {
  //   PORT->P1_DATA.bit.P0 = 0u;
  // }
  // else
  // {
  //   PORT->P1_DATA.bit.P0 = 1u;
  // }

}

static void Task_10msTask(void)
{
    Task_10msBasicTask();

    Interface_10msTask();
}

// static void Task_20msTask(void)
// {
//     Task_20msBasicTask();
// }
static void Task_100msTask(void)
{
    Task_100msBasicTask();
}

static void Task_1000msTask(void)
{
    Task_1000msBasicTask();
}

static void Task_10msBasicTask(void)
{
    BDRV_Init_Check();
    
    DIAG_VCPAndVDHDiff_Handle();

    ADC_VCP_Routine();

    //BDRV_StateSwitch();
    
    DIAG_VDDFault_Handle();

    DIAG_BasicToAPPfault_Monitor();
    
    (void)WDT1_Service();/*check and service the WDT1*/

}

// static void Task_20msBasicTask(void)
// {

// #if 1
//     if(test_flg==1)
//     {
//         if(u16_BattStableCnt<50u)
//         {
//             u16_BattStableCnt++;
//         }
//         else
//         {
//             SCU_EnterSleepMode();//SCU_EnterSleepMode
//         }
//     }
//     else
//     {
//         u16_BattStableCnt=0;
//     }
// #endif
// }

static void Task_100msBasicTask(void)
{
    // ADC_MON_Routine();



    DIAG_VCPFault_Handle();/* Charge Pump output voltage low threshold comparator in BDRV module */

    DIAG_HSLSFault_Handle();

    ADC_MCUTemp_Routine();
    ADC_TempOil_Routine();

    // PWM_MotorStateChange_Handle();
}

static void Task_1000msBasicTask(void)
{

    // SCU_enterSleepMode();//for debug

    DIAG_SysSupply_Err();
    
    // DIAG_Fault_Monitor();
}

void Task_Timer_ISR(void)//interrupt
{
 	//   if (1 == PORT->P1_DATA.bit.P0)
  // {
  //   PORT->P1_DATA.bit.P0 = 0u;
  // }
  // else
  // {
  //   PORT->P1_DATA.bit.P0 = 1u;
  // }
	Task_500usTask_ISR();

  if( Su16_TaskTickCnt >= TASK_MAX_CNT_VAL)
  {
    Su16_TaskTickCnt = 0u;
  }
  else
  {
    ;
  }
  // Increment the system tick 
  Su16_TaskTickCnt++;

  // if((Su16_TaskTickCnt%2u)==1u)
	// {
	// /*	PORT_P10_Output_Toggle_Set();*/
  //   timer_1ms++;//ComIf_1msTask()
		
	// }
  // else
  // {
  //   ;
  // }

  // DIAG_HSLS_OC_Timer_Handle_ISR();
}


