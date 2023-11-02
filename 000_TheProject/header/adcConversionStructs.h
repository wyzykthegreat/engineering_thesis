/*
 * adcConversionStructs.h
 *
 *  Created on: Oct 30, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_ADCCONVERSIONSTRUCTS_H_
#define HEADER_ADCCONVERSIONSTRUCTS_H_

struct ADC_CONVERSION_DATA_STRUCT{
    float gain;
    float offset;
    volatile float out;
};

struct ADC_CONVERTED_MEASUREMENTS{
    float IfbU;
    float IfbV;
    float IfbW;
    float IfbSum;

    float VfbU;
    float VfbV;
    float VfbW;
    float VfbDC;
};

#endif /* HEADER_ADCCONVERSIONSTRUCTS_H_ */
