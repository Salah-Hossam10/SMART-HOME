/*
 * LED_program.c
 *
 *  Created on: Mar 5, 2024
 *      Author: DELL
 */
#include <util/delay.h>
#include"../include/LIB/STD_TYPES_GCC.h"
#include"../include/LIB/BIT_MATH_GCC.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/HAL/LED/LED_interface.h"
#include "../include/HAL/LED/LED_private.h"
#include "../include/HAL/LED/LED_configuration.h"

void HLED_voidTurnOn(u8 A_u8PortID, u8 A_u8PinId)
{
    MDIO_voidSetPinValue(A_u8PortID, A_u8PinId, LED_ON);
}
void HLED_voidTurnOff(u8 A_u8PortID, u8 A_u8PinId)
{
    MDIO_voidSetPinValue(A_u8PortID, A_u8PinId, LED_OFF);
}

// LED_ON - LED_OFF
void HLED_voidSetLedStatus(u8 A_u8PortID, u8 A_u8PinId, u8 A_u8LedStatus)
{
    MDIO_voidSetPinValue(A_u8PortID, A_u8PinId, A_u8LedStatus);
}

void HLED_voidToggleLed(u8 A_u8PortID, u8 A_u8PinId)
{
	MDIO_voidTogglePinValue(A_u8PortID, A_u8PinId)	;
}
