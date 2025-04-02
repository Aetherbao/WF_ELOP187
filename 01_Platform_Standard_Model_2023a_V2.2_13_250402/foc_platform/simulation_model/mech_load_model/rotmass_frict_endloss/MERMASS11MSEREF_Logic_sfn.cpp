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

#define S_FUNCTION_NAME MERMASS11MSEREF_Logic_sfn
#define S_FUNCTION_LEVEL 2


#include "simstruc.h"

#define _USE_MATH_DEFINES
#include "math.h"


/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%HEADER) */
/* Function: mermass11mseref_log_convParamUnits2SI =============================================
 * Abstract:
 *   Conversion of the parameters to SI units
 */
void mermass11mseref_log_convParamUnits2SI(
        real_T  epsn,
        real_T& omegaeps,
        real_T  nStri,
        real_T& omegaStri,
        real_T& phimin,
        real_T& phimax)
{
    /* conversion to SI units */
    omegaeps   = epsn*M_PI/30.0; // [rev/min] to [rad/s]
    omegaStri  = nStri*M_PI/30.0; // [rev/min] to [rad/s]
    phimin    *= M_PI/180.0; // [degree] to [rad]
    phimax    *= M_PI/180.0; // [degree] to [rad]
}

/* Function: mermass11mseref_log_convInputUnits2SI =============================================
 * Abstract:
 *   Conversion of the inputs to SI units
 */
void mermass11mseref_log_convInputUnits2SI(
        real_T& phi,
        real_T  nRPM,
        real_T& omega)
{
    phi   *= M_PI/180.0; // [degree] to [rad]
    omega  = nRPM*M_PI/30.0; // [rev/min] to [rad/s]
}

/* Function: mermass11mseref_log_sign =============================================
 * Abstract:
 *   Sign function
 */
int mermass11mseref_log_sign(const double x) {
    if (x>0) return 1;
    if (x<0) return -1;
    return 0;
}


// S-function parameter related functions
#if defined(MATLAB_MEX_FILE) || defined(RT) ||defined(NRT)

real_T mermass11mseref_log_GetRealParam(SimStruct *S, int_T idx)
{
    return mxGetScalar( ssGetSFcnParam(S,idx));
}

int_T mermass11mseref_log_GetIntParam(SimStruct *S, int_T idx)
{
    return (int_T)mxGetScalar( ssGetSFcnParam(S,idx) );
}

int_T mermass11mseref_log_ParamIsDouble(SimStruct *S, int_T paridx)
{
    return mxIsDouble( ssGetSFcnParam(S, paridx) );
}

size_t mermass11mseref_log_ParamGetNumElements(SimStruct *S, int_T paridx)
{
    return mxGetNumberOfElements( ssGetSFcnParam(S, paridx) );
}

#endif /* MATLAB_MEX_FILE */


