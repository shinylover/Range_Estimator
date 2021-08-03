/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Controller0'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jun 25 17:50:38 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller0.h"
#include "rtwtypes.h"

static RT_MODEL_Controller0_T Controller0_M_;
static RT_MODEL_Controller0_T *const Controller0_MPtr = &Controller0_M_;/* Real-time model */
static B_Controller0_T Controller0_B;  /* Observable signals */
static DW_Controller0_T Controller0_DW;/* Observable states */

/* '<Root>/echo' */
static real32_T Controller0_U_echo;

/* '<Root>/trigger' */
static real32_T Controller0_Y_trigger;

/* '<Root>/pulse' */
static real32_T Controller0_Y_pulse;
volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  Controller0_step(Controller0_M, Controller0_U_echo, &Controller0_Y_trigger,
                   &Controller0_Y_pulse);

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 1.0E-6;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(Controller0_M, 0);
  Controller0_initialize(Controller0_M, &Controller0_U_echo,
    &Controller0_Y_trigger, &Controller0_Y_pulse);
  cli();
  configureArduinoAVRTimer();
  runModel =
    rtmGetErrorStatus(Controller0_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(Controller0_M) == (NULL));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Controller0_terminate(Controller0_M);
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
