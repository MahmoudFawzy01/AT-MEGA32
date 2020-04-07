/*
 * SCH_interface.h
 *
 *  Created on: Jan 25, 2020
 *      Author: sasafizo
 */

#ifndef SCH_INTERFACE_H_
#define SCH_INTERFACE_H_

/*	Struct of the Tasks	 */
typedef struct {
void (*ptfn)(void);
u32 Periodicity;  // the time of the task to be executed
u32 Periority;
}Task;


/*	 Used to push the task to the task arrays	*/
void SCH_voidCreateTask(Task * Copy_StrTask);

void SCH_voidStart(void);

void SCH_voidInit(void);

/*	the os delay	*/
void OS_voidDelay(u32 Copy_u32DelayTime,void (*Copy_voidPToTask) (void));

#endif /* SCH_INTERFACE_H_ */
