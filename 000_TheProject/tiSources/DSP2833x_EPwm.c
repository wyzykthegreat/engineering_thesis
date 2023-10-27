// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:46:19 $
//###########################################################################
//
// FILE:   DSP2833x_EPwm.c
//
// TITLE:  DSP2833x ePWM Initialization & Support Functions.
//
//###########################################################################
// $TI Release: 2833x/2823x Header Files V1.32 $
// $Release Date: June 28, 2010 $
// $Copyright:
// Copyright (C) 2009-2022 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//
// InitEPwm - This function initializes the ePWM(s) to a known state.
//
void 
InitEPwm(void)
{
    //
    // Initialize ePWM1/2/3 which control phases U/V/W
    //
    InitEPwm1();
    InitEPwm2();
    InitEPwm3();
    //REMINDER: CTRMODE will be configured last after every ePWM is configured
    //InitEPwm1Gpio(); <=currently pins configuret in initgpio

    //
    //Configure CTRMODE fields to start ePWMs
    //
    //EPwm3Regs.TBCTL.bit.CTRMODE = 2;
    //EPwm2Regs.TBCTL.bit.CTRMODE = 2;
    //EPwm1Regs.TBCTL.bit.CTRMODE = 2;

    EDIS;

}

//
// InitEPwmGpio - This function initializes GPIO pins to function as ePWM pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 
void 
InitEPwmGpio(void)
{
    InitEPwm1Gpio();
    InitEPwm2Gpio();
    InitEPwm3Gpio();
#if DSP28_EPWM4
    InitEPwm4Gpio();
#endif // endif DSP28_EPWM4
#if DSP28_EPWM5    
    InitEPwm5Gpio();
#endif // endif DSP28_EPWM5
#if DSP28_EPWM6
    InitEPwm6Gpio();
#endif // endif DSP28_EPWM6 
}

//
// InitEPwm1Gpio - This function initializes GPIO pins to function as ePWM1
// 
void 
InitEPwm1Gpio(void)
{
    EALLOW;

    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    // Enable pull-up on GPIO1 (EPWM1B)   

    //
    // Configure ePWM-1 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be ePWM1 functional 
    // pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B

    EDIS;
}

//
// InitEPwm2Gpio - This function initializes GPIO pins to function as ePWM2
//
void 
InitEPwm2Gpio(void)
{
    EALLOW;

    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;    // Enable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;    // Enable pull-up on GPIO3 (EPWM3B)

    //
    // Configure ePWM-2 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be ePWM2 functional 
    // pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B

    EDIS;
}

//
// InitEPwm3Gpio - This function initializes GPIO pins to function as ePWM3
//
void 
InitEPwm3Gpio(void)
{
    EALLOW;

    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;    // Enable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;    // Enable pull-up on GPIO5 (EPWM3B)

    //
    // Configure ePWM-3 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be ePWM3 functional
    // pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B

    EDIS;
}

#if DSP28_EPWM4
//
// InitEPwm4Gpio - This function initializes GPIO pins to function as ePWM4
//
void 
InitEPwm4Gpio(void)
{
    EALLOW;
    
    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;    // Enable pull-up on GPIO7 (EPWM4B)

    //
    // Configure ePWM-4 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be ePWM4 functional 
    // pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B

    EDIS;
}
#endif // endif DSP28_EPWM4  

#if DSP28_EPWM5
//
// InitEPwm5Gpio - This function initializes GPIO pins to function as ePWM5
//
void 
InitEPwm5Gpio(void)
{
    EALLOW;
    
    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;    // Enable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;    // Enable pull-up on GPIO9 (EPWM5B)

    //
    // Configure ePWM-5 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be ePWM5 functional 
    // pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B

    EDIS;
}
#endif // endif DSP28_EPWM5

#if DSP28_EPWM6
//
// InitEPwm6Gpio - This function initializes GPIO pins to function as ePWM6
//
void 
InitEPwm6Gpio(void)
{
    EALLOW;

    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;    // Enable pull-up on GPIO10 (EPWM6A)
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;    // Enable pull-up on GPIO11 (EPWM6B)

    //
    // Configure ePWM-6 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be ePWM6 functional 
    // pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EPWM6B

    EDIS;
}
#endif // endif DSP28_EPWM6  