// *******************************************************************************
// S-function related mathematical functions
#ifdef __cplusplus
extern "C" {
#endif

/**
 * FrictionState: Lists all the possible states of the
 * finite state machine diagram for friction handling
 * (the diagram is described in the <a href=":https://rb-mse.bosch.com/view/MSERef/doc/mechanics/MSERef_mechanics_background.pdf#fig:FSMdiagram">Mechanics background documentation</a>)
 */

enum FrictionState
{
    Stick = 0, /*!< stiction */
    SlipFW = 1, /*!< slip forward */
    SlipBW = -1, /*!< slip backward */
    DSfrInitialState = 99, /*!< initial state */
    DSfrDisabled = -99 /*!< friction disabled */
};

/**
 * EndStopState: Lists all the possible states of the
 * finite state machine diagrams for the end stop phenomenon
 * (For each modeling approach, there is one diagram:
 * - continuous approach: <a href="https://rb-mse.bosch.com/view/MSERef/doc/mechanics/MSERef_mechanics_background.pdf#fig:EndStop_FSMdiagramElastic">Mechanics background documentation</a>)
 * - discontinuous approach: <a href="https://rb-mse.bosch.com/view/MSERef/doc/mechanics/MSERef_mechanics_background.pdf#fig:endstop_FiniteStateDiagramDiscontinuous">Mechanics background documentation</a>)
 */

enum EndStopState
{
    DSendstopInitialState = 99, /*!< initial state */
    UpperLimit   = 1, /*!< upper limit */
    InRange = 0, /*!< in range */
    LowerLimit   = -1, /*!< lower limit */
    DSendstopDisabled = -99 /*!< end stop disabled */
};


/**
 * mermass11mseref_log_calcNewFrictionState: Calculates the new friction state according to the state machine described in ../MSERef_mechanics_background
 * \param oldState    the old state [-]
 * \param Fe         the external force [N or Nm]
 * \param FStickP     the stick friction force for positive v [N or Nm]
 * \param FStickM    the stick friction force for negative v [N or Nm]
 * \param v            the velocity [m/s or rad/s]
 * \param veps         the numerical parameter for friction with stiction [m/s or rad/s]
 * \return the new state
 *
 * For description of this function see  <a href="https://rb-mse.bosch.com/view/MSERef/doc/mechanics/MSERef_mechanics_background.pdf#fig:FSMdiagram">Mechanics background documentation</a>
 */
/****************************************************************/
int mermass11mseref_log_calcNewFrictionState(
        const int oldState,
        const double Fe,
        const double FStickP,
        const double FStickM,
        const double v,
        const double veps) {
    if (oldState == Stick) {            // OLD: stiction
        if (Fe > FStickP)
            return SlipFW;         // NEW: slip forward
        else if (Fe < -FStickM)
            return SlipBW;         // NEW: slip backward
        else if ( (Fe >= -FStickM) && (Fe <= FStickP) )
            return oldState;            // KEEP old state Stick
        else  printf("FATAL: mermass11mseref_log_calcNewFrictionState: never should reach this line with oldstate==Stick \n");

    } else if (oldState == SlipBW) {    // OLD: slip backward
        if ( (v >= 0) && (v < veps) && (Fe >= -FStickM) && (Fe <= FStickP) )
            return Stick;                  // NEW: stiction
        else if  ( ( ( v >= 0 ) && (Fe > FStickP) )   || ( v >= veps )  )
              return SlipFW;                 // NEW:  slip forward
        else if ( ( v < 0 ) || ( (v < veps) && ( Fe < -FStickM) ) )
            return oldState;             //KEEP old state slip backward
        else printf("FATAL: mermass11mseref_log_calcNewFrictionState: never should reach this line with oldstate==SlipBW \n");

     } else if (oldState == SlipFW) {    // OLD: slip forward
         if ( (v <= 0) && (v > -veps) && (Fe >= -FStickM) && (Fe <= FStickP) )
               return Stick;                  // NEW: stiction
         else if ( ( (v <= 0) && (Fe < -FStickM)  ) || (v <= -veps) )
               return SlipBW;                 // NEW: slip forward
         else if ( ( v > 0 ) || ( ( v > -veps) && ( Fe > FStickP) ) )
               return oldState;             //KEEP old state slip forward
         else printf("FATAL: mermass11mseref_log_calcNewFrictionState: never should reach this line with oldstate==SlipFW \n");

    } else if (oldState == DSfrInitialState) { // OLD: initial state
        if ( (v < 0) || ( (v == 0.0) && (Fe < -FStickM) ) )
            return SlipBW;                 // NEW: slip backward
        else if ( (v > 0) || ( (v == 0.0) && (Fe > FStickP) ) )
            return SlipFW;                 // NEW: slip forward
        else if ( (v == 0.0) && (-FStickM <= Fe) && (Fe <= FStickP) )
            return Stick;                 // NEW: Stiction
        else printf("FATAL: mermass11mseref_log_calcNewFrictionState: never should reach this line with oldstate==DSfrInitialState \n");

    } else if (oldState == DSfrDisabled) { // OLD: friction disabled
        return oldState;
    }
    else {
        printf("FATAL: mermass11mseref_log_calcNewFrictionState: never should reach this line with oldstate unknown \n");
    }
    return -1; // will not be reached, prevents compiler warning
}


/**
 * mermass11mseref_log_calcZeroCrossingFcnForFrictionHandling:
 * calculates the zero crossing function for transitions from a friction state to a new one,
 * according to the state machine described in ../MSERef_mechanics_background
 * \retval ZC0             returns the first transition variable [-]
 * \retval ZC1             returns the second transition variable [-]
 * \param DSfr             the discrete state of friction [-]
 * \param Fe             the external force [N or Nm]
 * \param v             the velocity [m/s or rad/s]
 * \param frictionmode     the friction mode [-]
 * \param FStickP         the stick friction force for positive v [N or Nm]
 * \param FStickM         the stick friction force for negative v [N or Nm]
 * \param veps             the numerical parameter for friction with stiction [m/s or rad/s]
 *
 * For description of this function see  <a href="https://rb-mse.bosch.com/view/MSERef/doc/mechanics/MSERef_mechanics_background.pdf#fig:FSMdiagram">Mechanics background documentation</a>
 */
/****************************************************************/

/****************************************************************/
void mermass11mseref_log_calcZeroCrossingFcnForFrictionHandling(
        double& ZC0,
        double& ZC1,
        const int DSfr,
        const double Fe,
        const double v,
        const int frictionmode,
        const double FStickP,
        const double FStickM,
        const double veps) {

 if ((frictionmode == 1)||(DSfr==DSfrInitialState) || (DSfr==DSfrDisabled)) // 1: no friction
 {
     ZC0 = DSfrDisabled;
     ZC1 = DSfrDisabled;
 }
 else                    // frictionmode=2: stribeck + slip/Coulomb friction
 {
     if(DSfr == Stick)
     {
         ZC0 = FStickP - Fe; // normally positive
         ZC1 = FStickM + Fe; // normally positive
     }
     else if (DSfr == SlipFW)
        {
            ZC0 = - 1.0; // not needed, same sign as in SlipBW
            ZC1 = 0.0 - v; // normally negative
        }
     else if (DSfr == SlipBW)
         {
            ZC0 = v; // normally negative
            ZC1 = -1.0; // not needed, same sign as in SlipFW
        }
    else
        printf("WARNING: mermass11mseref_log_calcZeroCrossingFcnForFrictionHandling: never should reach this line! \n");
    }// endif (frictionmode == 1)

}


/**
 * mermass11mseref_log_calcFrictionForceAndLosses: Calculates the friction force and losses, according to the state machine
 * described in ../MSERef_mechanics_background
 * \param DSfr         the discrete state of friction [-]
 * \param Fext         the external force [N or Nm]
 * \param Fstop     the end stop force [N or Nm]
 * \param v         the velocity [m/s or rad/s]
 * \param m         the mass [kg or kgm2]
 * \param dvisc     the viscous damping [N/(m/s) or Nm/(rad/s)]
 * \param tauinv     the inverse of time constant for numerical damping at stiction [1/s]
 * \param FStick     the force at stick friction [N or Nm]
 * \param FCoulomb     the force at Coulomb friction [N or Nm]
 * \param vStri     the stribeck velocity [m/s or rad/s]
 * \retval Ffr         the friction force [N or Nm]
 * \retval Pdfr     the friction losses [W]
 */

/****************************************************************/
void mermass11mseref_log_calcFrictionForceAndLosses(
              double& Ffr,
              double& Pdfr,
             const int DSfr,
             const double Fext,
             const double Fstop,
             const double v,
             const double m,
             const double dvisc,
             const double tauinv,
             const double FStick,
             const double FCoulomb,
             const double vStri) {


     if (DSfr == Stick)    // In stick mode, we add a damping force in order to let
                         // the velocity converge towards zero
     {
      Ffr = - Fext - Fstop - m*v*tauinv;
      Pdfr = 0.0;
     }
     else // DSfr = SlipFW or SlipBW
           // Otherwise, there is no damping force
     {
      Ffr = -mermass11mseref_log_sign(DSfr)*(FCoulomb+(FStick-FCoulomb)*exp( - mermass11mseref_log_sign(DSfr)*v/(3*vStri) ) ) - dvisc*v;
      Pdfr = fabs(Ffr*v);

     }

}


/**
 * mermass11mseref_log_calcNewEndStopStateContinuous: Calculates the new end-stop mode according to the state machine described
 * in ../MSERef_mechanics_background.
 * Here, this phenomenon is modeled with the continuous approach (Spring-damping system).
 * \param x     the displacement [m or rad]
 * \param xmin  the lower displacement limit [m or rad]
 * \param xmax  the upper displacement limit [m or rad]
 * \return the new mode
 *
 * For description of this function see  <a href="https://rb-mse.bosch.com/view/MSERef/doc/mechanics/MSERef_mechanics_background.pdf#fig:EndStop_FSMdiagramElastic">Mechanics background documentation</a>
 */

/****************************************************************/
int mermass11mseref_log_calcNewEndStopStateContinuous(
             const double x,
             const double xmin,
             const double xmax) {

      if (x >= xmax)         // Upper limit is reached
      {return UpperLimit;}
      else if (x <= xmin)     // Lower limit is reached
      {return LowerLimit;}
      else                     // xmin < x < xmax
      {return InRange;}
}


/**
 * mermass11mseref_log_calcEndStopDampingCoefficientContinuous: Calculates the damping coefficient
 * of the Spring-damping system to model the end stop phenomenon.
 * \param m         the mass [kg or kgm2]
 * \param cstop     the spring coefficient at displacement limit [N/m or Nm/rad]
 * \param kimpact     the coefficient of restitution [-]
 * \return the damping coefficient at displacement limit [N/(m/s) or Nm/(rad/s)]
 */


/****************************************************************/
double mermass11mseref_log_calcEndStopDampingCoefficientContinuous(
             const double m,
             const double cstop,
             const double kimpact) {
 /* declaring variable eps to prevent kimpact (double) from being
  * directly compared with 1 or 0 (integers, see below) */
 double eps = 1e-9;

 /* declaring variable dstop = sqrt( 4*cstop*m/(1+(pi/log(kimpact))^2 ) ) */
 if (kimpact <= eps) // pi/log(kimpact) is equal to zero, thus dstop = 2sqrt(cstop*m)
 {
  return 2*sqrt(cstop*m);
 }
 else if (kimpact >= 1.0-eps) // pi/log(kimpact) tends towards infinite, thus dstop = 0
 {
  return  0.0;
 }
 else // 0 < kimpact < 1
 {
  return  sqrt( 4.0*cstop*m / ( 1.0+(M_PI/log(kimpact)) * (M_PI/log(kimpact)) ));
 }
 //endif (kimpact == 0)
}


/**
 * mermass11mseref_log_calcEndStopForceAndLossesContinuous: Calculates the end-stop force and losses,
 * according to the state machine described in ../MSERef_mechanics_background
 * Here, this phenomenon is modeled with the continuous approach (Spring-damping system).
 * \param DSendstop the discrete state of end stop [-]
 * \param x         the displacement [m or rad]
 * \param v         the velocity [m/s or rad/s]
 * \param m         the mass [kg or kgm2]
 * \param xmin         the lower displacement limit [m or rad]
 * \param xmax         the upper displacement limit [m or rad]
 * \param cstop     the spring coefficient at displacement limit [N/m or Nm/rad]
 * \param dstop     the damping coefficient at displacement limit [N/(m/s) or Nm/(rad/s)]
 * \param kimpact     the coefficient of restitution [-]
 * \retval Fstop     the end stop force [N or Nm]
 * \retval Pdstop     the end stop losses [W]
 */

/****************************************************************/
void mermass11mseref_log_calcEndStopForceAndLossesContinuous(
             double& Fstop,
             double& Pdstop,
             const double DSendstop,
             const double x,
             const double v,
             const double m,
             const double xmin,
             const double xmax,
             const double cstop,
             const double dstop,
             const double kimpact) {

    if (DSendstop == UpperLimit) // Upper limit is reached
    {
        Fstop = -cstop*(x-xmax)-dstop*v;
        Pdstop = dstop*v*v;
    } else if (DSendstop == LowerLimit) // Lower limit is reached
    {
        Fstop = -cstop*(x-xmin)-dstop*v;
        Pdstop = dstop*v*v;
    } else // DSendstop == InRange
    {
        Fstop = 0.0;
        Pdstop = 0.0;
    }
}

#ifdef __cplusplus
}
#endif


