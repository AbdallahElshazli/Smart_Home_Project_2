/*
 * FInal_Master_1.c.c
 *
 * Created: 10/4/2020 1:08:51 PM
 * Author : ALLaH
 */ 

#include "UART.h"
#include "SPI.h"
#include "Smart_Home_Cfg.h"
#define  F_CPU  16000000
#include <util/delay.h>


int main(void)
{
    
	
	 uint8 Uart_Data = 0 ;

	
	
	//SPI Master Initializations
	SPI_MasterInit();
	SPI_InitTrans();
	 
	 // UART Initialization
	 UART_Init();   
	 
	 
	 
	 
	 while (1)
	 {
		Uart_Data = UART_ReceiveByte();
		 
		  
		 
		 
		 switch( Uart_Data)
		 {

			 case ROOM1_LED_ON :
        
		     SPI_transive(ROOM1_LED_ON);
		
			 break;

			 case ROOM2_LED_ON :

			  SPI_transive(ROOM2_LED_ON);

			 break;

			 case ROOM3_LED_ON :

			  SPI_transive(ROOM3_LED_ON);

			 break;

			 case ROOM1_LED_OFF :

			 SPI_transive(ROOM1_LED_OFF);

			 break;
             
			 
	        case ROOM2_LED_OFF :
			
			 SPI_transive(ROOM2_LED_OFF);

			break;
			
			
			case ROOM3_LED_OFF :
			
			 SPI_transive(ROOM3_LED_OFF);
			
			break;
			
			
			

			default:
			break;
		 }
		 
	 }
	
}
