#include "DSP28x_Project.h"

/**
 * main.c
 */
unsigned int tmr2IsrCtr = 0;

int main(void)
{
    InitSysCtrl();
    InitGpio();
    InitCpuTimers();
    InitPieVectTable();
    InitPieCtrl();
    IER = 0x0000 | M_INT14;
    IFR = 0x0000;
    EnableInterrupts();
    ERTM;
    //    InitECana();


    for(;;);
	return 0;
}
