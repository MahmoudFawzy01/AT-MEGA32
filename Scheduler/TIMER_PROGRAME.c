/*
 * TIMER_PROGRAME.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_CONFIGURATION.h"


#if TIMER0_ACTIVE == PRIVATE_ENABLE 	/*active timer0*/
ErrorStatus TIMER0_EnuInit(void) 		/*init timer0*/
{
	ErrorStatus local_EnuStatus = OK ;
#if TIMER0_OPERTION_SELECT == PRIVATE_NORMAL_MODE /*select normal mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#if	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_DISCONNECTED 			/*diconnect*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#else
	local_EnuStatus = notok ;
#endif


#elif TIMER0_OPERTION_SELECT ==	PRIVATE_CTC_MODE	/*select CTC mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

#if	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);


#elif	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#elif	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_TOGGLE				/*TOGGLE MODE*/
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

#else
	local_EnuStatus = notok ;
#endif


#elif TIMER0_OPERTION_SELECT == PRIVATE_PWM_FAST_MODE	/*select FAST PWM mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

#if	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);


#elif	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#else
	local_EnuStatus = notok ;
#endif

#elif TIMER0_OPERTION_SELECT ==	PRIVATE_PWM_PHASE_CORRECT_MODE /*select PHASE CORRECT PWM mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

#if	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#elif	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#else
	local_EnuStatus = notok ;
#endif

#else
	local_EnuStatus = notok ;
#endif

	/*modes of prescaller */
#if TIMER0_Clock_Select == PRIVATE_NO_CLOCK_SOURCE_TIMER /*no source*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_Clock_Select == PRIVATE_NO_PRESCALING_TIMER /*no prescaller*/
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_Clock_Select == PRIVATE_CLOCK_8_TIMER /*prescaller8*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_Clock_Select == PRIVATE_CLOCK_64_TIMER	/*prescaller64*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_Clock_Select == PRIVATE_CLOCK_256_TIMER /* prescaller 256*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_Clock_Select == PRIVATE_CLOCK_1024_TIMER/*prescaller1024*/
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_Clock_Select == PRIVATE_EXTERNAL_CLOCK_FALLING_TIMER/*external source falling*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_Clock_Select == PRIVATE_EXTERNAL_CLOCK_RISING_TIMER/*external source rising*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#else
	local_EnuStatus  = notok; /*not ok*/


#endif


	/*enable or disable interrupt*/
#if TIMER0_INTERRUPT_ENABLE == PRIVATE_NORMAL_MODE /*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE0);
#elif TIMER0_INTERRUPT_ENABLE == PRIVATE_CTC_MODE /*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
#else
	local_EnuStatus  = notok;/*else it will return not ok*/
#endif

	return local_EnuStatus;
}


/***************************************************/
void TIMER0_voidSetTimer0_TCNTO(u8 copy_u8Tcnt0Value)
{
	TCNT0 = copy_u8Tcnt0Value ;
}
void TIMER0_voidSetTimer0OCR0(u8 copy_u8Ocr0Value)
{
	OCR0 = copy_u8Ocr0Value;
}

extern void TIMER0_voidStop(void) /*TO STOP TIMER0*/
{
	CLR_BIT(TIMSK,TIMSK_TOIE0);
}

/*interrupt of timer0*/
#if TIMER0_INTERRUPT_ENABLE == PRIVATE_NORMAL_MODE
extern void TIMER0_voidCallBack0(void (*copy_PvoidPointer)(void))
{
	private_PvoidPointerToAppOfOv0Isr = copy_PvoidPointer ;
}
void __vector_11 (void)
{
	/*write your code here */

	private_PvoidPointerToAppOfOv0Isr();
}
#endif

