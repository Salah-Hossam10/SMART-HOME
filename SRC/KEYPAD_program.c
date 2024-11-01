/*
 * KEYPAD_program.c
 *
 *  Created on: Feb 29, 2024
 *      Author: DELL
 */
#include <util/delay.h>
#include"../include/LIB/STD_TYPES_GCC.h"
#include"../include/LIB/BIT_MATH_GCC.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/HAL/KEYPAD/KEYPAD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_private.h"
#include "../include/HAL/KEYPAD/KEYPAD_configuration.h"
#define F_CPU 8000000UL




u8 static global_u8SArrOfRows[ROW_NUMBER]= KEYPAD_ROWS;
u8 static global_u8SArrOfColumns[COLUMN_NUMBER]= KEYPAD_COLUMNS;


u8 HKEYPAD_u8KeyPressed(void)
{
u8 local_u8KeyValue=KEY_NOT_PRESSED;
u8 local_u8RowCounter,local_u8ColumnCounter,local_u8PinValue,FLAG=FLAG_DOWN;
for(local_u8RowCounter=0;local_u8RowCounter<ROW_NUMBER;local_u8RowCounter++)
{
MDIO_voidSetPinValue(KEYPAD_PORT,global_u8SArrOfRows[local_u8RowCounter],DIO_LOW);
for(local_u8ColumnCounter=0;local_u8ColumnCounter<COLUMN_NUMBER;local_u8ColumnCounter++)
          {
	local_u8PinValue=MDIO_voidGetPinValue(KEYPAD_PORT,global_u8SArrOfColumns[local_u8ColumnCounter]);
	if(local_u8PinValue==KEY_PRESSED)
	{

		_delay_ms(KEYPAD_DEPOUNCING_EFFECT_IN_MS);
		local_u8PinValue=MDIO_voidGetPinValue(KEYPAD_PORT,global_u8SArrOfColumns[local_u8ColumnCounter]);
	while(local_u8PinValue==KEY_PRESSED)
	{
		local_u8PinValue=MDIO_voidGetPinValue(KEYPAD_PORT,global_u8SArrOfColumns[local_u8ColumnCounter]);
	}

	local_u8KeyValue=global_u8ArrOfKeyValues[local_u8RowCounter][local_u8ColumnCounter];
	FLAG=FLAG_UP;
	break;

	}



          }
MDIO_voidSetPinValue(KEYPAD_PORT,global_u8SArrOfRows[local_u8RowCounter],DIO_HIGH);
if(FLAG==FLAG_UP)
{
break;
}
}
return local_u8KeyValue;
}







