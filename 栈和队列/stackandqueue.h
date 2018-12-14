#ifndef __STACKANDQUEUE_H_
#define __STACKANDQUEUE_H_
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef int DataType;
#define MAX 10
typedef struct Stack
{
	DataType* array;
	int  top; //栈顶 
	int  end;
}Stack;

// 栈的实现接口 
void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int  StackSize(Stack* s);
int StackEmpty(Stack* s);
void Stackprint(Stack* s);
typedef int DataType;

typedef struct QueueNode
{
	DataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int  QueueSize(Queue* q);
int QueueEmpty(Queue* q);



#endif

