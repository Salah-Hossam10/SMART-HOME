/*
 * GI_program.c
 *
 *  Created on: Mar 5, 2024
 *      Author: DELL
 */

#include"../include/LIB/STD_TYPES_GCC.h"
#include"../include/LIB/BIT_MATH_GCC.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/MCAL/GI/GI_interface.h"
#include "../include/MCAL/GI/GI_private.h"
#include "../include/MCAL/GI/GI_configuration.h"

void MGI_voidEnable(void)
{

	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}

void MGI_voidDisable(void)
{

	CLR_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}

