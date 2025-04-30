#ifndef _LCD_FUN_H
#define _LCD_FUN_H
#include <LPC21xx.H>
#include "delay.h"


#define DATA 0
#define RS 8
#define RW 9
#define EN 10


void LCD_init(void);
void LCD_cmd(unsigned char);
void LCD_data(unsigned char);
void LCD_S32(int);
void F32LCD(float,int);

#endif
