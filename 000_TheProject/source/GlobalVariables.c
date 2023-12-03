/*
 * GlobalVariables.c
 *
 *  Created on: Nov 1, 2023
 *      Author: wyzyk
 */
#include "adcConversionStructs.h"
#include "PiCtlrStructs.h"
#include "calibrateValueStructs.h"
#include "abcDqConvStructs.h"
#include "posSpdCalculateStructs.h"

unsigned int tmr2IsrCtr;
unsigned int testCtr;

float uPwmDuty;
float vPwmDuty;
float wPwmDuty;

float iUSet;
float vUSet;

struct ADC_CONVERTED_MEASUREMENTS_STRUCT adcConvMeas;
struct ADC_CONVERSION_DATA_STRUCT adcConvDataI;
struct ADC_CONVERSION_DATA_STRUCT adcConvDataV;

struct VALUE_CALIBRATION_STRUCT calStrIfbU;
struct VALUE_CALIBRATION_STRUCT calStrIfbV;
struct VALUE_CALIBRATION_STRUCT calStrIfbW;
struct VALUE_CALIBRATION_STRUCT calStrIfbSum;
struct VALUE_CALIBRATION_STRUCT calStrVfbU;
struct VALUE_CALIBRATION_STRUCT calStrVfbV;
struct VALUE_CALIBRATION_STRUCT calStrVfbW;
struct VALUE_CALIBRATION_STRUCT calStrVfbDC;

struct MEAN_VALUE_MEASUREMENT_STRUCT measMeanValStruct;


struct PI_CONTROLLER_STRUCT piCtlrTestV;
struct PI_CONTROLLER_STRUCT piCtlrTestI;

struct ABCDQ_STRUCT abcdqTest1;
struct ABCDQ_STRUCT abcdqTest2;

struct POS_CALC_STRUCT posCalcStruct;
struct SPD_CALC_STRUCT spdCalcStruct;
