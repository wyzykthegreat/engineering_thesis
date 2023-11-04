/*
 * calibrateValue.h
 *
 *  Created on: Nov 4, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_CALIBRATEVALUE_H_
#define HEADER_CALIBRATEVALUE_H_

#include "calibrateValueStructs.h"

void valCalStructInit(struct VALUE_CALIBRATION_STRUCT *data, float a, float b);
void meanValMeasStructInit(struct MEAN_VALUE_MEASUREMENT_STRUCT *data);
void meanValMeasStructStart(struct MEAN_VALUE_MEASUREMENT_STRUCT *data);
void meanValMeasStructStop(struct MEAN_VALUE_MEASUREMENT_STRUCT *data);
float calVal(struct VALUE_CALIBRATION_STRUCT *data, float inputValue);
void measMeanVal(struct MEAN_VALUE_MEASUREMENT_STRUCT *data);

#endif /* HEADER_CALIBRATEVALUE_H_ */
