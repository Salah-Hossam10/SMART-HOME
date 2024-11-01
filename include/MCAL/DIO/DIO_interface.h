/*
 * DIO_interface.h
 *
 *  Created on: Feb 24, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#define DIO_HIGH 1
#define DIO_LOW  0

#define DIO_PULLUP   1
#define DIO_FLOATING 0

#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

void MDIO_voidInit(void);
void MDIO_voidSetPinDirection(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Direction);
void MDIO_voidSetPinValue(u8 A_u8PortId,u8 A_u8PinId,u8 A_u8Value);
void MDIO_voidSetPortDirection(u8 A_u8PortId,u8 A_u8Direction);
void MDIO_voidSetPortValue(u8 A_u8PortId,u8 A_u8Value);
u8 MDIO_voidGetPinValue(u8 A_u8PortId,u8 A_u8PinId);
void MDIO_voidTogglePinValue (u8 A_u8PortId, u8 A_u8PinId);

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
