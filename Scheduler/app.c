/*
 * app.c
 *
 *  Created on: Jan 19, 2020
 *      Author: sasafizo
 */


#include "STD_Types.h"
#include "BIT_MATH.h"

#include "TIMER_INTERFACE.h"
#include "SCH_interface.h"
#include "PORT_interface.h"

void led_on_fun(void)
{
	static u8 Toggle = 0;

	DIO_EnuSetPinValue(DIO_PIN_31,Toggle);
	Toggle = TOGGLE_BIT(Toggle,0);
}

void led_on_fun1(void)
{
	static u8 Toggle = 0;

	DIO_EnuSetPinValue(DIO_PIN_30,Toggle);
	Toggle = TOGGLE_BIT(Toggle,0);
}

void led_on_fun2(void)
{
	static u8 Toggle = 0;

	DIO_EnuSetPinValue(DIO_PIN_29,Toggle);
	Toggle = TOGGLE_BIT(Toggle,0);
}


Task Led_TOGGLE = {
		.ptfn = led_on_fun,
		.Periodicity =  1000,
		.Periority = 0
};

Task Led_TOGGLE1 = {
		.ptfn = led_on_fun1,
		.Periodicity =  2000,
		.Periority = 0
};

Task Led_TOGGLE2 = {
		.ptfn = led_on_fun2,
		.Periodicity =  4000,
		.Periority = 0
};


int main(void)
{
	asm("SEI");

	PORT_voidInit();
	SCH_voidInit();

	OS_voidDelay(1000,led_on_fun2);

	SCH_voidCreateTask(&Led_TOGGLE);

	OS_voidDelay(4000,led_on_fun2);
	OS_voidDelay(16000,led_on_fun2);
	OS_voidDelay(8000,led_on_fun2);

	SCH_voidCreateTask(&Led_TOGGLE1);



	OS_voidDelay(10000,led_on_fun2);


	TIMER0_voidSetTimer0OCR0(250);

	TIMER0_EnuInit();


	SCH_voidStart();


	return 0;
}

