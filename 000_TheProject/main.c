#include "DSP28x_Project.h"
#include "GlobalVariables.h"
#include "adcConversion.h"
/**
 * main.c
 */


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
    adcDataStructInit(&adcConvDataV, (9.09/(300.0+820.0+9.09)), 0);

    for(;;);
	return 0;
}
