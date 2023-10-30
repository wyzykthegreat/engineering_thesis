/*
 * adcConversion.c
 *
 *  Created on: Oct 30, 2023
 *      Author: wyzyk
 */

#include "header/adcConversion.h"

float adcToReal(struct ADC_CONVERSION_DATA_STRUCT *data, unsigned int *meas){
    return ((((4095-*meas)*3.0)/4096.0)-data->offset)*data->gain;
}

void adcStructInit(struct ADC_CONVERSION_DATA_STRUCT *data, float gain, float offset){
    data->gain = gain;
    data->offset = offset;
}
