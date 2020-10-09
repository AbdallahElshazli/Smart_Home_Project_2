/*
 * LED.c
 *
 * Created: 10/5/2020 3:40:04 PM
 *  Author: ALLaH
 */ 


#include "LED.h"



void LED0_Init(void)
{
	DIO_SetPinDir(DIO_PORTC, DIO_PIN0 , DIO_PIN_OUTPUT);
	
}


void LED1_Init(void)
{
	DIO_SetPinDir(DIO_PORTC, DIO_PIN1 , DIO_PIN_OUTPUT);
	
}


void LED2_Init(void)
{
	DIO_SetPinDir(DIO_PORTC, DIO_PIN2 , DIO_PIN_OUTPUT);
	
}



void LED0_ON(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN0 ,  DIO_PIN_HIGH);
}


void LED1_ON(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN1 ,  DIO_PIN_HIGH);
}


void LED2_ON(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN2 ,  DIO_PIN_HIGH);
}




void LED0_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN0 ,  DIO_PIN_LOW);
}


void LED1_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN1 ,  DIO_PIN_LOW);
}


void LED2_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN2 ,  DIO_PIN_LOW);
}



void LED0_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN0);
}


void LED1_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN1);
}


void LED2_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN2);
}