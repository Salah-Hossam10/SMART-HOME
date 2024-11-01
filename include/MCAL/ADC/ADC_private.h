/*
 * ADC_private.h
 *
 *  Created on: Mar 7, 2024
 *      Author: DELL
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX    (*(volatile u8*)0x27)
#define  ADCSRA  (*(volatile u8*)0x26)
#define  ADCH    (*(volatile u8*)0x25)
#define  ADCL    (*(volatile u8*)0x24)
#define  ADCLH   (*(volatile u16*)0x24)
#define  SFIOR   (*(volatile u8*)0x50)

#define ADMUX_REFS0 6
#define ADMUX_REFS1 7

#define ADMUX_ADLAR 5

#define ADCSRA_ADATE 6

#define ADCSRA_ADPS0 0
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS2 2

#define ADCSRA_ADEN 7

#define ADC_CHANNEL_MASK 0b11100000

#define ADCSRA_ADSC 6

#define ADCSRA_ADIF 4

#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
