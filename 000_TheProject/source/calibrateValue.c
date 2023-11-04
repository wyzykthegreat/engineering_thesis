/*
 * calibrateValue.c
 *
 *  Created on: Nov 4, 2023
 *      Author: wyzyk
 */
#include "calibrateValue.h"

float calReal(struct VALUE_CALIBRATION_STRUCT *data, float inputValue){
    data->inputValue = inputValue;
    data->finalValue = (data->inputValue*data->a) + data->b;
    return data->finalValue;
}

void valCalStructInit(struct VALUE_CALIBRATION_STRUCT *data, float a, float b){
    data->a = a;
    data->b = b;

    data->finalValue = 0;
    data->inputValue = 0;
}
