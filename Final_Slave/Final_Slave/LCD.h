/*
 * LCD.h
 *
 * Created: 10/4/2020 1:25:54 PM
 *  Author: ALLaH
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "LCD_Cfg.h"
#include "BIT_Math.h"
#include "DIO.h"



void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteChar(uint8 data);

void LCD_GoTo(uint8 row, uint8 col);

void LCD_WriteString(uint8* str);

void LCD_WriteInteger(sint32 intgr);

void LCD_Clear(void);


#endif /* LCD_H_ */