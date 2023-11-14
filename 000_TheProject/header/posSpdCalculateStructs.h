/*
 * posSpdCalculateStructs.h
 *
 *  Created on: Nov 14, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_POSSPDCALCULATESTRUCTS_H_
#define HEADER_POSSPDCALCULATESTRUCTS_H_

struct POS_SPD_CALC_STRUCT{

    float mTheta;
    float eTheta;

    unsigned int* encVal;

    unsigned int polePairs;
    unsigned int rsln;

    unsigned int zeroed;
};

struct spdCalcStruct{

};
#endif /* HEADER_POSSPDCALCULATESTRUCTS_H_ */
