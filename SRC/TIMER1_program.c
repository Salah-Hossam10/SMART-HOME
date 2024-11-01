/*
 * TIMER1_program.c
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


#define TCCR1A_WGM10 0
#define TCCR1A_WGM11 1
#define TCCR1B_WGM12 3
#define TCCR1B_WGM13 4

#define TCCR1A_COM1A0 6
#define TCCR1A_COM1A1 7

#define TCCR1B_CS10 0
#define TCCR1B_CS11 1
#define TCCR1B_CS12 2

#define NULL 0
void (*TIMER1_CALLBACK)(void) = NULL;


void MTIMER1_voidInit(void)
{
	//Waveform Generation Mode
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	//Compare Output Mode for Compare unit A
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	//SET ICR1 VALUE
	ICR1=19999;
	//SET OCR1A VALUE
	OCR1A=1500;
	//CLK CONFIGURATION /8
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}

void MTIMER1_voidSetOCR1Value(u16 A_u16Angle)
{
	OCR1A=A_u16Angle;
}

void MTIMER1_voidSetTimer1Value(u16 A_u16Value)
{
	TCNT1=A_u16Value;
}

u16 MTIMER1_u16ReadTimerValue(void)
{
	return TCNT1;
}

u16 MTIMER1_u16ReadTimer1Value(void)
{
	return ICR1;
}

#define TIMSK_TICIE1 5
#define TCCR1B_ICES1 6

void MTIMER1_voidEnableICU (void)
{
	//Input Capture Interrupt Enable
	SET_BIT(TIMSK,TIMSK_TICIE1);
	//Input Capture Edge Select
	SET_BIT(TCCR1B,TCCR1B_ICES1);
}

void MTIMER1_voidDisableICU (void)
{
	//Input Capture Interrupt Enable
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

void MTIMER1_voidSetCallBack(void (*PtrToFunc)(void))
{
	if(PtrToFunc!=NULL)
	{
		TIMER1_CALLBACK=PtrToFunc;
	}
}

void __vector_6 (void) __attribute__ ((signal));
void __vector_6 (void)
{
	if(TIMER1_CALLBACK!=NULL)
	{
		TIMER1_CALLBACK();
	}
}

#define ICU_FALLING_EDGE 0
#define ICU_RISING_EDGE  1

void MTIMER1_voidSetTrigger(u8 A_u8Trigger)
{
	switch(A_u8Trigger)
	{
	case ICU_FALLING_EDGE: CLR_BIT(TCCR1B,TCCR1B_ICES1); break;
	case ICU_RISING_EDGE:  SET_BIT(TCCR1B,TCCR1B_ICES1); break;
	}
}

