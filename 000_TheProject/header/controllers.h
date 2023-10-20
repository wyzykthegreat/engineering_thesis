/*
 * controllers.h
 *
 *  Created on: Oct 20, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_CONTROLLERS_H_
#define HEADER_CONTROLLERS_H_

float piCtlr(float kp, float ki, float in, float inPrv, float outPrv, unsigned int cndItg);

#endif /* HEADER_CONTROLLERS_H_ */
