/*
 * adcConversion.c
 *
 *  Created on: Oct 30, 2023
 *      Author: wyzyk
 */

#include "adcConversion.h"

float adcToReal(struct ADC_CONVERSION_DATA_STRUCT *data,  unsigned int meas){
    data->out = ((((((meas)*3.0)/4096.0)-data->offset)*data->gain));
    return data->out; //the converted measurement will be returned in this line
}

void adcDataStructInit(struct ADC_CONVERSION_DATA_STRUCT *data, float gain, float offset){
    data->gain = gain;
    data->offset = offset;
    data->out = 0;
}
