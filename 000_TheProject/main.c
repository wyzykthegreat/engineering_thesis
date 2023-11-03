#include "DSP28x_Project.h"
#include "GlobalVariables.h"
#include "adcConversion.h"
#include "PiCtlr.h"
/**
 * main.c
 */

int main(void)
{
    pwmDuty = 0;
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

    for(;;);
	return 0;
}
