/*
 * LCD_interface.h
 *
 *  Created on: Mar 10, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

#define LCD_ROW_ONE 1
#define LCD_ROW_TWO 2

void HLCD_voidSendData (u8 A_u8Data);
void HLCD_voidSendCommand (u8 A_u8Command);
void HLCD_voidInit(void);
void HLCD_voidDisplayClear(void);
void HLCD_voidSendString(u8 *A_pu8String);
void HLCD_voidDisplayNumber(u32 A_u32Number);
void HLCD_voidGoToPosition(u8 A_u8Row,u8 A_u8Column);
void HLCD_voidSpecialCharacter(u8 *A_pu8CharArr,u8 A_u8PatternNumber,u8 A_u8RowNumber,u8 A_u8ColumnNumber);

#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
