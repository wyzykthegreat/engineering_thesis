/*
 * adcConversion.c
 *
 *  Created on: Oct 30, 2023
 *      Author: wyzyk
 */

#include "adcConversion.h"

float adcToReal(struct ADC_CONVERSION_DATA_STRUCT *data,  unsigned int meas){
    data->out = ((((4095-meas)*3.0)/4096.0)-1.65)/8.25;
    return data->out; //the converted measurement will be returned in this line
}

void adcDataStructInit(struct ADC_CONVERSION_DATA_STRUCT *data, float gain, float offset){
    data->gain = gain;
    data->offset = offset;
    data->out = 0;
}