/*
  Enum type for use with following functions
     mermass11mseref_log_GetRealParam(),
     mermass11mseref_log_GetIntParam(),
     mermass11mseref_log_ParamIsDouble(),
     mermass11mseref_log_ParamGetNumElements()
*/
enum Params
{
    en_phiinit,         /* Initial angular displacement [deg] */
    en_J,             /* Inertia [kg m^2] */
    en_dvisc,         /* Viscous damping [Nm/(rev/min)] */
    en_frictionmode, /* 1: no friction; 2: stribeck + slip/Coulomb friction [-] */
    en_epsn,       /* Numerical parameter for friction treatment [rev/min] */
    en_tauinv,         /* Inverse of time constant for numerical damping at stiction [1/s] */
    en_TStick,         /* Torque at stick friction [Nm] */
    en_TCoulomb,     /* Torque at Coulomb friction [Nm] */
    en_nStri,     /* Stribeck rotational speed [rev/min] */
    en_endstopmode,     /* 1: no end stop; 2: elastic */
    en_phimin,         /* Lower angular displacement limit [deg] */
    en_phimax,         /* Upper angular displacement limit [deg] */
    en_cstop,         /* Spring coefficient at displacement limit [Nm/deg] */
    en_kimpact,         /* Coefficient of restitution [-] */
};


