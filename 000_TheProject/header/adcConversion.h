/*
 * adcConversion.h
 *
 *  Created on: Oct 30, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_ADCCONVERSION_H_
#define HEADER_ADCCONVERSION_H_

#include "adcConversionStructs.h"

float   adcToReal(struct ADC_CONVERSION_DATA_STRUCT *data, unsigned int meas);
void    adcDataStructInit(struct ADC_CONVERSION_DATA_STRUCT *data, float gain, float offset);
void    adcConvMeasStructInit(struct ADC_CONVERTED_MEASUREMENTS_STRUCT *data);
#endif /* HEADER_ADCCONVERSION_H_ */
