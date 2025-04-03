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
  
#define S_FUNCTION_NAME PEPS101MSEREF_potential_sfn
#define S_FUNCTION_LEVEL 2


#include "simstruc.h"

#include <math.h>

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%PREHEADER) */
// S-function parameter related functions
#if defined(MATLAB_MEX_FILE) || defined(RT) ||defined(NRT)
real_T peps101mseref_GetRealParam(SimStruct *S, int_T idx)
{
    return mxGetScalar( ssGetSFcnParam(S,idx));
}

int_T peps101mseref_GetIntParam(SimStruct *S, int_T idx)
{
    return (int_T)mxGetScalar( ssGetSFcnParam(S,idx) );
}

int_T peps101mseref_ParamIsDouble(SimStruct *S, int_T paridx)
{
    return mxIsDouble( ssGetSFcnParam(S, paridx) );
}

size_t peps101mseref_ParamGetNumElements(SimStruct *S, int_T paridx)
{
    return mxGetNumberOfElements( ssGetSFcnParam(S, paridx) );
}

#endif /* MATLAB_MEX_FILE */


// *******************************************************************************
// S-function related mathematical functions
int peps101mseref_sign(const double x) {
    if (x>0) return 1;
    if (x<0) return -1;
    return 0;
}

/** 
 * peps101mseref_friction_with_slip_f1: Used to compute the friction torque Tfr 
 * in the continuous slip friction model. It reproduces the continuous transition between
 * stiction and motion.  
 * \param x the ratio (angular velocity)/(numerical parameter for friction treatment)
 * \return f1(x) a normalized value for the transition between stiction and motion
 * 
 * For description of this function see  <a href="https://rb-mse.bosch.com/view/MSERef/doc/powertrain/MSERef_powertrain_background.pdf#sec:mseref_pt_friction_slip_characteristics">Powertrain background documentation</a>
 */ 
/****************************************************************/
double peps101mseref_friction_with_slip_f1(double x)
{
  double x_abs=fabs(x);
  if (x_abs <= 1)
    {
        //return -0.5*x*x*x+1.5*x;
        //better is evaluation with Horner Scheme:
        return x*(1.5 -0.5*x*x);
    }
  else if (x_abs<=3)
    {
        //return (-0.1875 *x_abs*x_abs*x_abs*x_abs + 1.75 *x_abs*x_abs*x_abs-5.625*x_abs*x_abs+6.75*x_abs-1.6875)*((x>0) ? 1 : (x==0) ? 0 : -1);  
        //better is evaluation with Horner Scheme:
        
        return (-1.6875+x_abs *(6.75+ x_abs *(-5.625+ x_abs *(1.75 +x_abs * (-0.1875)))))*((x>0) ? 1 : (x==0) ? 0 : -1);
        
    }
  else
    {
        return 0;
    }
}

/** 
 * peps101mseref_friction_with_slip_f2: Used to compute the friction torque Tfr 
 * in the continuous slip friction model. It reproduces the Coulomb friction.  
 * \param x the ratio (angular velocity)/(numerical parameter for friction treatment)
 * \return f2(x) a normalized value for the Coulomb friction
 * 
 * For description of this function see  <a href="https://rb-mse.bosch.com/view/MSERef/doc/powertrain/MSERef_powertrain_background.pdf#sec:mseref_pt_friction_slip_characteristics">Powertrain background documentation</a>
 */ 
/****************************************************************/
double peps101mseref_friction_with_slip_f2(double x)
{
  double x_abs=fabs(x);
  if (x_abs <= 1)
    {
        return 0;
    }
  else if (x_abs<=3)
    {
        //return (1-(-0.1875 *x_abs*x_abs*x_abs*x_abs + 1.75 *x_abs*x_abs*x_abs-5.625*x_abs*x_abs+6.75*x_abs-1.6875))*((x>0) ? 1 : (x==0) ? 0 : -1);  
        //better is evaluation with Horner Scheme:
        
        return (1-(-1.6875+x_abs*(6.75+ x_abs*(-5.625+ x_abs*(1.75 +x_abs* (-0.1875))))))*((x>0) ? 1 : (x==0) ? 0 : -1);
    
    }
  else
    {
        return ((x>0) ? 1 : (x==0) ? 0 : -1);
    }
}

/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%PREHEADER) */

