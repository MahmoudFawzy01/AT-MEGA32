/*
 * TIMER_PRIVATE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
#define TCCR0		*((volatile u8*)0x53) 	/*Timer/Counter Control Register*/
#define TCCR0_FOC0		7 					/* Force Output Compare*/
#define TCCR0_WGM00		6					/* Waveform Generation Mode*/
#define TCCR0_COM01		5					/*Compare Match Output Mode*/
#define TCCR0_COM00		4					/*Compare Match Output Mode*/
#define TCCR0_WGM01		3					/* Waveform Generation Mode*/
#define TCCR0_CS02		2					/* Clock Select*/
#define TCCR0_CS01		1					/* Clock Select*/
#define TCCR0_CS00		0					/* Clock Select*/

#define TCNT0		*((volatile u8*)0x52)	/*Timer/Counter Register*/
#define OCR0		*((volatile u8*)0x5C)	/*Output Compare Register*/
#define TIMSK		*((volatile u8*)0x59)	/*Timer/Counter Interrupt Mask Register */
#define TIMSK_OCIE2		7					/*Timer/Counter2 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE2		6					/*Timer/Counter2 Overflow Interrupt Enable*/
#define TIMSK_TICIE1	5
#define TIMSK_OCIE1A	4	/*Output Compare A Match Interrupt Enable*/
#define TIMSK_OCIE1B	3
#define TIMSK_TOIE1		2
#define TIMSK_OCIE0		1					/*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE0		0					/*Timer/Counter0 Overflow Interrupt Enable*/
#define TIFR		*((volatile u8*)0x58)	/*Timer/Counter Interrupt Flag Register*/
#define TIFR_OCF2		7					/*OCF2: Output Compare Flag 2*/
#define TIFR_TOV2		6					/*Timer/Counter2 Overflow Flag*/
#define TIFR_ICF1		5
#define TIFR_OCF1A		4					/*Output Compare A Match Flag*/
#define TIFR_OCF1B		3
#define TIFR_TOV1		2
#define TIFR_OCF0		1					/*Output Compare Flag 0*/
#define TIFR_TOV0		0					/* Timer/Counter0 Overflow Flag*/
#define SFIOR		*((volatile u8*)0x50)	/*Special Function IO Register*/
#define SFIOR_ADTS2		7
#define SFIOR_ADTS1		6
#define SFIOR_ADTS0		5
#define SFIOR_ACME		3
#define SFIOR_PUD		2
#define SFIOR_PSR2		1					/*Prescaler Reset Timer/Counter2*/
#define SFIOR_PSR10		0					/*Prescaler Reset Timer/Counter1 and Timer/Counter0*/

#define PRIVATE_NO_PRESCALING_TIMER				1	/*NO PRESCALLER*/
#define PRIVATE_CLOCK_8_TIMER					2	/*PRESCALLER WITH 8*/
#define PRIVATE_CLOCK_64_TIMER					3	/*PRESCALLER WITH 64 */
#define PRIVATE_CLOCK_256_TIMER					4	/*PRESCALLER WITH 256*/
#define PRIVATE_CLOCK_1024_TIMER				5	/*PRESCALLER WITH 1024*/
#define PRIVATE_EXTERNAL_CLOCK_FALLING_TIMER 	6	/* EXTERNAL CLOCK FALLING*/
#define	PRIVATE_EXTERNAL_CLOCK_RISING_TIMER  	7	/*EXTERNA CLOCK RISING*/





#define	PRIVATE_ENABLE							1								/*enable*/
#define	PRIVATE_DISABLE							0								/*disable*/

void __vector_11 (void) __attribute__ ((signal)); 		/*timer0 over flow isr prototype*/
void __vector_10 (void) __attribute__ ((signal));		/*timer0 CTC isr prototype*/
void (*private_PvoidPointerToAppOfOv0Isr)(void);		/*call back function*/
/***************************************************************************************************************************/
#define TCCR2      *((volatile u8*)0x45) /*Timer/Counter Control Register*/
#define TCCR2_FOC2	7	/*Force Output Compare*/
#define TCCR2_WGM20	6	/*Waveform Generation Mode*/
#define TCCR2_COM21	5	/*Compare Match Output Mode*/
#define TCCR2_COM20	4	/*Compare Match Output Mode*/
#define TCCR2_WGM21	3	/*Waveform Generation Mode*/
#define TCCR2_CS22	2	/* Clock Select*/
#define TCCR2_CS21	1	/* Clock Select*/
#define TCCR2_CS20	0	/* Clock Select*/

#define TCNT2	*((volatile u8*)0x44)	/*Timer/Counter Register*/
#define OCR2	*((volatile u8*)0x43)	/*Output Compare Register*/
void __vector_5 (void) __attribute__ ((signal));
void __vector_4 (void) __attribute__ ((signal));
void (*private_PvoidPointerToAppOfOv2Isr)(void);		/*call back function*/

