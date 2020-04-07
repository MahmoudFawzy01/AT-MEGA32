/*
 * PORT_interface.h
 *
 *  Created on: Jan 13, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef PORT_INTERFACE_H_
#define PORT_INTERFACE_H_

#define DIO_PIN_0	0
#define DIO_PIN_1	1
#define DIO_PIN_2	2
#define DIO_PIN_3	3
#define DIO_PIN_4	4
#define DIO_PIN_5	5
#define DIO_PIN_6	6
#define DIO_PIN_7	7
#define DIO_PIN_8	8
#define DIO_PIN_9	9
#define DIO_PIN_10	10
#define DIO_PIN_11	11
#define DIO_PIN_12	12
#define DIO_PIN_13	13
#define DIO_PIN_14	14
#define DIO_PIN_15	15
#define DIO_PIN_16	16
#define DIO_PIN_17	17
#define DIO_PIN_18	18
#define DIO_PIN_19	19
#define DIO_PIN_20	20
#define DIO_PIN_21	21
#define DIO_PIN_22	22
#define DIO_PIN_23	23
#define DIO_PIN_24	24
#define DIO_PIN_25	25
#define DIO_PIN_26	26
#define DIO_PIN_27	27
#define DIO_PIN_28	28
#define DIO_PIN_29	29
#define DIO_PIN_30	30
#define DIO_PIN_31	31

#define DIO_PIN_LOW		0
#define DIO_PIN_HIGH	1

/*
 * Description : Set all pins direction.
 * Inputs  :
 * Outputs :
 * */
void PORT_voidInit(void);

/*
 * Description : Set the desired pin value.
 * Inputs  : [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)]   -  [Copy_u8Direction -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinValue(u8 Copy_u8PinNumber ,u8 Copy_u8PinValue);

/*
 * Description : Get the desired pin value.
 * Inputs  :[Copy_u8PinNumber-> pin number value = DIO_PIN_(0~31)] - [* Copy_u8Value used to receive the pin value 0/1]
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuGetPinValue(u8 Copy_u8PinNumber ,u8 * Copy_Pu8PinValue);


#endif /* PORT_INTERFACE_H_ */
