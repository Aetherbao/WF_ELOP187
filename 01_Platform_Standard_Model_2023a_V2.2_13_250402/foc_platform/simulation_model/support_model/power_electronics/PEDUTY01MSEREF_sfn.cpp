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

#define S_FUNCTION_NAME PEDUTY01MSEREF_sfn
#define S_FUNCTION_LEVEL 2
#define MAX_STRING_PARAM_LENGTH 1024


#include "simstruc.h"

#define _USE_MATH_DEFINES
#include <math.h>

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%HEADER) */

enum PEDUTY01MSEREF_enum_params
{
    en_mode    /* mode */
};


/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%PREHEADER) */
// S-function parameter related functions
#if defined(MATLAB_MEX_FILE) || defined(RT) ||defined(NRT)
real_T peduty01mseref_GetRealParam(SimStruct *S, int_T idx)
{
    return mxGetScalar( ssGetSFcnParam(S,idx));
}

int_T peduty01mseref_GetIntParam(SimStruct *S, int_T idx)
{
    return (int_T)mxGetScalar( ssGetSFcnParam(S,idx) );
}

int_T peduty01mseref_ParamIsDouble(SimStruct *S, int_T paridx)
{
    return mxIsDouble( ssGetSFcnParam(S, paridx) );
}

size_t peduty01mseref_ParamGetNumElements(SimStruct *S, int_T paridx)
{
    return mxGetNumberOfElements( ssGetSFcnParam(S, paridx) );
}

#endif /* MATLAB_MEX_FILE */


// *******************************************************************************
// S-function related mathematical functions
double triangle(double phi)/* see definition in PEDUTY01MSEREF_details.pdf*/
{

double y;
double modphi;

modphi =  fmod( phi,  2.*M_PI);


if(modphi<=M_PI/2.)
{
    y=1./(M_PI*2.)*modphi;
}
else if(modphi>M_PI/2. && modphi<=3./2.*M_PI)
{
    y=    -1./(M_PI*2.)*modphi+1./2.;
}
else
{
    y=    1./(M_PI*2.)*modphi-1.;
}

return y;
}

double sgn(double value)/* 'double', because of using double values in the following program */
{

    return (value>0.)?1.:((value<0.)?-1.:0.);
}

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%HEADER) */


/*
    Enum type for use with inline functions
        peduty01mseref_GetRealParam(),
        peduty01mseref_GetIntParam(),
        peduty01mseref_ParamIsDouble(),
        peduty01mseref_ParamGetNumElements()
*/

#define DECLARE_RWORK real_T* adRWork = ssGetRWork(S);
#define DECLARE_IWORK int_T* adIWork = ssGetIWork(S);
#define DECLARE_MODE     int_T mode = peduty01mseref_GetIntParam(S, en_mode); // mode


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
    int_T mode = peduty01mseref_GetIntParam(S, en_mode); // mode

    /* checking mode ['Pure', 'Triangle', '3. harmonics']*/
    if (!((mode >= 1) && (mode <= 3))){
        ssPrintf("ERROR: Parameter 'mode' %d outside boundaries [1; 3].\n", mode);
        ssSetErrorStatus(S,"ERROR: Parameter 'mode' outside boundaries [1; 3].\n");
    }
    if (!peduty01mseref_ParamIsDouble(S, en_mode) || peduty01mseref_ParamGetNumElements(S, en_mode) != 1|| (peduty01mseref_GetRealParam(S, en_mode) != peduty01mseref_GetIntParam(S, en_mode))) {
        ssPrintf("ERROR: Parameter 'mode' must be a scalar integer. \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'mode' must be a scalar integer. \n");
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
    /* declaring parameters as local variables */
    int_T mode = peduty01mseref_GetIntParam(S, en_mode); // mode

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
    /* parameters: mode */
    ssSetNumSFcnParams(S, 1);
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

    /* Input: Valpha */
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    /* Input: Vbeta */
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 1, 1);

    /* Input: Vsup */
    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortDataType(S, 2, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 2, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 2, 1);


    /* Outputs ------------------- */
    if (!ssSetNumOutputPorts(S, 3)) return;

    /* Output: Dutya */
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);

    /* Output: Dutyb */
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);

    /* Output: Dutyc */
    ssSetOutputPortWidth(S, 2, 1);
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 2, COMPLEX_NO);


    ssSetNumRWork(S, 0); /*  */
    ssSetNumIWork(S, 0); /*  */
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
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITSAMPLETIMES) */
}


#undef MDL_DERIVATIVES
/* mdlDerivatives() is disabled because PEDUTY01MSEREF has no continuous states */
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
    int_T mode = peduty01mseref_GetIntParam(S, en_mode); // mode



    /* declaring inputs as local variables */
    real_T Valpha = *(ssGetInputPortRealSignalPtrs(S, 0))[0];    // Desired voltage in $\alpha$ direction [V]
    real_T Vbeta = *(ssGetInputPortRealSignalPtrs(S, 1))[0];    // Desired voltage in $\beta$-direction [V]
    real_T Vsup = *(ssGetInputPortRealSignalPtrs(S, 2))[0];    // supply voltage [V]

    /* declaring output variables */
    real_T& Dutya = ((real_T *)(ssGetOutputPortSignal(S, 0)))[0];    // duty value for powerstage a [-]
    real_T& Dutyb = ((real_T *)(ssGetOutputPortSignal(S, 1)))[0];    // duty value for powerstage b [-]
    real_T& Dutyc = ((real_T *)(ssGetOutputPortSignal(S, 2)))[0];    // duty value for powerstage c [-]


