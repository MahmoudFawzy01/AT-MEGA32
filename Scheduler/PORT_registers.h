/*
 * PORT_registers.h
 *
 *  Created on: Jan 13, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef PORT_REGISTERS_H_
#define PORT_REGISTERS_H_

#define DDRA_ADRESS (0x3A)		// Address of the register
 #define DDRB_ADRESS (0x37)		// Address of the register
 #define DDRC_ADRESS (0x34)		// Address of the register
 #define DDRD_ADRESS (0x31)		// Address of the register

 #define PORTA_ADRESS (0x3B)	// Address of the register
 #define PORTB_ADRESS (0x38)	// Address of the register
 #define PORTC_ADRESS (0x35)	// Address of the register
 #define PORTD_ADRESS (0x32)	// Address of the register

 #define PINA_ADRESS (0x39)		// Address of the register
 #define PINB_ADRESS (0x36)		// Address of the register
 #define PINC_ADRESS (0x33)		// Address of the register
 #define PIND_ADRESS (0x30)		// Address of the register


 #define DDRA 	*((volatile u8 *)DDRA_ADRESS) 	// Value of the register
 #define DDRB 	*((volatile u8 *)DDRB_ADRESS) 	// Value of the register
 #define DDRC 	*((volatile u8 *)DDRC_ADRESS) 	// Value of the register
 #define DDRD 	*((volatile u8 *)DDRD_ADRESS) 	// Value of the register

 #define PORTA 	*((volatile u8 *)PORTA_ADRESS)	// Value of the register
 #define PORTB 	*((volatile u8 *)PORTB_ADRESS)	// Value of the register
 #define PORTC 	*((volatile u8 *)PORTC_ADRESS)	// Value of the register
 #define PORTD 	*((volatile u8 *)PORTD_ADRESS)	// Value of the register

 #define PINA 	*((volatile u8 *)PINA_ADRESS)	// Value of the register
 #define PINB 	*((volatile u8 *)PINB_ADRESS)	// Value of the register
 #define PINC 	*((volatile u8 *)PINC_ADRESS)	// Value of the register
 #define PIND 	*((volatile u8 *)PIND_ADRESS)	// Value of the register

// you now can use the register name to refer the address of it.

#endif /* PORT_REGISTERS_H_ */
