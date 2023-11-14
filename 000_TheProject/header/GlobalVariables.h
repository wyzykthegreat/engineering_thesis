/*
 * GlobalVariables.h
 *
 *  Created on: Nov 1, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_GLOBALVARIABLES_H_
#define HEADER_GLOBALVARIABLES_H_

#include "adcConversion.h"
#include "calibrateValue.h"
#include "PiCtlr.h"
#include "posSpdCalculate.h"

extern unsigned int   tmr2IsrCtr;
extern unsigned int   testCtr;

extern float uPwmDuty;
extern float vPwmDuty;
extern float wPwmDuty;

extern float iUSet;
extern float vUSet;

extern struct ADC_CONVERTED_MEASUREMENTS_STRUCT adcConvMeas;
extern struct ADC_CONVERSION_DATA_STRUCT adcConvDataI;
extern struct ADC_CONVERSION_DATA_STRUCT adcConvDataV;

extern struct VALUE_CALIBRATION_STRUCT calStrIfbU;
extern struct VALUE_CALIBRATION_STRUCT calStrIfbV;
extern struct VALUE_CALIBRATION_STRUCT calStrIfbW;
extern struct VALUE_CALIBRATION_STRUCT calStrIfbSum;
extern struct VALUE_CALIBRATION_STRUCT calStrVfbU;
extern struct VALUE_CALIBRATION_STRUCT calStrVfbV;
extern struct VALUE_CALIBRATION_STRUCT calStrVfbW;
extern struct VALUE_CALIBRATION_STRUCT calStrVfbDC;

extern struct MEAN_VALUE_MEASUREMENT_STRUCT measMeanValStruct;

extern struct PI_CONTROLLER_STRUCT piCtlrTestV;
extern struct PI_CONTROLLER_STRUCT piCtlrTestI;

extern struct ABCDQ_STRUCT abcdqTest1;
extern struct ABCDQ_STRUCT abcdqTest2;

extern struct POS_SPD_CALC_STRUCT posSpdTest;
#endif /* HEADER_GLOBALVARIABLES_H_ */
