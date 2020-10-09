/*
 * ATMEGA32_Regs.h
 *
 * Created: 10/4/2020 1:13:04 PM
 *  Author: ALLaH
 */ 


#ifndef ATMEGA32_REGS_H_
#define ATMEGA32_REGS_H_

#define Atmega32		0
#define Atmega328P		1

#define Chip_Type			Atmega32




#include "STD.h"

/******************************************* External Registers **************************************/


#define SREG   (*(volatile uint8*)(0x5F))

#define GICR   (*(volatile uint8*)(0x5B))

#define GIFR   (*(volatile uint8*)(0x5A))

#define MCUCR  (*(volatile uint8*)(0x55))

#define MCUCSR (*(volatile uint8*)(0x54))


/******************************************* DIO Registers **************************************/


#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))
#define DDRA  (*(volatile uint8*)(0x3A))

#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))
#define DDRB  (*(volatile uint8*)(0x37))

#define PORTC (*(volatile uint8*)(0x35))
#define PINC  (*(volatile uint8*)(0x33))
#define DDRC  (*(volatile uint8*)(0x34))

#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))
#define DDRD  (*(volatile uint8*)(0x31))

/*********************************    ADC    *********************************************/

#define ADMUX           (*(volatile uint8 *)(0x27))
#define ADCSRA          (*(volatile uint8 *)(0x26))
#define ADCH            (*(volatile uint8 *)(0x25))
#define ADCL            (*(volatile uint8 *)(0x24))
#define ADC_Adjust      (*(volatile uint16*)(0x24))
#define SFIOR           (*(volatile uint8 *)(0x50))

/**********************************  Timer0   **********************************************/

#define TCNT0  (*(volatile uint8*)(0x52))
#define TCCR0  (*(volatile uint8*)(0x53))
#define OCR0   (*(volatile uint8*)(0x5C))
#define TIMSK  (*(volatile uint8*)(0x59))
#define TIFR   (*(volatile uint8*)(0x58))

/************************************  Timer1  **********************************************/
#define TCCR1A (*(volatile uint8* )(0x4F))
#define TCCR1B (*(volatile uint8* )(0x4E))
#define OCR1A  (*(volatile uint16*)(0x4A))
#define ICR1   (*(volatile uint16*)(0x46))

/*************************************  Timer2  ************************************************/

#define TCCR2  (*(volatile uint8* )(0x45))
#define OCR2   (*(volatile uint8* )(0x43))

/************************************ UART   ***************************************************/

#define UBRRH   (*(volatile uint8*)0x40)
#define UBRRL  ( *(volatile uint8*)0x29)
#define UCSRA   (*(volatile uint8*)0x2B)
#define UCSRB   (*(volatile uint8*)0x2A)
#define UCSRC  ( *(volatile uint8*)0x40)
#define UDR    ( *(volatile uint8*)0x2C)

/**********************************   SPI  ******************************************************/

typedef struct
{
	uint8 SPR0 : 1;
	uint8 SPR1 : 1;
	uint8 CPHA : 1;
	uint8 CPOL : 1;
	uint8 MSTR : 1;
	uint8 DORD : 1;
	uint8 SPE  : 1;
	uint8 SPIE : 1;
}SPCR_REG;


typedef struct
{
	SPCR_REG SPCR;
	uint8    SPSR;
	uint8    SPDR;
}SPI_REG;


#if (Chip_Type == Atmega32)

#define		SPI	 ((volatile SPI_REG*)(0x2D)) //Atmega32

#elif (Chip_Type == Atmega328P)

#define		SPI	 ((volatile SPI_REG*)(0x4C)) //Atmega328P

#endif


#endif /* ATMEGA32_REGS_H_ */