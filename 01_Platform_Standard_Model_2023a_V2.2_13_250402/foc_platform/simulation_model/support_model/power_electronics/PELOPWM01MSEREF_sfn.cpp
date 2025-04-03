/**  @file
  *  MSERef Powerelectronics Simulink Library 
  *  protection class C-SC1
  *
  *  Copyright Robert Bosch GmbH 2021
  *
  *  All rights reserved, also regarding any disposal, exploitation,
  *  reproduction, editing, distribution, as well as in the event of
  *  applications for industrial property rights.
  *
  */

/* 
1 - Short Description
This blocks computes a PWM signal with variable period and customizable switch-on and switch-off duty values.

2 - Application area
Connect this block between a duty cycle generator block and a B6-bridge block to control 
the transistors of the B6-bridge.

3 - Features
Classic PWM signals are supported as: left-aligned, right-aligned, middle centered, always on, always off.
Customized PWM signals with following sequences OFF-ON-OFF are also supported.

4 - Model assumptions and limits (version v2.0)
- No checks are performed to ensure that:
  - The PWM period has a positive value
  - The switch on duty value is in the range [-1, 1]
  - The switch off duty value is in the range [-1, 1]
  - The switch off duty value is higher than the switch of duty value.

5 - Model equations
The PWM signal is generated from a finite state machine defined by a variable DSPWM (discrete state of PWM) 
with three possible modes: INIT, ON, OFF and six possible transitions: INIT <-> ON, INIT <-> OFF and ON <-> OFF.

The possible values for the PWM signal are defined as follows:
 * PWM = 1 if DSPWM = ON
 * PWM = 0 if DSPWM = OFF.

The finite state machine is implemented in MDL_GET_TIME_OF_NEXT_VAR_HIT. 
Once DSPWM has become a new value, the next varhit tnext is computed.

To correctly reset DSPWM, a discrete variable `nb_off` has been defined that tracks how many time
the PWM signal has been OFF over the current period.

The new PWM value is computed in MDL_OUTPUTS.

The varhit tnext corresponding to the next period begin is computed using equation: tnext = (nb_T+1)*T.
In this equation, `nb_T` is the number of times the period T has been reproduced in the past 
(the approach using following equation `tnext = ssGetT(S) + T` leads to unexpected behavior and is not used here).
`nb_T` is incremented until T_in remains constant. If T_in has a new value, nb_T is reset to zero, the current 
simulation time is saved as tnewT and tnext is computed using equation: tnext = tnewT + (nb_T+1)*T.

6 - Ports

 - Inputs
  * T_in [s]: PWM period, T in ]0, 10s] (direct-feedthrough=1 accordingly to the mathworks documentation)
  * dutyon_in [-]: switch on duty value [-1, 1] (direct-feedthrough=1 accordingly to the mathworks documentation)
  * dutyoff_in [-]: switch off duty value [-1, 1] (direct-feedthrough=1 accordingly to the mathworks documentation)

 - Outputs
  * PWM [-]: PWM signal [0, 1]
  * Internals: 
   ** DSPWM [-]: Discrete state of PWM {INIT, ON, OFF}
   ** nb_off [-]: Number of times the PWM signal was OFF on the current period {0, 1, 2}
   ** dutyon [-]: Scaled switch-on duty cycle [0, 1]
   ** dutyoff [-]: Scaled switch-off duty cycle [0, 1]
   ** IsNewPeriod [-]: Returns 1 at the beginning of each new period, 0 otherwise
   ** T [s]: Period width
   ** tnewT [s]: Simulation time where a change in T occured
*/


#define S_FUNCTION_NAME PELOPWM01MSEREF_sfn
#define S_FUNCTION_LEVEL 2
#define MAX_STRING_PARAM_LENGTH 1024


#include "simstruc.h"

#include "math.h"

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%PREHEADER) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%PREHEADER) */


enum DSPWM
{
    INIT = 99, // Initial state
    OFF = 0, // PWM=0
    ON = 1// PWM=1
};


/*====================*
 * S-function methods *
 *====================*/

/* Function: mdlCheckParameters =============================================
 * Abstract:
 *    Validate our parameters to verify they are okay.
 *
 *    This method is called from mdlInitializeSizes() at the start of
 *    the simulation or by Simulink if any S-Function parameters are changed
 *    while the simulation runs.
 */
#define MDL_CHECK_PARAMETERS
#if defined (MDL_CHECK_PARAMETERS)
/* PARAMETERS */
static void mdlCheckParameters(SimStruct *S)
{
}
#endif /* MDL_CHECK_PARAMETERS */


/* Function: mdlStart =======================================================
 * Abstract:
 *    Do startup tasks.
 */
