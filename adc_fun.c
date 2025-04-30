#include "adc_fun.h"
void ADC_init(void)
{
	//power on the adc using PCON reg (BIT 12)
	PCON|=1<<21;
	//enable adc channel SCL (BIT 0-7)
	ADCR|=(1<<0);
	//set the adc clock CLKDIV (BIT 8-15)
	ADCR|=13<<8;
	//power up the adc PDN BIT (BIT 21)
	ADCR|=1<<21;
}

unsigned int ADC_read(void)
{
//start the conversion using START BIT (24-26)
	ADCR|=1U<<24;
//weithing for the DONE BIT 31
	while((ADDR &(1U<<31)));
//extract the 10 bit data using using 0x3FF	
	return ((ADDR >>6)&0X3FF);
}