/* Function: mdlProcessParameters =============================================
 * Abstract:
 *    Validate our coupled parameters to verify the conditions on them are realized.
 *  (called in mdlStart at the beginning of the simulation)
 */
#define MDL_PROCESS_PARAMETERS
#if defined(MDL_PROCESS_PARAMETERS)
/* COUPLED PARAMETERS */
static void mdlProcessParameters(SimStruct *S)
{
    /* declaring parameters as local variables */
    real_T phiinit  = mermass11mseref_log_GetRealParam(S, en_phiinit);
    real_T phimin   = mermass11mseref_log_GetRealParam(S, en_phimin);
    real_T phimax   = mermass11mseref_log_GetRealParam(S, en_phimax);
    real_T TStick   = mermass11mseref_log_GetRealParam(S, en_TStick);
    real_T TCoulomb = mermass11mseref_log_GetRealParam(S, en_TCoulomb);
    real_T cstop    = mermass11mseref_log_GetRealParam(S, en_cstop);
    int_T  endstopmode = mermass11mseref_log_GetIntParam(S, en_endstopmode);

    /* checking phimin < phimax */
    if (phimin>=phimax) {
        ssSetErrorStatus(S,"ERROR: Parameter 'phimin' must be smaller than 'phimax'");        
    }

    /* checking phiinit > phimin and phiinit < phimax */
    if (endstopmode == 2) // With the elastic end stop mode, a warning message is displayed
        // when the conditions are not realized
    {
        if ((phiinit < phimin) || (phiinit > phimax)) {
            ssPrintf("WARNING: Parameter 'phiinit' %f outside boundaries [phimin;phimax] \n", phiinit);
        }
    }

    /* checking TCoulomb [0;TStick] */
    if (!((TCoulomb >= 0.0) && (TCoulomb <= TStick))) {
        ssPrintf("ERROR: Parameter 'TCoulomb' %f outside boundaries [0;TStick] \n", TCoulomb);
        ssSetErrorStatus(S,"ERROR: Parameter 'TCoulomb' outside boundaries [0;TStick], see command window for more information");        
    }

    /* checking parameter cstop >= 1e9 */
    if (cstop >= 1.0e9) {
        ssPrintf("WARNING: Parameter 'cstop' %f greater than 1e9  \n", cstop);
    }

    return;
}
#endif /* MDL_PROCESS_PARAMETERS */

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
    real_T J         = mermass11mseref_log_GetRealParam(S, en_J);
    real_T dvisc     = mermass11mseref_log_GetRealParam(S, en_dvisc);
    real_T epsn  = mermass11mseref_log_GetRealParam(S, en_epsn);
    real_T tauinv    = mermass11mseref_log_GetRealParam(S, en_tauinv);
    real_T TStick    = mermass11mseref_log_GetRealParam(S, en_TStick);
    real_T TCoulomb  = mermass11mseref_log_GetRealParam(S, en_TCoulomb);
    real_T nStri = mermass11mseref_log_GetRealParam(S, en_nStri);
    real_T phimin    = mermass11mseref_log_GetRealParam(S, en_phimin);
    real_T phimax    = mermass11mseref_log_GetRealParam(S, en_phimax);
    real_T cstop     = mermass11mseref_log_GetRealParam(S, en_cstop);
    real_T kimpact   = mermass11mseref_log_GetRealParam(S, en_kimpact);

    int_T frictionmode = mermass11mseref_log_GetIntParam(S, en_frictionmode);
    int_T endstopmode  = mermass11mseref_log_GetIntParam(S, en_endstopmode);

    /* checking parameter J [1e-8;1e9] */
    if (!((J >= 1.0e-8) && (J <= 1.0e9))) {
        ssPrintf("ERROR: Parameter 'J' %f outside boundaries [1e-8;1e9] \n", J);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'J', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_J) || mermass11mseref_log_ParamGetNumElements(S, en_J) != 1) {
        ssPrintf("ERROR: Parameter 'J' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'J', see command window for more information");
    }

    /* checking parameter dvisc [0;1e6] */
    if (!((dvisc >= 0.0) && (dvisc <= 1.0e6))) {
        ssPrintf("ERROR: Parameter 'dvisc' %f outside boundaries [0;1e6] \n", dvisc);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'dvisc', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_dvisc) || mermass11mseref_log_ParamGetNumElements(S, en_dvisc) != 1) {
        ssPrintf("ERROR: Parameter 'dvisc' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'dvisc', see command window for more information");
    }

    /* checking parameter frictionmode [1;2] */
    if (!((frictionmode >= 1) && (frictionmode <= 2))) {
        ssPrintf("ERROR: Parameter 'frictionmode' %d outside boundaries [1;2] \n", frictionmode);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'frictionmode', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_frictionmode) || mermass11mseref_log_ParamGetNumElements(S, en_frictionmode) != 1 || (mermass11mseref_log_GetRealParam(S, en_frictionmode) != mermass11mseref_log_GetIntParam(S, en_frictionmode))) {
        ssPrintf("ERROR: Parameter 'frictionmode' must be a scalar integer \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'frictionmode', see command window for more information");
    }

    /* checking parameter epsn [1e-11;1e4] */
    if (!((epsn >= 1.0e-11) && (epsn <= 1.0e4))) {
        ssPrintf("ERROR: Parameter 'epsn' %f outside boundaries [1e-11;1e4] \n", epsn);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'epsn', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_epsn) || mermass11mseref_log_ParamGetNumElements(S, en_epsn) != 1) {
        ssPrintf("ERROR: Parameter 'epsn' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'epsn', see command window for more information");
    }

    /* checking parameter tauinv [0;1e6] */
    if (!((tauinv >= 0.0) && (tauinv <= 1.0e6))) {
        ssPrintf("ERROR: Parameter 'tauinv' %f outside boundaries [0;1e6] \n", tauinv);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'tauinv', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_tauinv) || mermass11mseref_log_ParamGetNumElements(S, en_tauinv) != 1) {
        ssPrintf("ERROR: Parameter 'tauinv' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'tauinv', see command window for more information");
    }

    /* checking parameter TStick [1e-6;1e6] */
    if (!((TStick >= 1.0e-6) && (TStick <= 1.0e6))) {
        ssPrintf("ERROR: Parameter 'TStick' %f outside boundaries [1e-6;1e6] \n", TStick);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'TStick', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_TStick) || mermass11mseref_log_ParamGetNumElements(S, en_TStick) != 1) {
        ssPrintf("ERROR: Parameter 'TStick' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'TStick', see command window for more information");
    }

    /* checking parameter TCoulomb [0;1e6] */
    if (!((TCoulomb >= 0.0) && (TCoulomb <= 1.0e6))) {
        ssPrintf("ERROR: Parameter 'TCoulomb' %f outside boundaries [0;1e6] \n", TCoulomb);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'TCoulomb', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_TCoulomb) || mermass11mseref_log_ParamGetNumElements(S, en_TCoulomb) != 1) {
        ssPrintf("ERROR: Parameter 'TCoulomb' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'TCoulomb', see command window for more information");
    }

    /* checking parameter nStri [1e-8;1e3] */
    if (!((nStri >= 1.0e-8) && (nStri <= 1.0e3))) {
        ssPrintf("ERROR: Parameter 'nStri' %f outside boundaries [1e-8;1e3] \n", nStri);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'nStri', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_nStri) || mermass11mseref_log_ParamGetNumElements(S, en_nStri) != 1) {
        ssPrintf("ERROR: Parameter 'nStri' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'nStri', see command window for more information");
    }

    /* checking parameter endstopmode [1;2] */
    if (!((endstopmode >= 1) && (endstopmode <= 2))) {
        ssPrintf("ERROR: Parameter 'endstopmode' %d outside boundaries [1;2] \n", endstopmode);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'endstopmode', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_endstopmode) || mermass11mseref_log_ParamGetNumElements(S, en_endstopmode) != 1 || (mermass11mseref_log_GetRealParam(S, en_endstopmode) != mermass11mseref_log_GetIntParam(S, en_endstopmode))) {
        ssPrintf("ERROR: Parameter 'endstopmode' must be a scalar integer \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'endstopmode', see command window for more information");
    }

    /* checking parameter phimin [-1e6;1e6] */
    if (!((phimin >= -1.0e6) && (phimin <= 1.0e6))) {
        ssPrintf("ERROR: Parameter 'phimin' %f outside boundaries [-1e6;1e6] \n", phimin);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'phimin', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_phimin) || mermass11mseref_log_ParamGetNumElements(S, en_phimin) != 1) {
        ssPrintf("ERROR: Parameter 'phimin' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'phimin', see command window for more information");
    }

    /* checking parameter phimax [-1e6;1e6] */
    if (!((phimax >= -1.0e6) && (phimax <= 1.0e6))) {
        ssPrintf("ERROR: Parameter 'phimax' %f outside boundaries [-1e6;1e6] \n", phimax);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'phimax', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_phimax) || mermass11mseref_log_ParamGetNumElements(S, en_phimax) != 1) {
        ssPrintf("ERROR: Parameter 'phimax' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'phimax', see command window for more information");
    }

    /* checking parameter cstop [0;1e12] */
    if (!((cstop >= 0.0) && (cstop <= 1.0e12))) {
        ssPrintf("ERROR: Parameter 'cstop' %f outside boundaries [0;1e12] \n", cstop);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'cstop', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_cstop) || mermass11mseref_log_ParamGetNumElements(S, en_cstop) != 1) {
        ssPrintf("ERROR: Parameter 'cstop' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'cstop', see command window for more information");
    }

    /* checking parameter kimpact [0;1] */
    if (!((kimpact >= 0.0) && (kimpact <= 1.0))) {
        ssPrintf("ERROR: Parameter 'kimpact' %f outside boundaries [0;1] \n", kimpact);
        ssSetErrorStatus(S,"ERROR: Wrong parameter value for 'kimpact', see command window for more information");
    }
    if (!mermass11mseref_log_ParamIsDouble(S, en_kimpact) || mermass11mseref_log_ParamGetNumElements(S, en_kimpact) != 1) {
        ssPrintf("ERROR: Parameter 'kimpact' must be a scalar double \n");
        ssSetErrorStatus(S,"ERROR: Wrong parameter definition for 'kimpact', see command window for more information");
    }

    return;
}
#endif /* MDL_CHECK_PARAMETERS */


