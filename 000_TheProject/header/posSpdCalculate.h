/*
 * posSpdCalculate.h
 *
 *  Created on: Nov 14, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_POSSPDCALCULATE_H_
#define HEADER_POSSPDCALCULATE_H_

#include "posSpdCalculateStructs.h"

void posCalcStructInit(struct POS_CALC_STRUCT *data, unsigned int* encVal, unsigned int polePairs, unsigned int rsln);
void spdCalcStructInit(struct SPD_CALC_STRUCT *data, unsigned int tmrPrscCcps, unsigned int encPrscUpps, unsigned int* stsFlgReg, unsigned int dirChgFlgMsk, unsigned int cntOvfFlgMsk, unsigned int dirFlgMsk, unsigned int* cntPrd, unsigned int rotRsln, unsigned long* qposlat, unsigned int quprd);
void posCalc(struct POS_CALC_STRUCT *data);
void posZero(struct POS_CALC_STRUCT *data);
void spdCalc(struct SPD_CALC_STRUCT *data);

#endif /* HEADER_POSSPDCALCULATE_H_ */
