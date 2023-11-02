/*
 * PiCtlr.h
 *
 *  Created on: Oct 20, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_PICTLR_H_
#define HEADER_PICTLR_H_

#include "PiCtlrStructs.h"

void initPiCtlrStruct(struct PI_CONTROLLER_STRUCT *data, float ki, float kp, float ts, float satHi, float satLo);
float calcPiCtl(struct PI_CONTROLLER_STRUCT *data, float realValue, float setValue);


#endif /* HEADER_PICTLR_H_ */