#define MDL_START   /* Change to #undef to remove function */
#if defined(MDL_START)
static void mdlStart(SimStruct *S)
/*mdlStart is called at the beginning of the simulation*/
{
    /* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%START) */
    mdlProcessParameters(S);
    if (ssGetErrorStatus(S) != NULL) return;
    /* }}}}}}}}}}}}}}} END OF YOUR CODE (%%START) */

}
#endif /* MDL_START */


/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* set number of parameters */
    /* parameters: phiinit J dvisc frictionmode epsn tauinv TStick TCoulomb nStri endstopmode phimin phimax cstop kimpact */
    ssSetNumSFcnParams(S,14);
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) return;
    } else {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    /* Continuous states: */
    ssSetNumContStates(S, 0);
    /* Discrete states:  */
    ssSetNumDiscStates(S, 0);

    if (!ssSetNumInputPorts(S, 3)) return;

    /* Input: Text */
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    /* Input: phi */
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  1, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    /* Input: nRPM */
    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortDataType(S, 2, SS_DOUBLE);
    ssSetInputPortComplexSignal(S,  2, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 2, 1);

    if (!ssSetNumOutputPorts(S, 5)) return;

    /* Output: Tfr */
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S,  0, COMPLEX_NO);

    /* Output: Tstop */
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S,  1, COMPLEX_NO);

    /* Output: Pd */
    ssSetOutputPortWidth(S, 2, 1);
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S,  2, COMPLEX_NO);

    /* Output: DSfrOut */
    ssSetOutputPortWidth(S, 3, 1);
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S,  3, COMPLEX_NO);

    /* Output: DSendstopOut */
    ssSetOutputPortWidth(S, 4, 1);
    ssSetOutputPortDataType(S, 4, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S,  4, COMPLEX_NO);

    ssSetNumSampleTimes(S, 1); /* multiple sample times are not supported by the s-fn generator */

