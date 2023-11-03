/*
 * GlobalVariables.h
 *
 *  Created on: Nov 1, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_GLOBALVARIABLES_H_
#define HEADER_GLOBALVARIABLES_H_

#include "adcConversionStructs.h"

extern unsigned int   tmr2IsrCtr;
extern unsigned int   testCtr;

extern struct ADC_CONVERTED_MEASUREMENTS adcConvMeas;
extern struct ADC_CONVERSION_DATA_STRUCT adcConvDataI;
extern struct ADC_CONVERSION_DATA_STRUCT adcConvDataV;

extern struct PI_CONTROLLER_STRUCT piCtlrTest;

extern struct ABCDQ_STRUCT abcdqTest1;
extern struct ABCDQ_STRUCT abcdqTest2;
#endif /* HEADER_GLOBALVARIABLES_H_ */