#define MDL_START
#if defined (MDL_START)
static void mdlStart(SimStruct *S)
{

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%START) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%START) */
}
#endif /* MDL_START */


#define MDL_INITIALIZE_CONDITIONS
#if defined(MDL_INITIALIZE_CONDITIONS)


/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* set number of parameters */
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) return;
    } else {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    /* Continuous states:  */
    ssSetNumContStates(S, 0);

    /* Time Discrete States:  */
    ssSetNumDiscStates(S, 0);

    /* Event Discrete States:  */
    ssSetNumModes(S, 0);

    /* Inputs ------------------ */
    if (!ssSetNumInputPorts(S, 3)) return;

    /* Input: T_in */
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    /* Input: dutyon_in */
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 1, 1);

    /* Input: dutyoff_in */
    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortDataType(S, 2, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 2, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 2, 1);


    /* Outputs ------------------- */
    if (!ssSetNumOutputPorts(S, 2)) return;

    /* Output: PWM */
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);

    /* Output: Internals */
    ssSetOutputPortWidth(S, 1, 7);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);

    ssSetNumRWork(S, 5); /* dutyon, dutyoff, IsNewPeriod, T, tnewT */
    ssSetNumIWork(S, 3); /* DSPWM, nb_off, nb_T */
    ssSetNumSampleTimes(S, 1); /* multiple sample times are not supported by the s-fn generator */

    /* If you want to use pointer work vectors, use the following statement */
    /* ssSetNumPWork(S, [number of work vectors]); */

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    /* ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_WORKS_WITH_CODE_REUSE)); */

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITSIZES) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITSIZES) */
}

#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)
/* Function: mdlSetWorkWidths ===============================================
* Abstract:
*      Set up run-time parameters.
*/
static void mdlSetWorkWidths(SimStruct *S)
{
    ssSetNumRunTimeParams(S, 0);
    if (ssGetErrorStatus(S) != NULL) return;

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%SETWORKWIDTHS) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%SETWORKWIDTHS) */
}
#endif /* MDL_SET_WORK_WIDTHS */


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specify the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S);

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITSAMPLETIMES) */
    ssSetSampleTime(S, 0, VARIABLE_SAMPLE_TIME);
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITSAMPLETIMES) */
}


static void mdlInitializeConditions(SimStruct *S)
{
    /* declaring internal iwork variables */
    int_T* adIWork = ssGetIWork(S);
    int_T& DSPWM = adIWork[0];        // Discrete State of PWM
    int_T& nb_off = adIWork[1];        // Number of time the signal was OFF over a period
    int_T& nb_T = adIWork[2];        // Number of simulated periods
        
    /* declaring internal rwork variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& dutyon = adRWork[0];    // Switch on duty on actual period
    real_T& dutyoff = adRWork[1];    // Switch off duty on actual period
    real_T& IsNewPeriod = adRWork[2];    // Returns 1 at the beginning of each new period, 0 otherwise
    real_T& T = adRWork[3];            // Period width
    real_T& tnewT = adRWork[4];        // Simulation time where a change in T occured
        
    /* Initialisation */
    DSPWM = INIT;
    nb_off = 0;
    nb_T = 0;

    dutyon = 0.0;
    dutyoff = 0.0;
    IsNewPeriod = 1.0; // New period assumed at the beginning of the simulation
    T = 0.0;
    tnewT = ssGetTStart(S);
}
#endif


#define MDL_GET_TIME_OF_NEXT_VAR_HIT
#if defined(MDL_GET_TIME_OF_NEXT_VAR_HIT)