/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITSIZES) */
    int_T endstopmode = mermass11mseref_log_GetIntParam(S, en_endstopmode);

    ssSetNumModes(S, 2);  // Mode vector has two elements: DSfr & DSendstop
    ssSetNumNonsampledZCs(S, 4); // 4 zero crossing variables (2 for DSfr & 2 for DSendstop)

    ssSetNumRWork(S, 2); // dstop, omega_major

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
#ifdef  MDL_INITIALIZE_CONDITIONS
static void mdlInitializeConditions(SimStruct *S)
{
    /* declaring parameters as local variables */
    real_T J         = mermass11mseref_log_GetRealParam(S, en_J);
    real_T dvisc     = mermass11mseref_log_GetRealParam(S, en_dvisc);
    real_T epsn  = mermass11mseref_log_GetRealParam(S, en_epsn);
    real_T nStri = mermass11mseref_log_GetRealParam(S, en_nStri);
    real_T phimin    = mermass11mseref_log_GetRealParam(S, en_phimin);
    real_T phimax    = mermass11mseref_log_GetRealParam(S, en_phimax);
    real_T cstop     = mermass11mseref_log_GetRealParam(S, en_cstop);
    real_T kimpact   = mermass11mseref_log_GetRealParam(S, en_kimpact);
    int_T frictionmode = mermass11mseref_log_GetIntParam(S, en_frictionmode);
    int_T endstopmode  = mermass11mseref_log_GetIntParam(S, en_endstopmode);

    /* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%INITIALIZECONDITIONS) */

    /* declaring spring coefficient at displacement limit with SI-unit */
    real_T cstopphi;
    
    // Unit Conversion: cstopphi = 180/PI * cstop
    cstopphi = 180.0/M_PI*cstop;

    /* declaring mode vector as local variable */
    int_T *Mode = ssGetModeVector(S);
    int_T& DSfr      = Mode[0];
    int_T& DSendstop = Mode[1];


    /* DSfr initialization */
    if (frictionmode == 1) { // 1: no friction
        DSfr = DSfrDisabled; /* DSfr is not used */
    }
    else {               // 2: stribeck + slip/Coulomb friction
        DSfr = DSfrInitialState; /* Initially unlocked */
    }


    /* declaring internal work variable */
    real_T* adRWork = ssGetRWork(S);
    real_T& dstop = adRWork[0];
    real_T& omega_major =     adRWork[1]; 

    /* DSendstop initialization */
    if (endstopmode==1) {    // 1: no end stop
        DSendstop = DSendstopDisabled; /* DSendstop is not used */
        dstop=0.0;
    }
    else                    // endstopmode=2: elastic
    {
        DSendstop = DSendstopInitialState; /* Initially unlocked */
        /* Calculating dstop only one time */
        dstop = mermass11mseref_log_calcEndStopDampingCoefficientContinuous(J, cstopphi, kimpact);
    }
    omega_major=0.;

    /* }}}}}}}}}}}}}}} END OF YOUR CODE (%%INITIALIZECONDITIONS) */
}
#endif

#undef MDL_DERIVATIVES

#undef MDL_UPDATE


/* Function: mdlOutputs =======================================================
 *
*/

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /* declaring parameters as local variables */
    real_T J = mermass11mseref_log_GetRealParam(S, en_J);
    real_T dvisc = mermass11mseref_log_GetRealParam(S, en_dvisc);
    int_T frictionmode = mermass11mseref_log_GetIntParam(S, en_frictionmode);
    real_T epsn = mermass11mseref_log_GetRealParam(S, en_epsn);
    real_T tauinv = mermass11mseref_log_GetRealParam(S, en_tauinv);
    real_T TStick = mermass11mseref_log_GetRealParam(S, en_TStick);
    real_T TCoulomb = mermass11mseref_log_GetRealParam(S, en_TCoulomb);
    real_T nStri = mermass11mseref_log_GetRealParam(S, en_nStri);
    int_T endstopmode = mermass11mseref_log_GetIntParam(S, en_endstopmode);
    real_T phimin = mermass11mseref_log_GetRealParam(S, en_phimin);
    real_T phimax = mermass11mseref_log_GetRealParam(S, en_phimax);
    real_T cstop = mermass11mseref_log_GetRealParam(S, en_cstop);
    real_T kimpact = mermass11mseref_log_GetRealParam(S, en_kimpact);

    /* declaring output variables */
    real_T *output0 = (real_T *)ssGetOutputPortSignal(S, 0);
    real_T& Tfr = output0[0];
    real_T *output1 = (real_T *)ssGetOutputPortSignal(S, 1);
    real_T& Tstop = output1[0];
    real_T *output2 = (real_T *)ssGetOutputPortSignal(S, 2);
    real_T& Pd = output2[0];
    real_T *output3 = (real_T *)ssGetOutputPortSignal(S, 3);
    real_T& DSfrOut = output3[0];
    real_T *output4 = (real_T *)ssGetOutputPortSignal(S, 4);
    real_T& DSendstopOut = output4[0];

    /* declaring inputs as local variables */
    real_T Text = *ssGetInputPortRealSignalPtrs(S, 0)[0];
    real_T phi = *ssGetInputPortRealSignalPtrs(S, 1)[0];
    real_T nRPM = *ssGetInputPortRealSignalPtrs(S, 2)[0];

    /*
        Tfr = ???
        Tstop = ???
        Pd = ???
        DSfrOut = ???
        DSendstopOut = ???

    */
/* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%OUTPUTS) */
    /* declaring viscous damping with SI-unit */
    real_T dviscomega;

    // Unit Conversion: dviscomega = 30/PI * dvisc
    dviscomega = 30.0/M_PI * dvisc;

    /* declaring spring coefficient at displacement limit with SI-unit */
    real_T cstopphi;

    // Unit Conversion: cstopphi = 180/PI * cstop
    cstopphi = 180.0/M_PI*cstop;

    /* conversion to SI units */
    real_T omegaeps, omegaStri, omega;

    mermass11mseref_log_convParamUnits2SI(epsn, omegaeps, nStri, omegaStri, phimin, phimax);

    mermass11mseref_log_convInputUnits2SI(phi, nRPM, omega);

    /* declaring mode vector as local variable */
    int_T  *Mode = ssGetModeVector(S);
    int_T& DSfr = Mode[0];
    int_T& DSendstop = Mode[1];

    real_T Pdstop; // Losses of the end stop model
    real_T Pdfr;   // Losses of the friction model

    /* declaring internal work variables */
    real_T* adRWork = ssGetRWork(S);
    real_T& dstop = adRWork[0];

    // Updating DSendstop, calculating then Tstop and Pdstop
    if (endstopmode == 1) // 1: no end stop
    {
        DSendstop = DSendstopDisabled;
        Tstop = 0.0;
        Pdstop = 0.0;
    }
    else // 2: elastic
    {

        /* declaring temporary variable */
        EndStopState tempstate = InRange;

        if (ssIsMajorTimeStep(S))
        {
            tempstate = (EndStopState)mermass11mseref_log_calcNewEndStopStateContinuous(phi, phimin, phimax);

            if (tempstate != (EndStopState)DSendstop)
            {
                DSendstop = tempstate;
                // Reset Solver, because a change of end-stop mode is a change
                // in the dynamics of the corresponding mass
                // The Simulink-Documentation gives the following recommendation:
                // "An S-function should invoke this macro whenever changes occur in the dynamics
                // of the S-function, e.g., a discontinuity in a state or output, that might
                // invalidate the solver's step-size computations."
                ssSetSolverNeedsReset(S);
            }
        }
        mermass11mseref_log_calcEndStopForceAndLossesContinuous(Tstop, Pdstop, DSendstop,
                phi, omega, J, phimin, phimax, cstopphi, dstop, kimpact);
    }

    real_T& omega_major =     adRWork[1]; 

    // Updating DSfr, calculating then Tfr and Pdfr
    // If the elastic end-stop mode is chosen, the viscous force and losses are not always considered
    if (frictionmode == 1) // 1: no friction
    {
        DSfr = DSfrDisabled;
        if (endstopmode == 1) // 1: no end stop
        {
            Tfr = -dviscomega*omega;
            Pdfr = dviscomega*omega*omega;
        }
        else
        {
            if (DSendstop == InRange)
            {
                Tfr = -dviscomega*omega;
                Pdfr = dviscomega*omega*omega;
            }
            else
            {
                Tfr = 0.0;
                Pdfr = 0.0;
            }
        }
    }
    else // stick slip friction
    {
        /* declaring temporary variable */
        FrictionState tempstate = Stick;

        if (ssIsMajorTimeStep(S))
        {
                        
            // store angularvelocity at major timestep for reset to stiction with fixed-step-solver
            omega_major=omega;

            tempstate = (FrictionState)mermass11mseref_log_calcNewFrictionState(DSfr, Text+Tstop, TStick, TStick, omega, omegaeps);
            if (tempstate != (FrictionState)DSfr)
            {
                DSfr = tempstate;
                // Reset Solver, because a change of friction mode is a change
                // in the dynamics of the corresponding mass
                // The Simulink-Documentation gives the following recommendation:
                // "An S-function should invoke this macro whenever changes occur in the dynamics
                // of the S-function, e.g., a discontinuity in a state or output, that might
                // invalidate the solver's step-size computations."
                ssSetSolverNeedsReset(S);
            }
        }

        if (endstopmode == 1) // 1: no end stop
        {
            mermass11mseref_log_calcFrictionForceAndLosses(Tfr, Pdfr, DSfr, Text, Tstop,
                    omega, J, dviscomega, tauinv, TStick, TCoulomb, omegaStri);
        }
        else
        {
            if (DSendstop == InRange)
            {
                mermass11mseref_log_calcFrictionForceAndLosses(Tfr, Pdfr, DSfr, Text, Tstop,
                        omega, J, dviscomega, tauinv, TStick, TCoulomb, omegaStri);
            }
            else
            {
                mermass11mseref_log_calcFrictionForceAndLosses(Tfr, Pdfr, DSfr, Text, Tstop,
                        omega, J, 0.0, tauinv, TStick, TCoulomb, omegaStri);
            }
        }

        // for fixed step solver re-calculate the friction state with the extrapolated velocity 
        // value at the thend of the major timestep
        if (  (!ssIsVariableStepSolver(S)) && (ssIsMajorTimeStep(S)) && (DSfr!=0) && (fabs(omega)< omegaeps) ) 
        {
            real_T omega_extrapol; //extrapolated velocity
            omega_extrapol=omega + ssGetFixedStepSize(S)*(Text+Tstop+Tfr)/J;

            tempstate=(FrictionState)mermass11mseref_log_calcNewFrictionState(DSfr, Text+Tstop, TStick, TStick, omega_extrapol, omegaeps);
            DSfr = tempstate;
        }


    }

    // checking here condition: |Text + Tfr| << cstopphi
    if (endstopmode == 2) // 2: elastic
    {
        if (ssIsMajorTimeStep(S))
        {
            if (DSendstop == UpperLimit)         // Upper limit is reached
            {
                if (fabs(Text + Tfr) >= 10.0*cstopphi) {
                    #if defined(SS_STDIO_AVAILABLE)                    
                        ssPrintf("WARNING: Condition |Text + Tfr| << cstopphi not fulfilled  \n");
                    #endif                    
                }
            }
            else if (DSendstop == LowerLimit)     // Lower limit is reached
            {
                if (fabs(Text + Tfr) >= 10.0*cstopphi) {
                    #if defined(SS_STDIO_AVAILABLE)
                        ssPrintf("WARNING: Condition |Text + Tfr| << cstopphi not fulfilled  \n");
                    #endif
                }
            }
        }
    }

    Pd = Pdfr + Pdstop;
     DSfrOut = DSfr;
    DSendstopOut = DSendstop;

    // for fixed-step solvers in Stick mode: calculate an artificial Friciton, so that v=0 is reached within one major timestep
    if ( (DSfr==0) && ( !ssIsVariableStepSolver(S)) )
     {
         real_T T_artificial =J*omega_major/ssGetFixedStepSize(S);
         Tfr= -Text -Tstop -T_artificial;
         Pd=fabs(T_artificial*omega);
     }


