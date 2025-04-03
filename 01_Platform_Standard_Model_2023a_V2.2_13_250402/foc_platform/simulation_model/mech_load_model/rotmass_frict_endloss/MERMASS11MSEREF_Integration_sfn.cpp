/**  @file
  *  MSERef Mechanics Simulink Library 
  *  protection class C-SC1
  *
  *  Copyright Robert Bosch GmbH 2021
  *
  *  All rights reserved, also regarding any disposal, exploitation,
  *  reproduction, editing, distribution, as well as in the event of
  *  applications for industrial property rights.
  *
  */

#define S_FUNCTION_NAME MERMASS11MSEREF_Integration_sfn
#define S_FUNCTION_LEVEL 2


#include "simstruc.h"

#define _USE_MATH_DEFINES
#include "math.h"

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%HEADER) */
// S-function parameter related functions
#if defined(MATLAB_MEX_FILE) || defined(RT) ||defined(NRT)

real_T mermass11mseref_int_GetRealParam(SimStruct *S, int_T idx)
{
    return mxGetScalar( ssGetSFcnParam(S,idx));
}

int_T mermass11mseref_int_ParamIsDouble(SimStruct *S, int_T paridx)
{
    return mxIsDouble( ssGetSFcnParam(S, paridx) );
}

size_t mermass11mseref_int_ParamGetNumElements(SimStruct *S, int_T paridx)
{
    return mxGetNumberOfElements( ssGetSFcnParam(S, paridx) );
}

#endif /* MATLAB_MEX_FILE */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%HEADER) */

/*
  Enum type for use with following functions
     mermass11mseref_int_GetRealParam(),
     mermass11mseref_int_GetIntParam(),
     mermass11mseref_int_ParamIsDouble(),
     mermass11mseref_int_ParamGetNumElements()
*/
enum Params
{
    en_phiinit,    /* Initial Angular displacement [deg] */
    en_nRPMinit,    /* Initial Rotational speed [rev/min] */
    en_J,    /* Inertia [kgm2] */
};


/*====================*
 * S-function methods *
 *====================*/

/* Function: mdlCheckParameters =============================================
 * Abstract:
 *    Validate our parameters to verify they are okay.
 */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS)

/* PARAMETERS */
static void mdlCheckParameters(SimStruct *S)
{
    /* declaring parameters as local variables */
    const real_T phiinit = mermass11mseref_int_GetRealParam(S, en_phiinit);
    const real_T nRPMinit = mermass11mseref_int_GetRealParam(S, en_nRPMinit);
    const real_T J = mermass11mseref_int_GetRealParam(S, en_J);

    /* checking parameter phiinit [-1e7;1e7] */
    if (!((phiinit >= -1.0e7) && (phiinit <= 1.0e7))) {
        ssPrintf("ERROR: Parameter 'phiinit' %f outside boundaries [-1e7;1e7] \n", phiinit);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'phiinit', see command window for more information");
    }
    if (!mermass11mseref_int_ParamIsDouble(S, en_phiinit) || mermass11mseref_int_ParamGetNumElements(S, en_phiinit) != 1) {
        ssPrintf("ERROR: Parameter 'phiinit' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'phiinit', see command window for more information");
    }

    /* checking initial of parameter nRPMinit [-1e7;1e7] */
    if (!((nRPMinit >= -1.0e7) && (nRPMinit <= 1e7))) {
        ssPrintf("ERROR: Parameter 'nRPMinit' %f outside boundaries [-1e7;1e7] \n", nRPMinit);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'nRPMinit', see command window for more information");
    }
    if (!mermass11mseref_int_ParamIsDouble(S, en_nRPMinit) || mermass11mseref_int_ParamGetNumElements(S, en_nRPMinit) != 1) {
        ssPrintf("ERROR: Parameter 'nRPMinit' must be a scalar double  \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'nRPMinit', see command window for more information");
    }

    /* checking parameter J [1e-8;1e9] */
    if (!((J >= 1.0e-8) && (J <= 1.0e9))) {
        ssPrintf("ERROR: Parameter 'J' %f outside boundaries [1e-8;1e9] \n", J);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'J', see command window for more information");
    }
    if (!mermass11mseref_int_ParamIsDouble(S, en_J) || mermass11mseref_int_ParamGetNumElements(S, en_J) != 1) {
        ssPrintf("ERROR: Parameter 'J' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'J', see command window for more information");
    }

    return;
}
#endif /* MDL_CHECK_PARAMETERS */


