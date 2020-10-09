/*
 * Final_Slave.c.c
 *
 * Created: 10/6/2020 3:00:09 PM
 * Author : ALLaH
 */ 

#include "SPI.h"
#include "LED.h"
#include "LCD.h"
#include "DC_Motor.h"
#include "Smart_Home_Cfg.h"

#include <util/delay.h>


int main(void)
{
	uint8 Received_Data = 0 ;
	uint8 Trans_Data = 0 ;
	
	
	
	// LCD Initialization
	LCD_Init();
	
	
	LCD_GoTo(0,5);
	LCD_WriteString("Welcome");
	
	LCD_GoTo(1,3);
	LCD_WriteString("to our home");
	_delay_ms(1500);
	LCD_Clear();
	
	LCD_GoTo(0,5);
	LCD_WriteString("Smile !");
	
	//SPI Slave Initializations
	SPI_SlaveInit();
	
	
	
	
	//DC_Motor Initialization
	DC_Motor_Init();
	
	
	
	// LEDS Initializations
	LED0_Init();
	LED1_Init();
	LED2_Init();
	
	
	
    while (1) 
    {
		
		Received_Data = SPI_transive(Trans_Data);
		
		
		switch(Received_Data)
		{

			case ROOM1_LED_ON :

			LED0_ON();

			break;

			case ROOM2_LED_ON :

			LED1_ON();
			break;

			case ROOM3_LED_ON :

			LED2_ON();

			break;

			case ROOM1_LED_OFF :
			
			LED0_OFF();

			break;
			
			
			case ROOM2_LED_OFF :
			
			LED1_OFF();

			break;
			
			
			case ROOM3_LED_OFF :
			
			LED2_OFF();
			
			break;
			
			
			case ROOM1_FAN_ON :
			
			DC_Motor_SetDir(CLOCK_WISE_DIR );
			DC_Motor_SetSpeed(10);
			DC_Motor_Start();
			
			break;
			
			
			case ROOM1_FAN_OFF :
			
			
			DC_Motor_Stop();
			
			

			default:
			break;
		}
		
		
		
		
    }
}