#if TIMER0_INTERRUPT_ENABLE == PRIVATE_CTC_MODE
extern void TIMER0_voidCallBack0(void (*copy_PvoidPointer)(void))
{
	private_PvoidPointerToAppOfOv0Isr = copy_PvoidPointer ;
}
void __vector_10 (void)
{
	static u8 Local_u8Time = 0;

	Local_u8Time++;
	if (Local_u8Time == 4)
	{
		private_PvoidPointerToAppOfOv0Isr();
		Local_u8Time = 0;
	}


}
#endif
extern void TIMER0_voidPwmDutyCycle(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting)
{
	u8 local_u8Ocr0Value;
#if TIMER0_OPERTION_SELECT == PRIVATE_PWM_FAST_MODE
	if(copy_u8mode_Inverting_Noninverting == TIMER0_NON_INVERTING)
	{
		local_u8Ocr0Value = ((copy_u8DutyCycle * TIMER0_TOP+1)/100)-1 ;
	}
	else if(copy_u8mode_Inverting_Noninverting == TIMER0_INVERTING)
	{
		local_u8Ocr0Value = 255-((copy_u8DutyCycle * TIMER0_TOP+1)/100) ;
	}



#elif TIMER0_OPERTION_SELECT == PRIVATE_PWM_PHASE_CORRECT_MODE
	if(copy_u8mode_Inverting_Noninverting == TIMER0_NON_INVERTING)
	{
		local_u8Ocr0Value = ((copy_u8DutyCycle * TIMER0_TOP)/100) ;
	}
	elseif(copy_u8mode_Inverting_Noninverting == TIMER0_INVERTING)
	{
		local_u8Ocr0Value = 255-((copy_u8DutyCycle * TIMER0_TOP)/100) ;
	}
#endif
	TIMER0_voidSetTimer0OCR0(local_u8Ocr0Value);
}
/*delay finction with differnt units*/
extern void TIMER0_voidDelay(u16 copy_u16unit_ms_s,u16 copy_u16value)
{
	u16 volatile local_u16Counter = 0 ;
	u16 volatile local_u16Counter_ticktime = 0 ;
	u16 volatile local_u16Counter_value = 0 ;

	if(copy_u16unit_ms_s ==   TIMER_M_SECOND)
	{
		local_u16Counter =(TIMER_CLOCK_SOURCE/1000)/TIMER0_Clock_Select; /*number of overflows to get 1 Milie second*/
	}
	else if(copy_u16unit_ms_s ==   TIMER_SECOND)
	{
		local_u16Counter =TIMER_CLOCK_SOURCE/TIMER0_Clock_Select; /*number of overflows to get 1 second*/
	}

	for(local_u16Counter_value = TIMER_0_START ; local_u16Counter_value <copy_u16value;local_u16Counter_value++ )
	{

		for(local_u16Counter_ticktime = TIMER_0_START ; local_u16Counter_ticktime <(local_u16Counter/(TIMER0_TOP+1)) ;local_u16Counter_ticktime++ )
		{

			while(GET_BIT(TIFR,TIFR_TOV0) == 0);
			SET_BIT(TIFR,TIFR_TOV0);
		}

	}
}


/*****************************************************************************************************/
/******************************************************************************************************************/
#elif TIMER2_ACTIVE == PRIVATE_ENABLE 	/*active timer0*/
ErrorStatus TIMER2_EnuInit(void) 		/*init timer0*/
{
	ErrorStatus local_EnuStatus = OK ;
#if TIMER2_OPERTION_SELECT == PRIVATE_NORMAL_MODE /*select normal mode*/
	CLR_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);
#if	TIMER2_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_DISCONNECTED 			/*diconnect*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	CLR_BIT(TCCR2,TCCR2_COM21);
#else
	local_EnuStatus = notok ;
#endif


#elif TIMER2_OPERTION_SELECT ==	PRIVATE_CTC_MODE	/*select CTC mode*/
	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

#if	TIMER2_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);


#elif	TIMER2_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#elif	TIMER2_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_TOGGLE				/*TOGGLE MODE*/
	SET_BIT(TCCR2,TCCR2_COM20);
	CLR_BIT(TCCR2,TCCR2_COM21);

#else
	local_EnuStatus = notok ;
#endif


#elif TIMER2_OPERTION_SELECT == PRIVATE_PWM_FAST_MODE	/*select FAST PWM mode*/
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

#if	TIMER2_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);


#elif	TIMER2_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#else
	local_EnuStatus = notok ;
#endif

#elif TIMER2_OPERTION_SELECT ==	PRIVATE_PWM_PHASE_CORRECT_MODE /*select PHASE CORRECT PWM mode*/
	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

