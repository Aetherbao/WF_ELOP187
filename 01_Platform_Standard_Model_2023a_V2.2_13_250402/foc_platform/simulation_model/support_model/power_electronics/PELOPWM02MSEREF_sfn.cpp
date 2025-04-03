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

#define S_FUNCTION_NAME PELOPWM02MSEREF_sfn
#define S_FUNCTION_LEVEL 2
#define MAX_STRING_PARAM_LENGTH 1024


#include "simstruc.h"

#include "math.h"

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%PREHEADER) */
// S-function parameter related functions
#if defined(MATLAB_MEX_FILE) || defined(RT) ||defined(NRT)
real_T pelopwm02mseref_GetRealParam(SimStruct *S, int_T idx)
{
    return mxGetScalar( ssGetSFcnParam(S,idx));
}

int_T pelopwm02mseref_GetIntParam(SimStruct *S, int_T idx)
{
    return (int_T)mxGetScalar( ssGetSFcnParam(S,idx) );
}

int_T pelopwm02mseref_ParamIsDouble(SimStruct *S, int_T paridx)
{
    return mxIsDouble( ssGetSFcnParam(S, paridx) );
}

size_t pelopwm02mseref_ParamGetNumElements(SimStruct *S, int_T paridx)
{
    return mxGetNumberOfElements( ssGetSFcnParam(S, paridx) );
}

#endif /* MATLAB_MEX_FILE */

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%PREHEADER) */

/*
    Enum type for use with inline functions
        pelopwm02mseref_GetRealParam(),
        pelopwm02mseref_GetIntParam(),
        pelopwm02mseref_ParamIsDouble(),
        pelopwm02mseref_ParamGetNumElements()
*/
enum PELOPWM02MSEREF_enum_params
{
    en_mode,    /* Type */
    en_Tpl,    /* Period length [s] */
    en_disc,    /* Discret */
    en_off,    /* OFF */
    en_Td    /* Sampling time [s] */
};

#define DECLARE_RWORK real_T* adRWork = ssGetRWork(S);
#define DECLARE_IWORK int_T* adIWork = ssGetIWork(S);
#define DECLARE_DUTY_WORK real_T& duty_work = adRWork[0];        //  [-]
#define DECLARE_TNEXT1 real_T& tnext1 = adRWork[1];        //  [-]
#define DECLARE_TIME real_T& time = adRWork[2];        //  [-]
#define DECLARE_SATURATION int_T& saturation = adIWork[0];        //
#define DECLARE_STATUS int_T& status = adIWork[1];        //
#define DECLARE_NUM int_T& num = adIWork[2];        //
#define DECLARE_MODE     int_T mode = mseGetIntParam(S, en_mode); // Type
#define DECLARE_TPL     real_T Tpl = mseGetRealParam(S, en_Tpl);    // Period length [s]
#define DECLARE_DISC     boolean_T disc = (boolean_T)mseGetIntParam(S, en_disc);    // Discret
#define DECLARE_OFF     boolean_T off = (boolean_T)mseGetIntParam(S, en_off);    // OFF
#define DECLARE_TD     real_T Td = mseGetRealParam(S, en_Td);    // Sampling time [s]

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%HEADER) */

/*Functions for fixed step solver only!!*/
double triangle(double t, double Tpl)/* Triangle function*/
{
    double y;
    double modt;
    modt =  fmod( t,  Tpl);
    if(modt<=Tpl/2.)
    {
        y = -4/Tpl*modt+1;
    }
    else
    {
        y = 4/Tpl*modt-3;
    }
    return y;
}
double     left(double t, double Tpl)/* Left function*/
{
    double y;
    double modt;
    modt =  fmod( t,  Tpl);
    y = 2/Tpl*modt-1;
    return y;
}
double     right(double t, double Tpl)/* Right function*/
{
    double y;
    double modt;
    modt =  fmod( t,  Tpl);
    y = -2/Tpl*modt+1;
    return y;
}
enum status
{
    BEGIN_PERIOD,
    FIRST_EDGE,
    SECOND_EDGE
};


#define MDL_INITIALIZE_CONDITIONS
#if defined(MDL_INITIALIZE_CONDITIONS)

