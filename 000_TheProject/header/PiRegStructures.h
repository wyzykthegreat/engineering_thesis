/*
 * PiReglatorStructures.h
 *
 *  Created on: Oct 27, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_PIREGULATORSTRUCTURES_H_
#define HEADER_PIREGULATORSTRUCTURES_H_

struct PI_REGULATOR_STRUCT{

    float uPrv;
    float y;

    float kp;
    float ki;
    float ts;

    float satHi;
    float satLo;

    float cndItg;

    float KItTSmKP
};

#endif /* HEADER_PIREGULATORSTRUCTURES_H_ */
