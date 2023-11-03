/*
 * GlobalVariables.c
 *
 *  Created on: Nov 1, 2023
 *      Author: wyzyk
 */
#include "adcConversionStructs.h"
#include "PiCtlrStructs.h"

unsigned int tmr2IsrCtr;
unsigned int testCtr;

float pwmDuty;

struct ADC_CONVERTED_MEASUREMENTS adcConvMeas;
struct ADC_CONVERSION_DATA_STRUCT adcConvDataI;
struct ADC_CONVERSION_DATA_STRUCT adcConvDataV;


struct ADC_CALIBRATE{
    unsigned int count;
    unsigned int measurements[25000];
    float meanValue;
    float offset;
    float gain;
};


struct PI_CONTROLLER_STRUCT piCtlrTest;
