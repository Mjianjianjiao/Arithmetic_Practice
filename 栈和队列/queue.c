#include "stackandqueue.h"
void QueueInit(Queue* q)    //初始化队列
{
	
	q->head = malloc(sizeof(QueueNode));
	q->tail = q->head;
}

void QueuePush(Queue* q, DataType x)    //入队
{
	q->tail->next = malloc(sizeof(QueueNode));
	q->tail = q->tail->next;
	q->tail->data = x;
	q->tail->next = NULL;
}
void QueuePop(Queue* q)   //出队
{
	Queue *p;
	if (q->head->next == q->tail)
	{
		printf("队空");
		return;
	}
	p = q->head;
	q->head = q->head->next;
	free(p);
	q->head->data = 0;
}
DataType QueueFront(Queue* q) //取出队头元素
{
	QueueNode *p;
	p = q->head->next;
	return p->data;
}
DataType QueueBack(Queue* q)   //取队尾元素
{
	return q->tail->data;
}

int QueueSize(Queue* q)   //判读队中元素个数
{
	QueueNode* p;
	int size = 1;
	p = q->head->next;
	while (p != q->tail)
	{
		size++;
		p = p->next;
	}
	return size;
}
int QueueEmpty(Queue* q)    //判断队列是否为空 
{
	assert(q);
	if (q->head == q->tail)
		return 1;
	else return 0;
}


void QueuePrint(Queue* q)
{
	assert(q);
	QueueNode *t;
	t = q->head->next;
	while (t!= q->tail->next)
	{
		printf("%d ", t->data);
		t = t->next;
	}
}