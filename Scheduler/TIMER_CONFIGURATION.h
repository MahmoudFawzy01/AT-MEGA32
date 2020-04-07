/*
 * TIMER_CONFIGURATION.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef TIMER_CONFIGURATION_H_													/*header guard*/
#define TIMER_CONFIGURATION_H_													/*header guard*/
#define TIMER0_ACTIVE						PRIVATE_ENABLE						/*enable or disable timer0*/
#define TIMER0_OPERTION_SELECT 				PRIVATE_CTC_MODE					/*NORMAL OR CT PWMFAST PHASE CORRECT*/
#define	TIMER0_COMPARE_MATCH_OUT_PUT_MODE 	PRIVATE_OCN_SET 					/*select output mode*/
#define TIMER0_Clock_Select 				PRIVATE_CLOCK_8_TIMER 		/*SELESCT MODE OF THE PRESCALLER*/
#define TIMER0_INTERRUPT_ENABLE				PRIVATE_CTC_MODE					/*ENABLE INTERRRUPT*/
#define TIMER0_TOP 							255									/*pwm calculltions*/
#define TIMER_0_START 						0 									/*polling*/
#define TIMER_CLOCK_SOURCE 8000000 /*clock source*/
/***********************************************************************************************************/
#define TIMER2_ACTIVE						PRIVATE_DISABLE					/*enable or disable timer2*/
#define TIMER2_OPERTION_SELECT 				PRIVATE_PWM_FAST_MODE				/*NORMAL OR CT PWMFAST PHASE CORRECT*/
#define	TIMER2_COMPARE_MATCH_OUT_PUT_MODE 	PRIVATE_OCN_SET						/*select output mode*/
#define TIMER2_Clock_Select 				PRIVATE_NO_PRESCALING_TIMER 		/*SELESCT MODE OF THE PRESCALLER*/
#define TIMER2_INTERRUPT_ENABLE				PRIVATE_CTC_MODE					/*ENABLE INTERRRUPT*/
#define TIMER2_TOP 							255									/*pwm calculltions*/
#define TIMER_2_START 						0 									/*polling*/
/*********************************************************************************************************************/
#define TIMER1_ACTIVE							PRIVATE_DISABLE					/*enable or disable timer1*/
#define TIMER1_OPERTION_SELECT 					PRIVATE_TIMER1_CTC_OCR1A				/*NORMAL OR CT PWMFAST PHASE CORRECT*/
#define	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A 	PRIVATE_OCN_DISCONNECTED					/*select output mode A*/
#define	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B 	PRIVATE_OCN_DISCONNECTED					/*select output mode B*/
#define TIMER1_Clock_Select 					PRIVATE_NO_PRESCALING_TIMER 	/*SELESCT MODE OF THE PRESCALLER*/
#define TIMER1_INTERRUPT_ENABLE_NORMAL			PRIVATE_DISABLE					/*ENABLE INTERRRUPT*/
#define TIMER1_INTERRUPT_ENABLE_A				PRIVATE_ENABLE				/*ENABLE INTERRRUPT*/
#define TIMER1_INTERRUPT_ENABLE_B				PRIVATE_DISABLE				/*ENABLE INTERRRUPT*/
#define TIMER1_TOP 								255								/*pwm calculltions*/
#define TIMER_1_START 							0 								/*polling*/
#endif /* TIMER_CONFIGURATION_H_ */
