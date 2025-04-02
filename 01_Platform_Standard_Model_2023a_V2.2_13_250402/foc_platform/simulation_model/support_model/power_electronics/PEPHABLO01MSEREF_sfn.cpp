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

#define S_FUNCTION_NAME PEPHABLO01MSEREF_sfn
#define S_FUNCTION_LEVEL 2
#define MAX_STRING_PARAM_LENGTH 1024


#include "simstruc.h"

#define _USE_MATH_DEFINES
#include <math.h>

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%PREHEADER) */
// S-function parameter related functions
#if defined(MATLAB_MEX_FILE) || defined(RT) ||defined(NRT)
real_T pephablo01mseref_GetRealParam(SimStruct *S, int_T idx)
{
    return mxGetScalar( ssGetSFcnParam(S,idx));
}

int_T pephablo01mseref_GetIntParam(SimStruct *S, int_T idx)
{
    return (int_T)mxGetScalar( ssGetSFcnParam(S,idx) );
}

int_T pephablo01mseref_ParamIsDouble(SimStruct *S, int_T paridx)
{
    return mxIsDouble( ssGetSFcnParam(S, paridx) );
}

size_t pephablo01mseref_ParamGetNumElements(SimStruct *S, int_T paridx)
{
    return mxGetNumberOfElements( ssGetSFcnParam(S, paridx) );
}

#endif /* MATLAB_MEX_FILE */

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%PREHEADER) */


/*
    Enum type for use with inline functions
        pephablo01mseref_GetRealParam(),
        pephablo01mseref_GetIntParam(),
        pephablo01mseref_ParamIsDouble(),
        pephablo01mseref_ParamGetNumElements()
*/
enum PEPHABLO01MSEREF_enum_params
{
    en_beta,    /* Block width [Elec degree] */
    en_range,    /* PWM range */
    en_phi_offset,    /* Offset angle [Elec degree] */
};

#define DECLARE_BETA     real_T beta = pephablo01mseref_GetRealParam(S, en_beta);    // Block width [Elec degree]
#define DECLARE_range    int_T range = pephablo01mseref_GetIntParam(S, en_range); // PWM range
#define DECLARE_phi_offset   int_T phi_offset = pephablo01mseref_GetIntParam(S, en_phi_offset); // Offset angle [Elec degree]


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
    real_T beta = pephablo01mseref_GetRealParam(S, en_beta);     // Block width [Elec degree]
    int_T range = pephablo01mseref_GetIntParam(S, en_range);   // PWM range
    real_T phi_offset = pephablo01mseref_GetRealParam(S, en_phi_offset); // Offset angle [Elec degree]

    /* checking parameter beta [0; 180] -- Block width */
    if (!((beta >= 0.0) && (beta <= 180.0))) {
        ssPrintf("ERROR: Parameter 'beta'=%f outside boundaries [0;180]. \n", beta);
        ssSetErrorStatus(S,"ERROR: Parameter 'beta' outside boundaries [0;180]. \n");
    }
    if (!pephablo01mseref_ParamIsDouble(S, en_beta) || pephablo01mseref_ParamGetNumElements(S, en_beta) != 1) {
        ssPrintf("ERROR: Parameter 'beta' must be a scalar double. \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'beta' must be a scalar double. \n");
    }

    /* checking parameter range {1; 2} -- PWM range */
    if (!((range >= 1) && (range <= 2))) {
        ssPrintf("ERROR: Parameter 'range'=%d outside set {1;2}. \n", range);
        ssSetErrorStatus(S,"ERROR: Parameter 'range' outside set {1;2}. \n");
    }
    if (!pephablo01mseref_ParamIsDouble(S, en_range) || pephablo01mseref_ParamGetNumElements(S, en_range) != 1
       || (pephablo01mseref_GetRealParam(S, en_range) != pephablo01mseref_GetIntParam(S, en_range))) {
        ssPrintf("ERROR: Parameter 'range' must be a scalar integer. \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'range' must be a scalar integer. \n");
    }

    /* checking parameter phi_offset {0, 120, 240} -- Offset angle */
    if (!((phi_offset == 0.0) || (phi_offset == 120.0) || (phi_offset == 240.0))) {
        ssPrintf("ERROR: Parameter 'phi_offset'=%f outside set {0;120;240}. \n", phi_offset);
        ssSetErrorStatus(S,"ERROR: Parameter 'phi_offset' outside set {0;120;240}. \n");
    }
    if (!pephablo01mseref_ParamIsDouble(S, en_phi_offset) || pephablo01mseref_ParamGetNumElements(S, en_phi_offset) != 1) {
        ssPrintf("ERROR: Parameter 'phi_offset' must be a scalar double. \n");
        ssSetErrorStatus(S,"ERROR: Parameter 'phi_offset' must be a scalar double. \n");
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
}
#endif /* MDL_START */

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* set number of parameters */
    /* parameters: beta, range, phi_offset */
    ssSetNumSFcnParams(S, 3);
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

    /* Input: gamma */
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    /* Input: N */
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 1, 1);

    /* Input: phi */
    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortDataType(S, 2, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 2, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 2, 1);


    /* Outputs ------------------- */
    if (!ssSetNumOutputPorts(S, 3)) return;

    /* Output: En */
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);

    /* Output: PWM */
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);

    /* Output: Internal variables */
    ssSetOutputPortWidth(S, 2, 4); // DSPWM, DSEn, yPWM, yEn
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 2, COMPLEX_NO);

    ssSetNumRWork(S, 0); /* */
    ssSetNumIWork(S, 0); /*  */
    ssSetNumSampleTimes(S, 1); /* multiple sample times are not supported by the s-fn generator */

    /* If you want to use pointer work vectors, use the following statement */
    /* ssSetNumPWork(S, [number of work vectors]); */

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    /* ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_WORKS_WITH_CODE_REUSE)); */

    // DO NOT FORGET TO DEFINE ZERO CROSSING VARIABLES !!!

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITSIZES) */
    ssSetNumNonsampledZCs(S, 2); // two zero-crossing signals ZC0 and ZC1
    ssSetNumModes(S, 2); // two mode vectors: DSPWM and DSEn
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITSIZES) */
}


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