/*
    Enum type for use with inline functions
        peps101mseref_GetRealParam(),
        peps101mseref_GetIntParam(),
        peps101mseref_ParamIsDouble(),
        peps101mseref_ParamGetNumElements()
*/
enum Params
{
    en_RT20,    /* Transistor on resistance at 20 degC [Ohm] */
    en_RD20,    /* Diode on resistance at 20 degC [Ohm] */
    en_VT20,    /* Transistor forward voltage [V] */
    en_VD20,    /* Diode forward voltage [V] */
    en_IGBT,    /* Enable IGBT [-] */
    en_Ieps,    /* Numerical parameter for diode treatment [A] */
    en_alphaRT,    /* Temperature coefficient of transistor on resistance [1/K] */
    en_alphaRD,    /* Temperature coefficient of diode on resistance [1/K] */
    en_alphaVT,    /* Temperature coefficient of transistor forward voltage [1/K] */
    en_alphaVD,    /* Temperature coefficient of diode forward voltage [1/K] */
};


enum DSEn
{
    INIT = 99, // Initial state
    OFF = 0, // En=0
    ON = 1// En=1
};
/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%HEADER) */

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
    const real_T RT20 = mxGetScalar( ssGetSFcnParam(S, en_RT20)); // Transistor on resistance at 20 degC [Ohm]
    const real_T RD20 = mxGetScalar( ssGetSFcnParam(S, en_RD20)); // Diode on resistance at 20 degC [Ohm]
    const real_T VT20 = mxGetScalar( ssGetSFcnParam(S, en_VT20)); // Transistor forward voltage at 20 degC [V]
    const real_T VD20 = mxGetScalar( ssGetSFcnParam(S, en_VD20)); // Diode forward voltage at 20 degC [V]
    boolean_T IGBT  = (boolean_T)peps101mseref_GetIntParam(S, en_IGBT); // Enable IGBT [-]
    const real_T Ieps = mxGetScalar( ssGetSFcnParam(S, en_Ieps)); // Numerical parameter for diode treatment [A]
    const real_T alphaRT = mxGetScalar( ssGetSFcnParam(S, en_alphaRT)); // Thermal coefficient of transistor on resistance [1/K]
    const real_T alphaRD = mxGetScalar( ssGetSFcnParam(S, en_alphaRD)); // Thermal coefficient of diode on resistance [1/K]
    const real_T alphaVT = mxGetScalar( ssGetSFcnParam(S, en_alphaVT)); // Thermal coefficient of transistor forward voltage [1/K]
    const real_T alphaVD = mxGetScalar( ssGetSFcnParam(S, en_alphaVD)); // Thermal coefficient of diode forward voltage [1/K]


     /* checking parameter RT20 [0;1e3] */
     if (!((RT20 >= 0) && (RT20 <= 1e3))) {
        ssPrintf("ERROR: Parameter 'RT20' %f outside boundaries [0;1e3]. \n", RT20);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'RT20', see command window for more information.");
     }
     if (!peps101mseref_ParamIsDouble(S, en_RT20) || peps101mseref_ParamGetNumElements(S, en_RT20) != 1) {
        ssSetErrorStatus(S,"ERROR: Parameter 'RT20' must be a scalar double");
     }

     /* checking parameter RD20 [0;1e3] */
     if (!((RD20 >= 0) && (RD20 <= 1e3))) {
        ssPrintf("ERROR: Parameter 'RD20' %f outside boundaries [0;1e3]. \n", RD20);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'RD20', see command window for more information.");
     }
     if (!peps101mseref_ParamIsDouble(S, en_RD20) || peps101mseref_ParamGetNumElements(S, en_RD20) != 1) {
        ssSetErrorStatus(S,"ERROR: Parameter 'RD20' must be a scalar double.");
     }

     /* checking parameter VT20 [0;1e3] */
     if (!((VT20 >= 0) && (VT20 <= 1e3))) {
        ssPrintf("ERROR: Parameter 'VT20' %f outside boundaries [0;1e3]. \n", VT20);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'VT20', see command window for more information.");
     }
     if (!peps101mseref_ParamIsDouble(S, en_VT20) || peps101mseref_ParamGetNumElements(S, en_VT20) != 1) {
        ssSetErrorStatus(S,"ERROR: Parameter 'VT20' must be a scalar double.");
     }

     /* checking parameter VD20 [0;1e3] */
       if (!((VD20 >= 0) && (VD20 <= 1e3))) {
        ssPrintf("ERROR: Parameter 'VD20' %f outside boundaries [0;1e3]. \n", VD20);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'VD20', see command window for more information.");
       }
       if (!peps101mseref_ParamIsDouble(S, en_VD20) || peps101mseref_ParamGetNumElements(S, en_VD20) != 1) {
        ssSetErrorStatus(S,"ERROR: Parameter 'VD20' must be a scalar double.");
       }
  
       /* checking parameter IGBT {0;1} */
       if (!((IGBT == 0) || (IGBT == 1))) {
        ssPrintf("ERROR: Parameter 'IGBT' %f outside values {0;1}. \n", IGBT);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'IGBT', see command window for more information.");
       }
       if (!peps101mseref_ParamIsDouble(S, en_IGBT) || peps101mseref_ParamGetNumElements(S, en_IGBT) != 1) {
         ssSetErrorStatus(S,"ERROR: Parameter 'IGBT' must be a scalar double.");
       }

       /* checking parameter Ieps [1e-11;1e6] */
       if (!((Ieps >= 1e-11) && (Ieps <= 1e6))) {
        ssPrintf("ERROR: Parameter 'Ieps' %f outside boundaries [1e-11;1e6]. \n", Ieps);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'Ieps', see command window for more information.");
       }
       if (!peps101mseref_ParamIsDouble(S, en_Ieps) || peps101mseref_ParamGetNumElements(S, en_Ieps) != 1) {
         ssSetErrorStatus(S,"ERROR: Parameter 'Ieps' must be a scalar double.");
       }

       /* checking parameter alphaRT [-1e9;1e9] */
       if (!((alphaRT >= -1e9) && (alphaRT <= 1e9))) {
        ssPrintf("ERROR: Parameter 'alphaRT' %f outside boundaries [-1e9;1e9]. \n", alphaRT);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'alphaRT', see command window for more information.");
       }
       if (!peps101mseref_ParamIsDouble(S, en_alphaRT) || peps101mseref_ParamGetNumElements(S, en_alphaRT) != 1) {
        ssSetErrorStatus(S,"ERROR: Parameter 'alphaRT' must be a scalar double.");
       }
  
       /* checking parameter alphaRD [-1e9;1e9] */
       if (!((alphaRD >= -1e9) && (alphaRD <= 1e9))) {
        ssPrintf("ERROR: Parameter 'alphaRD' %f outside boundaries [-1e9;1e9]. \n", alphaRD);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'alphaRD', see command window for more information.");
       }
       if (!peps101mseref_ParamIsDouble(S, en_alphaRD) || peps101mseref_ParamGetNumElements(S, en_alphaRD) != 1) {
         ssSetErrorStatus(S,"ERROR: Parameter 'alphaRD' must be a scalar double.");
       }
  
       /* checking parameter alphaVT [-1e9;1e9] */
       if (!((alphaVT >= -1e9) && (alphaVT <= 1e9))) {
        ssPrintf("ERROR: Parameter 'alphaVT' %f outside boundaries [-1e9;1e9]. \n", alphaVT);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'alphaVT', see command window for more information.");
       }
       if (!peps101mseref_ParamIsDouble(S, en_alphaVT) || peps101mseref_ParamGetNumElements(S, en_alphaVT) != 1) {
         ssSetErrorStatus(S,"ERROR: Parameter 'alphaVT' must be a scalar double");
       }
  
       /* checking parameter alphaVD [-1e9;1e9] */
       if (!((alphaVD >= -1e9) && (alphaVD <= 1e9))) {
        ssPrintf("ERROR: Parameter 'alphaVD' %f outside boundaries [-1e9;1e9]. \n", alphaVD);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'alphaVD', see command window for more information.");
       }
       if (!peps101mseref_ParamIsDouble(S, en_alphaVD) || peps101mseref_ParamGetNumElements(S, en_alphaVD) != 1) {
         ssSetErrorStatus(S,"ERROR: Parameter 'alphaVD' must be a scalar double.");
       }
      
     return;
}
#endif /* MDL_CHECK_PARAMETERS */


