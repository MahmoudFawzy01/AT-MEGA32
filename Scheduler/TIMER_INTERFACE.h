/*
 * TIMER_INTERFACE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

ErrorStatus TIMER0_EnuInit(void);																/*to init the time0*/
void TIMER0_voidSetTimer0_TCNTO(u8 copy_u8Tcnt0Value); 											/*set tcnt0*/
void TIMER0_voidSetTimer0OCR0(u8 copy_u8Ocr0Value); 											/*set ocr0*/
extern void TIMER0_voidCallBack0(void (*copy_PvoidPointer)(void));  							/* callback of interrupt0*/
extern void TIMER0_voidStop(void); 																/*timer0 stop with interrupt*/
extern void TIMER0_voidPwmDutyCycle(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting);	/* to get duty cycle*/
extern void TIMER0_voidDelay(u16 copy_u16unit_ms_s,u16 copy_u16value);
#define TIMER0_INVERTING 		0	/*the mode of pwm on oc0*/
#define TIMER0_NON_INVERTING 	1	/*the mode of pwm on oc0*/
#define TIMER_U_SECOND 	0  	/*Micro second */
#define TIMER_M_SECOND 	1	/*milie second*/
#define TIMER_SECOND 	2	/*second*/

/******************************************************************************************************/
ErrorStatus TIMER2_EnuInit(void);																/*to init the time2*/
void TIMER2_voidSetTimer2_TCNT2(u8 copy_u8Tcnt2Value); 											/*set tcnt2*/
void TIMER2_voidSetTimer2OCR2(u8 copy_u8Ocr2Value); 											/*set ocr2*/
extern void TIMER2_voidCallBack2(void (*copy_PvoidPointer)(void));  							/* callback of interrupt2*/
extern void TIMER2_voidStop(void); 																/*timer2 stop with interrupt*/
extern void TIMER2_voidPwmDutyCycle(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting);	/* to get duty cycle*/
extern void TIMER2_voidDelay(u16 copy_u16unit_ms_s,u32 copy_u16value);
#define TIMER2_INVERTING 		0	/*the mode of pwm on oc0*/
#define TIMER2_NON_INVERTING 	1	/*the mode of pwm on oc0*/

/*******************************************************************************************************************/
ErrorStatus TIMER1_EnuInit(void);																/*to init the time2*/
void TIMER1_voidSetTimer1_TCNT1(u16 copy_u16Tcnt2Value); 											/*set tcnt2*/
void TIMER1_voidSetTimer1OCR1A(u16 copy_u16Ocr2Value); 											/*set ocr2*/
void TIMER1_voidSetTimer1OCR1B(u16 copy_u16Ocr2Value); 											/*set ocr2*/
extern void TIMER1_voidCallBack1_Normal(void (*copy_PvoidPointer)(void));  							/* callback of interrupt2*/
extern void TIMER1_voidCallBack1_A(void (*copy_PvoidPointer)(void));  							/* callback of interrupt2*/
extern void TIMER1_voidCallBack1_B(void (*copy_PvoidPointer)(void));  							/* callback of interrupt2*/
extern void TIMER2_voidStop(void); 																/*timer2 stop with interrupt*/
extern void TIMER2_voidPwmDutyCycleA(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting);	/* to get duty cycle*/
extern void TIMER2_voidPwmDutyCycleB(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting);
extern void TIMER1_voidDelay(u16 copy_u16unit_ms_s,u16 copy_u16value);
#define TIMER1_INVERTING 		0	/*the mode of pwm on oc0*/
#define TIMER1_NON_INVERTING 	1	/*the mode of pwm on oc0*/



#endif /* TIMER_INTERFACE_H_ */