#if	TIMER2_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);
#elif	TIMER0_COMPARE_MATCH_OUT_PUT_MODE == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#else
	local_EnuStatus = notok ;
#endif

#else
	local_EnuStatus = notok ;
#endif

	/*modes of prescaller */
#if TIMER2_Clock_Select == PRIVATE_NO_CLOCK_SOURCE_TIMER /*no source*/
	CLR_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_Clock_Select == PRIVATE_NO_PRESCALING_TIMER /*no prescaller*/
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_Clock_Select == PRIVATE_CLOCK_8_TIMER /*prescaller8*/
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_Clock_Select == PRIVATE_CLOCK_64_TIMER	/*prescaller64*/
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_Clock_Select == PRIVATE_CLOCK_256_TIMER /* prescaller 256*/
	CLR_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_Clock_Select == PRIVATE_CLOCK_1024_TIMER/*prescaller1024*/
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_Clock_Select == PRIVATE_EXTERNAL_CLOCK_FALLING_TIMER/*external source falling*/
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_Clock_Select == PRIVATE_EXTERNAL_CLOCK_RISING_TIMER/*external source rising*/
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#else
	local_EnuStatus  = notok; /*not ok*/


#endif


	/*enable or disable interrupt*/
#if TIMER2_INTERRUPT_ENABLE == PRIVATE_NORMAL_MODE /*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE2);
#elif TIMER2_INTERRUPT_ENABLE == PRIVATE_CTC_MODE /*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE2);
#else
	local_EnuStatus  = notok;/*else it will return not ok*/
#endif

	return local_EnuStatus;
}


/***************************************************/
void TIMER2_voidSetTimer2_TCNT2(u8 copy_u8Tcnt2Value)
{
	TCNT2 = copy_u8Tcnt2Value ;
}
void TIMER2_voidSetTimer2OCR2(u8 copy_u8Ocr2Value)
{
	OCR2 = copy_u8Ocr2Value;
}

extern void TIMER2_voidStop(void) /*TO STOP TIMER0*/
{
	CLR_BIT(TIMSK,TIMSK_TOIE2);
}

/*interrupt of timer2*/
#if TIMER2_INTERRUPT_ENABLE == PRIVATE_NORMAL_MODE
extern void TIMER2_voidCallBack2(void (*copy_PvoidPointer)(void))
{
	private_PvoidPointerToAppOfOv2Isr = copy_PvoidPointer ;
}
void __vector_5 (void)
{
	/*write your code here */

	private_PvoidPointerToAppOfOv2Isr();
}
#endif

