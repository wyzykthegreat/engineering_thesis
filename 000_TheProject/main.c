#include "DSP28x_Project.h"
#include "GlobalVariables.h"
#include "adcConversion.h"
#include "PiCtlr.h"
#include "calibrateValue.h"
#include "abcDqConv.h"
#include "posSpdCalculate.h"


/**
 * main.c
 */
float aTodq = 0.3, bTodq = 0.7, cTodq = -0.4, dToabc = 0.4, qToabc = 0.7, ang = M_PI/2;


int main(void)
{
    uPwmDuty = 0;
    vPwmDuty = 0;
    wPwmDuty = 0;
    dPwmDuty = 0;
    qPwmDuty = 0;
    angVar = 0;
    uVar = 0;
    vVar = 0;
    wVar = 0;
    gainTest = 0;
    findZero = 0;
    atfclAng = 0;

    idSet = 0;
    iqSet = 0;
    spdSet = 0;
    InitSysCtrl();
    InitGpio();
    InitCpuTimers();
    InitAdc();
    InitEPwm();
    InitEQep();
    InitECana();
    InitPieVectTable();
    InitPieCtrl();
    IER = 0x0000 | M_INT14 | M_INT1 | M_INT3 | M_INT5 | M_INT9;
    IFR = 0x0000;
    EnableInterrupts();
    ERTM;

    //    InitECana();
    adcDataStructInit(&adcConvDataI, 8.25, 1.65);
    adcDataStructInit(&adcConvDataV, ((300.0+820.0+9.09)/9.09), 0);

    adcConvMeasStructInit(&adcConvMeas);

    valCalStructInit(&calStrIfbU, 0.7, -0.05);
    valCalStructInit(&calStrIfbV, 0.7, 0.09);
    valCalStructInit(&calStrIfbW, 0.7, -0.09);
    valCalStructInit(&calStrIfbSum, 1, 0);
    valCalStructInit(&calStrVfbU, 1, 0);
    valCalStructInit(&calStrVfbV, 1, 0);
    valCalStructInit(&calStrVfbW, 1, 0);
    valCalStructInit(&calStrVfbDC, 1, -0.34512);

    meanValMeasStructInit(&measMeanValStruct);

    initPiCtlrStruct(&piCtlrId, 10, 2, 0.0001, -5.0, 5.0);
    initPiCtlrStruct(&piCtlrIq, 10, 2, 0.0001, -5.0, 5.0);
    initPiCtlrStruct(&piCtlrSpd, 0.05, 0.025, 0.0001, -3.0, 3.0);

    abcdqStructInit(&dqToAbcStruct);
    abcdqStructInit(&abcToDqStruct);

    posCalcStructInit(&posCalcStruct,(unsigned int*) &EQep1Regs.QPOSCNT, 4, 10000);
    spdCalcStructInit(&spdCalcStruct, EQep1Regs.QCAPCTL.bit.CCPS, EQep1Regs.QCAPCTL.bit.UPPS, &EQep1Regs.QEPSTS.all, 0x2, 0x4, 0x10, &EQep1Regs.QCPRDLAT, 10000, &EQep1Regs.QPOSLAT, EQep1Regs.QUPRD);
    for(;;){
/*        abcToDq(&abcdqTest1, aTodq, bTodq, cTodq, ang);
        dqToAbc(&abcdqTest2, dToabc, qToabc, ang);*/
    }
	return 0;
}
