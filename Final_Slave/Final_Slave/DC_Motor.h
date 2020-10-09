/*
 * DC_Motor.h
 *
 * Created: 10/7/2020 2:38:53 PM
 *  Author: ALLaH
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Timer.h"
#include "DIO.h"


typedef enum 
{
	CLOCK_WISE_DIR,
	ANTI_CLOCK_WISE_DIR
	}DC_MOTOR_DIR;


void DC_Motor_Init(void);

void DC_Motor_SetDir(DC_MOTOR_DIR dir);

void DC_Motor_SetSpeed(uint8 speed);

void DC_Motor_Start(void);

void DC_Motor_Stop(void);





#endif /* DC_MOTOR_H_ */