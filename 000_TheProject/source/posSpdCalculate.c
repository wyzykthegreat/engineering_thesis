/*
 * posSpdCalculate.c
 *
 *  Created on: Nov 14, 2023
 *      Author: wyzyk
 */
#include <math.h>
#include "posSpdCalculate.h"

void posCalcStructInit(struct POS_CALC_STRUCT *data, unsigned int* encVal, unsigned int polePairs, unsigned int rotRsln){
    data->rotRsln = rotRsln;
    data->polePairs = polePairs;

    data->encVal = encVal;

    data->mTheta = 0;
    data->eTheta = 0;

    data->zeroed = 0;

}

void posZero(struct POS_CALC_STRUCT *data){
    data->zeroed = 1;
}

void posCalc(struct POS_CALC_STRUCT *data){
    data->mTheta = (float)((*data->encVal+272)/(float)data->rotRsln)*M_PI*2;
    data->eTheta = (float)((*data->encVal+272)/(float)data->rotRsln)*M_PI*8;
    while(M_PI*2 < data->eTheta){
        data->eTheta -=M_PI*2;
    }
}

void spdCalcStructInit(struct SPD_CALC_STRUCT *data, unsigned int tmrPrscCcps, unsigned int encPrscUpps, unsigned int* stsFlgReg, unsigned int dirChgFlgMsk, unsigned int cntOvfFlgMsk, unsigned int dirFlgMsk, unsigned int* cntPrd, unsigned int rotRsln, unsigned long* qposlat, unsigned int quprd){
    data->tmrPrscCcps = pow(2, tmrPrscCcps);
    data->encPrscUpps = pow(2, encPrscUpps);
    data->stsFlgReg = stsFlgReg;
    data->dirChgFlgMsk = dirChgFlgMsk;
    data->cntOvfFlgMsk = cntOvfFlgMsk;
    data->dirFlgMsk = dirFlgMsk;
    data->cntPrd = cntPrd;
    data->rotRsln = (float)rotRsln;
    data->qposlat = qposlat;
    data->quprd = (float)quprd;

    data->spd = 0;
}

void spdCalc(struct SPD_CALC_STRUCT *data){
    //data->spd = (data->encPrscUpps/data->rotRsln)/(float)((*data->cntPrd*data->tmrPrscCcps)/(9000000000.0));//150Mhz*60 to have unit per minute
    switch ((*data->stsFlgReg&data->cntOvfFlgMsk)){
        case 4:
            switch ((*data->stsFlgReg&data->dirChgFlgMsk)){
            case 0:
                data->spd = (data->encPrscUpps/data->rotRsln)/(float)((*data->cntPrd*data->tmrPrscCcps)/(9000000000.0));//150Mhz*60 to have unit per minute
                break;
            default:
                *data->stsFlgReg |= data->dirChgFlgMsk;
                data->spd = 0;
            }
            break;
        default:
            data->spd = 900000.0/(*data->cntPrd*data->tmrPrscCcps);//(*data->qposlat/data->rotRsln)/((150000000.0/data->quprd)*60.0);
            if(0 == (*data->stsFlgReg&data->dirFlgMsk)){
                data->spd = data->spd*-1;
            }
            //*data->stsFlgReg |= data->cntOvfFlgMsk;

    }

}
