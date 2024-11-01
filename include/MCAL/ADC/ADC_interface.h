/*
 * ADC_interface.h
 *
 *  Created on: Mar 7, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

void MADC_voidInit (void);
u16 MADC_u16GetDigitalValue(u8 A_u8Channel);
#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
