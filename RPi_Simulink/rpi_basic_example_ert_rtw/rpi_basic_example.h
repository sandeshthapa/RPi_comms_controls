/*
 * rpi_basic_example.h
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

#ifndef RTW_HEADER_rpi_basic_example_h_
#define RTW_HEADER_rpi_basic_example_h_
#ifndef rpi_basic_example_COMMON_INCLUDES_
#define rpi_basic_example_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_gpio.h"
#endif                                 /* rpi_basic_example_COMMON_INCLUDES_ */

#include "rpi_basic_example_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_Digi_T obj; /* '<S2>/Digital Write' */
  int32_T counter;                     /* '<Root>/Sine Wave' */
  boolean_T objisempty;                /* '<S2>/Digital Write' */
} DW_rpi_basic_example_T;

/* Parameters (default storage) */
struct P_rpi_basic_example_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S1>/Constant'
                                       */
  real_T ON_Value;                     /* Expression: 1
                                        * Referenced by: '<Root>/ON'
                                        */
  real_T OFF_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/OFF'
                                        */
  real_T SineWave_Amp;                 /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_NumSamp;             /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Offset;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_rpi_basic_example_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_rpi_basic_example_T rpi_basic_example_P;

/* Block states (default storage) */
extern DW_rpi_basic_example_T rpi_basic_example_DW;

/* Model entry point functions */
extern void rpi_basic_example_initialize(void);
extern void rpi_basic_example_step(void);
extern void rpi_basic_example_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rpi_basic_example_T *const rpi_basic_example_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'rpi_basic_example'
 * '<S1>'   : 'rpi_basic_example/Compare To Constant'
 * '<S2>'   : 'rpi_basic_example/GPIO Write'
 */
#endif                                 /* RTW_HEADER_rpi_basic_example_h_ */
