/*
 * GlobalVariables.c
 *
 *  Created on: Nov 1, 2023
 *      Author: wyzyk
 */
#include "adcConversionStructs.h"
#include "PiCtlrStructs.h"
#include "abcDqConvStructs.h"

unsigned int tmr2IsrCtr;
unsigned int testCtr;

struct ADC_CONVERTED_MEASUREMENTS adcConvMeas;
struct ADC_CONVERSION_DATA_STRUCT adcConvDataI;
struct ADC_CONVERSION_DATA_STRUCT adcConvDataV;

struct PI_CONTROLLER_STRUCT piCtlrTest;

struct ABCDQ_STRUCT abcdqTest1;
struct ABCDQ_STRUCT abcdqTest2;
