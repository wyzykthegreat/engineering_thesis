/*
 * controllers.c
 *
 *  Created on: Oct 20, 2023
 *      Author: wyzyk
 */

float piCtlr(float kp, float ki, float ts, float in, float inPrv, float outPrv, unsigned int cndItg){
    if(1 == cndItg){
        return ( (in*kp) + (inPrv*((ki*ts)-kp)) + (outPrv));
    } else {
        return (kp*in);
    }
}


