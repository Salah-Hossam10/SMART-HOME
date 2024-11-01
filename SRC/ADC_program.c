/*
 * ADC_program.c
 *
 *  Created on: Mar 7, 2024
 *      Author: DELL
 */

#include"../include/LIB/STD_TYPES_GCC.h"
#include"../include/LIB/BIT_MATH_GCC.h"

#include "../include/MCAL/ADC/ADC_interface.h"
#include "../include/MCAL/ADC/ADC_private.h"
#include "../include/MCAL/ADC/ADC_configuration.h"

#include "../include/MCAL/DIO/DIO_interface.h"


void MADC_voidInit (void)
{

	//1-Select VREF= AVCC
    SET_BIT(ADMUX,ADMUX_REFS0);
    CLR_BIT(ADMUX,ADMUX_REFS1);
	//2-Right Adjustment
    CLR_BIT(ADMUX,ADMUX_ADLAR);
	//3-Disable Auto Trigger
    CLR_BIT(ADCSRA,ADCSRA_ADATE);
	//4-SELECT CLK/64
    CLR_BIT(ADCSRA,ADCSRA_ADPS0);
    SET_BIT(ADCSRA,ADCSRA_ADPS1);
    SET_BIT(ADCSRA,ADCSRA_ADPS2);
	//5-Enable ADC
    SET_BIT(ADCSRA,ADCSRA_ADEN);

}



u16 MADC_u16GetDigitalValue(u8 A_u8Channel)
{
u16 local_u16Digaitalvalue=0;
if(A_u8Channel<32)
{
	//Clear The Channel 5-bits
    ADMUX&=	ADC_CHANNEL_MASK;
    //Select Channel
    ADMUX|=A_u8Channel;
    //Start Conversion
    SET_BIT(ADCSRA,ADCSRA_ADSC);
    //Polling on ADC Complete Flag
    while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
    //Clear INTERRUPT Flag
    SET_BIT(ADCSRA,ADCSRA_ADIF);
    //Read Conversion Values
    local_u16Digaitalvalue=ADCLH;
}
//RETURN THE READEN VALUE
return local_u16Digaitalvalue;
}