/* Function: mdlStart =======================================================
 * Abstract:
 *    Does startup tasks.
 */
#define MDL_START
#if defined(MDL_START)
static void mdlStart(SimStruct *S)
{
}
#endif /* MDL_START */


/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setups sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* set number of parameters */
    /* parameters: RT20 RD20 VT20 VD20 IGBT Ieps alphaRT alphaRD alphaVT alphaVD */
    ssSetNumSFcnParams(S,10);
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) return;
    } else {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    /* Continuous states:  */
    ssSetNumContStates(S, 0);
    /* Discrete states:  */
    ssSetNumDiscStates(S, 0);

    if (!ssSetNumInputPorts(S, 5)) return;

    /* Input: I */
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    /* Input: En */
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  1, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 1, 1);

    /* Input: PWM */
    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortDataType(S, 2, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  2, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 2, 1);

    /* Input: Vsup */
    ssSetInputPortWidth(S, 3, 1);
    ssSetInputPortDataType(S, 3, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  3, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 3, 1);

    /* Input: theta */
    ssSetInputPortWidth(S, 4, 1);
    ssSetInputPortDataType(S, 4, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  4, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 4, 1);

    if (!ssSetNumOutputPorts(S, 2)) return;

    /* Output: V */
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);

    /* Output: Ploss */
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);

    ssSetNumRWork(S, 1); /* Is_VTrans_geq_VD (flag: Is VTrans = R*|I| >= VD for the first time?) */
    ssSetNumIWork(S, 0); /* */

    ssSetNumSampleTimes(S, 1);

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITSIZES) */
    ssSetNumNonsampledZCs(S, 1);
    ssSetNumModes(S, 1); // DSEn (flag: Is En-input greater than 0.5?)
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

