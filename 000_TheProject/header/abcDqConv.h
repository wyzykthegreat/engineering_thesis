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

void abcToDq(struct ABCDQ_STRUCT *data, float a, float b, float c, float eAngle);

#endif /* HEADER_ABCDQCONV_H_ */