static void mdlInitializeConditions(SimStruct *S)
{
            int_T mode = pelopwm02mseref_GetIntParam(S, en_mode); // type: 1=left aligned, 2=right aligned, 3=middle centered
            real_T Tpl = pelopwm02mseref_GetRealParam(S, en_Tpl);    // period length [s]

            /* declaring internal rwork variables */
            real_T* adRWork = ssGetRWork(S);
            real_T& duty_work = adRWork[0];        //  [-]
            real_T& tnext1 = adRWork[1];        //  [-]
            real_T& time = adRWork[2];        //  [-]
            /* declaring internal iwork variables */
            int_T* adIWork = ssGetIWork(S);
            int_T& saturation = adIWork[0];        //
            int_T& status = adIWork[1];        //
            int_T& num = adIWork[2];        //
            time=ssGetT(S);
            real_T o = 0;
            real_T tnext= time + o;


            /* declaring inputs as local variables */
                   real_T duty = *(ssGetInputPortRealSignalPtrs(S, 0))[0];    // Length of duty cycle [-]

    saturation = 0;
    status     = BEGIN_PERIOD;
    duty_work  = 0.0;
    num        = 1;
}
#endif






#define MDL_GET_TIME_OF_NEXT_VAR_HIT
#if defined(MDL_GET_TIME_OF_NEXT_VAR_HIT)

