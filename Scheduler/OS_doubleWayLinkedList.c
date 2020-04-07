#include <stdlib.h>
#include "STD_Types.h"
#include "OS_doubleWayLinkedList.h"



u16 Counter = 0;

node *Head = NULL;
node *Current = NULL;
node *Last = NULL;

/*
void print_LinkedList(void)
{
	if (Head==NULL)
	{
		printf("list is empty\n");// as that means there is nothing in the list
	} 
	else 
	{
		Current = Head;
		while(Current != NULL)
		{
			printf("Node ID: %d \n",Current -> Task.uNID);
			printf("Node periodicity: %d \n",Current -> Task.periodicity);
			printf("Node periority: %d \n",Current -> Task.periority);
			//Current -> Task.pToTask();
			printf("********************* \n");
			Current = Current -> Next;
		}
	}
}
*/

void OS_voidNewTask(TaskNode * Copy_StrTask)
{
	node * Link;
	
	static u32 NID = 0;
	if (Head == NULL)
	{
		Head = (node*) malloc(sizeof(node));

		Head -> Task.periodicity = Copy_StrTask -> periodicity;
		Head -> Task.periority = Copy_StrTask -> periority;
		Head -> Task.startTime = Copy_StrTask -> startTime;
		Head -> Task.DesiredDelayTime = Copy_StrTask -> DesiredDelayTime;
		Head -> Task.pToTask = Copy_StrTask -> pToTask;

		if (Copy_StrTask -> TaskAdd == 0)
		{
			Head -> Task.uNID = 999999;
			Head -> Task.periority = 999999;
			Head -> Task.TaskAdd = 0;
		}
		else if (Copy_StrTask -> TaskAdd == 1)
		{
			Head -> Task.uNID = NID;
			Head -> Task.TaskAdd = 1;
			NID++;
		}

		Head -> Next = NULL;
		Head -> Prev = NULL;
		Last = Head;
		Counter++;

	}
	else
	{			

		Link = (node*) malloc(sizeof(node));

		Link -> Task.periodicity = Copy_StrTask -> periodicity;
		Link -> Task.periority = Copy_StrTask -> periority;
		Link -> Task.startTime = Copy_StrTask -> startTime;
		Link -> Task.DesiredDelayTime = Copy_StrTask -> DesiredDelayTime;
		Link -> Task.pToTask = Copy_StrTask -> pToTask;


		if (Copy_StrTask -> TaskAdd == 0)
		{
			Link -> Task.uNID = 999999;
			Link -> Task.periority = 999999;
			Link -> Task.TaskAdd = 0;
		}
		else if (Copy_StrTask -> TaskAdd == 1)
		{
			Link -> Task.uNID = NID;
			Link -> Task.TaskAdd = 1;
			NID++;
		}

		Link -> Next = NULL;
		Link -> Prev = Last;
		Last -> Next = Link;

		Last = Link;
		Counter++;

	}
}

void OS_voidDeleteAllTasks(void)
{	
	if (Head==NULL)
	{
	} 
	else 
	{
		Current = Head;
		while(Current != NULL)
		{
			Current = Current -> Next;
			free(Head);
			Head = Current;
		}
		Head = NULL;
		Last = NULL;
		Current = NULL;
	}
	Counter = 0;
}

void OS_voidDeleteLastTask(void)
{
	if (Head==NULL)
	{
	} 
	else 
	{
		Current = Last;
		Last = Last -> Prev;
		Last -> Next = NULL;
		free(Current);
		Current = NULL;
	}
	Counter--;
}


TaskNode * OS_StrSearchTaskByID(u32 NID)
{
	if (Head==NULL)
	{
	} 
	else 
	{
		Current = Head;
		while(Current != NULL)
		{
			if (Current -> Task.uNID == NID)
			{
				return &(Current -> Task);
			}
			Current = Current -> Next;
		}
		if (Current == NULL)
		{
		}
	}
	return NULL;
}

node * OS_voidDeleteTaskNodeAndGoNext(node * CurrentNode)
{
	node * Local_StrtmpNode;
	if (Head == NULL)
		CurrentNode = NULL;
	else
	{
		Local_StrtmpNode = CurrentNode -> Prev;
		Local_StrtmpNode -> Next = CurrentNode -> Next;
		free(CurrentNode);
		CurrentNode = Local_StrtmpNode -> Next;
		Counter--;
	}
	return CurrentNode;
}