//
// InitEPwmSyncGpio - This function initializes GPIO pins to function as ePWM 
// Synch pins
//
void 
InitEPwmSyncGpio(void)
{
    EALLOW;
    
    //
    // Configure EPWMSYNCI
    //

    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;  //Enable pull-up on GPIO6 (EPWMSYNCI)
    //GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;//Enable pull-up on GPIO32 (EPWMSYNCI)    

    //
    // Set qualification for selected pins to asynch only
    // This will select synch to SYSCLKOUT for the selected pins.
    // Comment out other unwanted lines.
    //
    
    //
    // Synch to SYSCLKOUT GPIO6 (EPWMSYNCI)
    //
    GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;
    
    //
    //Synch to SYSCLKOUT GPIO32 (EPWMSYNCI)
    //
    //GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0;   

    //
    // Configure EPwmSync pins using GPIO regs
    // This specifies which of the possible GPIO pins will be EPwmSync 
    // functional pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 2;  //Enable pull-up on GPIO6(EPWMSYNCI)
    //GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 2;//Enable pull-up on GPIO32(EPWMSYNCI)    

    //
    // Configure EPWMSYNC0
    //

    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    
    //
    // Enable pull-up on GPIO6 (EPWMSYNC0)
    //
    //GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;
    
    //
    // Enable pull-up on GPIO33 (EPWMSYNC0)
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;

    //
    // Enable pull-up on GPIO6 (EPWMSYNC0)
    //
    //GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 3;
    
    //
    // Enable pull-up on GPIO33 (EPWMSYNC0)
    //
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2;
}

//
// InitTzGpio -  This function initializes GPIO pins to function as Trip Zone
// (TZ) pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 
void 
InitTzGpio(void)
{
    EALLOW;

    //
    // Enable internal pull-up for the selected pins
    // Pull-ups can be enabled or disabled by the user. 
    // This will enable the pullups for the specified pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;    // Enable pull-up on GPIO12 (TZ1)
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;    // Enable pull-up on GPIO13 (TZ2)
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // Enable pull-up on GPIO14 (TZ3)
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Enable pull-up on GPIO15 (TZ4)

    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;    // Enable pull-up on GPIO16 (TZ5)
    //GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up on GPIO28 (TZ5)

    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;    // Enable pull-up on GPIO17 (TZ6) 
    //GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;    // Enable pull-up on GPIO29 (TZ6)  

    //
    // Set qualification for selected pins to asynch only
    // Inputs are synchronized to SYSCLKOUT by default.  
    // This will select asynch (no qualification) for the selected pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3;  // Asynch input GPIO12 (TZ1)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3;  // Asynch input GPIO13 (TZ2)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;  // Asynch input GPIO14 (TZ3)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;  // Asynch input GPIO15 (TZ4)

    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;  // Asynch input GPIO16 (TZ5)
    //GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (TZ5)

    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;  // Asynch input GPIO17 (TZ6) 
    //GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 3;  // Asynch input GPIO29 (TZ6)  

    //
    // Configure TZ pins using GPIO regs
    // This specifies which of the possible GPIO pins will be TZ functional 
    // pins. Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;  // Configure GPIO12 as TZ1
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;  // Configure GPIO13 as TZ2
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1;  // Configure GPIO14 as TZ3
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;  // Configure GPIO15 as TZ4

    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 3;  // Configure GPIO16 as TZ5
    //GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // Configure GPIO28 as TZ5

    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;  // Configure GPIO17 as TZ6               
    //GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // Configure GPIO29 as TZ6  

    EDIS;
}