#define MDL_INITIALIZE_CONDITIONS   /*Change to #undef to remove */
                                                    /*function*/
#if defined(MDL_INITIALIZE_CONDITIONS)

static void mdlInitializeConditions(SimStruct *S)
{
    real_T beta = pephablo01mseref_GetRealParam(S, en_beta);    // Block width [Elec degree]

    // declaring mode variables
    int_T& DSPWM = (ssGetModeVector(S))[0];
    int_T& DSEn = (ssGetModeVector(S))[1];

    DSPWM = 99; // DSPWM initialization
    DSEn = 99; // DSEn initialization

}
#endif


/* Function: mdlOutputs =======================================================
 * Abstract:
 *    Calculate model outputs here.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    /* declaring parameters as local variables */
    real_T beta = pephablo01mseref_GetRealParam(S, en_beta);    // Block width [Elec degree]
    int_T range = pephablo01mseref_GetIntParam(S, en_range); // PWM range
    real_T phi_offset = pephablo01mseref_GetRealParam(S, en_phi_offset); // Offset angle [Elec degree]

    /* declaring inputs as local variables */
    real_T gamma = *(ssGetInputPortRealSignalPtrs(S, 0))[0]; // Advance angle for turn-on [Elec degree]
    real_T N = *(ssGetInputPortRealSignalPtrs(S, 1))[0];     // Number of pole pairs [-]
    real_T phi = *(ssGetInputPortRealSignalPtrs(S, 2))[0];     // Mechanical rotor angle [degree]

    /* declaring output variables */
    real_T& En = ((real_T *)(ssGetOutputPortSignal(S, 0)))[0];    // Enable [-]
    real_T& PWM = ((real_T *)(ssGetOutputPortSignal(S, 1)))[0];    // PWM [-]

    /* output for internal variables */
    real_T *internalsOutput = (real_T *)ssGetOutputPortSignal(S, 2);

    // declaring mode variables
    int_T& DSPWM = (ssGetModeVector(S))[0];
    int_T& DSEn = (ssGetModeVector(S))[1];

/*
    En = ???
    PWM = ???
*/
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%OUTPUTS) */

    /* checking input gamma ]-180; 180] */
    if (!((gamma > -180.0) && (gamma <= 180.0))) {
        ssPrintf("ERROR: Input 'gamma'=%f outside boundaries ]-180;180]. \n", gamma);
        ssSetErrorStatus(S,"ERROR: Input 'gamma' outside boundaries ]-180;180]. \n");
    }

    /* checking input N >= 1.0 */
    if (!(N >= 1.0)) {
    ssSetErrorStatus(S,"ERROR: Input 'N' outside boundaries [1;+Infty]. \n");
    }
    if (ceil(N) != N) {
        ssSetErrorStatus(S,"ERROR: Input 'N' must be a scalar integer. \n");
    }

    // Temporary variable declaration
    real_T yPWM, yEn;
    real_T phirad, gammarad, phi_offsetrad;

    // Unit conversion degree -> rad
    phirad = phi*M_PI/180.0;
    gammarad = gamma*M_PI/180.0;
    phi_offsetrad = phi_offset*M_PI/180.0;

    // Compute DSPWM and DSEn
    if (ssIsMajorTimeStep(S))
    {
        if (beta == 0.0)
        {
            DSPWM = -99; // unused
            DSEn = -99; // unused
        }
        else if (beta == 180.0)
        {
            // Compute yPWM
            yPWM = sin(N*phirad - gammarad - phi_offsetrad); // Implementing Eqn (7) from `PE3PHABLO01MSEREF_details`
        
            if ( yPWM < 0.0 ) // Implementing Eqn (8) from `PE3PHABLO01MSEREF_details`
            {DSPWM = 1;} // new mode: 1 (meaning PWM = 1)
            else // ( yPWM >= 0.0 )
            {DSPWM = 0;} // new mode: 0 (meaning PWM = 0)
            
            // Compute DSEn
            DSEn = -99; // unused
        }
        else // beta in ]0.0, 180.0[ [Elec degree]
        {
            // Temporary variable declaration
            real_T  betarad;

            // Unit conversion degree -> rad
            betarad = beta*M_PI/180.0;
            
            // Compute DSEn resp. DSPWM from yEn resp. yPWM
            yEn = cos( 2.0*(N*phirad - gammarad - phi_offsetrad) ) + cos(betarad); // Implementing Eqn (4) from `PE3PHABLO01MSEREF_details`
         
            // Compute `DSEn`
            if (yEn < 0.0) // Implementing Eqn (6) from `PE3PHABLO01MSEREF_details`
            {DSEn = 1;} // new mode: 1 (meaning En = 1)
            else // (yEn >= 0.0)
            {DSEn = 0;} // new mode: 0 (meaning En = 0)
         
            if (DSEn == 1) // En = 1
            {
                yPWM = sin(N*phirad - gammarad - phi_offsetrad); // Implementing Eqn (7) from `PE3PHABLO01MSEREF_details`
                
                if ( yPWM < 0.0 ) // Implementing Eqn (8) from `PE3PHABLO01MSEREF_details`
                {DSPWM = 1;} // new mode: 1 (meaning PWM = 1)
                else // ( yPWM >= 0.0 )
                {DSPWM = 0;} // new mode: 0 (meaning PWM = 0)
            } // end if (DSEn == 1)
            else // (DSEn != 1)
            {
                yPWM = -99.0; // unused
                DSPWM = -99; // unused                
            }
        } // endif (beta == 0.0)        
    }  // endif ssIsMajorTimeStep(S)


    // Implementing Eqns (1) and (2) from `PE3PHABLO01MSEREF_details`
    // Compute PWM below in range [0; 1]
    if (beta == 0.0)
    {
        // Compute En
        En = 0.0;

        // Compute PWM
        PWM = 0.5;
        
        // Compute yPWM and yEn
        yPWM = -99.0; // unused
        yEn = -99.0; // unused

    }
    else if (beta == 180.0)
    {
        // Compute En
        En = 1.0;        

        // Compute PWM from DSPWM    
        if (DSPWM == 1 ) // Implementing Eqn (8) from `PE3PHABLO01MSEREF_details`
        {PWM = 1.0;}
        else // ( DSPWM == 0 )
        {PWM = 0.0;}        

        // Compute yEn
        yEn = -99.0; // unused

    }
    else // beta in ]0.0, 180.0[ [Elec degree]
    {
        // Compute En resp. PWM from DSEn resp. DSPWM
        if (DSEn == 1) // En = 1.0
        {
            En = 1.0;
        
            if ( DSPWM == 1 ) // Implementing Eqn (8) from `PE3PHABLO01MSEREF_details`
            {PWM = 1.0;}
            else if ( DSPWM == 0 )
            {PWM = 0.0;}
            else // (DSPWM != 0) && (DSPWM != 1)
            {
                ssPrintf("ERROR: Mode 'DSPWM'=%d shall never reach this state. Possible values after initialization are: 0 or 1. \n", DSPWM);
                ssSetErrorStatus(S,"ERROR: Mode `DSPWM` shall never reach this state. Possible values after initialization are: 0 or 1. \n");
            } // endif ( DSPWM == 1)
                
        }
        else if (DSEn == 0) // En = 0.0
        {
            // Compute En
            En = 0.0;

            // Compute PWM
            PWM = 0.5;
        } // endif (DSEn == 1)
        else // (DSEn != 0) && (DSEn != 1)
        {
            ssPrintf("ERROR: Mode 'DSEn'=%d shall never reach this state. Possible values after initialization are: 0 or 1.  \n", DSEn);
            ssSetErrorStatus(S,"ERROR: `DSEn` shall never reach this state. Possible values after initialization are: 0 or 1.  \n");
        } // endif ( DSEn == 1)

    
    } // endif (beta == 0.0)
        
    // Compute PWM in range [-1; 1] if range == 2
    if (range == 2) // PWM range: -1 to 1
    {PWM = 2.0*PWM - 1.0;} // Implementing Eqn (3) from `PE3PHABLO01MSEREF_details`

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%OUTPUTS) */
    internalsOutput[0] = DSPWM;
    internalsOutput[1] = DSEn;
    internalsOutput[2] = yPWM;
    internalsOutput[3] = yEn;
}


