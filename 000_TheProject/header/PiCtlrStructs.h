/*
 * PiCtlrStructs.h
 *
 *  Created on: Oct 27, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_PICTLRSTRUCTS_H_
#define HEADER_PICTLRSTRUCTS_H_

struct PI_CONTROLLER_STRUCT{

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

#endif /* HEADER_PICTLRSTRUCTS_H_ */
