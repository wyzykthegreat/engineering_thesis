/*
 * PiCtlr.c
 *
 *  Created on: Oct 20, 2023
 *      Author: wyzyk
 */

#include "PiCtlr.h"

void initPiCtlrStruct(struct PI_CONTROLLER_STRUCT *data, float ki, float kp, float ts, float satLo, float satHi){

    data->diffVal = 0;
    data->realVal = 0;
    data->setVal = 0;
    data->output = 0;

    data->itg = 0;
    data->kiOut = 0;
    data->kpOut = 0;
    data->sumOut = 0;
    data->kiStop = 0;

    data->ki = ki;
    data->kp = kp;
    data->ts = ts;
    data->satHi = satHi;
    data->satLo = satLo;
}

float calcPiCtl(struct PI_CONTROLLER_STRUCT *data, float realValue, float setValue){
    data->realVal = realValue;
    data->setVal = setValue;

    data->diffVal = data->setVal-data->realVal;

    data->kpOut = data->diffVal * data->kp;
    data->kiOut = data->itg;
    data->sumOut = data->kiOut + data->kpOut;

    if(data->satHi < data->sumOut){
        data->output = data->satHi;
        data->kiStop = 1;
    } else if (data->satLo > data->sumOut) {
        data->output = data->satLo;
        data->kiStop = 1;
    } else {
        data->output = data->sumOut;
        data->kiStop = 0;
    }
    if(0 == data->kiStop){
        data->itg += data->diffVal * data->ts * data->ki;
    }
    return data->output;
}


