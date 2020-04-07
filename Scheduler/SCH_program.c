/*
 * SCH_program.c
 *
 *  Created on: Jan 25, 2020
 *      Author: sasafizo
 */


#include "STD_Types.h"
#include "BIT_MATH.h"

#include "SCH_interface.h"
#include "SCH_private.h"
#include "TIMER_INTERFACE.h"
#include "OS_doubleWayLinkedList.h"

/*	the os delay	*/
void OS_voidDelay(u32 Copy_u32DelayTime,void (*Copy_voidPToTask) (void))
{
	TaskNode Local_StrDelayTask;

	// configure the task as a non periodic task to add it.
	Local_StrDelayTask.DesiredDelayTime = Copy_u32DelayTime;
	Local_StrDelayTask.startTime = SCH_u32TimeMS;
	Local_StrDelayTask.pToTask = Copy_voidPToTask;
	Local_StrDelayTask.TaskAdd = 0;

	// add new task to the linked list
	OS_voidNewTask(&Local_StrDelayTask);
}

/*	 Used to push the task to the task arrays	*/
void SCH_voidCreateTask(Task * Copy_StrTask)
{
	TaskNode Local_StrTask;

	// configure the task as a periodic task to add it.
	Local_StrTask.periodicity = Copy_StrTask -> Periodicity;
	Local_StrTask.periority = Copy_StrTask -> Periority;
	Local_StrTask.pToTask = Copy_StrTask -> ptfn;
	Local_StrTask.TaskAdd = 1;

	// add new task to the linked list
	OS_voidNewTask(&Local_StrTask);
}

/*	the scheduler main	*/
void SCH_voidScheduler(void)
{
	node * Local_StrCurrentNode;

	// Go to first task at the linked list
	Local_StrCurrentNode = OS_GoFirstNode();

	// execute the tasks
	while(Local_StrCurrentNode != NULL_POINTER)
	{
		if ((Local_StrCurrentNode -> Task.TaskAdd) == 0)
		{
			if ((SCH_u32TimeMS - Local_StrCurrentNode -> Task.startTime) == Local_StrCurrentNode -> Task.DesiredDelayTime)
			{
				// execute the task
				Local_StrCurrentNode -> Task.pToTask();
				// delete the current node then go next
				Local_StrCurrentNode = OS_voidDeleteTaskNodeAndGoNext(Local_StrCurrentNode);
			}
			else
			{
				// Go to Next task at the linked list
				Local_StrCurrentNode = OS_GoNextNode(Local_StrCurrentNode);
			}
		}
		// check if this task is periodic task or just a delay only
		else if ((Local_StrCurrentNode -> Task.TaskAdd) == 1)
		{
			if( (SCH_u32TimeMS % Local_StrCurrentNode -> Task.periodicity) == 0)
			{
				// execute the task
				Local_StrCurrentNode -> Task.pToTask();
			}
			// Go to Next task at the linked list
			Local_StrCurrentNode = OS_GoNextNode(Local_StrCurrentNode);
		}
	}

}

void SCH_voidStart(void)
{
	OS_voidBubbleSort();
	while(1)
	{
		if (SCH_u8TimeFlag == 1)
		{
			SCH_voidScheduler();
			SCH_u8TimeFlag = 0;
		}
	}
}
void SCH_void1msCallBack(void)
{

	SCH_u32TimeMS++;

	if ((SCH_u32TimeMS%SCH_u16TickTime) == 0)
	{
		SCH_u8TimeFlag = 1;
	}
}



void SCH_voidInit(void)
{
	TIMER0_voidCallBack0(SCH_void1msCallBack);
}
