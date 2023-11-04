/*
 * abcDqConv.h
 *
 *  Created on: Nov 2, 2023
 *      Author: wyzyk
 */

#ifndef HEADER_ABCDQCONV_H_
#define HEADER_ABCDQCONV_H_

#include <math.h>
#include "abcDqConvStructs.h"

void abcdqStructInit(struct ABCDQ_STRUCT *data);
void abcToDq(struct ABCDQ_STRUCT *data, float a, float b, float c, float eAngle);
void dqToAbc(struct ABCDQ_STRUCT *data, float d, float q, float eAngle);

#endif /* HEADER_ABCDQCONV_H_ */
