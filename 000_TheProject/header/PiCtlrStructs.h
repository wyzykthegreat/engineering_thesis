/*
 * PiCtlrStructs.h
 *
 *  Created on: Oct 27, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_PICTLRSTRUCTS_H_
#define HEADER_PICTLRSTRUCTS_H_

struct PI_CONTROLLER_STRUCT{

    float diffVal;
    float realVal;
    float setVal;
    float output;

    float itg;
    float kiOut;
    float kpOut;
    float sumOut;
    float kiStop;

    float ki;
    float kp;
    float ts;
    float satHi;
    float satLo;



};

#endif /* HEADER_PICTLRSTRUCTS_H_ */