u16 OS_SearchNodeByID_And_Destroy(u32 NID)
{
	node * Tmp_ptr;
	
	if (Head==NULL)
	{
	} 
	else 
	{
		Current = Head;
		Tmp_ptr = Head;
		while(Current != NULL)
		{
			if (Current -> Task.uNID == NID)
			{
				if(Current == Head)
				{
					Head = Head -> Next;
					Head -> Prev = NULL;
					free(Current);
					Current = NULL;
					Counter--;
					return 1;
				}
				else if (Current == Last)
				{
					Last = Last -> Prev;
					Last -> Next = NULL;
					free(Current);
					Current = NULL;
					Counter--;
					return 1;
				}					
				else
				{
					Tmp_ptr -> Next = Current -> Next;
					Tmp_ptr -> Next -> Prev = Tmp_ptr;
					free(Current);
					Current = NULL;
					Counter--;
					return 1;
				}				
			}
			if(Current != Head)
			{
				Tmp_ptr = Tmp_ptr -> Next;
			}
			Current = Current -> Next;
			
		}
		if (Current == NULL)
		{
			
		}
	}
	return 0;
}


void OS_voidBubbleSort(void)
{
	node* Tmp_ptr;
	TaskNode tmpTask;
	u16 currentCount = 0;
	
	
	// case of 0 not working for now .
	if (Counter > 1)
	{
		Current = Head;
		Tmp_ptr = Head;

		while(currentCount < Counter)
		{
			Current = Head;
			Tmp_ptr = Head;
			while(Current != NULL)
			{
				if (Current -> Task.periority <  Tmp_ptr -> Task.periority)
				{
					tmpTask.uNID = Current -> Task.uNID;
					tmpTask.periodicity = Current -> Task.periodicity;
					tmpTask.periority = Current -> Task.periority;
					tmpTask.pToTask = Current -> Task.pToTask;
					tmpTask.DesiredDelayTime = Current -> Task.DesiredDelayTime;
					tmpTask.startTime = Current -> Task.startTime;
					tmpTask.TaskAdd = Current -> Task.TaskAdd;

					Current -> Task.uNID = Tmp_ptr -> Task.uNID;
					Current -> Task.periodicity = Tmp_ptr -> Task.periodicity;
					Current -> Task.periority = Tmp_ptr -> Task.periority;
					Current -> Task.pToTask = Tmp_ptr -> Task.pToTask;
					Current -> Task.DesiredDelayTime = Tmp_ptr -> Task.DesiredDelayTime;
					Current -> Task.startTime = Tmp_ptr -> Task.startTime;
					Current -> Task.TaskAdd = Tmp_ptr -> Task.TaskAdd;
					
					Tmp_ptr -> Task.uNID = tmpTask.uNID;
					Tmp_ptr -> Task.periodicity = tmpTask.periodicity;
					Tmp_ptr -> Task.periority = tmpTask.periority;
					Tmp_ptr -> Task.pToTask = tmpTask.pToTask;
					Tmp_ptr -> Task.DesiredDelayTime = tmpTask.DesiredDelayTime;
					Tmp_ptr -> Task.startTime = tmpTask.startTime;
					Tmp_ptr -> Task.TaskAdd = tmpTask.TaskAdd;

				}
				
				if(Current != Head)
				{
					Tmp_ptr = Tmp_ptr -> Next;
				}
				Current = Current -> Next;
			}
			currentCount++;
			
		}
		Current = NULL;
		Tmp_ptr = NULL;
	}
}
node * OS_GoFirstNode(void)
{
	return Head;
}

node * OS_GoNextNode(node * Copy_StrCurrent)
{
	Copy_StrCurrent = (Copy_StrCurrent -> Next);

	return Copy_StrCurrent;
}

u16 OS_GetTasksCount (void)
{
	return Counter;
}
/*
void main(void){
	node * ptr;	
	
	TaskNode newTask1,newTask2,newTask3,newTask4,newTask5;
	
	newTask1.periority = 0;
	newTask2.periority = 2;
	newTask3.periority = 4;
	newTask4.periority = 4;
	newTask5.periority = 2;
	
	newTask1.periodicity = 1000;
	newTask2.periodicity = 2000;
	newTask3.periodicity = 4000;
	newTask4.periodicity = 1000;
	newTask5.periodicity = 3000;
	
	
	OS_voidNewTask(&newTask1);
	OS_voidNewTask(&newTask2);
	OS_voidNewTask(&newTask3);
	OS_voidNewTask(&newTask4);
	OS_voidNewTask(&newTask5);

	OS_voidBubbleSort();
//	print_LinkedList();
	
	
	
}*/
