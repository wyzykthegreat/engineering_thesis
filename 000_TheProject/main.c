#include "DSP28x_Project.h"
#include "GlobalVariables.h"
#include "adcConversion.h"
#include "PiCtlr.h"
#include "abcDqConv.h"
/**
 * main.c
 */
float aTodq = 0.3, bTodq = 0.7, cTodq = -0.4, dToabc = 0.4, qToabc = 0.7, ang = M_PI/2;


int main(void)
{
    InitSysCtrl();
    InitGpio();
    InitCpuTimers();
    InitAdc();
    InitEPwm();
    InitPieVectTable();
    InitPieCtrl();
    IER = 0x0000 | M_INT14 | M_INT1 | M_INT3;
    IFR = 0x0000;
    EnableInterrupts();
    ERTM;

    //    InitECana();
    adcDataStructInit(&adcConvDataI, 8.25, 1.65);
    adcDataStructInit(&adcConvDataV, ((300.0+820.0+9.09)/9.09), 0);

    //initPiCtlrStruct(&piCtlrTest, 1, 0, 0.0001, -1, 1);

    abcdqStructInit(&abcdqTest1);
    abcdqStructInit(&abcdqTest2);


    for(;;){
        abcToDq(&abcdqTest1, aTodq, bTodq, cTodq, ang);
        dqToAbc(&abcdqTest2, dToabc, qToabc, ang);
    }
	return 0;
}
