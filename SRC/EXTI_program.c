/*
 * EXTI_program.c
 *
 *  Created on: Mar 5, 2024
 *      Author: DELL
 */

#include"../include/LIB/STD_TYPES_GCC.h"
#include"../include/LIB/BIT_MATH_GCC.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/MCAL/EXTI/EXTI_interface.h"
#include "../include/MCAL/EXTI/EXTI_private.h"
#include "../include/MCAL/EXTI/EXTI_configuration.h"

#define NULL 0

void(*EXTI0_CALLBACK) (void)=NULL;
void(*EXTI1_CALLBACK) (void)=NULL;
void(*EXTI2_CALLBACK) (void)=NULL;

void MEXTI_voidConfig(u8 A_u8EXTI, u8 A_u8SenseMode)
{
	switch(A_u8EXTI)
	{
	case EXTI0:   MCUCR&=~(SENSE_MODE_MASK<<EXTI0_SENSE_BIT);
	              MCUCR|=(A_u8SenseMode<<EXTI0_SENSE_BIT);
	              break;

	case EXTI1:   MCUCR&=~(SENSE_MODE_MASK<<EXTI1_SENSE_BIT);
	              MCUCR|=(A_u8SenseMode<<EXTI1_SENSE_BIT);
	              break;

	case EXTI2:
		switch(A_u8SenseMode)
	{
		case RISING_EDGE:  SET_BIT(MCUCSR,EXTI2_SENSE_BIT);  break;
		case FALLING_EDGE: CLR_BIT(MCUCSR,EXTI2_SENSE_BIT);  break;
	}


	}
}
void MEXTI_voidEnable(u8 A_u8EXTI)
{
	switch(A_u8EXTI)
	{
	case EXTI0:   SET_BIT(MCUCR,EXTI0_ENABLE_BIT);
	              break;

	case EXTI1:   SET_BIT(MCUCR,EXTI1_ENABLE_BIT);
                  break;

	case EXTI2:   SET_BIT(MCUCSR,EXTI2_ENABLE_BIT);
			      break;
    }
}
void MEXTI_voidDisable(u8 A_u8EXTI)
{
	switch(A_u8EXTI)
	{
	case EXTI0:   CLR_BIT(MCUCR,EXTI0_DISABLE_BIT);
	              break;

	case EXTI1:   CLR_BIT(MCUCR,EXTI1_DISABLE_BIT);
                  break;

	case EXTI2:   CLR_BIT(MCUCSR,EXTI2_DISABLE_BIT);
			      break;
    }
}

void HEXTI_voidSetCallBack(u8 A_u8EXTI, void (*PtrToFunc) (void))
{
	if(PtrToFunc!=NULL)
	{
	switch(A_u8EXTI)
	{
	case EXTI0:   EXTI0_CALLBACK=PtrToFunc;
	              break;

	case EXTI1:   EXTI1_CALLBACK=PtrToFunc;
                  break;

	case EXTI2:   EXTI2_CALLBACK=PtrToFunc;
			      break;
    }
	}
}



void __vector1(void) __attribute((signal));
void __vector1(void)
{
	if(EXTI0_CALLBACK!=NULL)
	{
		EXTI0_CALLBACK();
	}
}

void __vector2(void) __attribute((signal));
void __vector2(void)
{
	if(EXTI1_CALLBACK!=NULL)
	{
		EXTI1_CALLBACK();
	}
}

void __vector3(void) __attribute((signal));
void __vector3(void)
{
	if(EXTI2_CALLBACK!=NULL)
	{
		EXTI2_CALLBACK();
	}
}