/****************************************************************************************************************************/
#define	TCCR1A	*((volatile u8*)0x4F) /*Timer/Counter1 Control Register A*/

#define	TCCR1A_WGM10	0
#define	TCCR1A_WGM11	1
#define	TCCR1A_FOC1B	2
#define	TCCR1A_FOC1A	3
#define	TCCR1A_COM1B0	4
#define	TCCR1A_COM1B1	5
#define	TCCR1A_COM1A0	6
#define	TCCR1A_COM1A1	7

#define	TCCR1B	*((volatile u8*)0x4E) /*Timer/Counter1 Control Register B*/
#define TCCR1B_CS10 	0
#define TCCR1B_CS11 	1
#define TCCR1B_CS12 	2
#define TCCR1B_WGM12 	3
#define TCCR1B_WGM13 	4
#define TCNT1	*((volatile u16*)0x4D)
#define	TCNT1H	*((volatile u8*)0x4D) /*Timer/Counter1 TCNT1H*/
#define	TCNT1L	*((volatile u8*)0x4C) /*Timer/Counter1 TCNT1L*/
void (*private_PvoidPointerToAppOfOv1Isr_NORMAL)(void);		/*call back function*/
void (*private_PvoidPointerToAppOfOv1Isr_A)(void);		/*call back function*/
void (*private_PvoidPointerToAppOfOv1Isr_B)(void);		/*call back function*/
void __vector_9 (void) __attribute__ ((signal));
void __vector_7 (void) __attribute__ ((signal));
void __vector_8 (void) __attribute__ ((signal));
/**********************************************************/
#define PRIVATE_NORMAL_MODE				0 	/*NORMAL*/
#define PRIVATE_CTC_MODE				1	/*CTC*/
#define PRIVATE_PWM_FAST_MODE			2	/*FAST PWM */
#define PRIVATE_PWM_PHASE_CORRECT_MODE	3	/*PHASECORRECT*/
/***************************************************************************************************************************************/
#define PRIVATE_TIMER1_Normal							0	/*NORMAL TIMER1*/
#define PRIVATE_TIMER1_PWM_PHASE_CORECT_8_BIT			1	/*PWM, Phase Correct, 8-bit TIMER1*/
#define PRIVATE_TIMER1_PWM_PHASE_CORECT_9_BIT			2	/*PWM, Phase Correct, 9-bit TIMER1*/
#define PRIVATE_TIMER1_PWM_PHASE_CORECT_10_BIT			3	/*PWM, Phase Correct, 10-bit TIMER1*/
#define PRIVATE_TIMER1_CTC_OCR1A								4	/*CTC TIMER1*/
#define PRIVATE_TIMER1_PWM_FAST_8_BIT					5	/*PWM, FAST, 8-bit TIMER1*/
#define PRIVATE_TIMER1_PWM_FAST_9_BIT					6	/*PWM, FAST, 9-bit TIMER1*/
#define PRIVATE_TIMER1_PWM_FAST_10_BIT					7	/*PWM, FAST, 10-bit TIMER1*/
#define PRIVATE_TIMER1_PWM_PHASE_CORRECT_ICR1			8	/*PWM,PHASE_CORRECT,IMER1*/
#define PRIVATE_TIMER1_PWM_PHASE_CORRECT_OCR1A			9	/*PWM,PHASE_CORRECT,IMER1*/
#define PRIVATE_TIMER1_PWM_CTC_ICR1							10	/*PWM,PHASE_CORRECT,IMER1*/
#define PRIVATE_TIMER1_PWM_FAST_ICR1					11	/*PWM,FAST,IMER1*/
#define PRIVATE_TIMER1_PWM_FAST_OCR1A					11	/*PWM,FAST,IMER1*/


#define PRIVATE_OCN_DISCONNECTED	0 	/*OCO DISCONNECTED*/
#define PRIVATE_OCN_TOGGLE 			1	/*OCO TOGGLE*/
#define PRIVATE_OCN_CLEAR			2	/*OCO CLEAR*/
#define PRIVATE_OCN_SET				3	/*OCO SET*/


/************************************************************/

#define OCR1A	*((volatile u16*)0x49)
#define	OCR1AH	*((volatile u8*)0x4B) /*Output Compare Register 1 A OCR1AH*/
#define	OCR1AL	*((volatile u8*)0x4A) /*Output Compare Register 1 A OCR1AL*/
#define OCR1B	*((volatile u8*)0x48)
#define	OCR1BH	*((volatile u8*)0x49) /*Output Compare Register 1 A OCR1BH*/
#define	OCR1BL	*((volatile u8*)0x48) /*Output Compare Register 1 A OCR1BL*/

#define	ICR1H	*((volatile u8*)0x47) /*Input Capture Register ICR1H*/
#define	ICR1L	*((volatile u8*)0x46) /*Input Capture Register ICR1L*/

#endif /* TIMER_PRIVATE_H_ */
