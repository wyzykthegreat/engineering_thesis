/*
 * calibrateValue.h
 *
 *  Created on: Nov 4, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_CALIBRATEVALUE_H_
#define HEADER_CALIBRATEVALUE_H_

#include "calibrateValueStructs.h"

float   calReal(struct VALUE_CALIBRATION_STRUCT *data, float inputValue);
void    valCalStructInit(struct VALUE_CALIBRATION_STRUCT *data, float a, float b);


#endif /* HEADER_CALIBRATEVALUE_H_ */
