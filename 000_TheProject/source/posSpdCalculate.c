/*
 * posSpdCalculate.c
 *
 *  Created on: Nov 14, 2023
 *      Author: wyzyk
 */
#include <math.h>
#include "posSpdCalculate.h"

void posSpdCalcStructInit(struct POS_SPD_CALC_STRUCT *data, unsigned int* encVal, unsigned int polePairs, unsigned int rsln){
    data->rsln = rsln;
    data->polePairs = polePairs;

    data->encVal = encVal;

    data->mTheta = 0;
    data->eTheta = 0;

    data->zeroed = 0;

}

void posZero(struct POS_SPD_CALC_STRUCT *data){
    data->zeroed = 1;
}

void posCalc(struct POS_SPD_CALC_STRUCT *data){
    data->mTheta = (float)*data->encVal/(float)data->rsln*M_PI*2;
    data->eTheta = (float)*data->encVal/(float)data->rsln*M_PI*8;
    while(M_PI*2 < data->eTheta){
        data->eTheta -=M_PI*2;
    }

}
