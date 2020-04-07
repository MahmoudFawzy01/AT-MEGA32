/*
 * PORT_private.h
 *
 *  Created on: Jan 13, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

/*Macro for Pin Directions*/
#define DIO_PIN_INPUT	0
#define DIO_PIN_OUTPUT 	1

// to concatinate the port value and replace each pin to the value configured with.
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)	CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define DIO_PORT_PIN_COUNT 8

#endif /* PORT_PRIVATE_H_ */
