/*
 * SCH_private.h
 *
 *  Created on: Jan 25, 2020
 *      Author: sasafizo
 */

#ifndef SCH_PRIVATE_H_
#define SCH_PRIVATE_H_

/* the maximum number the os can handle */
Task * SCH_ATaskArray[10] = {0};

u32 SCH_u32TimeMS = 0;

u16 SCH_u16TickTime = 1;

u8 SCH_u8TimeFlag = 0;

void SCH_void1msCallBack(void);

/*	the scheduler main	*/
void SCH_voidScheduler(void);

#endif /* SCH_PRIVATE_H_ */
