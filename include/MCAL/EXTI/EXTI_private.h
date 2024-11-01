/*
 * EXTI_private.h
 *
 *  Created on: Mar 5, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_
#define INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_

#define MCUCR  (*(volatile u8*)0x55)
#define MCUCSR (*(volatile u8*)0x54)
#define GICR   (*(volatile u8*)0x5B)
#define GIFR   (*(volatile u8*)0x5A)

#define EXTI0_ENABLE_BIT  0
#define EXTI1_ENABLE_BIT  2
#define EXTI2_ENABLE_BIT  6

#define EXTI0_DISABLE_BIT  0
#define EXTI1_DISABLE_BIT  2
#define EXTI2_DISABLE_BIT  6

#define SENSE_MODE_MASK  3
#define EXTI0_SENSE_BIT  0
#define EXTI1_SENSE_BIT  2
#define EXTI2_SENSE_BIT  6

#endif /* INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_ */
