//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {

	unsigned short sampleLeft;								// Just to analyze the values
	unsigned short sampleRight;
	unsigned short sampleFront;
//	unsigned char i = 0;										// index into sample array

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0 | BIT6;										// Set the LEDs as output

	while(1) {

		// Configure P1.5 to be the ADC input, left sensor
		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_5 | ADC10DIV_3 ;						// Channel 5, ADC10CLK/4
		ADC10AE0 = BIT5;		 								// Make P1.5 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		sampleLeft = ADC10MEM;									// collect that 10-bit value

		// Configure P1.3 to be the ADC input, front sensor
		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_3 | ADC10DIV_3 ;						// Channel 3, ADC10CLK/4
		ADC10AE0 = BIT3;		 								// Make P1.3 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		sampleFront = ADC10MEM;									// collect that 10-bit value

		// Configure P1.4 to be the ADC input, right sensor
		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
		ADC10AE0 = BIT4;		 								// Make P1.4 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		sampleRight = ADC10MEM;								// collect that 10-bit value

		if (sampleRight > 0x0250)	P1OUT |= BIT0;
		else if (sampleLeft > 0x0250)		P1OUT |= BIT6;
		else if (sampleFront > 0x0300)	P1OUT |= BIT0|BIT6;
		else					P1OUT &= ~(BIT0 | BIT6);

//		i = (i+1) & 0xF;							// This is a mod 16 increment
	} // end infinite loop

} // end main
