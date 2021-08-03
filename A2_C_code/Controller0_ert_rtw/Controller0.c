/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller0.c
 *
 * Code generated for Simulink model 'Controller0'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jun 25 23:14:00 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller0.h"

/* Named constants for Chart: '<Root>/Create_pulses' */
#define Controller0_IN_Medile          ((uint8_T)1U)
#define Controller0_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Controller0_IN_SignalOne       ((uint8_T)2U)
#define Controller0_IN_SignalZero      ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Create_trigger' */
#define Controller0_IN_TriggerOff      ((uint8_T)1U)
#define Controller0_IN_TriggerOn       ((uint8_T)2U)

/* Named constants for Chart: '<Root>/Echo_numbers1' */
#define Controller0_IN_CountNums       ((uint8_T)1U)
#define Controller0_IN_Init            ((uint8_T)2U)
#define Controller0_IN_Stop            ((uint8_T)3U)
#define Controller0_IN_Wait            ((uint8_T)4U)
#define NumBitsPerChar                 8U

/* Invariant block signals (default storage) */
const ConstB_Controller0_T Controller0_ConstB = {
  232.0                                /* '<Root>/Multiply' */
};

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/* Model step function */
void Controller0_step(RT_MODEL_Controller0_T *const Controller0_M, real32_T
                      Controller0_U_echo, real32_T *Controller0_Y_trigger,
                      real32_T *Controller0_Y_pulse)
{
  B_Controller0_T *Controller0_B = Controller0_M->blockIO;
  DW_Controller0_T *Controller0_DW = Controller0_M->dwork;
  int32_T tmp;
  real32_T u;
  real32_T v;
  int16_T rtb_Gain;
  boolean_T guard1 = false;

  /* Chart: '<Root>/Create_trigger' */
  if (Controller0_DW->temporalCounter_i1_f < 65535U) {
    Controller0_DW->temporalCounter_i1_f++;
  }

  if (Controller0_DW->is_active_c1_Controller0 == 0U) {
    Controller0_DW->is_active_c1_Controller0 = 1U;
    Controller0_DW->is_c1_Controller0 = Controller0_IN_TriggerOff;
    Controller0_DW->temporalCounter_i1_f = 0U;

    /* Outport: '<Root>/trigger' */
    *Controller0_Y_trigger = 0.0F;
  } else if (Controller0_DW->is_c1_Controller0 == 1) {
    /* Outport: '<Root>/trigger' */
    *Controller0_Y_trigger = 0.0F;
    if (Controller0_DW->temporalCounter_i1_f >= 60000U) {
      Controller0_DW->is_c1_Controller0 = Controller0_IN_TriggerOn;
      Controller0_DW->temporalCounter_i1_f = 0U;

      /* Outport: '<Root>/trigger' */
      *Controller0_Y_trigger = 1.0F;
    }
  } else {
    /* Outport: '<Root>/trigger' */
    /* case IN_TriggerOn: */
    *Controller0_Y_trigger = 1.0F;
    if (Controller0_DW->temporalCounter_i1_f >= 20U) {
      Controller0_DW->is_c1_Controller0 = Controller0_IN_TriggerOff;
      Controller0_DW->temporalCounter_i1_f = 0U;

      /* Outport: '<Root>/trigger' */
      *Controller0_Y_trigger = 0.0F;
    }
  }

  /* End of Chart: '<Root>/Create_trigger' */

  /* Chart: '<Root>/Echo_numbers1' incorporates:
   *  Inport: '<Root>/echo'
   */
  if (Controller0_DW->is_active_c5_Controller0 == 0U) {
    Controller0_DW->is_active_c5_Controller0 = 1U;
    Controller0_DW->is_c5_Controller0 = Controller0_IN_Init;
    Controller0_B->objectDetc = 0.0F;
    Controller0_B->distance = 0.0F;
    Controller0_B->numbers = 0.0F;
  } else {
    switch (Controller0_DW->is_c5_Controller0) {
     case Controller0_IN_CountNums:
      if (Controller0_U_echo == 0.0F) {
        Controller0_DW->is_c5_Controller0 = Controller0_IN_Stop;
        Controller0_B->objectDetc = 1.0F;
        Controller0_B->numbers++;
      } else {
        Controller0_B->distance++;
      }
      break;

     case Controller0_IN_Init:
      Controller0_B->objectDetc = 0.0F;
      Controller0_DW->is_c5_Controller0 = Controller0_IN_Wait;
      break;

     case Controller0_IN_Stop:
      Controller0_B->objectDetc = 1.0F;
      if (Controller0_B->numbers < 4.0F) {
        Controller0_DW->is_c5_Controller0 = Controller0_IN_Wait;
      }
      break;

     default:
      /* case IN_Wait: */
      if (Controller0_U_echo == 1.0F) {
        Controller0_DW->is_c5_Controller0 = Controller0_IN_CountNums;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Echo_numbers1' */

  /* Product: '<Root>/Divide' */
  u = (real32_T)(Controller0_B->distance / Controller0_ConstB.Multiply);
  v = (real32_T)fabs(u);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      u = (real32_T)floor(u + 0.5F);
    } else {
      u *= 0.0F;
    }
  }

  if (rtIsNaNF(u) || rtIsInfF(u)) {
    u = 0.0F;
  } else {
    u = (real32_T)fmod(u, 65536.0);
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Product: '<Root>/Divide'
   */
  rtb_Gain = (int16_T)(u < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-u :
                       (int32_T)(int16_T)(uint16_T)u);

  /* Chart: '<Root>/Create_pulses' */
  if (Controller0_DW->temporalCounter_i1 < MAX_uint32_T) {
    Controller0_DW->temporalCounter_i1++;
  }

  if (Controller0_DW->is_active_c2_Controller0 == 0U) {
    Controller0_DW->is_active_c2_Controller0 = 1U;
    Controller0_DW->is_c2_Controller0 = Controller0_IN_Medile;
    Controller0_DW->temporalCounter_i1 = 0U;
  } else {
    guard1 = false;
    switch (Controller0_DW->is_c2_Controller0) {
     case Controller0_IN_Medile:
      if ((Controller0_B->numbers >= 4.0F) ||
          (Controller0_DW->temporalCounter_i1 >= 500000U)) {
        Controller0_DW->is_c2_Controller0 = Controller0_IN_SignalOne;
        Controller0_DW->temporalCounter_i1 = 0U;

        /* Outport: '<Root>/pulse' */
        *Controller0_Y_pulse = 1.0F;
      }
      break;

     case Controller0_IN_SignalOne:
      /* Outport: '<Root>/pulse' */
      *Controller0_Y_pulse = 1.0F;
      if (((Controller0_B->objectDetc == 0.0F) &&
           (Controller0_DW->temporalCounter_i1 >= 500000U)) ||
          ((Controller0_B->objectDetc == 1.0F) && (((rtb_Gain >= 10) &&
             (rtb_Gain <= 100) && (Controller0_DW->temporalCounter_i1 >=
              (uint32_T)(rtb_Gain * 1000))) || (((rtb_Gain < 10) || (rtb_Gain >
               100)) && (Controller0_DW->temporalCounter_i1 >= 250000U))))) {
        Controller0_DW->is_c2_Controller0 = Controller0_IN_SignalZero;
        Controller0_DW->temporalCounter_i1 = 0U;

        /* Outport: '<Root>/pulse' */
        *Controller0_Y_pulse = 0.0F;
      }
      break;

     default:
      /* Outport: '<Root>/pulse' */
      /* case IN_SignalZero: */
      *Controller0_Y_pulse = 0.0F;
      if ((Controller0_B->objectDetc == 0.0F) &&
          (Controller0_DW->temporalCounter_i1 >= 500000U)) {
        guard1 = true;
      } else {
        if (Controller0_B->objectDetc == 1.0F) {
          if (((rtb_Gain < 10) || (rtb_Gain > 100)) &&
              (Controller0_DW->temporalCounter_i1 >= 250000U)) {
            guard1 = true;
          } else {
            tmp = 100 - rtb_Gain;
            if (100 - rtb_Gain > 32767) {
              tmp = 32767;
            }

            if ((rtb_Gain >= 10) && (rtb_Gain <= 100) &&
                (Controller0_DW->temporalCounter_i1 >= (uint32_T)(tmp * 1000)))
            {
              guard1 = true;
            }
          }
        }
      }
      break;
    }

    if (guard1) {
      Controller0_DW->is_c2_Controller0 = Controller0_IN_SignalOne;
      Controller0_DW->temporalCounter_i1 = 0U;

      /* Outport: '<Root>/pulse' */
      *Controller0_Y_pulse = 1.0F;
    }
  }

  /* End of Chart: '<Root>/Create_pulses' */
}

/* Model initialize function */
void Controller0_initialize(RT_MODEL_Controller0_T *const Controller0_M,
  real32_T *Controller0_U_echo, real32_T *Controller0_Y_trigger, real32_T
  *Controller0_Y_pulse)
{
  DW_Controller0_T *Controller0_DW = Controller0_M->dwork;
  B_Controller0_T *Controller0_B = Controller0_M->blockIO;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) Controller0_B), 0,
                sizeof(B_Controller0_T));

  /* states (dwork) */
  (void) memset((void *)Controller0_DW, 0,
                sizeof(DW_Controller0_T));

  /* external inputs */
  *Controller0_U_echo = 0.0F;

  /* external outputs */
  (*Controller0_Y_trigger) = 0.0F;
  (*Controller0_Y_pulse) = 0.0F;

  /* SystemInitialize for Chart: '<Root>/Create_trigger' */
  Controller0_DW->temporalCounter_i1_f = 0U;
  Controller0_DW->is_active_c1_Controller0 = 0U;
  Controller0_DW->is_c1_Controller0 = Controller0_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/Echo_numbers1' */
  Controller0_DW->is_active_c5_Controller0 = 0U;
  Controller0_DW->is_c5_Controller0 = Controller0_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/Create_pulses' */
  Controller0_DW->temporalCounter_i1 = 0U;
  Controller0_DW->is_active_c2_Controller0 = 0U;
  Controller0_DW->is_c2_Controller0 = Controller0_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void Controller0_terminate(RT_MODEL_Controller0_T *const Controller0_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(Controller0_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