/*
    Dutya = ???
    Dutyb = ???
    Dutyc = ???
*/
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%OUTPUTS) */

   real_T Vi;
   real_T gamma;

   Vi = sqrt((Valpha*Valpha)+(Vbeta*Vbeta));//*Amplitude [V]

   gamma=atan2(Valpha,Vbeta)+M_PI;//*angle gamma [rad]

   real_T g;
   real_T h;
   real_T i;
   real_T eps;

   eps = 1e-10;


    if (mode>= 1 && mode <4)
    {
        switch(mode)
        {
        case 1:// mode pure : c(t) = 0
            if(Vsup/2>=0 && Vsup/2< eps)
            {
                g=(1.*Valpha) + (0.*Vbeta);
                h=((-1./2.)*Valpha) + (((sqrt(3.))/2.)*Vbeta);
                i=((-1./2.)*Valpha) + (-((sqrt(3.))/2.)*Vbeta);

                Dutya=sgn(g);
                Dutyb=sgn(h);
                Dutyc=sgn(i);
            }
            else
            {

            Dutya = ((1.*Valpha) + (0.*Vbeta))/(Vsup/2.);
            Dutyb = (((-1./2.)*Valpha) + (((sqrt(3.))/2.)*Vbeta))/(Vsup/2.);
            Dutyc = (((-1./2.)*Valpha) + (-((sqrt(3.))/2.)*Vbeta))/(Vsup/2.);
            }
            break;

        case 2:// mode triangle : c(t)= 1/4 tri(2*Omega*t)
            if(Vsup/2>=0 && Vsup/2< eps)
            {
                g=(1.*Valpha) + (0.*Vbeta)- (Vi*triangle(3.*gamma));
                h=((-1./2.)*Valpha) + (((sqrt(3.))/2.)*Vbeta)- (Vi*triangle(3.*gamma));
                i=((-1./2.)*Valpha) + (-((sqrt(3.))/2.)*Vbeta)- (Vi*triangle(3.*gamma));

                Dutya=sgn(g);
                Dutyb=sgn(h);
                Dutyc=sgn(i);
            }
            else
            {

            Dutya = ((1.*Valpha) + (0.*Vbeta) - (Vi*triangle(3.*gamma)))/(Vsup/2.);
            Dutyb = (((((-1./2.)*Valpha) + ((sqrt(3.))/2.)*Vbeta)) - (Vi*triangle(3.*gamma)))/(Vsup/2.);
            Dutyc = ((((-1./2.)*Valpha) + (-((sqrt(3.))/2.)*Vbeta)) - (Vi*triangle(3.*gamma)))/(Vsup/2.);
            }
            break;

        case 3:// mode 3. harmonic : c(t)= (Vi/6.*sin(3*gamma))
            if(Vsup/2>=0 && Vsup/2< eps)
            {
                g=(1.*Valpha) + (0.*Vbeta)+ (Vi/6.*sin(3.*gamma));
                h=((-1./2.)*Valpha) + (((sqrt(3.))/2.)*Vbeta)+ (Vi/6.*sin(3.*gamma));
                i=((-1./2.)*Valpha) + (-((sqrt(3.))/2.)*Vbeta)+ (Vi/6.*sin(3.*gamma));

                Dutya=sgn(g);
                Dutyb=sgn(h);
                Dutyc=sgn(i);
            }
            else
            {
            gamma=atan2(Valpha,Vbeta);

            Dutya = ((1.*Valpha) + (0.*Vbeta) + (Vi/6.*sin(3*gamma)))/(Vsup/2.);
            Dutyb = (((((-1./2.)*Valpha) + ((sqrt(3.))/2.)*Vbeta)) + (Vi/6.*sin(3.*gamma)))/(Vsup/2.);
            Dutyc = ((((-1./2.)*Valpha) + (-((sqrt(3.))/2.)*Vbeta)) + (Vi/6.*sin(3.*gamma)))/(Vsup/2.);
            }
            break;

        default:
            Dutya = 0;
            Dutyb = 0;
            Dutyc = 0;
        }
        Dutya=((Dutya>1.)?1.:((Dutya<-1.)?-1.:Dutya));
        Dutyb=((Dutyb>1.)?1.:((Dutyb<-1.)?-1:Dutyb));
        Dutyc=((Dutyc>1.)?1.:((Dutyc<-1.)?-1.:Dutyc));
    }

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%OUTPUTS) */
}

/* Function: mdlUpdate ========================================================
 * Abstract:
 *    This function is called once for every major integration time step.
 *    Time-discrete states are typically updated here, but this function is useful
 *    for performing any tasks that should only take place once per integration
 *    step.
 */
#undef MDL_UPDATE
/* mdlUpdate() is disabled because PEDUTY01MSEREF has no time-discrete states */
#if defined (MDL_UPDATE)
static void mdlUpdate(SimStruct *S, int_T tid)
{
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%UPDATE) */

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%UPDATE) */
}
#endif /* MDL_UPDATE */

#undef MDL_ZERO_CROSSINGS
/* mdlZeroCrossings() is disabled because PEDUTY01MSEREF has no "hasDiscontinuities" flag. */
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