static void mdlGetTimeOfNextVarHit(SimStruct *S)
{
    /* declaring internal iwork variables */
    int_T* adIWork = ssGetIWork(S);
    int_T& DSPWM = adIWork[0];        // Discrete state of PWM
    int_T& nb_off = adIWork[1];        // Number of time the signal was OFF over a period
     int_T& nb_T = adIWork[2];        // Number of simulated periods
       
    /* declaring internal rwork variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& dutyon = adRWork[0];    // Switch on duty on actual period
    real_T& dutyoff = adRWork[1];    // Switch off duty on actual period
    real_T& IsNewPeriod = adRWork[2];    // Returns 1 at the beginning of each new period, 0 otherwise
    real_T& T = adRWork[3];            // Period
    real_T& tnewT = adRWork[4];        // Simulation time where a change in `T_in` occured


    /* declaring inputs as local variables */
    real_T T_in = *(ssGetInputPortRealSignalPtrs(S, 0))[0];    // Period [-]
    real_T dutyon_in = *(ssGetInputPortRealSignalPtrs(S, 1))[0];    // Switch on duty [-]
    real_T dutyoff_in = *(ssGetInputPortRealSignalPtrs(S, 2))[0];    // Switch off duty [-]

    real_T tnext; // Next var hit

    // Checking T, ton and toff
    // T>0
    if (T_in <= 0.0)
    {ssSetErrorStatus(S,"ERROR: Input 'T' is negative or equal to zero.");}
    // ton in [0,1]
    // toff in [0,1]
    // ton <= toff

    // Resetting DSPWM to INIT at the end of a period
    if (DSPWM != INIT)
    {
        if ( (DSPWM == ON && dutyoff == 1.0) //End of left aligned PWM or PWM=1 reached
            || (DSPWM == OFF && nb_off == 1 && dutyoff==dutyon) // End of PWM=0
            || (DSPWM == OFF && nb_off == 1 && dutyon == 0.0 && dutyoff < 1.0) // End of right aligned PWM
            || (DSPWM == OFF && nb_off == 2 ) )// End of OFF-ON-OFF PWM reached
        {
            DSPWM = INIT;
        }
    }

    // At the beginning of each new period:
    // - Writing `dutyon` resp. `dutyoff` values (range: [0, 1]) from `dutyon_in` resp. `dutyoff_in` (range: [-1, 1])
    // - Resetting `nb_off` value
    // - Resetting `nb_T` and updating `tnewT` if a change in T_in occured
    // - Updating `T`
    // - Setting `IsNewPeriod` to 1.0
    if (DSPWM == INIT)
    {
        dutyon = 0.5*(dutyon_in + 1);
        dutyoff = 0.5*(dutyoff_in + 1);
        nb_off = 0;
        
        if ( (ssGetT(S) > ssGetTStart(S)) && ( T_in != T ) ) // Simulation time t > tStart && Change in T_in
        {
            nb_T = 0; // Reset `nb_T` to zero
            tnewT = ssGetT(S); // Update `tnewT` to the current simulation time
        }
            
        T = T_in;
        IsNewPeriod = 1.0;
    }

    // Computing new state for DSPWM. Possible transitions are:
    // INIT -> ON,    INIT -> OFF, OFF <-> ON (OFF-> INIT and ON -> INIT are already treated above)
    // Updating value of nb_off if new state is OFF
    if (DSPWM == INIT) // Old state: INIT
    {
        if ( (dutyon == 0.0) && (dutyoff != dutyon) ) // PWM=1 or left aligned PWM
        {
            DSPWM = ON; // New state: ON
        }
        else // (dutyon != 0.0) || (dutyoff == dutyon) // PWM=0 or right aligned PWM or OFF-ON-OFF PWM
        {
            DSPWM = OFF; // New state: OFF
            nb_off = nb_off + 1;
        }
    }
    else if (DSPWM == OFF) // Old state: OFF
    {
        if ( (dutyon > 0.0) && (dutyon != dutyoff) ) // right aligned PWM or OFF-ON-OFF PWM
        {
            DSPWM = ON; // New state: ON
        }
        else // ( (dutyon <= 0.0) || (dutyon == dutyoff) ): 
        {ssSetErrorStatus(S, "Do not reach this state with DSPWM=OFF and (dutyon <= 0.0) || (dutyon == dutyoff)");}
    }
    else if (DSPWM == ON) // Old state: ON
    {
        if (dutyoff < 1.0) // left aligned PWM of OFF-ON-OFF PWM
        {
            DSPWM = OFF; // New state: OFF
            nb_off = nb_off + 1;
        }
        else // (dutyoff >= 1.0)
        {ssSetErrorStatus(S, "Do not reach this state with DSPWM=ON and (dutyoff >= 1.0)");}
    }
    else
    {ssSetErrorStatus(S, "Computing new state for DSPWM: unvalid value for DSPWM");} // endif (DSPWM == INIT)


    //  Computing next var hit. Possible states are: OFF or ON.
    if (DSPWM == OFF) // New state: OFF
    {
        if (nb_off == 1) // State OFF has been reached for the first time: PWM=0 or right-aligned PWM or left-aligned PWM or OFF-ON-OFF PWM
        {
            if (dutyoff == dutyon) // PWM=0
            {
                tnext=(nb_T+1)*T; // Next var hit: begin next period
                nb_T = nb_T+1;
            }
            else // (dutyoff != dutyon)
            {
                if (dutyon > 0.0) // right-aligned PWM or OFF-ON-OFF PWM
                {
                    tnext = (nb_T + dutyon)*T; // Next var hit: begin ON sequence
                }
                else // (dutyon <= 0.0)
                {
                    if (dutyoff < 1.0) // left-aligned PWM
                    {
                        tnext=(nb_T+1)*T; // Next var hit: begin next period
                        nb_T = nb_T+1;
                    }
                    else // (dutyoff >= 1.0)
                    {ssSetErrorStatus(S, "Do not reach this state with DSPWM=OFF, (nb_off == 1) and (dutyoff >= 1.0)");}

                } // endif (dutyon > 0.0)
            } // endif (dutyoff == dutyon)
        }
        else if (nb_off == 2) // State OFF has been reached for the second time: OFF-ON-OFF PWM
        {
            if (dutyoff < 1.0)
            {
                tnext=(nb_T+1)*T; // Next var hit: begin next period
                nb_T = nb_T+1;
            }
            else // (duty_off >= 1.0)
            {ssSetErrorStatus(S, "Do not reach this state with DSPWM=OFF, (nb_off == 2) and (dutyoff >= 1.0)");} // endif (duty_off < 1.0)
        } // endif (DSPWM == OFF)

    }
    else if (DSPWM == ON) // New state: ON
    {
        if (dutyoff < 1.0) // left-aligned PWM or OFF-ON-OFF PWM
        {
            tnext = (nb_T + dutyoff)*T; // Next var hit: switch off pwm
        }
        else // (dutyoff >= 1.0): right-aligned PWM or PWM=1
        {
            tnext=(nb_T+1)*T; // New var hit: begin next period
            nb_T = nb_T+1;
        } // endif (dutyoff < 1.0)
    }
    else
    {ssSetErrorStatus(S, "Computing next var hit: unvalid value for DSPWM");} // endif (DSPWM == PWMOFF)
    

    // Setting next var hit
    ssSetTNext(S, tnewT + tnext);

}
#endif


