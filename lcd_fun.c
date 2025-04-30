#include "lcd_fun.h"
void LCD_cmd(unsigned char data)
{
	//clear data pins
	IOCLR0 |=0XFF<<DATA;
	//sending the data
	IOSET0 = data<<DATA;
	// select the RS functionality RS=1 fot command reg RS=0 data reg
	IOCLR0 = 1<<RS;
	// select the RW functionality RW=0 for writr RW=1 for read
	IOCLR0 = 1<<RW;
	// set the EN pin (high)
	IOSET0 = 1<<EN;
	// give the delay >1 ms
	delay_ms(1);
	// clear the EN pin (low)
	IOCLR0 = 1<<EN;
	delay_ms(2);
}
void LCD_data(unsigned char data)
{
	//clear data pins
	IOCLR0 |=0XFF<<DATA;
	//sending the data
	IOSET0 = data<<DATA;
	// select the RS functionality RS=1 fot command reg RS=0 data reg
	IOSET0 = 1<<RS;
	// select the RW functionality RW=0 for writr RW=1 for read
	IOCLR0 = 1<<RW;
	// set the EN pin (high)
	IOSET0 = 1<<EN;
	// give the delay >1 ms
	delay_ms(1);
	// clear the EN pin (low)
	IOCLR0 = 1<<EN;
	delay_ms(2);
}
void LCD_init(void)
{
	 // set the direction of data pins (D0-D7) and RS , RW and EN
		IODIR0|=( (0XFF << DATA) | (1 << RS) |(1 << RW) |(1 << EN) );	
		// give power on delay
	delay_ms(20);
		// function set command
	LCD_cmd(0x30);
		// delay >4.5 ms
	delay_ms(2);
		//function set command
	LCD_cmd(0x30);
		// delay of >100ms
	delay_us(100);
	  // function set command
	LCD_cmd(0x30);
	  //function set with 8 bit or 4 bit mode and lines(1/2)
	LCD_cmd(0x38);   // 0 0 1 1 N F * *
								 // N=NO of display line 1(0)/2(1)
								 // F= charactor font 5x10(1)/5x7(0)
									//(0 0 1 1 1 0 0 0) N=1 F=0
	
  //display (on/off) cursor (on/off)
	LCD_cmd(0x0F); // 0 0 0 0 1 D C B 
									// D=Turn Display ON(1)/OFF(0)
									//C=Turn Cursor ON(1)/OFF(0)
									//B=Cursor Blink ON(1)/OFF(0)
									//0 0 0 0 1 1 1 1 (D=1,C=1,B=1)
	  
		//clear the lcd
		LCD_cmd(0x01); //0 0 0 0 0 0 0 1
  	//increment the cursor
		LCD_cmd(0x07); // 0 0 0 0 0 1 ID S
									 // ID=Increment the Cursor after Each Byte Written to Display
									 // S=Shift Display when Byte Written to Display
									 //0 0 0 0 0 1 1 0 (ID=1 S=0) 
	
}

void LCD_S32(int num)
{
	
	int a[10];
	int i=0;
	if(num==0)
	{
		//display 0 on lcd
		LCD_data('0');
	}
	else
	{
		//extract digit by digit and store it into array
		while(num)
		{
			a[i++] = (num%10)+48;
			num = num/10;
		}
		//display digit by digit on LCD 
		for(--i;i>=0;i--)
		{
			LCD_data(a[i]);	
		}
	}
}


void F32LCD(float fNum,int nDP)
{
	int iNum;
	if(fNum<0.0)
	{
		//display '-' on LCD
		LCD_data('-');		
		//change the sign of the given number
		fNum = -fNum;	
	}
	//assign float number to integer variable	
	iNum = fNum;	
	//display integer value on LCD
	LCD_S32(iNum);
	//display '.' on LCD
	LCD_data('.');
	//extract digit by digit after decimal point and display it on LCD up to given no.of digits after decimal point
	while(nDP)
	{
		fNum = (fNum-iNum)*10;
		iNum = fNum;
		LCD_data(iNum+0x30);
		nDP--;
	}
}

