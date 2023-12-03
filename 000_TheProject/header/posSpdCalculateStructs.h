/*
 * posSpdCalculateStructs.h
 *
 *  Created on: Nov 14, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_POSSPDCALCULATESTRUCTS_H_
#define HEADER_POSSPDCALCULATESTRUCTS_H_

struct POS_CALC_STRUCT{

    float mTheta;
    float eTheta;

    unsigned int* encVal;

    unsigned int polePairs;
    unsigned int rotRsln;

    unsigned int zeroed;
};

struct SPD_CALC_STRUCT{
    float tmrPrscCcps;
    float encPrscUpps;
    unsigned int* stsFlgReg;
    unsigned int dirChgFlgMsk;
    unsigned int cntOvfFlgMsk;
    unsigned int dirFlgMsk;
    unsigned int* cntPrd;
    unsigned long* qposlat;
    float quprd;
    float rotRsln;

    unsigned int spd;
};
#endif /* HEADER_POSSPDCALCULATESTRUCTS_H_ */
