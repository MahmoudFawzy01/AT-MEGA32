/*
 * PORT_program.c
 *
 *  Created on: Jan 13, 2020
 *      Author: Mahmoud Fawzy
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "PORT_private.h"
#include "PORT_registers.h"
#include "PORT_config.h"


/*
 * Description : Set all pins direction.
 * Inputs  :
 * Outputs :
 * */
void PORT_voidInit(void)
{
	DDRA = CONC(DIO_PIN_7_DIR,DIO_PIN_6_DIR,DIO_PIN_5_DIR,DIO_PIN_4_DIR,DIO_PIN_3_DIR,DIO_PIN_2_DIR,DIO_PIN_1_DIR,DIO_PIN_0_DIR);
	DDRB = CONC(DIO_PIN_15_DIR,DIO_PIN_14_DIR,DIO_PIN_13_DIR,DIO_PIN_12_DIR,DIO_PIN_11_DIR,DIO_PIN_10_DIR,DIO_PIN_9_DIR,DIO_PIN_8_DIR);
	DDRC = CONC(DIO_PIN_23_DIR,DIO_PIN_22_DIR,DIO_PIN_21_DIR,DIO_PIN_20_DIR,DIO_PIN_19_DIR,DIO_PIN_18_DIR,DIO_PIN_17_DIR,DIO_PIN_16_DIR);
	DDRD = CONC(DIO_PIN_31_DIR,DIO_PIN_30_DIR,DIO_PIN_29_DIR,DIO_PIN_28_DIR,DIO_PIN_27_DIR,DIO_PIN_26_DIR,DIO_PIN_25_DIR,DIO_PIN_24_DIR);

	PORTA = CONC(DIO_PIN_7_VALUE,DIO_PIN_6_VALUE,DIO_PIN_5_VALUE,DIO_PIN_4_VALUE,DIO_PIN_3_VALUE,DIO_PIN_2_VALUE,DIO_PIN_1_VALUE,DIO_PIN_0_VALUE);
	PORTB = CONC(DIO_PIN_15_VALUE,DIO_PIN_14_VALUE,DIO_PIN_13_VALUE,DIO_PIN_12_VALUE,DIO_PIN_11_VALUE,DIO_PIN_10_VALUE,DIO_PIN_9_VALUE,DIO_PIN_8_VALUE);
	PORTC = CONC(DIO_PIN_23_VALUE,DIO_PIN_22_VALUE,DIO_PIN_21_VALUE,DIO_PIN_20_VALUE,DIO_PIN_19_VALUE,DIO_PIN_18_VALUE,DIO_PIN_17_VALUE,DIO_PIN_16_VALUE);
	PORTD = CONC(DIO_PIN_31_VALUE,DIO_PIN_30_VALUE,DIO_PIN_29_VALUE,DIO_PIN_28_VALUE,DIO_PIN_27_VALUE,DIO_PIN_26_VALUE,DIO_PIN_25_VALUE,DIO_PIN_24_VALUE);
}


/*
 * Description : Set the desired pin value.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)]   -  [Copy_u8Direction -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinValue(u8 Copy_u8PinNumber ,u8 Copy_u8PinValue)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
	u8 Local_u8PortNumber;
	// to ensure that the passed Pin Number value is between [0~31]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_31))
	{
		Local_u8PortNumber = Copy_u8PinNumber/DIO_PORT_PIN_COUNT;
		Copy_u8PinNumber %= DIO_PORT_PIN_COUNT;
		// to ensure that the passed Direction value is between [0/1]
		if ((Copy_u8PinValue >= DIO_PIN_LOW) && (Copy_u8PinValue <= DIO_PIN_HIGH))
		{
			//Assign value to the desired pin.
			switch (Local_u8PortNumber)
			{
				case DIO_PORTA:
					ASSIGN_BIT(PORTA,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				case DIO_PORTB:
					ASSIGN_BIT(PORTB,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				case DIO_PORTC:
					ASSIGN_BIT(PORTC,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				case DIO_PORTD:
					ASSIGN_BIT(PORTD,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				default:
					Local_EnuError = OUTOFRANGE;
				break;
			}
		}
		else
		{
			Local_EnuError = OUTOFRANGE;
		}

	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}
	return Local_EnuError;
}
/*
* Description : Get the desired pin value.
* Inputs  :[Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)] - [* Copy_u8Value used to receive the pin value 0/1]
* Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
* */
ErrorStatus DIO_EnuGetPinValue(u8 Copy_u8PinNumber ,u8 * Copy_Pu8PinValue)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
	u8 Local_u8PortNumber;
	// to ensure that the passed Pin Number value is between [0~31]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_31))
	{
		Local_u8PortNumber = Copy_u8PinNumber/DIO_PORT_PIN_COUNT;
		Copy_u8PinNumber %= DIO_PORT_PIN_COUNT;
		// Check if the pointer passed
		if (Copy_Pu8PinValue != NULL_POINTER)
		{
			// Get the value of the pin
			switch (Local_u8PortNumber)
			{
				case DIO_PORTA:
					*Copy_Pu8PinValue = GET_BIT(PINA,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				case DIO_PORTB:
					*Copy_Pu8PinValue = GET_BIT(PINB,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				case DIO_PORTC:
					*Copy_Pu8PinValue = GET_BIT(PINC,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				case DIO_PORTD:
					*Copy_Pu8PinValue = GET_BIT(PIND,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				default:
					Local_EnuError = OUTOFRANGE;
				break;
			}
		}
		else
		{
			Local_EnuError = NULLPOINTER;
		}
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}
	return Local_EnuError;
}