static void mdlGetTimeOfNextVarHit(SimStruct *S)
{
    /* declaring parameters as local variables */
        int_T mode = pelopwm02mseref_GetIntParam(S, en_mode); // type: 1=left aligned, 2=right aligned, 3=middle centered
        real_T Tpl = pelopwm02mseref_GetRealParam(S, en_Tpl);    // period length [s]

        /* declaring internal rwork variables */
        real_T* adRWork = ssGetRWork(S);
        real_T& duty_work = adRWork[0];        //  [-]
        real_T& tnext1 = adRWork[1];        //  [-]
        real_T& time = adRWork[2];        //  [-]
        /* declaring internal iwork variables */
        int_T* adIWork = ssGetIWork(S);
        int_T& saturation = adIWork[0];        //
        int_T& status = adIWork[1];        //
        int_T& num = adIWork[2];        //
        
        
        time=ssGetT(S);
        real_T o = 0;             //offset
        real_T tnext= time + o;    //tnext = current_time + offset


        /* declaring inputs as local variables */
        real_T duty = *(ssGetInputPortRealSignalPtrs(S, 0))[0];    // Length of duty cycle [-]

        real_T eps =1.0e-10;



    if(mode == 1) /*****LEFT*****/
    {
        switch(status)
        {
        case BEGIN_PERIOD:

                /* duty -> -1...1 */
                /* duty_work ->  0...1 */

                duty_work = (duty + 1.0) * 0.5;

            if((duty_work > eps) && (duty_work < (1.0-eps)))
            {
                saturation = 0;
                o =  duty_work * Tpl;
                tnext= time + o;
            }
            else /* (duty_work ~ 0.0 || duty_work ~ 1.0) */
            {
                /* set proper 0.0 or 1.0 */
                duty_work = (duty_work <= eps)? 0.0 : 1.0;
                saturation = 1;
                //tnext=time+o;  //old solution (R2010) without variable num
                tnext=num*Tpl; //new R2011
                num = num+1;
            }
            break;

        case FIRST_EDGE:
                tnext=num*Tpl;
                num = num+1;
                break;
        }

    }
    else if(mode == 2)  /*****RIGHT*****/
    {
        switch(status)
        {
        case BEGIN_PERIOD:
                /* duty -> -1...1 */
                /* duty_work ->  0...1 */
            duty_work = (duty + 1.0) * 0.5;

            if((duty_work > eps) && (duty_work < (1.0-eps)))
            {
                saturation = 0;
                o =  (1 - duty_work)*Tpl;
                tnext= time + o;

            }
            else /* (duty_work ~ 0.0 || duty_work ~ 1.0) */
            {
                /* set proper 0.0 or 1.0 */
                duty_work = (duty_work <= eps)? 0.0 : 1.0;
                saturation = 1;
                tnext=num*Tpl;
                num = num+1;
            }


                break;

        case FIRST_EDGE:
                tnext=num*Tpl;
                num = num+1;

        }
    }
    else if(mode == 3)
        {
        switch(status)
        {
        case BEGIN_PERIOD:
                /* duty -> -1...1 */
                /* duty_work ->  0...1 */

                duty_work = (duty + 1.0) * 0.5;


            if((duty_work > eps) && (duty_work < (1.0-eps)))
            {
                saturation = 0;
                o =(1-duty_work) * Tpl * 0.5;
                tnext=time+o;
            }
            else /* Saturation */
            {
                /* set proper 0.0 or 1.0 */
                duty_work = (duty_work <= eps)? 0.0 : 1.0;
                saturation = 1;
                tnext=num*Tpl;
                num = num+1;
            }
            break;

        case FIRST_EDGE:
            o =duty_work*Tpl;
            tnext=time+o;
            break;

        case SECOND_EDGE:
            o =(1-duty_work) * Tpl * 0.5;
            tnext=num*Tpl;      
            num = num+1;
            break;
        }
    }
    ssSetTNext(S,tnext);
    tnext1=tnext;

}
#endif
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%HEADER) */

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
    /* declaring parameters as local variables */
    int_T mode = pelopwm02mseref_GetIntParam(S, en_mode); // Type
    real_T Tpl = pelopwm02mseref_GetRealParam(S, en_Tpl);    // Period length [s]
    boolean_T disc = (boolean_T)pelopwm02mseref_GetIntParam(S, en_disc);    // Discret
    boolean_T off = (boolean_T)pelopwm02mseref_GetIntParam(S, en_off);    // OFF
    real_T Td = pelopwm02mseref_GetRealParam(S, en_Td);    // Sampling time [s]

    /* checking Type ['left aligned', 'right aligned', 'middle centered']*/
    if (!((mode >= 1) && (mode <= 3))){
        ssPrintf("ERROR: Parameter 'mode' %d outside boundaries [1; 3]. \n", mode);
        ssSetErrorStatus(S,"ERROR: Parameter 'mode' outside boundaries [1; 3]. \n");
    }
    if (!pelopwm02mseref_ParamIsDouble(S, en_mode) || pelopwm02mseref_ParamGetNumElements(S, en_mode) != 1|| (pelopwm02mseref_GetRealParam(S, en_mode) != pelopwm02mseref_GetIntParam(S, en_mode))) {
        ssPrintf("ERROR: Parameter 'mode' must be a scalar integer. \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'mode' must be a scalar integer. \n");
    }

    /* checking parameter Tpl [1e-7; 1e3] -- Period length */
    if (!((Tpl >= 1e-7) && (Tpl <= 1e3))) {
        ssPrintf("ERROR: Parameter 'Tpl'=%f outside boundaries [1e-7;1e3]. \n", Tpl);
        ssSetErrorStatus(S,"ERROR: Parameter 'Tpl' outside boundaries [1e-7;1e3]. \n");
    }
    if (!pelopwm02mseref_ParamIsDouble(S, en_Tpl) || pelopwm02mseref_ParamGetNumElements(S, en_Tpl) != 1) {
        ssPrintf("ERROR: Parameter 'Tpl' must be a scalar double. \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'Tpl' must be a scalar double. \n");
    }

    /* checking Discret */
    if (!pelopwm02mseref_ParamIsDouble(S, en_disc) || pelopwm02mseref_ParamGetNumElements(S, en_disc) != 1
            || (pelopwm02mseref_GetRealParam(S, en_disc) != pelopwm02mseref_GetIntParam(S, en_disc))
            || ( pelopwm02mseref_GetIntParam(S, en_disc) != 0 && pelopwm02mseref_GetIntParam(S, en_disc) != 1)) {
        ssPrintf("ERROR: Parameter 'disc' must be a boolean value (0 or 1). \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'disc' must be a boolean value (0 or 1). \n");
    }

    /* checking OFF */
    if (!pelopwm02mseref_ParamIsDouble(S, en_off) || pelopwm02mseref_ParamGetNumElements(S, en_off) != 1
            || (pelopwm02mseref_GetRealParam(S, en_off) != pelopwm02mseref_GetIntParam(S, en_off))
            || ( pelopwm02mseref_GetIntParam(S, en_off) != 0 && pelopwm02mseref_GetIntParam(S, en_off) != 1)) {
        ssPrintf("ERROR: Parameter 'off' must be a boolean value (0 or 1). \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'off' must be a boolean value (0 or 1). \n");
    }

    /* checking parameter Td [1e-12; 1e3] -- Sampling time */
    if (!((Td >= 1e-12) && (Td <= 1e3))) {
        ssPrintf("ERROR: Parameter 'Td'=%f outside boundaries [1e-12;1e3]. \n", Td);
        ssSetErrorStatus(S,"ERROR: Parameter 'Td' outside boundaries [1e-12;1e3]. \n");
    }
    if (!pelopwm02mseref_ParamIsDouble(S, en_Td) || pelopwm02mseref_ParamGetNumElements(S, en_Td) != 1) {
        ssPrintf("ERROR: Parameter 'Td' must be a scalar double. \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'Td' must be a scalar double. \n");
    }

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%CHECKPARAMETERS) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%CHECKPARAMETERS) */
}
#endif /* MDL_CHECK_PARAMETERS */