void InitEPwm1(void){
    EALLOW;

    //TBPRD
    EPwm1Regs.TBPRD = 7500; //10000Hz ==fPWM == 2*TBPRD*TBCLK <=Assuming that CTRMODE will be configuret as UPDOWN(2)

    //TBPHS
    EPwm1Regs.TBPHS.half.TBPHS = 0;

    //TBCTR
    EPwm1Regs.TBCTR = 0; //<what should be the initial value?

    //TBCTL
        //CTRMODE will be set to 2 after every ePWM is configured
    EPwm1Regs.TBCTL.bit.FREE_SOFT = 2; //ePWM will be in free run mode
    EPwm1Regs.TBCTL.bit.CLKDIV = 0;    //150MHz == SYSCLKOUT == TBCLK
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0; //150MHz == SYSCLKOUT == TBCLK
    EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;  //Synchronization pulse when zero == CTR
    EPwm1Regs.TBCTL.bit.PHSEN = 0;

    //TBSTS
        //this register exists, just so you know

    //CMPA
    EPwm1Regs.CMPA.half.CMPA = 7500/2;//for test purposes, ASSMPTION: above CMPA value: vout = vdc; below CMPA value: vout = 0;

    //CMPB
    EPwm1Regs.CMPB = 7500; //this register is planned to be used as ADC starter some time in the future

    //CMPCTL
        //Shadow workings of the PWM module

    //CMPAHR
        //not used HighResolution part of counter-compare A value

    //AQCTLA
    EPwm1Regs.AQCTLA.bit.CAU = 2;//ASSUMPTION: EPWMxA high sets vout = vdc;
    EPwm1Regs.AQCTLA.bit.CAD = 1;//ASSUMPTION: EPWMxA low sets vout = 0;
    //AQCTLB
        //Probably not needed, to make sure deadband has to be worked out
    //AQSFRC
        //this register exists, just so you know
    //AQCSFRC
        //!!!continuous software force on outputs, very useful!!!
    //DBCTL
    EPwm1Regs.DBCTL.bit.IN_MODE  = 0;
    EPwm1Regs.DBCTL.bit.POLSEL   = 2;
    EPwm1Regs.DBCTL.bit.OUT_MODE = 3;
    //DBRED
    EPwm1Regs.DBRED = 600; //<=12us,  ASSUMPTION: SYSCLKOKUT == TBCLK

    //DBFED
    EPwm1Regs.DBFED = 600; //<=12us,  ASSUMPTION: SYSCLKOKUT == TBCLK

    //PCCTL
        //chopper register, not used for now

    //TZSEL
    EPwm1Regs.TZSEL.bit.OSHT1 = 1;

    //TZCTL
    EPwm1Regs.TZCTL.bit.TZA = 2; //force low ASSUMPTION EPWMxA turns off transistor
    EPwm1Regs.TZCTL.bit.TZB = 2; //force low  ASSUMPTION EPWMxB turns off transistor

    //TZEINT
    EPwm1Regs.TZEINT.bit.OST = 1;

    //TZFLG
        //this register exists, just so you know

    //TZCLR
        //this register exists, just so you know

    //TZFRC
        //this register exists, just so you know

    //ETSEL
    EPwm1Regs.ETSEL.bit.SOCAEN = 1;
    EPwm1Regs.ETSEL.bit.SOCASEL = 2; //will happen if TBcounter equals to PRD
    EPwm1Regs.ETSEL.bit.INTEN = 1;
    EPwm1Regs.ETSEL.bit.INTSEL = 2; // will happen when SOCA happens

    //ETPS
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;
    EPwm1Regs.ETPS.bit.INTPRD  = 0; //ENABLE AFTER IMPLEMENTING isr for pwm functions!!!

    //ETFLG
        //this register exists, just so you know

    //ETCLR
        //this register exists, just so you know

    //ETFRC
        //this register exists, just so you know

    //REMINDER: CTRMODE will be configured last after every ePWM is configured
    EDIS;
}

