#include <util/delay.h>
#include"../include/LIB/STD_TYPES_GCC.h"
#include"../include/LIB/BIT_MATH_GCC.h"
#include<string.h>

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_interface.h"
#include "../include/MCAL/GI/GI_interface.h"
#include "../include/MCAL/EXTI/EXTI_interface.h"
#include "../include/MCAL/ADC/ADC_interface.h"

#define F_CPU 8000000UL

#define KEY_PRESSED DIO_LOW


int main (void)
{
	u8 local_u8PinValue=255;
	u8 local_u8PressedKey=0xff;
	static u8 local_u8Pass[4]="1234";
	u8 local_u8ClearPass[4]="CCCC";
	u8 local_u8EnteredPass[4];
	u8 local_u8NewPass[4];
	u8 local_u8TryAgain=1;
	u16 local_u16DigitalValue=0;
	u16 local_u16AnalogValue=0;
	u8 local_u8Flag=0;

	MDIO_voidInit();
	HLCD_voidInit();
	MADC_voidInit();
	MTIMER1_voidInit();
	HSERVO_voidSetServoAngle(0);


	while(1)
	{
	local_u8PinValue=MDIO_voidGetPinValue(DIO_PORTA,PIN7);
	if(local_u8PinValue==KEY_PRESSED)
	{
	while(1)
	{
		HLCD_voidDisplayClear();
		HLCD_voidSendString("    WELCOME    ");
		_delay_ms(2000);
		HLCD_voidDisplayClear();
		HLCD_voidSendString("Choose Your Mode");
		_delay_ms(2000);
		HLCD_voidDisplayClear();
		HLCD_voidSendString("1-Enter Pass");
		HLCD_voidGoToPosition(2,1);
		HLCD_voidSendString("2-Change Pass");

		while(local_u8PressedKey==0xff)
		{
			local_u8PressedKey=HKEYPAD_u8KeyPressed();
		}

		if(local_u8PressedKey == '1')
		{
			while(1)
			{
			local_u8PressedKey=0xff;
			HLCD_voidDisplayClear();
			HLCD_voidSendString("Enter Ur Pass");
			HLCD_voidGoToPosition(2,1);

			for(u8 i=0;i<4;i++)
			{
				while(local_u8PressedKey==0xff)
				{
					local_u8PressedKey=HKEYPAD_u8KeyPressed();
				}
				local_u8EnteredPass[i]=local_u8PressedKey;
				HLCD_voidSendString("*");
				local_u8PressedKey=0xff;
			}

			if(local_u8EnteredPass[0]==local_u8Pass[0] &&
			   local_u8EnteredPass[1]==local_u8Pass[1] &&
			   local_u8EnteredPass[2]==local_u8Pass[2] &&
			   local_u8EnteredPass[3]==local_u8Pass[3] )
			{
				HLCD_voidDisplayClear();
				HLCD_voidSendString(" WELCOME BACK ");
				_delay_ms(1000);
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Happy To See U");
				_delay_ms(1000);
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Door Is Opening");

				do{
					_delay_ms(1000);
					HSERVO_voidSetServoAngle(90);
					MDIO_voidSetPinValue(DIO_PORTD,PIN4,DIO_HIGH);
					_delay_ms(5000);
					HSERVO_voidSetServoAngle(0);
					MDIO_voidSetPinValue(DIO_PORTD,PIN4,DIO_LOW);
				  } while(local_u8Flag==1);

				while(1)
				{
				HLCD_voidDisplayClear();
				HLCD_voidSendString("1-AC");
				HLCD_voidGoToPosition(1,6);
				HLCD_voidSendString("2-LDR");
				HLCD_voidGoToPosition(1,12);
				HLCD_voidSendString("3-Fan");
				HLCD_voidGoToPosition(2,1);
				HLCD_voidSendString("4-Light");
				HLCD_voidGoToPosition(2,9);
				HLCD_voidSendString("5-LM35");

				while(local_u8PressedKey==0xff)
				{
					local_u8PressedKey=HKEYPAD_u8KeyPressed();
				}

				if(local_u8PressedKey == '1')
				{
					while(1)
					{
					local_u8PressedKey=0xff;
					HLCD_voidDisplayClear();
					HLCD_voidSendString("1-AC ON");
					HLCD_voidGoToPosition(2,1);
					HLCD_voidSendString("2-AC OFF");

					while(local_u8PressedKey==0xff)
					{
						local_u8PressedKey=HKEYPAD_u8KeyPressed();
					}
					if(local_u8PressedKey== '1')
					{
						local_u8PressedKey=0xff;
						MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_HIGH);
						break;
					}
					else if(local_u8PressedKey == '2')
					{
						local_u8PressedKey=0xff;
						MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_LOW);
						break;
					}
					else if(local_u8PressedKey=='C')
					{
						local_u8PressedKey=0xff;
						break;
					}
					else
					{
						local_u8PressedKey=0xff;
						HLCD_voidDisplayClear();
						HLCD_voidSendString(" Invalid Input ");
						HLCD_voidGoToPosition(2,4);
						HLCD_voidSendString("Try Again");
						_delay_ms(1000);
					}
					}

				}

				else if(local_u8PressedKey == '2')
				{
					local_u8PressedKey=0xff;
					HLCD_voidDisplayClear();
					HLCD_voidSendString("LDR IS CHECKING");
					HLCD_voidGoToPosition(2,1);
					HLCD_voidSendString("Please Wait...");
					_delay_ms(1000);

					local_u16DigitalValue=MADC_u16GetDigitalValue(ADC1);
					local_u16AnalogValue=(local_u16DigitalValue*5)/1024;

					if(local_u16AnalogValue<2)
					{
						MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_HIGH);
						MDIO_voidSetPinValue(DIO_PORTA,PIN4,DIO_HIGH);
						MDIO_voidSetPinValue(DIO_PORTA,PIN5,DIO_HIGH);
					}
					else if (local_u16AnalogValue>=2 && local_u16AnalogValue<3)
					{
						MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_HIGH);
						MDIO_voidSetPinValue(DIO_PORTA,PIN4,DIO_HIGH);
						MDIO_voidSetPinValue(DIO_PORTA,PIN5,DIO_LOW);
					}
					else if(local_u16AnalogValue>=4)
					{
						MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_HIGH);
						MDIO_voidSetPinValue(DIO_PORTA,PIN4,DIO_LOW);
						MDIO_voidSetPinValue(DIO_PORTA,PIN5,DIO_LOW);
					}
				}

				else if(local_u8PressedKey == '3')
				{
					while(1)
					{
					local_u8PressedKey=0xff;
					HLCD_voidDisplayClear();
					HLCD_voidSendString("1-FAN ON");
					HLCD_voidGoToPosition(2,1);
					HLCD_voidSendString("2-FAN OFF");

					while(local_u8PressedKey==0xff)
					{
						local_u8PressedKey=HKEYPAD_u8KeyPressed();
					}
					if(local_u8PressedKey== '1')
					{
						local_u8PressedKey=0xff;
						MDIO_voidSetPinValue(DIO_PORTA,PIN6,DIO_HIGH);
						break;
					}
					else if(local_u8PressedKey == '2')
					{
						local_u8PressedKey=0xff;
						MDIO_voidSetPinValue(DIO_PORTA,PIN6,DIO_LOW);
						break;
					}
					else if(local_u8PressedKey=='C')
					{
						local_u8PressedKey=0xff;
						break;
					}
					else
					{
						local_u8PressedKey=0xff;
						HLCD_voidDisplayClear();
						HLCD_voidSendString(" Invalid Input ");
						HLCD_voidGoToPosition(2,4);
						HLCD_voidSendString("Try Again");
						_delay_ms(1000);
					}
					}
				}

				else if(local_u8PressedKey == '4')
				{
					while(1)
					{
					local_u8PressedKey=0xff;
					HLCD_voidDisplayClear();
					HLCD_voidSendString("1-Light ON");
					HLCD_voidGoToPosition(2,1);
					HLCD_voidSendString("2-Light OFF");

					while(local_u8PressedKey==0xff)
					{
						local_u8PressedKey=HKEYPAD_u8KeyPressed();
					}

					if(local_u8PressedKey == '1')
					{
						local_u8PressedKey=0xff;
						MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_HIGH);
						MDIO_voidSetPinValue(DIO_PORTA,PIN4,DIO_HIGH);
						MDIO_voidSetPinValue(DIO_PORTA,PIN5,DIO_HIGH);
						break;
					}
					else if(local_u8PressedKey == '2')
					{
						local_u8PressedKey=0xff;
						MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_LOW);
						MDIO_voidSetPinValue(DIO_PORTA,PIN4,DIO_LOW);
						MDIO_voidSetPinValue(DIO_PORTA,PIN5,DIO_LOW);
						break;
					}
					else if(local_u8PressedKey=='C')
					{
						local_u8PressedKey=0xff;
						break;
					}
					else
					{
						local_u8PressedKey=0xff;
						HLCD_voidDisplayClear();
						HLCD_voidSendString(" Invalid Input ");
						HLCD_voidGoToPosition(2,4);
						HLCD_voidSendString("Try Again");
						_delay_ms(1000);
					}
					}

				}

				else if(local_u8PressedKey == '5')
				{
					local_u8PressedKey=0xff;
					HLCD_voidDisplayClear();
					HLCD_voidSendString("LM35 Is Checking");
					HLCD_voidGoToPosition(2,1);
					HLCD_voidSendString("Please wait...");

					local_u16DigitalValue=MADC_u16GetDigitalValue(ADC0);
					local_u16AnalogValue=(local_u16DigitalValue*500UL)/1024;

					if(local_u16AnalogValue<=30)
					{
						HLCD_voidDisplayClear();
						HLCD_voidSendString("GOOD WEATHER");
						HLCD_voidGoToPosition(2,1);
						HLCD_voidSendString("AC OFF");
						_delay_ms(1000);
						MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_LOW);
					}
					else if(local_u16AnalogValue>=31)
					{
						HLCD_voidDisplayClear();
						HLCD_voidSendString("HOT WEATHER");
						HLCD_voidGoToPosition(2,1);
						HLCD_voidSendString("AC ON");
						_delay_ms(1000);
						MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_HIGH);
					}

				}
				else if(local_u8PressedKey=='C')
				{
					local_u8PressedKey=0xff;
					break;
				}
				else
				{
					local_u8PressedKey=0xff;
					HLCD_voidDisplayClear();
					HLCD_voidSendString(" Invalid Input ");
					HLCD_voidGoToPosition(2,4);
					HLCD_voidSendString("Try Again");
					_delay_ms(1000);
				}
				}

			}
			else if(local_u8EnteredPass[0]== local_u8ClearPass[0]&&
					local_u8EnteredPass[1]== local_u8ClearPass[1]&&
					local_u8EnteredPass[2]== local_u8ClearPass[2]&&
					local_u8EnteredPass[3]== local_u8ClearPass[3])
			{
				break;
			}
			else if(local_u8EnteredPass[0]==local_u8Pass[3] &&
					local_u8EnteredPass[1]==local_u8Pass[2] &&
					local_u8EnteredPass[2]==local_u8Pass[1] &&
					local_u8EnteredPass[3]==local_u8Pass[0] )
			{
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Calling 911");
				HLCD_voidGoToPosition(2,1);
				HLCD_voidSendString("They Will Kill u");

				while(1)
				{
					MDIO_voidSetPinValue(DIO_PORTD,PIN3,DIO_HIGH);
					MDIO_voidSetPinValue(DIO_PORTD,PIN6,DIO_HIGH);
					_delay_ms(500);
					MDIO_voidSetPinValue(DIO_PORTD,PIN3,DIO_LOW);
					MDIO_voidSetPinValue(DIO_PORTD,PIN6,DIO_LOW);
					_delay_ms(500);
				}
			}
			else if(local_u8TryAgain<3)
			{
				local_u8TryAgain++;
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Wrong Password");
				HLCD_voidGoToPosition(2,1);
				HLCD_voidSendString("  Try Again  ");
				_delay_ms(2000);
			}
			else if(local_u8TryAgain==3)
			{
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Exceeded Number");
				HLCD_voidGoToPosition(2,1);
				HLCD_voidSendString(" Of Tries");
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Calling 911");
				HLCD_voidGoToPosition(2,1);
				HLCD_voidSendString("They Will Kill u");

				while(1)
				{
					MDIO_voidSetPinValue(DIO_PORTD,PIN3,DIO_HIGH);
					MDIO_voidSetPinValue(DIO_PORTD,PIN6,DIO_HIGH);
					_delay_ms(500);
					MDIO_voidSetPinValue(DIO_PORTD,PIN3,DIO_LOW);
					MDIO_voidSetPinValue(DIO_PORTD,PIN6,DIO_LOW);
					_delay_ms(500);
				}
			}
			}

		}
		else if(local_u8PressedKey == '2')
		{
			while(1)
			{
			local_u8PressedKey=0xff;
			HLCD_voidDisplayClear();
			HLCD_voidSendString("Enter Old Pass:");
			HLCD_voidGoToPosition(2,1);

			for(u8 i=0; i < 4;i++)
			{
				while(local_u8PressedKey==0xff)
				{
					local_u8PressedKey=HKEYPAD_u8KeyPressed();
				}
				local_u8EnteredPass[i]=local_u8PressedKey;
				HLCD_voidSendString("*");
				local_u8PressedKey=0xff;
			}
			if(local_u8EnteredPass[0] == local_u8Pass[0] &&
			   local_u8EnteredPass[1] == local_u8Pass[1] &&
			   local_u8EnteredPass[2] == local_u8Pass[2] &&
			   local_u8EnteredPass[3] == local_u8Pass[3] )
			{
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Welcome To Pass");
				HLCD_voidGoToPosition(2,1);
				HLCD_voidSendString("Change Page");
				_delay_ms(1000);
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Enter New Pass:");
				HLCD_voidGoToPosition(2,1);

				for(u8 i=0; i<4 ;i++)
				{
					while(local_u8PressedKey==0xff)
					{
						local_u8PressedKey=HKEYPAD_u8KeyPressed();
					}
					local_u8NewPass[i]=local_u8PressedKey;
					HLCD_voidSendString("*");
					local_u8PressedKey=0xff;
				}
				local_u8Pass[0]=local_u8NewPass[0];
				local_u8Pass[1]=local_u8NewPass[1];
				local_u8Pass[2]=local_u8NewPass[2];
				local_u8Pass[3]=local_u8NewPass[3];

				HLCD_voidDisplayClear();
				HLCD_voidSendString("Password Changed");
				HLCD_voidGoToPosition(2,2);
				HLCD_voidSendString("Successfully");
				_delay_ms(2000);
				break;
			}
			else
			{
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Wrong Password");
				HLCD_voidGoToPosition(2,3);
				HLCD_voidSendString("Try Again");
				_delay_ms(1000);
			}
			}
		}
		else if(local_u8PressedKey=='C')
		{
			local_u8PressedKey=0xff;
			break;
		}
		else
		{
			local_u8PressedKey=0xff;
			HLCD_voidDisplayClear();
			HLCD_voidSendString("Invalid Input");
			_delay_ms(1000);
			HLCD_voidDisplayClear();
			HLCD_voidSendString("Try Carefully");
			_delay_ms(1000);
		}


	}
	}

	else
	{
		while(1)
		{
			local_u8PinValue=MDIO_voidGetPinValue(DIO_PORTA,PIN7);
			if(local_u8PinValue==KEY_PRESSED)
			{
				break;
			}
			HLCD_voidDisplayClear();
			HLCD_voidSendString("Temperature:");

			local_u16DigitalValue=MADC_u16GetDigitalValue(ADC0);
			local_u16AnalogValue=(local_u16DigitalValue*500UL)/1024;
			HLCD_voidGoToPosition(1,13);
			HLCD_voidDisplayNumber(local_u16AnalogValue);
			HLCD_voidGoToPosition(1,16);
			HLCD_voidSendString("C");

			HLCD_voidGoToPosition(2,1);
			HLCD_voidSendString("Light:");

			local_u16DigitalValue=MADC_u16GetDigitalValue(ADC1);
			local_u16AnalogValue=(local_u16DigitalValue*5)/1024;
			HLCD_voidGoToPosition(2,8);
			HLCD_voidDisplayNumber(local_u16AnalogValue);
			HLCD_voidGoToPosition(2,10);
			HLCD_voidSendString("Volt");
			_delay_ms(1000);
		}
	}
	}
}
