/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller0.h
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

#ifndef RTW_HEADER_Controller0_h_
#define RTW_HEADER_Controller0_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef Controller0_COMMON_INCLUDES_
#define Controller0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Controller0_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Controller0_T RT_MODEL_Controller0_T;

/* Block signals (default storage) */
typedef struct {
  real32_T objectDetc;                 /* '<Root>/Echo_numbers1' */
  real32_T distance;                   /* '<Root>/Echo_numbers1' */
  real32_T numbers;                    /* '<Root>/Echo_numbers1' */
} B_Controller0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<Root>/Create_pulses' */
  uint16_T temporalCounter_i1_f;       /* '<Root>/Create_trigger' */
  uint8_T is_active_c5_Controller0;    /* '<Root>/Echo_numbers1' */
  uint8_T is_c5_Controller0;           /* '<Root>/Echo_numbers1' */
  uint8_T is_active_c1_Controller0;    /* '<Root>/Create_trigger' */
  uint8_T is_c1_Controller0;           /* '<Root>/Create_trigger' */
  uint8_T is_active_c2_Controller0;    /* '<Root>/Create_pulses' */
  uint8_T is_c2_Controller0;           /* '<Root>/Create_pulses' */
} DW_Controller0_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Multiply;               /* '<Root>/Multiply' */
} ConstB_Controller0_T;

/* Real-time Model Data Structure */
struct tag_RTM_Controller0_T {
  const char_T * volatile errorStatus;
  B_Controller0_T *blockIO;
  DW_Controller0_T *dwork;
};

extern const ConstB_Controller0_T Controller0_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Controller0_initialize(RT_MODEL_Controller0_T *const Controller0_M,
  real32_T *Controller0_U_echo, real32_T *Controller0_Y_trigger, real32_T
  *Controller0_Y_pulse);
extern void Controller0_step(RT_MODEL_Controller0_T *const Controller0_M,
  real32_T Controller0_U_echo, real32_T *Controller0_Y_trigger, real32_T
  *Controller0_Y_pulse);
extern void Controller0_terminate(RT_MODEL_Controller0_T *const Controller0_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/dealedDistanceDis' : Unused code path elimination
 * Block '<Root>/distanceDis' : Unused code path elimination
 * Block '<Root>/numbersDis' : Unused code path elimination
 * Block '<Root>/rawDistanceDis' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Controller0'
 * '<S1>'   : 'Controller0/Create_pulses'
 * '<S2>'   : 'Controller0/Create_trigger'
 * '<S3>'   : 'Controller0/Echo_numbers1'
 */
#endif                                 /* RTW_HEADER_Controller0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
