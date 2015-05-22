#include<msp430f2013.h>  
/*
This header file to be included for all msp430f2013 versions
*/
volatile int i;
void configtime(void){  
/*
This Function sets the clocksource, 8MHz for precision requiring jobs and 3 to 12Khz for sleep mode and other non precise mode
refer datasheet*/

BCSCTL1 = CALBC1_8MHZ; //Configure Basic clock source control 1 to calibratedConstant1 8 MHz;
DCOCTL = CALDCO_8MHZ; // Configure Digital clock oscillator to 8 MHz
BCSCTL3 = LFXT1S_2;  //  Set Basic clock source control 3 to 12 Khz
}

void main(){
WDTCTL = WDTPW+WDTHOLD;         // MSP430 has internal watch dog timer inbuilt. You have to disable it, or send it alive pulse in short duration
configtime();
P1DIR=0xff;                    // This sets the P1 Port to Output  
P1OUT=0xff;                   // Output is set to one 
while(1){             
P1OUT=~P1OUT;                  //Blink
for(i=0;i<32700;i++);         //Delay 

}

}
