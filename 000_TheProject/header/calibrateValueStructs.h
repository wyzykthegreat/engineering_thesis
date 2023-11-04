/*
 * calibrateValueStructs.h
 *
 *  Created on: Nov 4, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_CALIBRATEVALUESTRUCTS_H_
#define HEADER_CALIBRATEVALUESTRUCTS_H_

struct VALUE_CALIBRATION_STRUCT{
    float finalValue;
    float inputValue;
    float a;
    float b;
};

struct MEAN_VALUE_MEASUREMENT_STRUCT{
    float mean;
    unsigned int* measSrc;
    unsigned int measDo;
    unsigned int measCtr;
    unsigned int measPrd;
    unsigned long sum;
};

#endif /* HEADER_CALIBRATEVALUESTRUCTS_H_ */
