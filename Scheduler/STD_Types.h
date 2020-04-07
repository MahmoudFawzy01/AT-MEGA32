/*
 * STD_Types.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Mahmoud Fawzy
 */
 
 #ifndef	STD_Types_H_
 #define	STD_Types_H_
 
// #define NULL 			'\0'					     /* 0 */
 #define NULL_CHAR 		'\0'						 /* 0 */
 #define NULL_POINTER_EMB	((void *)0xFFFF)			 // 2 byte address bus or (void *)NULL
 #define NULL_POINTER	((void *)0)			 // 2 byte address bus or (void *)NULL
 
 typedef unsigned char 	u8; 						 // 1 byte = 8 bit
 typedef signed char 	s8;							 // 1 byte = 8 bit
 
 typedef unsigned short int u16;					 // 2 bytes = 16 bit
 typedef signed short int s16;						 // 2 bytes = 16 bit
 
 typedef unsigned long int u32;						 // 4 bytes = 32 bit
 typedef signed long int s32;						 // 4 bytes = 32 bit
 
 typedef unsigned long long int u64;				 // 8 bytes = 64 bit
 typedef signed long long int s64;					 // 8 bytes = 64 bit
 
 typedef float 	f32;								 // 4 bytes = 32 bit
 typedef double f64;								 // 8 bytes = 64 bit

 typedef enum 
 {
	OK = 0,
	NOK,
	OUTOFRANGE,
	NULLPOINTER
 }ErrorStatus;
	
 #endif /* STD_Types */
