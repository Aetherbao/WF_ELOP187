#include "Task_Task.h"
#include "Sys_McuInit.h"
#include "Mem_Mem.h"

//  uint8 Memory_stEreaseCalibrationROM_mp;   /* used to erease Dflash test*/
//  uint8 Memory_stEreaseCalibrationROMPre_mp;/* used to erease Dflash test*/


int main(void)
{

	Sys_McuInit();/*basic software init*/

  for (;;)
  {
   
    
	
	Task_TaskRun();      /*task scheduler*/

	//   	if(Memory_stEreaseCalibrationROM_mp!=Memory_stEreaseCalibrationROMPre_mp)
	//   	{
    //    Memory_stEreaseCalibrationROMPre_mp=Memory_stEreaseCalibrationROM_mp;
    //    Mem_EreaseEeprom();
	//   	}
	}
}

