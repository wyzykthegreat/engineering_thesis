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

void adcConvMeasStructInit(struct ADC_CONVERTED_MEASUREMENTS_STRUCT *data){
    data->IfbSum = 0;
    data->IfbU = 0;
    data->IfbV = 0;
    data->IfbW = 0;

    data->VfbU = 0;
    data->VfbV = 0;
    data->VfbW = 0;
    data->VfbDC = 0;
}
