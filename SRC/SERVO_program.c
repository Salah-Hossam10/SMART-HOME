/*
 * SERVO_program.c
 *
 *  Created on: Apr 26, 2024
 *      Author: DELL
 */

#include "../include/LIB/STD_TYPES_GCC.h"
#include "../include/LIB/BIT_MATH_GCC.h"

#include "../include/MCAL/DIO/DIO_interface.h"


#include "../include/MCAL/TIMER1/TIMER1_interface.h"
#include "../include/MCAL/TIMER1/TIMER1_private.h"
#include "../include/MCAL/TIMER1/TIMER1_configuration.h"

void HSERVO_voidSetServoAngle(u16 A_u16Angle)
{
	u16 local_u16OCR1Value=((A_u16Angle*1000UL)/180)+999;
	MTIMER1_voidSetOCR1Value(local_u16OCR1Value);
}
