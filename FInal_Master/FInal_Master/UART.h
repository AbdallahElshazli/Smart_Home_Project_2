/*
 * UART.h
 *
 * Created: 10/4/2020 1:23:02 PM
 *  Author: ALLaH
 */ 


#ifndef UART_H_
#define UART_H_


#include "DIO.h"

void UART_Init(void);

void UART_SendByte(uint8 );

void UART_SendString(uint8* str);

uint8 UART_ReceiveByte(void);

uint8* UART_ReceiveString(void);


#endif /* UART_H_ */