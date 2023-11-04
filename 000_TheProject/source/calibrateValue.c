/*
 * calibrateValue.c
 *
 *  Created on: Nov 4, 2023
 *      Author: wyzyk
 */
#include "calibrateValue.h"



void valCalStructInit(struct VALUE_CALIBRATION_STRUCT *data, float a, float b){
    data->a = a;
    data->b = b;

    data->finalValue = 0;
    data->inputValue = 0;
}

void meanValMeasStructInit(struct MEAN_VALUE_MEASUREMENT_STRUCT *data){
    data->mean = 0;
    data->measSrc = 0;
    data->measDo = 0;
    data->measCtr = 0;
    data->measPrd = 0;
    data->sum = 0;
}

void meanValMeasStructStart(struct MEAN_VALUE_MEASUREMENT_STRUCT *data){
    data->mean = 0;
    data->sum = 0;
}

void meanValMeasStructStop(struct MEAN_VALUE_MEASUREMENT_STRUCT *data){
    data->measDo = 0;
    data->measCtr = 0;
    data->mean = ((float)data->sum/(float)data->measPrd);
}

float calVal(struct VALUE_CALIBRATION_STRUCT *data, float inputValue){
    data->inputValue = inputValue;
    data->finalValue = (data->inputValue*data->a) + data->b;
    return data->finalValue;
}

void measMeanVal(struct MEAN_VALUE_MEASUREMENT_STRUCT *data){
    switch (data->measDo){
    case 1:
        switch (data->measCtr){
        case 0:
            meanValMeasStructStart(data);
        default:
            data->sum += *data->measSrc;
            data->measCtr++;
            if(data->measPrd <= data->measCtr){
                meanValMeasStructStop(data);
            }
        }
    case 0:
        break;
    default:
        meanValMeasStructInit(data);
    }
}
