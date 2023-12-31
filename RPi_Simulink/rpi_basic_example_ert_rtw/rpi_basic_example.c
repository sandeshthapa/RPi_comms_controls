/*
 * rpi_basic_example.c
 *
 * Code generation for model "rpi_basic_example".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Dec 28 13:54:30 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rpi_basic_example.h"
#include "rtwtypes.h"
#include <math.h>
#include "rpi_basic_example_private.h"
#include <string.h>

/* Block states (default storage) */
DW_rpi_basic_example_T rpi_basic_example_DW;

/* Real-time model */
static RT_MODEL_rpi_basic_example_T rpi_basic_example_M_;
RT_MODEL_rpi_basic_example_T *const rpi_basic_example_M = &rpi_basic_example_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void rpi_basic_example_step(void)
{
  real_T rtb_Switch;
  real_T tmp;
  uint8_T tmp_0;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/OFF'
   *  Constant: '<Root>/ON'
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  Sin: '<Root>/Sine Wave'
   */
  if (sin(((real_T)rpi_basic_example_DW.counter +
           rpi_basic_example_P.SineWave_Offset) * 2.0 * 3.1415926535897931 /
          rpi_basic_example_P.SineWave_NumSamp) *
      rpi_basic_example_P.SineWave_Amp + rpi_basic_example_P.SineWave_Bias >=
      rpi_basic_example_P.CompareToConstant_const) {
    rtb_Switch = rpi_basic_example_P.ON_Value;
  } else {
    rtb_Switch = rpi_basic_example_P.OFF_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<S2>/Digital Write' */
  tmp = rt_roundd_snf(rtb_Switch);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  EXT_GPIO_write(17U, tmp_0);

  /* End of MATLABSystem: '<S2>/Digital Write' */
  /* Update for Sin: '<Root>/Sine Wave' */
  rpi_basic_example_DW.counter++;
  if (rpi_basic_example_DW.counter == rpi_basic_example_P.SineWave_NumSamp) {
    rpi_basic_example_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void rpi_basic_example_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(rpi_basic_example_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&rpi_basic_example_DW, 0,
                sizeof(DW_rpi_basic_example_T));

  /* Start for MATLABSystem: '<S2>/Digital Write' */
  rpi_basic_example_DW.obj.matlabCodegenIsDeleted = false;
  rpi_basic_example_DW.objisempty = true;
  rpi_basic_example_DW.obj.isInitialized = 1;
  EXT_GPIO_init(17U, true);
  rpi_basic_example_DW.obj.isSetupComplete = true;

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  rpi_basic_example_DW.counter = 0;
}

/* Model terminate function */
void rpi_basic_example_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  if (!rpi_basic_example_DW.obj.matlabCodegenIsDeleted) {
    rpi_basic_example_DW.obj.matlabCodegenIsDeleted = true;
    if ((rpi_basic_example_DW.obj.isInitialized == 1) &&
        rpi_basic_example_DW.obj.isSetupComplete) {
      EXT_GPIO_terminate(17U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write' */
}