#define MDL_ZERO_CROSSINGS
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
    /* declaring parameters as local variables */
    real_T beta = pephablo01mseref_GetRealParam(S, en_beta);    // Block width [Elec degree]
    int_T range = pephablo01mseref_GetIntParam(S, en_range); // PWM range
    real_T phi_offset = pephablo01mseref_GetRealParam(S, en_phi_offset); // Offset angle [Elec degree]

    /* declaring inputs as local variables */
    real_T gamma = *(ssGetInputPortRealSignalPtrs(S, 0))[0]; // Advance angle for turn-on [Elec degree]
    real_T N = *(ssGetInputPortRealSignalPtrs(S, 1))[0];     // Number of pole pairs [-]
    real_T phi = *(ssGetInputPortRealSignalPtrs(S, 2))[0];     // Mechanical rotor angle [degree]

    /* declaring zero crossing variables as local variables */
    real_T *zcSignals = ssGetNonsampledZCs(S);
    real_T& ZC0       = zcSignals[0];
    real_T& ZC1       = zcSignals[1];

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%ZEROCROSSINGS) */
    // Temporary variable declaration
    real_T  phirad, gammarad, betarad, phi_offsetrad;

    // Unit conversion degree -> rad
    phirad = phi*M_PI/180.0;
    gammarad = gamma*M_PI/180.0;
    betarad = beta*M_PI/180.0;
    phi_offsetrad = phi_offset*M_PI/180.0;
    
    // Compute ZC0 and ZC1
    if ( beta == 0.0)
    {
        ZC0 = -99.0; // unused
        ZC1 = -99.0; // unused
    }
    else if ( beta == 180.0)
    {
        /* Calculating value for zero-crossing variable ZC0.
        * It represents the transition between PWM=1 (ZC0 < 0.0) and PWM=0 (ZC0 >= 0.0),
        * and is related to the variable `DSPWM` of the mode vector*/
        ZC0 = sin(N*phirad - gammarad - phi_offsetrad);
        ZC1 = -99.0; // unused
    }
    else // beta in ]0.0, 180.0[ [Elec degree]
    {        
        /* Calculating value for zero-crossing variables ZC0 & ZC1.
        * Regarding ZC0: It represents the transition between PWM=1 (ZC0 < 0.0) and PWM=0 (ZC0 >= 0.0),
        * and is related to the variable `DSPWM` of the mode vector
        * Regarding ZC1: It represents the transition between En=1 (ZC1 < 0.0) and En=0 (ZC1 >= 0.0),
        * and is related to the variable `DSEn` of the mode vector*/
        ZC0 = sin(N*phirad - gammarad - phi_offsetrad);
        ZC1 = cos( 2.0*(N*phirad - gammarad - phi_offsetrad) ) + cos(betarad);
    }

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