/* Function: mdlInitializeConditions ========================================
 * Abstract:
 *    Initialize the states
 */
static void mdlInitializeConditions(SimStruct *S)
{
    /* declaring mode vector variables */
    int_T  *Mode = ssGetModeVector(S);
    int_T& DSEn = Mode[0]; // Flag: Is En-input greater than 0.5?
    
    /* declaring Rwork vector variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& Is_VTrans_geq_VD = adRWork[0]; // Flag: Is VTrans = R*|I| >= VD for the first time?

    /* Initialisation */
    DSEn = INIT;
    Is_VTrans_geq_VD = 0.0;

}

/* Function: mdlOutputs =======================================================
 *
*/

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /* declaring parameters as local variables */
    const real_T RT20 = mxGetScalar( ssGetSFcnParam(S, en_RT20)); // Transistor on resistance at 20 degC [Ohm]
    const real_T RD20 = mxGetScalar( ssGetSFcnParam(S, en_RD20)); // Diode on resistance at 20 degC [Ohm]
    const real_T VT20 = mxGetScalar( ssGetSFcnParam(S, en_VT20)); // Transistor forward voltage at 20 degC [V]
    const real_T VD20 = mxGetScalar( ssGetSFcnParam(S, en_VD20)); // Diode forward voltage at 20 degC [V]
    boolean_T IGBT  = (boolean_T)peps101mseref_GetIntParam(S, en_IGBT); // Enable IGBT [-]
    const real_T Ieps = mxGetScalar( ssGetSFcnParam(S, en_Ieps)); // Numerical parameter for diode treatment [A]
    const real_T alphaRT = mxGetScalar( ssGetSFcnParam(S, en_alphaRT)); // Thermal coefficient of transistor on resistance [1/K]
    const real_T alphaRD = mxGetScalar( ssGetSFcnParam(S, en_alphaRD)); // Thermal coefficient of diode on resistance [1/K]
    const real_T alphaVT = mxGetScalar( ssGetSFcnParam(S, en_alphaVT)); // Thermal coefficient of transistor forward voltage [1/K]
    const real_T alphaVD = mxGetScalar( ssGetSFcnParam(S, en_alphaVD)); // Thermal coefficient of diode forward voltage [1/K]
    
    /* declaring mode vector variables */
    int_T  *Mode = ssGetModeVector(S);
    int_T& DSEn = Mode[0]; // Flag: Is En-input greater than 0.5?

    /* declaring Rwork vector variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& Is_VTrans_geq_VD = adRWork[0]; // Flag: Is VTrans = R*|I| >= VD for the first time?

    /* declaring inputs as local variables */
    const real_T I = *ssGetInputPortRealSignalPtrs(S, 0)[0];        // Leg current [A]
    const real_T En = *ssGetInputPortRealSignalPtrs(S, 1)[0];       // Enable transistor control [-]
    const real_T PWM = *ssGetInputPortRealSignalPtrs(S, 2)[0];      // PWM signal [-]
    const real_T Vsup = *ssGetInputPortRealSignalPtrs(S, 3)[0];     // Supply voltage [V]
    const real_T theta = *ssGetInputPortRealSignalPtrs(S, 4)[0];    // Temperature [degC]
    
    /* declaring output variables */
    real_T *output0 = (real_T *)ssGetOutputPortSignal(S, 0);    // Leg potential [V]
    real_T& V = output0[0];
    real_T *output1 = (real_T *)ssGetOutputPortSignal(S, 1);    // Power losses [W]
    real_T& Ploss = output1[0];
    
