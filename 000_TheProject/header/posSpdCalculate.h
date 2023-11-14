/*
 * posSpdCalculate.h
 *
 *  Created on: Nov 14, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_POSSPDCALCULATE_H_
#define HEADER_POSSPDCALCULATE_H_

#include "posSpdCalculateStructs.h"

void posSpdCalcStructInit(struct POS_SPD_CALC_STRUCT *data, unsigned int* encVal, unsigned int polePairs, unsigned int rsln);
void posCalc(struct POS_SPD_CALC_STRUCT *data);
void posZero(struct POS_SPD_CALC_STRUCT *data);

#endif /* HEADER_POSSPDCALCULATE_H_ */