void InitEPwm2(void){
    EALLOW;

    //TBPRD
    EPwm2Regs.TBPRD = 7500; //10000Hz ==fPWM == 2*TBPRD*TBCLK <=Assuming that CTRMODE will be configuret as UPDOWN(2)

    //TBPHS
    EPwm2Regs.TBPHS.half.TBPHS = 2; //<====TODO calculate the phase value

    //TBCTR
    EPwm2Regs.TBCTR = 0; //<what should be the initial value?

    //TBCTL
        //CTRMODE will be set to 2 after every ePWM is configured
    EPwm2Regs.TBCTL.bit.FREE_SOFT = 2; //ePWM will be in free run mode
    EPwm2Regs.TBCTL.bit.CLKDIV = 0;    //150MHz == SYSCLKOUT == TBCLK
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = 0; //150MHz == SYSCLKOUT == TBCLK
    EPwm2Regs.TBCTL.bit.SYNCOSEL = 0;  //Synchronization pulse when passed further
    EPwm2Regs.TBCTL.bit.PHSEN = 1; //Synchronization enabled

    //TBSTS
        //this register exists, just so you know

    //CMPA
    EPwm2Regs.CMPA.half.CMPA = 7500/2;//for test purposes, ASSMPTION: above CMPA value: vout = vdc; below CMPA value: vout = 0;

    //CMPB
    EPwm2Regs.CMPB = 7500; //this register is planned to be used as ADC starter some time in the future

    //CMPCTL
        //Shadow workings of the PWM module

    //CMPAHR
        //not used HighResolution part of counter-compare A value

    //AQCTLA
    EPwm2Regs.AQCTLA.bit.CAU = 2;//ASSUMPTION: EPWMxA high sets vout = vdc;
    EPwm2Regs.AQCTLA.bit.CAD = 1;//ASSUMPTION: EPWMxA low  sets vout = 0;
    //AQCTLB
        //Probably not needed, to make sure deadband has to be worked out
    //AQSFRC
        //this register exists, just so you know
    //AQCSFRC
        //!!!continuous software force on outputs, very useful!!!
    //DBCTL
    EPwm2Regs.DBCTL.bit.IN_MODE  = 0;
    EPwm2Regs.DBCTL.bit.POLSEL   = 2;
    EPwm2Regs.DBCTL.bit.OUT_MODE = 3;
    //DBRED
    EPwm2Regs.DBRED = 600; //<=12us,  ASSUMPTION: SYSCLKOKUT == TBCLK

    //DBFED
    EPwm2Regs.DBFED = 600; //<=12us,  ASSUMPTION: SYSCLKOKUT == TBCLK

    //PCCTL
        //chopper register, not used for now

    //TZSEL
    EPwm2Regs.TZSEL.bit.OSHT1 = 1;

    //TZCTL
    EPwm2Regs.TZCTL.bit.TZA = 2; //force low ASSUMPTION EPWMxA turns off transisotr
    EPwm2Regs.TZCTL.bit.TZB = 2; //force low  ASSUMPTION EPWMxB turns off transistor

    //TZEINT
    EPwm2Regs.TZEINT.bit.OST = 1;

    //TZFLG
        //this register exists, just so you know

    //TZCLR
        //this register exists, just so you know

    //TZFRC
        //this register exists, just so you know

    //ETSEL
    EPwm2Regs.ETSEL.bit.SOCAEN = 1;
    EPwm2Regs.ETSEL.bit.SOCASEL = 2; //will happen if TBcounter equals to PRD
    EPwm2Regs.ETSEL.bit.INTEN = 1;
    EPwm2Regs.ETSEL.bit.INTSEL = 2; // will happen when SOCA happens

    //ETPS
    EPwm2Regs.ETPS.bit.SOCAPRD = 1;
    EPwm2Regs.ETPS.bit.INTPRD  = 0; //ENABLE AFTER IMPLEMENTING isr for pwm functions!!!

    //ETFLG
        //this register exists, just so you know

    //ETCLR
        //this register exists, just so you know

    //ETFRC
        //this register exists, just so you know

    //REMINDER: CTRMODE will be configured last after every ePWM is configured
    EDIS;
}