/*
    V = ???
    Ploss = ???
*/
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%OUTPUTS) */
// Auxiliary variables declaration
real_T RT, RD, VT, VD; // Temperature dependent on resistances resp. forward voltages

// Checking that `PWM` input value is in range [0; 1]
if ( (PWM < 0) || (PWM > 1) ) // PWM in ]-Inf; 0[ Or ]1; +Inf[
{
    ssSetErrorStatus(S, "ERROR: `PWM` value not in range [0; 1]");
}

// Computing temperature dependent parameters (linear approximation)
// Implementing equations (1a)-(1d) from `PEPS101MSEREF_details.pdf`
    RT = RT20*(1 + alphaRT*(theta - 20));
    RD = RD20*(1 + alphaRD*(theta - 20));
    VT = VT20*(1 + alphaVT*(theta - 20));
    VD = VD20*(1 + alphaVD*(theta - 20));
    
     // checking RT > 0
     if ( RT < 0 ) {
        ssPrintf("ERROR: 'RT(theta)' %f strictly negative. \n", RT);
        ssSetErrorStatus(S,"ERROR: Wrong value for 'RT(theta)', see command window for more information.");
     }

     // checking RD > 0
     if ( RD < 0 ) {
        ssPrintf("ERROR: 'RD(theta)' %f strictly negative. \n", RD);
        ssSetErrorStatus(S,"ERROR: Wrong value for 'RD(theta)', see command window for more information.");
     }

     // checking VT > 0
     if ( VT < 0 ) {
        ssPrintf("ERROR: 'VT(theta)' %f strictly negative. \n", VT);
        ssSetErrorStatus(S,"ERROR: Wrong value for 'VT(theta)', see command window for more information.");
     }

     // checking VD > 0
     if ( VD < 0 ) {
        ssPrintf("ERROR: 'VD(theta)' %f strictly negative. \n", VD);
        ssSetErrorStatus(S,"ERROR: Wrong value for 'VD(theta)', see command window for more information.");
     }
        

// Setting new discrete state value for `DSEn`
if (ssIsMajorTimeStep(S))
{
    if (En >= 0.5)
    {
        DSEn = ON;
        
        // Checking once in Major Time Step if a free-wheel diode can conduct current with upper/lower transistor ON.
        if ( (IGBT == false) && (Is_VTrans_geq_VD <= 0.5) ) // MOSFET considered
        {
            if (PWM >= 1.0) // Upper transistor is ON
            {
                // Checking if free-wheel diode can conduct current with upper transistor ON.
                if ( - RT*I >= VD ) // - RT*I >= VD implies I < 0 since RT >= 0 and VD >= 0
                {
                    ssPrintf("WARNUNG: - RT*I >= VD at t = %f, leading to possible free-wheel diode conduction. Please interpret simulation results carefully. \n", ssGetT(S));
                    Is_VTrans_geq_VD = 1.0; // Setting `Is_VTrans_geq_VD` to one to display warning message only once
                }
                
            }
            else if (PWM <= 0.0) // Lower transistor is ON
            {
                // Checking if free-wheel diode can conduct current with lower transistor ON.
                if ( RT*I >= VD ) // RT*I >= VD implies I >= 0 since VD >= 0 and RT >= 0
                {
                    ssPrintf("WARNUNG: RT*I >= VD at t = %f, leading to possible free-wheel diode conduction. Please interpret simulation results carefully. \n", ssGetT(S));
                    Is_VTrans_geq_VD = 1.0; // Setting `Is_VTrans_geq_VD` to one to display warning message only once
                }
                
            } // endif (PWM >= 1.0)
                
        } // endif (IGBT == false)
            
    } 
    else if (En < 0.5)
    {DSEn = OFF;}
    else // Unsupported case
    {
        ssSetErrorStatus(S, "ERROR: DSEn not in the set {`OFF`, `ON`}. Never reach this state.");
    } // endif (En >= 0.5)
}