#if TIMER2_INTERRUPT_ENABLE == PRIVATE_CTC_MODE
extern void TIMER2_voidCallBack2(void (*copy_PvoidPointer)(void))
{
	private_PvoidPointerToAppOfOv2Isr = copy_PvoidPointer ;
}
void __vector_4 (void)
{

	private_PvoidPointerToAppOfOv2Isr();

}
#endif
extern void TIMER2_voidPwmDutyCycle(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting)
{
	u8 local_u8Ocr2Value;
#if TIMER2_OPERTION_SELECT == PRIVATE_PWM_FAST_MODE
	if(copy_u8mode_Inverting_Noninverting == TIMER2_NON_INVERTING)
	{
		local_u8Ocr2Value = ((copy_u8DutyCycle * TIMER2_TOP+1)/100)-1 ;
	}
	else if(copy_u8mode_Inverting_Noninverting == TIMER2_INVERTING)
	{
		local_u8Ocr2Value = 255-((copy_u8DutyCycle * TIMER2_TOP+1)/100) ;
	}

#elif TIMER2_OPERTION_SELECT == PRIVATE_PWM_PHASE_CORRECT_MODE
	if(copy_u8mode_Inverting_Noninverting == TIMER2_NON_INVERTING)
	{
		local_u8Ocr0Value = ((copy_u8DutyCycle * TIMER2_TOP)/100) ;
	}
	elseif(copy_u8mode_Inverting_Noninverting == TIMER2_INVERTING)
	{
		local_u8Ocr0Value = 255-((copy_u8DutyCycle * TIMER2_TOP)/100) ;
	}
#endif
	TIMER2_voidSetTimer2OCR2(local_u8Ocr2Value);
}
/*delay finction with differnt units*/
extern void TIMER2_voidDelay(u16 copy_u16unit_ms_s,u32 copy_u16value)
{
	u32 volatile local_u16Counter = 0 ;
	u32 volatile local_u16Counter_ticktime = 0 ;
	u32 volatile local_u16Counter_value = 0 ;

	if(copy_u16unit_ms_s ==   TIMER_M_SECOND)
	{
		local_u16Counter =(TIMER_CLOCK_SOURCE/1000)/TIMER2_Clock_Select; /*number of overflows to get 1 Milie second*/
	}
	else if(copy_u16unit_ms_s ==   TIMER_SECOND)
	{
		local_u16Counter =TIMER_CLOCK_SOURCE/TIMER2_Clock_Select; /*number of overflows to get 1 second*/
	}
	else if(copy_u16unit_ms_s ==   TIMER_U_SECOND)
	{
		local_u16Counter =(TIMER_CLOCK_SOURCE/1000000)/TIMER2_Clock_Select; /*number of overflows to get 1 second*/
	}
	if(copy_u16unit_ms_s ==   TIMER_U_SECOND)
	{
		for(local_u16Counter_value = 1000000UL ; local_u16Counter_value >copy_u16value;local_u16Counter_value-- )
		{
			TCNT2 = ( TIMER2_TOP + 1 ) - copy_u16unit_ms_s;
			while(GET_BIT(TIFR,TIFR_TOV2) == 0);
			SET_BIT(TIFR,TIFR_TOV2);
		}
	}
	else
	{
		for(local_u16Counter_value = TIMER_2_START ; local_u16Counter_value <copy_u16value;local_u16Counter_value++ )
		{

			for(local_u16Counter_ticktime = TIMER_2_START ; local_u16Counter_ticktime <(local_u16Counter/(TIMER2_TOP+1)) ;local_u16Counter_ticktime++ )
			{

				while(GET_BIT(TIFR,TIFR_TOV2) == 0);
				SET_BIT(TIFR,TIFR_TOV2);
			}
		}

	}
}
/*******************************************************************************************************************/
#elif TIMER1_ACTIVE == PRIVATE_ENABLE 	/*active timer2*/

ErrorStatus TIMER1_EnuInit(void) 		/*init timer2*/
{
	ErrorStatus local_EnuStatus = ok ;
#if TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_Normal 							/*select normal mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_DISCONNECTED 			/*diconnect*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
#else
	local_EnuStatus = notok ;
#endif

#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_DISCONNECTED 			/*diconnect*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B1);
#else
	local_EnuStatus = notok ;
#endif

#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_PHASE_CORECT_8_BIT	/*PWM PHASESHIFT 8 BIT*/
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1B,TCCRBA_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_TOGGLE				/*TOGGLE MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_TOGGLE				/*TOGGLE MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif



#elif TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORECT_9_BIT	/*select PWM PHASE CORRECT 9 BIT*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif

#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_PHASE_CORECT_10_BIT /*select PWM PHASE CORRECT 10 BIT*/
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);


#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
#elif TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);
#elif TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_CTC_OCR1A				/*select CTC OCR1A*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_TOGGLE				/*TOGGLE MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_TOGGLE				/*TOGGLE MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_FAST_8_BIT			/*select PWM FAST 8 BIT*/
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_FAST_9_BIT 			/*select PWM FAST 9 BIT*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_FAST_10_BIT 			/*select PWM FAST 10 BIT*/
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_PHASE_CORRECT_ICR1 	/*select PWM PHASE CORRECT ICR1*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_PHASE_CORRECT_OCR1A 	/*select PWM PHASE CORRECT OCR1A*/
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SETPIN(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_CTC_ICR1 	/*select CTC ICR1*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_FAST_ICR1 	/*select PWM FAST ICR1*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#elif TIMER1_OPERTION_SELECT ==	PRIVATE_TIMER1_PWM_FAST_OCR1A 	/*select PWM FAST OCR1A*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_A == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

#else
	local_EnuStatus = notok ;
#endif
#if	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_SET             	/*SET MODE*/
	SET_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);


