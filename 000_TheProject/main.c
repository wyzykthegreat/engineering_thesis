#include "DSP28x_Project.h"

/**
 * main.c
 */
Uint16 tmr2IsrCtr = 0;
struct ADC_CONVERSION_DATA_STRUCT adcConvData;
struct ADC_CONVERTED_MEASUREMENTS adcConvMeas;

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
    adcStructInit(&adcConvData, 8.25, 1.65);

    for(;;);
	return 0;
}