/* Function: mdlProcessParameters =============================================
 * Abstract:
 *    This function is for pre-processing parameters, e.g. when you have
 *    to convert units of mask parameters for use in your S-Function or
 *    to do some computation with the parameters once they change.
 *
 *    However we also use this function for validating parameters
 *    when the validation depends on the value of other parameters,
 *    e.g. when one parameter must be larger than another parameter.
 *
 *    This method is called in mdlStart() at the beginning of the simulation
 *    and every time when S-Function parameters have changed.
 *
 */
#define MDL_PROCESS_PARAMETERS
#if defined(MDL_PROCESS_PARAMETERS)
static void mdlProcessParameters(SimStruct *S)
{
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%PROCESSPARAMETERS) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%PROCESSPARAMETERS) */
}
#endif /* MDL_PROCESS_PARAMETERS */

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

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* set number of parameters */
    /* parameters: mode, Tpl, disc, off, Td */
    ssSetNumSFcnParams(S, 5);
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
    if (!ssSetNumInputPorts(S, 1)) return;

    /* Input: duty */
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);


    /* Outputs ------------------- */
    if (!ssSetNumOutputPorts(S, 2)) return;

    /* Output: PWM */
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);

    /* Output: Internal variables */
    ssSetOutputPortWidth(S, 1, 6);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);

    ssSetNumRWork(S, 3); /* duty_work, tnext1, time */
    ssSetNumIWork(S, 3); /* saturation, status, num */
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
    boolean_T disc = (boolean_T)pelopwm02mseref_GetIntParam(S, en_disc);    // Discrete
    real_T Td      = pelopwm02mseref_GetRealParam(S, en_Td);    // sampling time [s]
    boolean_T off = (boolean_T)pelopwm02mseref_GetIntParam(S, en_off);    // off
    boolean_T vss = ssIsVariableStepSolver(S);
    if (disc==1 ) {
        ssSetSampleTime(S, 0, Td);
    } else if ((disc==0 && vss==0) || (off==1)){
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    }
    else {
        ssSetSampleTime(S, 0, VARIABLE_SAMPLE_TIME);
    }
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITSAMPLETIMES) */
}



#undef MDL_DERIVATIVES
/* mdlDerivatives() is disabled because PELOPWM02MSEREF has no continuous states */
#ifdef MDL_DERIVATIVES
/* Function: mdlDerivatives =================================================
 * Abstract:
 *    In this function, you compute the S-function block's derivatives.
 *    The derivatives are placed in the derivative vector, ssGetdX(S).
 */
static void mdlDerivatives(SimStruct *S)
{
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%DERIVATIVES) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%DERIVATIVES) */
}
#endif

/* Function: mdlOutputs =======================================================
 * Abstract:
 *    Calculate model outputs here.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    /* declaring parameters as local variables */
    int_T mode = pelopwm02mseref_GetIntParam(S, en_mode); // Type
    real_T Tpl = pelopwm02mseref_GetRealParam(S, en_Tpl);    // Period length [s]
    boolean_T disc = (boolean_T)pelopwm02mseref_GetIntParam(S, en_disc);    // Discret
    boolean_T off = (boolean_T)pelopwm02mseref_GetIntParam(S, en_off);    // OFF
    real_T Td = pelopwm02mseref_GetRealParam(S, en_Td);    // Sampling time [s]

    /* declaring internal rwork variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& duty_work = adRWork[0];        //  [-]
    real_T& tnext1 = adRWork[1];        //  [-]
    real_T& time = adRWork[2];        //  [-]
    /* declaring internal iwork variables */
    int_T* adIWork = ssGetIWork(S);
    int_T& saturation = adIWork[0];        //
    int_T& status = adIWork[1];        //
    int_T& num = adIWork[2];        //


    /* declaring inputs as local variables */
    real_T duty = *(ssGetInputPortRealSignalPtrs(S, 0))[0];    // Length of duty cycle [-]

    /* declaring output variables */
    real_T& PWM = ((real_T *)(ssGetOutputPortSignal(S, 0)))[0];    // PWM signal [-]

    /* output for internal variables */
    real_T *internalsOutput = (real_T *)ssGetOutputPortSignal(S, 1);