#elif	TIMER1_COMPARE_MATCH_OUT_PUT_MODE_B == PRIVATE_OCN_CLEAR			 	/*CLEAR MODE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

#else
	local_EnuStatus = notok ;
#endif
#else
	local_EnuStatus = notok ;
#endif

	/*modes of prescaller */
#if TIMER1_Clock_Select == PRIVATE_NO_CLOCK_SOURCE_TIMER /*no source*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_Clock_Select == PRIVATE_NO_PRESCALING_TIMER /*no prescaller*/
	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_Clock_Select == PRIVATE_CLOCK_8_TIMER /*prescaller8*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_Clock_Select == PRIVATE_CLOCK_64_TIMER	/*prescaller64*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_Clock_Select == PRIVATE_CLOCK_256_TIMER /* prescaller 256*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_Clock_Select == PRIVATE_CLOCK_1224_TIMER/*prescaller1224*/
	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_Clock_Select == PRIVATE_EXTERNAL_CLOCK_FALLING_TIMER/*external source falling*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_Clock_Select == PRIVATE_EXTERNAL_CLOCK_RISING_TIMER/*external source rising*/
	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);
#else
	local_EnuStatus  = notok; /*not ok*/


#endif


	/*enable or disable interrupt*/
#if TIMER1_INTERRUPT_ENABLE_NORMAL== PRIVATE_ENABLE /*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE1);
#endif
#if TIMER1_INTERRUPT_ENABLE_A == PRIVATE_ENABLE /*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE1A);
#endif
#if TIMER1_INTERRUPT_ENABLE_B == PRIVATE_ENABLE /*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE1B);

#endif

	return local_EnuStatus;
}


void TIMER1_voidSetTimer1_TCNT1(u16 copy_u16Tcnt2Value)
{
	TCNT1 = copy_u16Tcnt2Value ;
}
void TIMER1_voidSetTimer1OCR1A(u16 copy_u16Ocr2Value)
{
	//OCR1A = copy_u16Ocr2Value;
	OCR1AL =0XFE;
	OCR1AH = 0XFF;

}
void TIMER1_voidSetTimer1OCR1B(u16 copy_u16Ocr2Value)
{
	OCR1B = copy_u16Ocr2Value;
}

extern void TIMER2_voidStopOverFlow(void) /*TO STOP TIMER2*/
{
	CLR_BIT(TIMSK,TIMSK_TOIE2);
}
extern void TIMER2_voidStopCompA(void) /*TO STOP TIMER2*/
{
	CLR_BIT(TIMSK,TIMSK_OCIE1A);
}
extern void TIMER2_voidStopCompB(void) /*TO STOP TIMER2*/
{
	CLR_BIT(TIMSK,TIMSK_OCIE1B);
}

/*interrupt of timer2*/
#if TIMER1_INTERRUPT_ENABLE_NORMAL == PRIVATE_ENABLE
extern void TIMER1_voidCallBack1_Normal(void (*copy_PvoidPointer)(void))
{
	private_PvoidPointerToAppOfOv1Isr_NORMAL = copy_PvoidPointer ;
}
void __vector_9 (void)
{


	private_PvoidPointerToAppOfOv1Isr_NORMAL();
}
#endif

