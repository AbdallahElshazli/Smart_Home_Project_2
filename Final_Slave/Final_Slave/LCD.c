/*
 * LCD.c
 *
 * Created: 10/4/2020 1:25:34 PM
 *  Author: ALLaH
 */ 
#include "LCD.h"
#define F_CPU 8000000
#include <util/delay.h>



void LCD_Init(void)
{
	#if LCD_MODE == 8
	
	DIO_SetPinDir(LCD_8BIT_CMD_PORT ,LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT ,LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT ,LCD_RS_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_DATA_PORT , DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0E);
	LCD_WriteCommand(0x01);
	
	_delay_ms(20);
	
	LCD_WriteCommand(0x38);
	
	_delay_ms(5);
	
	#elif LCD_MODE == 4
	
	DIO_SetPinDir(LCD_4BIT_CMD_PORT ,LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT ,LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT ,LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D4 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D5 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D6 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D7 , DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	

	
	
	#endif
	
}

void LCD_WriteCommand(uint8 cmd)
{
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_RS_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (cmd & 0xF0) | (PORTA & 0x0F);
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0x0F);
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
	
}


void LCD_WriteChar(uint8 data)
{
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_RS_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (data & 0xF0) ;
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (data << 4) ;
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteString(uint8* str)
{
	uint8 i = 0;
	
	while(str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}

void LCD_GoTo(uint8 row, uint8 col)
{
	uint8 pos[2] = {0x80 , 0xC0};
	
	LCD_WriteCommand(pos[row]+col);
	
}

void LCD_WriteInteger(sint32 intgr)
{

	sint32 y = 1;

	if(intgr < 0)
	{
		LCD_WriteChar('-');
		intgr *= -1;
	}

	while(intgr > 0)
	{
		y = ((y*10) + (intgr%10));
		intgr /= 10;
	}

	while(y > 1 )
	{
		LCD_WriteChar(((y%10)+48));
		y /= 10;
	}
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}