/* Function: mdlOutputs =======================================================
 * Abstract:
 *    Calculate model outputs here.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    /* declaring internal iwork variables */
    int_T* adIWork = ssGetIWork(S);
    int_T& DSPWM = adIWork[0];        // Discrete state of PWM
    int_T& nb_off = adIWork[1];        // Number of time the signal was OFF over a period
        
    /* declaring internal rwork variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& dutyon = adRWork[0];    // Switch on duty on actual period
    real_T& dutyoff = adRWork[1];    // Switch off duty on actual period
    real_T& IsNewPeriod = adRWork[2];    // Returns 1 at the beginning of each new period, 0 otherwise
    real_T& T = adRWork[3];            // Period
    real_T& tnewT = adRWork[4];        // Simulation time where a change in `T_in` occured

    /* declaring output variables */
    real_T& PWM = ((real_T *)(ssGetOutputPortSignal(S, 0)))[0];    // PWM signal [-]
    real_T *Internals = (real_T *)ssGetOutputPortSignal(S, 1);    // Internals [-]

/*
    PWM = ???
*/
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%OUTPUTS) */

    if (DSPWM == ON)
    {PWM = 1.0;}
    else if (DSPWM == OFF)
    {PWM = 0.0;}
    else
    {ssSetErrorStatus(S, "Computing PWM output: invalid value for DSPWM");} // endif (DSPWM == ON)

    Internals[0] = DSPWM;
    Internals[1] = nb_off;
    Internals[2] = dutyon;
    Internals[3] = dutyoff;
    Internals[4] = IsNewPeriod;
    Internals[5] = T;
    Internals[6] = tnewT;

}


#define MDL_UPDATE  /* Change to #undef to remove function */
#if defined(MDL_UPDATE)
  /* Function: mdlUpdate ======================================================
   * Abstract:
   *    This function is called once for every major integration time step.
   *    Discrete states are typically updated here, but this function is useful
   *    for performing any tasks that should only take place once per
   *    integration step.
   */
  static void mdlUpdate(SimStruct *S, int_T tid)
  {

    /* declaring internal rwork variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& IsNewPeriod = adRWork[2];    // Returns 1 at the beginning of each new period, 0 otherwise

    /* declaring output variables */
    real_T *Internals = (real_T *)ssGetOutputPortSignal(S, 1);    // Internals [-]

    // Resetting IsNewPeriod and the corresponding Internals to 0.0 after `mdlOutputs` call such, that the
    // block returns 0.0 until the next var hit.
    IsNewPeriod = 0.0;
    Internals[4] = 0.0; //IsNewPeriod

  }
#endif /* MDL_UPDATE */


/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%TERMINATE) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%TERMINATE) */
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
    #include "simulink.c"      /* MEX-file interface mechanism */
#else
    #include "cg_sfun.h"       /* Code generation registration function */
#endif