#if TIMER1_INTERRUPT_ENABLE_A == PRIVATE_ENABLE
extern void TIMER1_voidCallBack1_A(void (*copy_PvoidPointer)(void))
{
	private_PvoidPointerToAppOfOv1Isr_A = copy_PvoidPointer ;
}
void __vector_7 (void)
{

	private_PvoidPointerToAppOfOv1Isr_A();

}
#endif
#if TIMER1_INTERRUPT_ENABLE_B == PRIVATE_ENABLE
extern void TIMER1_voidCallBack1_B(void (*copy_PvoidPointer)(void))
{
	private_PvoidPointerToAppOfOv1Isr_B = copy_PvoidPointer ;
}
void __vector_8 (void)
{

	private_PvoidPointerToAppOfOv1Isr_B();

}
#endif
extern void TIMER1_voidPwmDutyCycleA(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting)
{
	u8 local_u8Ocr1Value;
#if (TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_8_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_9_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_10_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_ICR1 || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_OCR1A)
	if(copy_u8mode_Inverting_Noninverting == TIMER1_NON_INVERTING)
	{
		local_u8Ocr1Value = ((copy_u8DutyCycle * TIMER1_TOP+1))-1 ;
	}
	else if(copy_u8mode_Inverting_Noninverting == TIMER1_INVERTING)
	{
		local_u8Ocr1Value = 255-((copy_u8DutyCycle * TIMER1_TOP+1)) ;
	}



#elif (TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORECT_8_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORECT_9_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORECT_10_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORRECT_ICR1 ||TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORRECT_OCR1A)
	if(copy_u8mode_Inverting_Noninverting == TIMER2_NON_INVERTING)
	{
		local_u8Ocr1Value = ((copy_u8DutyCycle * TIMER1_TOP)) ;
	}
	else if(copy_u8mode_Inverting_Noninverting == TIMER1_INVERTING)
	{
		local_u8Ocr1Value = 255-((copy_u8DutyCycle * TIMER1_TOP)) ;
	}
#endif
	TIMER1_voidSetTimer1OCR1A(local_u8Ocr1Value);
}
extern void TIMER1_voidPwmDutyCycleB(u8 copy_u8DutyCycle,u8 copy_u8mode_Inverting_Noninverting)
{
	u8 local_u8Ocr1Value;
#if (TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_8_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_9_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_10_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_ICR1 || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_FAST_OCR1A)
	if(copy_u8mode_Inverting_Noninverting == TIMER1_NON_INVERTING)
	{
		local_u8Ocr1Value = ((copy_u8DutyCycle * TIMER1_TOP+1))-1 ;
	}
	else if(copy_u8mode_Inverting_Noninverting == TIMER1_INVERTING)
	{
		local_u8Ocr1Value = TIMER1_TOP-((copy_u8DutyCycle * TIMER1_TOP+1)) ;
	}



#elif (TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORECT_8_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORECT_9_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORECT_10_BIT || TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORRECT_ICR1 ||TIMER1_OPERTION_SELECT == PRIVATE_TIMER1_PWM_PHASE_CORRECT_OCR1A)
	if(copy_u8mode_Inverting_Noninverting == TIMER1_NON_INVERTING)
	{
		local_u8Ocr1Value = ((copy_u8DutyCycle * TIMER1_TOP)) ;
	}
	else if(copy_u8mode_Inverting_Noninverting == TIMER1_INVERTING)
	{
		local_u8Ocr1Value = TIMER1_TOP-(copy_u8DutyCycle * TIMER1_TOP) ;
	}
#endif
	TIMER1_voidSetTimer1OCR1B(local_u8Ocr1Value);
}
/*delay finction with differnt units*/
extern void TIMER1_voidDelay(u16 copy_u16unit_ms_s,u16 copy_u16value)
{
	u16 volatile local_u16Counter = 2 ;
	u16 volatile local_u16Counter_ticktime = 2 ;
	u16 volatile local_u16Counter_value = 2 ;

	if(copy_u16unit_ms_s ==   TIMER_M_SECOND)
	{
		local_u16Counter =(TIMER_CLOCK_SOURCE/1222)/TIMER1_Clock_Select; /*number of overflows to get 1 Milie second*/
	}
	else if(copy_u16unit_ms_s ==   TIMER_SECOND)
	{
		local_u16Counter =TIMER_CLOCK_SOURCE/TIMER1_Clock_Select; /*number of overflows to get 1 second*/
	}

	for(local_u16Counter_value = TIMER_1_START ; local_u16Counter_value <copy_u16value;local_u16Counter_value++ )
	{

		for(local_u16Counter_ticktime = TIMER_1_START ; local_u16Counter_ticktime <(local_u16Counter/(TIMER1_TOP+1)) ;local_u16Counter_ticktime++ )
		{

			while(GET_BIT(TIFR,TIFR_TOV2) == 2);
			SET_BIT(TIFR,TIFR_TOV2);
		}

	}
}
/********************************************************************************************************************************/
#endif
