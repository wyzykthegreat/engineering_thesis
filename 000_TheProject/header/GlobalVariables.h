/*
 * GlobalVariables.h
 *
 *  Created on: Nov 1, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_GLOBALVARIABLES_H_
#define HEADER_GLOBALVARIABLES_H_

#include "adcConversionStructs.h"

extern Uint16   tmr2IsrCtr;
extern struct ADC_CONVERTED_MEASUREMENTS adcConvMeas;
extern struct ADC_CONVERSION_DATA_STRUCT adcConvDataI;
extern struct ADC_CONVERSION_DATA_STRUCT adcConvDataV;

#endif /* HEADER_GLOBALVARIABLES_H_ */