// Computing leg potential `V` and power losses `Ploss` (implementing Tables 1 and 2 from `PEPS101MSEREF_details.pdf`)
if (DSEn == ON) // En >= 0.5: only one transistor is ON.
{
    
    if (IGBT == true) // IGBT considered
    {
        
        if(PWM >= 1.0) // Upper transistor is ON
        {
            if(I >= 0.0)
            {
                V = Vsup - RT*I - VT*peps101mseref_sign(I);
                Ploss = RT*I*I + VT*I;
            }
            else // I < 0
            {
                V = Vsup - RD*I + VD;
                Ploss = RD*I*I - VD*I;
            }
        }
        
        else if (PWM <= 0.0) // Lower transistor is ON
        {
            if(I >= 0.0)
            {
                V = -RD*I - VD*peps101mseref_sign(I);
                Ploss = RD*I*I + VD*I;
            }
            else // I < 0
            {
                V = -RT*I + VT;
                Ploss = RT*I*I - VT*I;
            }
        } 
        else // (PWM > 0.0) && (PWM < 1.0)
        {
            V = -99.0;
            Ploss = -99.0;
            ssSetErrorStatus(S, "ERROR: PWM value can only be either 0 or 1 for IGBT transistors.");
        }// end if( PWM >= 1.0 )
            
    }

    else // (IGBT == false): MOSFET considered
    {    
        if (PWM >= 1.0) // Upper transistor is ON
        {
            V = Vsup - RT*I;
            
            Ploss = RT*I*I;
        }
        else if (PWM <= 0.0) // Lower transistor is ON
        {
            V = - RT*I;
            
            Ploss = RT*I*I;
        }
        else // (PWM > 0.0) && (PWM < 1.0)
        {
            V = PWM*Vsup - RT*I;
            
            Ploss = RT*I*I;
        }// end if( PWM >= 1.0 )
        
    } // endif (IGBT == true)
    
}
else // (DSEn == OFF) En < 0.5: Free-wheel mode (both transistors are OFF)
{
    // Implementing Equation (2) from `PEPS101MSEREF_details.pdf`
    // with f1 = peps101mseref_friction_with_slip_f1 and f2 = peps101mseref_friction_with_slip_f2
    V = -(0.5*Vsup + VD)*( peps101mseref_friction_with_slip_f1(I/Ieps) 
    + peps101mseref_friction_with_slip_f2(I/Ieps) ) + Vsup/2 - RD*I; 

    Ploss = RD*I*I + ( peps101mseref_friction_with_slip_f1(I/Ieps) 
    + peps101mseref_friction_with_slip_f2(I/Ieps) )*VD*I;
}    // endif(DSEn == ON)

}

/* Function: mdlUpdate ========================================================
 * Abstract:
 *    This function is called once for every major integration time step.
 *    Discrete states are typically updated here, but this function is useful
 *    for performing any tasks that should only take place once per integration
 *    step.
 */
#define MDL_UPDATE
#if defined(MDL_UPDATE)
static void mdlUpdate(SimStruct *S, int_T tid)
{
}

#endif /* MDL_UPDATE */

#define MDL_DERIVATIVES
#ifdef MDL_DERIVATIVES
/* Function: mdlDerivatives =================================================
 * Abstract:
 *    In this function, you compute the S-function block's derivatives.
 *    The derivatives are placed in the derivative vector, ssGetdX(S).
 */
static void mdlDerivatives(SimStruct *S)
{

}
#endif

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
    /* declaring inputs as local variables */
    const real_T En = *ssGetInputPortRealSignalPtrs(S, 1)[0];   // Enable signal [-]

    real_T *zcSignals = ssGetNonsampledZCs(S);

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%ZEROCROSSINGS) */
    // Detecting when `En` crosses `0.5`
    zcSignals[0] = En - 0.5;
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
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
    #include "simulink.c"      /* MEX-file interface mechanism */
#else
    #include "cg_sfun.h"       /* Code generation registration function */
#endif 
