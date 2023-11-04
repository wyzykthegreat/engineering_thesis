/*
 * GlobalVariables.c
 *
 *  Created on: Nov 1, 2023
 *      Author: wyzyk
 */
#include "adcConversionStructs.h"
#include "PiCtlrStructs.h"
<<<<<<< HEAD
#include "calibrateValueStructs.h"
=======
#include "abcDqConvStructs.h"
>>>>>>> refs/heads/abcTodq_and_dqToabc

unsigned int tmr2IsrCtr;
unsigned int testCtr;

float pwmDuty;

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


struct PI_CONTROLLER_STRUCT piCtlrTest;

struct ABCDQ_STRUCT abcdqTest1;
struct ABCDQ_STRUCT abcdqTest2;
