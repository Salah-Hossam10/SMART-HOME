/*
 * LCD_private.h
 *
 *  Created on: Mar 10, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_LCD_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_LCD_PRIVATE_H_

#define FUNCTION_SET CONC_BIT(0,0,1,1,NUMBER_OF_LINES,CHARACTER_FONT,0,0)
#define DISPLAY_ON_OFF_CONTROL CONC_BIT(0,0,0,0,1,DISPLAY,CURSOR_DISPLAY,CURSOR_BLINK)
#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET CONC_BIT(0,0,0,0,0,1,DATA_DIRECTION,DATA_SHIFT)

#define LCD_ROW1_ADDRESS 127
#define LCD_ROW2_ADDRESS 191


#endif /* INCLUDE_HAL_LCD_LCD_PRIVATE_H_ */