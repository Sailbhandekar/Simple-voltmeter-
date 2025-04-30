#include <LPC21xx.H>
#include "lcd_fun.h"
#include "adc_fun.h"
int main()
{
	int data;
	float voltage;
	LCD_init();
	ADC_init();
	LCD_cmd(0X01);
	while(1)
	{
		LCD_cmd(0x0C);
		data=(int)ADC_read();
		voltage = data * (3.3 / 1023);  // Convert ADC value to voltage
    voltage = voltage * 8.9; 
		LCD_cmd(0x80);
		F32LCD(voltage,2);
		LCD_cmd(0x85);
		LCD_data('V');
	}
}
