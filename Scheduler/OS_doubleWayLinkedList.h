#ifndef OS_DOUBLE_WAY_LINKED_LIST_H_
#define	OS_DOUBLE_WAY_LINKED_LIST_H_

typedef struct NodeStructure node;

typedef struct TaskStructure TaskNode;

struct TaskStructure{
	u32 uNID;
	u32 periodicity;
	u32 periority;
	u32 DesiredDelayTime;
	u32 startTime;

	u8 TaskAdd;

	void (*pToTask) (void);
};


struct NodeStructure{
	TaskNode Task;

	node * Next;
	node * Prev;
};

void OS_voidNewTask(TaskNode * Copy_StrTask);

void OS_voidDeleteAllTasks(void);

void OS_voidDeleteLastTask(void);

TaskNode * OS_StrSearchTaskByID(u32 NID);

node * OS_voidDeleteTaskNodeAndGoNext(node * CurrentNode);

u16 OS_SearchNodeByID_And_Destroy(u32 NID);

void OS_voidBubbleSort(void);

node * OS_GoNextNode(node * Copy_StrCurrent);

node * OS_GoFirstNode(void);

u16 OS_GetTasksCount (void);

#endif /*OS_DOUBLE_WAY_LINKED_LIST_H_*/