/* }}}}}}}}}}}}}}} END OF YOUR CODE (%%OUTPUTS) */
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
    /* declaring zero crossing variables as local variables */
    real_T *zcSignals = ssGetNonsampledZCs(S);
    real_T& ZC0       = zcSignals[0];
    real_T& ZC1       = zcSignals[1];
    real_T& ZC2       = zcSignals[2];
    real_T& ZC3       = zcSignals[3];

    /* declaring parameters as local variables */
    real_T dvisc = mermass11mseref_log_GetRealParam(S, en_dvisc);
    int_T frictionmode = mermass11mseref_log_GetIntParam(S, en_frictionmode);
    real_T TStick = mermass11mseref_log_GetRealParam(S, en_TStick);
    real_T epsn = mermass11mseref_log_GetRealParam(S, en_epsn);
    real_T nStri = mermass11mseref_log_GetRealParam(S, en_nStri);
    int_T endstopmode = mermass11mseref_log_GetIntParam(S, en_endstopmode);
    real_T J = mermass11mseref_log_GetRealParam(S, en_J);
    real_T phimin = mermass11mseref_log_GetRealParam(S, en_phimin);
    real_T phimax = mermass11mseref_log_GetRealParam(S, en_phimax);
    real_T cstop = mermass11mseref_log_GetRealParam(S, en_cstop);
    real_T kimpact = mermass11mseref_log_GetRealParam(S, en_kimpact);

    /* declaring inputs as local variables */
    real_T Text = *ssGetInputPortRealSignalPtrs(S, 0)[0];
    real_T phi = *ssGetInputPortRealSignalPtrs(S, 1)[0];
    real_T nRPM = *ssGetInputPortRealSignalPtrs(S, 2)[0];

    /* {{{{{{{{{{{{{{{ YOUR CODE HERE (%%ZEROCROSSINGS) */

    /* declaring spring coefficient at displacement limit with SI-unit */
    real_T cstopphi;

    // Unit Conversion: cstopphi = 180/PI * cstop
    cstopphi = 180.0/M_PI*cstop;

    /* conversion to SI units */
    real_T omegaeps, omegaStri, omega;

    mermass11mseref_log_convParamUnits2SI(epsn, omegaeps, nStri, omegaStri, phimin, phimax);

    mermass11mseref_log_convInputUnits2SI(phi, nRPM, omega);

    /* declaring mode variables as local variables */
    int_T  *Mode = ssGetModeVector(S);
    int_T& DSfr      = Mode[0];
    int_T& DSendstop = Mode[1];

    /* In the following if-block, two zero-crossing variables ZC2 and ZC3 are computed,
     * along with Tstop for the state machine (friction handling).
     * ZC2 & ZC3 represent the transitions of the state machine for the end-stop handling phenomenon,
     * and are related to the variable DSendstop of the mode vector*/

    real_T Tstop;
    real_T PdstopUnused;     // Unused losses (output of the function calcEndStopForceAndLossesElastic)

    if (endstopmode == 1) // 1: no end stop
    {
        ZC2 = DSendstopDisabled;
        ZC3 = DSendstopDisabled;
        Tstop = 0;
    }
    else                     // endstopmode=2: elastic
    {
        /* declaring internal work variables */
        real_T* adRWork = ssGetRWork(S);
        real_T& dstop = adRWork[0];

        ZC2 = phi - phimax;
        ZC3 = phi - phimin;

        /* Computing Tstop again for the state machine */
        mermass11mseref_log_calcEndStopForceAndLossesContinuous(Tstop, PdstopUnused, DSendstop,
                phi, omega, J, phimin, phimax, cstopphi, dstop, kimpact);
    }// endif (endstopmode == 1)


    /* Calculating values for zero-crossing variables ZC0 and ZC1.
     * They represent the transitions of the state machine for the combined friction and end-stop handling,
     * and are related to the variable DSfr of the mode vector*/
    mermass11mseref_log_calcZeroCrossingFcnForFrictionHandling(ZC0, ZC1, DSfr, Text+Tstop, omega, frictionmode, TStick, TStick, omegaeps);

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