#undef MDL_START

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* set number of parameters */
    /* parameters: phiinit nRPMinit J */
    ssSetNumSFcnParams(S,3);
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) return;
    } else {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    /* Continuous states: phi omega  */
    ssSetNumContStates(S, 2);
    /* Discrete states:  */
    ssSetNumDiscStates(S, 0);

    if (!ssSetNumInputPorts(S, 1)) return;


    /* Input: Tsum */
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 0);

    if (!ssSetNumOutputPorts(S, 2)) return;


    /* Output: phiOut */
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S,  0, COMPLEX_NO);


    /* Output: nRPM */
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S,  1, COMPLEX_NO);

    ssSetNumRWork(S, 0); /* */
    ssSetNumIWork(S, 0); /* */

    ssSetNumSampleTimes(S, 1); /* multiple sample times are not supported by the s-fn generator */

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITSIZES) */
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITSIZES) */
}

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specify the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}


#define MDL_INITIALIZE_CONDITIONS
#ifdef MDL_INITIALIZE_CONDITIONS
/* Function: mdlInitializeConditions ========================================
 * Abstract:
 *    Initialize the states
 */

static void mdlInitializeConditions(SimStruct *S)
{
    /* declaring state variables as local variables */
    real_T *adContStates = ssGetContStates(S);
    real_T& phi   = adContStates[0];
    real_T& omega = adContStates[1];

    /* declaring parameters as local variables */
    const real_T phiinit   = mermass11mseref_int_GetRealParam(S, en_phiinit);
    const real_T nRPMinit = mermass11mseref_int_GetRealParam(S, en_nRPMinit);

    phi   = phiinit; /* initialize  displacement */

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITIALIZECONDITIONS) */
    /* convert to SI */
    phi *= M_PI/180.0; // [degree]  to [rad]
    omega = nRPMinit*M_PI/30.0; // [rev/min] to [rad/s]
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITIALIZECONDITIONS) */
}
#endif

#define MDL_DERIVATIVES
#ifdef MDL_DERIVATIVES
/* Function: mdlDerivatives =================================================
 * Abstract:
 *    In this function, you compute the S-function block's derivatives.
 *    The derivatives are placed in the derivative vector, ssGetdX(S).
 */

static void mdlDerivatives(SimStruct *S)
{
    /* declaring state derivatives as local variables */
    real_T *adContStateDerivs = ssGetdX(S);
    real_T& dphi = adContStateDerivs[0];
    real_T& domega = adContStateDerivs[1];
    /* declaring inputs as local variables */
    const real_T Tsum = *ssGetInputPortRealSignalPtrs(S, 0)[0];
    /* declaring parameters as local variables */
    const real_T J = mermass11mseref_int_GetRealParam(S, en_J);
    /* declaring state variables as local variables */
    real_T *adContStates = ssGetContStates(S);
    const real_T& omega = adContStates[1];

    /*
        dphi = ???
        domega = ???

    */
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%DERIVATIVES) */

 // Derivative of displacement = velocity ...
    dphi = omega;
    domega = Tsum/J;
 // Derivative of velocity = acceleration ...

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%DERIVATIVES) */
}
#endif

#undef MDL_UPDATE

/* Function: mdlOutputs =======================================================
 *
*/

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /* declaring output variables */
    real_T *output0 = (real_T *)ssGetOutputPortSignal(S, 0);
    real_T& phiOut = output0[0];
    real_T *output1 = (real_T *)ssGetOutputPortSignal(S, 1);
    real_T& nRPM = output1[0];
    /* declaring state variables as local variables */
    real_T *adContStates = ssGetContStates(S);
    real_T& phi = adContStates[0];
    real_T& omega = adContStates[1];

    /*
        phiOut = ???
        nRPM = ???

    */
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%OUTPUTS) */
 phiOut = phi * 180.0/M_PI; // [rad] to [degree]
 nRPM = omega * 30.0/M_PI; // [rad/s] to [rev/min]
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%OUTPUTS) */
}

#undef MDL_ZERO_CROSSINGS

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

