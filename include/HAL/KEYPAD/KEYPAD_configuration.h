/*
 * KEYPAD_configuration.h
 *
 *  Created on: Feb 29, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_


#define ROW_NUMBER    4
#define COLUMN_NUMBER 4
u8 global_u8ArrOfKeyValues [ROW_NUMBER][COLUMN_NUMBER]={{'7','8','9','/'},
                                                        {'4','5','6','*'},
		                                                {'1','2','3','-'},
		                                                {'C','0','=','+'}};



#define KEYPAD_DEPOUNCING_EFFECT_IN_MS 30

#define KEYPAD_PORT DIO_PORTB

#define ROW0 PIN0
#define ROW1 PIN1
#define ROW2 PIN2
#define ROW3 PIN3

#define COL0 PIN4
#define COL1 PIN5
#define COL2 PIN6
#define COL3 PIN7

#define KEYPAD_ROWS    {ROW0,ROW1,ROW2,ROW3}
#define KEYPAD_COLUMNS {COL0,COL1,COL2,COL3}


#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */
