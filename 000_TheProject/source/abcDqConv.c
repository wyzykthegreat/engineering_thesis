/*
 * abcDqConv.c
 *
 *  Created on: Nov 2, 2023
 *      Author: wyzyk
 */

#include "abcDqConv.h"

void abcdqStructInit(struct ABCDQ_STRUCT *data){
    data->a = 0;
    data->b = 0;
    data->c = 0;

    data->d = 0;
    data->q = 0;
    data->eAngle = 0;
    //data->zero = 0;

}

void abcToDq(struct ABCDQ_STRUCT *data, float a, float b, float c, float eAngle){
    data->a = a;
    data->b = b;
    data->c = c;
    data->eAngle = eAngle;

    data->d = (2.0/3.0) * ((data->a*cos(eAngle)     ) +   (data->b*cos((data->eAngle-(M_PI*2.0/3.0)))     ) + (data->c*cos((data->eAngle+(M_PI*2.0/3.0)))     ));
    data->q = (2.0/3.0) * ((data->a*sin(eAngle)*(-1)) +   (data->b*sin((data->eAngle-(M_PI*2.0/3.0)))*(-1)) + (data->c*sin((data->eAngle+(M_PI*2.0/3.0)))*(-1)));

    //data->zero = (a+b+c)/3.0;
}

void dqToAbc(struct ABCDQ_STRUCT *data, float d, float q, float eAngle){
    //eAngle is electrical angle IN RADIANS
    data->d = d;
    data->q = q;
    data->eAngle = eAngle;

    data->a = data->d*cos(eAngle) + data->q*sin(eAngle)*(-1);
    data->b = data->d*cos((data->eAngle-(M_PI*2.0/3.0))) + data->q*sin((data->eAngle-(M_PI*2.0/3.0)))*(-1);
    data->c = data->d*cos((data->eAngle+(M_PI*2.0/3.0))) + data->q*sin((data->eAngle+(M_PI*2.0/3.0)))*(-1);
}
