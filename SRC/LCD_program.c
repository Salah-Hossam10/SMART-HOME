/*
 * LCD_program.c
 *
 *  Created on: Mar 10, 2024
 *      Author: DELL
 */


#include <util/delay.h>
#include"../include/LIB/STD_TYPES_GCC.h"
#include"../include/LIB/BIT_MATH_GCC.h"


#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configuration.h"
#define F_CPU 8000000UL

void HLCD_voidSendData (u8 A_u8Data)
{
//RS---->1  RW----->0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
//Send Data To the LCD
    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);
//Set PUlse on E PIN with 2ms delay
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}
void HLCD_voidSendCommand (u8 A_u8Command)
{
//RS---->0  RW----->0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
//Send Data To the LCD
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

//Set PUlse on E PIN with 2ms delay
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}

void HLCD_voidInit(void)
{
	//Wait FOR more than 30ms after VDD rises to 4.5v
	_delay_ms(30);
	//Function Set
	HLCD_voidSendCommand(FUNCTION_SET);
	//Wait FOR more than 38us
	_delay_us(40);
   //DISPLAY ON/OFF
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	//Wait FOR more than 38us
	_delay_us(40);
	//DISPLAY clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//Wait FOR more than 1.53ms
	_delay_ms(2);
	//Entry Mode set
	HLCD_voidSendCommand(ENTRY_MODE_SET);

}
void HLCD_voidDisplayClear(void)
{
	//DISPLAY clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//Wait FOR more than 1.53ms
	_delay_ms(2);
}
void HLCD_voidSendString(u8 *A_pu8String)
{
   while(*A_pu8String>0)
  {
	   HLCD_voidSendData(*A_pu8String++);
  }
}


void HLCD_voidGoToPosition(u8 A_u8Row,u8 A_u8Column)
{
switch(A_u8Row)
{
case LCD_ROW_ONE: HLCD_voidSendCommand(LCD_ROW1_ADDRESS+A_u8Column); break;
case LCD_ROW_TWO: HLCD_voidSendCommand(LCD_ROW2_ADDRESS+A_u8Column); break;
default: break;
}
}

void HLCD_voidDisplayNumber(u32 A_u32Number)
{
u32 local_u32Number=1;
if(A_u32Number==0)
{
HLCD_voidSendCommand('0');
}
while(A_u32Number!=0)
{
	//1-->local_u32Number=(1*10)+(75%10)=10+5=15
	//2-->local_u32Number=(15*10)+(7%10)=150+7=157
	local_u32Number=((local_u32Number*10)+(A_u32Number%10));
	//1-->A_u32Number=75/10=7.5=7
	//2-->A_u32Number=7/10=0.7=0
	A_u32Number=A_u32Number/10;
}
while(local_u32Number!=1)
{
	//1-->(157%10)+48=7+48=55       55 by ASCII is 7
	//2-->(15% 10)+48=5+48=53       53 by ASCII is 5
	HLCD_voidSendData((local_u32Number%10)+48);
	//1-->157/10=15
	//2-->15/10=1.5=1
	local_u32Number=local_u32Number/10;
}
}

void HLCD_voidSpecialCharacter(u8 *A_pu8CharArr,u8 A_u8PatternNumber,u8 A_u8RowNumber,u8 A_u8ColumnNumber)
{
	u8 local_u8CGRAMAddress,local_u8Counter;
	/* Calculate CGRAM Address = Pattern Number * 8 */
	local_u8CGRAMAddress=A_u8PatternNumber*8;
	SET_BIT(local_u8CGRAMAddress,6);
	/* Send Command to set CGRAM Address */
	HLCD_voidSendCommand(local_u8CGRAMAddress);

	for(local_u8Counter=0;local_u8Counter<8;local_u8Counter++)
	{
		/* Send byte from character array */
		HLCD_voidSendData(A_pu8CharArr[local_u8Counter]);
	}
	/* Send Command to set DDRAM Address */
	HLCD_voidGoToPosition(A_u8RowNumber,A_u8ColumnNumber);
	/* Display pattern from CGRAM */
	HLCD_voidSendData(A_u8PatternNumber);

}
