#include "DSP28x_Project.h"

/**
 * main.c
 */
Uint16 tmr2IsrCtr = 0;


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


    for(;;);
	return 0;
}
