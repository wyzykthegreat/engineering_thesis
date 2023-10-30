// TI File $Revision: /main/5 $
// Checkin $Date: October 23, 2007   13:34:09 $
//###########################################################################
//
// FILE:	DSP2833x_Adc.c
//
// TITLE:	DSP2833x ADC Initialization & Support Functions.
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
// Defines
//
#define ADC_usDELAY  5000L

//
// InitAdc - This function initializes ADC to a known state.
//
void 
InitAdc(void)
{
    extern void DSP28x_usDelay(Uint32 Count);

    //
    //                          *IMPORTANT*
    // The ADC_cal function, which  copies the ADC calibration values from 
    // TI reserved OTP into the ADCREFSEL and ADCOFFTRIM registers, occurs 
    // automatically in the Boot ROM. If the boot ROM code is bypassed during
    // the debug process, the following function MUST be called for the ADC to
    // function according to specification. The clocks to the ADC MUST be 
    // enabled before calling this function. See the device data manual and/or
    // the ADC Reference Manual for more information.
    //
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
    ADC_cal();
    EDIS;

    //
    // To powerup the ADC the ADCENCLK bit should be set first to enable
    // clocks, followed by powering up the bandgap, reference circuitry, and 
    // ADC core. Before the first conversion is performed a 5ms delay must be
    // observed after power up to give all analog circuits time to power up 
    // and settle
    //

    //
    // Please note that for the delay function below to operate correctly the
    // CPU_RATE define statement in the DSP2833x_Examples.h file must
    // contain the correct CPU clock period in nanoseconds.
    //
    AdcRegs.ADCTRL3.all = 0x00E0;  // Power up bandgap/reference/ADC circuits
    DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels

    //Current configuration ADC clock is 12.5MHz, width of SOC pulse is 15 => 80ns*10 = 800ns->0.8us

    //ADCTRL1 ADC Control Register 1
    AdcRegs.ADCTRL1.bit.ACQ_PS = 9; //Acquisition window size
    AdcRegs.ADCTRL1.bit.CPS = 0; //FCLK/2 check adcclkps in ADCTRL3 and check SysCtrlRegs.HISPCP.bit.HSPCLK in InitSysCtrl()
    AdcRegs.ADCTRL1.bit.CONT_RUN = 0; //Sequencer stops after reaching end of EOS
    AdcRegs.ADCTRL1.bit.SEQ_CASC = 1; //Operating as 1 16-state sequencer

    //ADCTRL2 ADC Control Register 2
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0;

    //ADCMAXCONV ADC Maximun Conversion Channels
    AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 3; //Vref, U phase, V phase, W phase, Bus Value

    //ADCCHELSEQ1
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;  //ADC-A0 Vref (1.8V)
    AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1;  //ADC-A1 Ifb-U (low side phase U current sensor)
    AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x9;  //ADC-B1 Ifb-V (low side phase V current sensor)
    AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 0x3;  //ADC-A3 Ifb-W (low side phase W current sensor)

    //ADCCHSELSEQ2
    AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 0x2;  //ADC-A2 Ifb-Sum (return current on DC bus sensor)
    AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 0x0;  //ADC-A0 Vref (1.8V)
    AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 0xF;  //ADC-B7 Vfb-U (U-phase voltage sensor)
    AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 0xE;  //ADC-B6 Vfb-V (V-phase voltage sensor)

    //ADCCHSELSEQ3
    AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 0xC;  //ADC-B4 Vfb-W (W-phase voltage sensor)
    AdcRegs.ADCCHSELSEQ3.bit.CONV09 = 0x7;  //ADC-A7 Vfb-Bus (DC Bus voltage sensor)

    //ADCCHSELSEQ4
        //this register exists, just so you know

    //ADCASEQSR
        //this register exists, just so you know

    //ADCRESULT_0 - ADCRESULT_15
        //this register exists, just so you know

    //ADCTRL3
    AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;
    AdcRegs.ADCTRL3.bit.SMODE_SEL = 0;

    //ADCST
        //this register exists, just so you know

    //ADCREFSEL
    AdcRegs.ADCREFSEL.bit.REF_SEL = 0;

    //ADCOFFTRIM
        //this register exists, just so you know
}

//
// End of file
//