/*
    PWM = ???
*/
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%OUTPUTS) */
if (off==1) { //OFF
PWM = (duty + 1.0) * 0.5; /*PWM between 0 and 1*/
}
else{ //ON
    boolean_T vss = ssIsVariableStepSolver(S);
    if (disc==1 || vss==0) {

/***CASE Fixed Step Solver ***/
        time_T simtime = ssGetT(S);
        real_T comp;
        real_T eps =0;
        eps = 1.0e-10;
        /*   middle centered     */
         if(mode == 3)
        {
            comp = triangle(simtime,Tpl);
            if (duty>comp || duty>(1-eps))
                PWM=1;
                else
                PWM=0;
        }
            /*   Left aligned     */
         else if (mode==1)
            {
                comp = left(simtime,Tpl);
                if (duty>comp || duty>(1-eps))
                    PWM=1;
                    else
                    PWM=0;
            }
            /*   Right aligned     */
         else
            {
                comp = right(simtime,Tpl);
                if (duty>comp || duty>(1-eps))
                    PWM=1;
                    else
                    PWM=0;
            }


/***CASE Continuous Solver ***/

    } else {
            /* Left aligned PWM signal */
            if(mode == 1)
            {
                switch(status)
                {
                case BEGIN_PERIOD:
                    if(!saturation)
                    {
                        PWM = 1.0;
                        status = FIRST_EDGE;
                    }
                    else
                    {
                    /* saturation: no falling edge status remains "BEGIN_PERIOD"
                    *    duty_work == 0.0
                        * OR duty_work == 1.0  */
                        PWM = duty_work;
                    }
                    break;
                case FIRST_EDGE:

                    PWM = 0.0;
                    status = BEGIN_PERIOD;
                    break;
                }




            }

           /*      right aligned    */
        else if (mode==2)
        {

            switch(status)
            {
                case BEGIN_PERIOD:
                    if(!saturation)
                    {
                        PWM = 0.0;
                        status = FIRST_EDGE;
                    }
                    else
                    {
                        /* saturation: no falling edge
                         *    duty_work == 0.0
                         * OR duty_work == 1.0  */
                        PWM = duty_work;
                    }
                    break;
                case FIRST_EDGE:
                    PWM = 1.0;
                    status = BEGIN_PERIOD;
                    break;
            }



        }
            /*   middle centered     */
        else if(mode == 3)
        {
            switch(status)
            {
            case BEGIN_PERIOD:
                if(saturation)
                {
                    PWM = duty_work;
                    /* leave status unchanged*/
                }
                else
                {
                    PWM = 0.0;
                    status = FIRST_EDGE;
                }
                break;

            case FIRST_EDGE:
                PWM = 1.0;
                status = SECOND_EDGE;
                break;

            case SECOND_EDGE:
                PWM = 0.0;
                status = BEGIN_PERIOD;
                break;
            }



        }

    }
}/*end OFF if*/

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%OUTPUTS) */
    internalsOutput[0] = saturation;
    internalsOutput[1] = status;
    internalsOutput[2] = num;
    internalsOutput[3] = duty_work;
    internalsOutput[4] = tnext1;
    internalsOutput[5] = time;
}

/* Function: mdlUpdate ========================================================
 * Abstract:
 *    This function is called once for every major integration time step.
 *    Time-discrete states are typically updated here, but this function is useful
 *    for performing any tasks that should only take place once per integration
 *    step.
 */
#undef MDL_UPDATE
/* mdlUpdate() is disabled because PELOPWM02MSEREF has no time-discrete states */
#if defined (MDL_UPDATE)
static void mdlUpdate(SimStruct *S, int_T tid)
{
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%UPDATE) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%UPDATE) */
}
#endif /* MDL_UPDATE */

#undef MDL_ZERO_CROSSINGS
/* mdlZeroCrossings() is disabled because PELOPWM02MSEREF has no "hasDiscontinuities" flag. */
#ifdef MDL_ZERO_CROSSINGS
/* Function: mdlZeroCrossings ===============================================
 * Abstract:
 *    If your S-function has registered CONTINUOUS_SAMPLE_TIME and there
 *    are signals entering the S-function or internally generated signals
 *    which have discontinuities, you can use this method to locate the
 *    discontinuities. When called, this method must update the
 *    ssGetNonsampleZCs(S) vector.
 */
static void mdlZeroCrossings(SimStruct *S)
{
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%ZEROCROSSINGS) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%ZEROCROSSINGS) */
}
#endif

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
