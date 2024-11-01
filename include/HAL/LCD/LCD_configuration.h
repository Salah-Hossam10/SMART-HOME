/*
 * LCD_configuration.h
 *
 *  Created on: Mar 10, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_

#define LCD_DATA_PORT    DIO_PORTC
#define LCD_CONTROL_PORT DIO_PORTD

#define LCD_RS_PIN PIN0
#define LCD_RW_PIN PIN1
#define LCD_E_PIN  PIN2
//0-->NUMBER_OF_LINES is 1 Line
//1-->NUMBER_OF_LINES is 2 Lines
#define NUMBER_OF_LINES 1

//0-->5*7  FONT
//1-->5*10 FONT
#define CHARACTER_FONT 0

//0-->DISPLAY OFF
//1-->DISPLAY ON
#define DISPLAY 1

//0-->CURSOR is not displayed
//1-->CURSOR is displayed
#define CURSOR_DISPLAY 1

//0-->BLINK is off
//1-->BLINK is on
#define CURSOR_BLINK 1

//0-->Display Data from Right to Left
//1-->Display Data from Left to Right
#define DATA_DIRECTION 1

//0--> NO SHIFt
//1--> SHIFT OCCUR
#define DATA_SHIFT 0


#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_ */
