/*
 * DC_Mototr.c
 *
 * Created: 10/7/2020 2:39:11 PM
 *  Author: ALLaH
 */ 

#include "DC_Motor.h"

void DC_Motor_Init(void)
{
	DIO_SetPinDir(DIO_PORTC ,DIO_PIN3 , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(DIO_PORTC ,DIO_PIN4 , DIO_PIN_OUTPUT);
	
	PWM0_Init();
	
}



void DC_Motor_SetDir(DC_MOTOR_DIR dir)
{
	switch(dir) 
	{
		case CLOCK_WISE_DIR :
		
		DIO_SetPinValue(DIO_PORTC ,DIO_PIN3 , DIO_PIN_HIGH);
		DIO_SetPinValue(DIO_PORTC ,DIO_PIN4 , DIO_PIN_LOW);
		
		break;
		
		case ANTI_CLOCK_WISE_DIR :
		
		DIO_SetPinValue(DIO_PORTC ,DIO_PIN3 , DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTC ,DIO_PIN4 , DIO_PIN_HIGH);
		
		break;
		
		default:
		break;
	}
	
	
	
}
void DC_Motor_SetSpeed(uint8 speed)
{
	speed *= 10 ;
	
	PWM0_Generate(speed); 
	
}



void DC_Motor_Start(void)
{
	
	
	PWM0_Start();
	
}
void DC_Motor_Stop(void)
{
	DIO_SetPinValue(DIO_PORTC ,DIO_PIN3 , DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTC ,DIO_PIN4 , DIO_PIN_LOW);
	
}