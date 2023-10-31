/*
 * adcConversion.c
 *
 *  Created on: Oct 30, 2023
 *      Author: wyzyk
 */

#include "adcConversion.h"

float adcToReal(struct ADC_CONVERSION_DATA_STRUCT *data, unsigned int *meas){
    return 0; //the converted measurement will be returned in this line
}

void adcStructInit(struct ADC_CONVERSION_DATA_STRUCT *data, float gain, float offset){
    data->gain = gain;
    data->offset = offset;
}