void InitEPwm3(void){
    EALLOW;

    //TBPRD
    EPwm3Regs.TBPRD = 7500; //10000Hz ==fPWM == 2*TBPRD*TBCLK <=Assuming that CTRMODE will be configuret as UPDOWN(2)

    //TBPHS
    EPwm3Regs.TBPHS.half.TBPHS = 2; //<====TODO calculate the phase value

    //TBCTR
    EPwm3Regs.TBCTR = 0; //<what should be the initial value?

    //TBCTL
        //CTRMODE will be set to 2 after every ePWM is configured
    EPwm3Regs.TBCTL.bit.FREE_SOFT = 2; //ePWM will be in free run mode
    EPwm3Regs.TBCTL.bit.CLKDIV = 0;    //150MHz == SYSCLKOUT == TBCLK
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = 0; //150MHz == SYSCLKOUT == TBCLK
    EPwm3Regs.TBCTL.bit.SYNCOSEL = 3;  //Synchronization pulse disabled
    EPwm3Regs.TBCTL.bit.PHSEN = 1; //Synchronization enabled

    //TBSTS
        //this register exists, just so you know

    //CMPA
    EPwm3Regs.CMPA.half.CMPA = 7500/2;//for test purposes, ASSMPTION: above CMPA value: vout = vdc; below CMPA value: vout = 0;

    //CMPB
    EPwm3Regs.CMPB = 7500; //this register is planned to be used as ADC starter some time in the future

    //CMPCTL
        //Shadow workings of the PWM module

    //CMPAHR
        //not used HighResolution part of counter-compare A value

    //AQCTLA
    EPwm3Regs.AQCTLA.bit.CAU = 2;//ASSUMPTION: EPWMxA high sets vout = vdc;
    EPwm3Regs.AQCTLA.bit.CAD = 1;//ASSUMPTION: EPWMxA low  sets vout = 0;
    //AQCTLB
        //Probably not needed, to make sure deadband has to be worked out
    //AQSFRC
        //this register exists, just so you know
    //AQCSFRC
        //!!!continuous software force on outputs, very useful!!!
    //DBCTL
    EPwm3Regs.DBCTL.bit.IN_MODE  = 0;
    EPwm3Regs.DBCTL.bit.POLSEL   = 2;
    EPwm3Regs.DBCTL.bit.OUT_MODE = 3;
    //DBRED
    EPwm3Regs.DBRED = 600; //<=12us,  ASSUMPTION: SYSCLKOKUT == TBCLK

    //DBFED
    EPwm3Regs.DBFED = 600; //<=12us,  ASSUMPTION: SYSCLKOKUT == TBCLK

    //PCCTL
        //chopper register, not used for now

    //TZSEL
    EPwm3Regs.TZSEL.bit.OSHT1 = 1;

    //TZCTL
    EPwm3Regs.TZCTL.bit.TZA = 2; //force low ASSUMPTION EPWMxA turns off transistor
    EPwm3Regs.TZCTL.bit.TZB = 2; //force low ASSUMPTION EPWMxB turns off transistor

    //TZEINT
    EPwm3Regs.TZEINT.bit.OST = 1;

    //TZFLG
        //this register exists, just so you know

    //TZCLR
        //this register exists, just so you know

    //TZFRC
        //this register exists, just so you know

    //ETSEL
    EPwm3Regs.ETSEL.bit.SOCAEN = 1;
    EPwm3Regs.ETSEL.bit.SOCASEL = 2; //will happen if TBcounter equals to PRD
    EPwm3Regs.ETSEL.bit.INTEN = 1;
    EPwm3Regs.ETSEL.bit.INTSEL = 2; // will happen when SOCA happens

    //ETPS
    EPwm3Regs.ETPS.bit.SOCAPRD = 1;
    EPwm3Regs.ETPS.bit.INTPRD  = 0; //ENABLE AFTER IMPLEMENTING isr for pwm functions!!!

    //ETFLG
        //this register exists, just so you know

    //ETCLR
        //this register exists, just so you know

    //ETFRC
        //this register exists, just so you know

    //REMINDER: CTRMODE will be configured last after every ePWM is configured
    EDIS;
}

//
// End of file
//

