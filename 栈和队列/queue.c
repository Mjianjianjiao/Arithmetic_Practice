#include "stackandqueue.h"
void QueueInit(Queue* q)    //��ʼ������
{
	
	q->head = malloc(sizeof(QueueNode));
	q->tail = q->head;
}

void QueuePush(Queue* q, DataType x)    //���
{
	q->tail->next = malloc(sizeof(QueueNode));
	q->tail = q->tail->next;
	q->tail->data = x;
	q->tail->next = NULL;
}
void QueuePop(Queue* q)   //����
{
	Queue *p;
	if (q->head->next == q->tail)
	{
		printf("�ӿ�");
		return;
	}
	p = q->head;
	q->head = q->head->next;
	free(p);
	q->head->data = 0;
}
DataType QueueFront(Queue* q) //ȡ����ͷԪ��
{
	QueueNode *p;
	p = q->head->next;
	return p->data;
}
DataType QueueBack(Queue* q)   //ȡ��βԪ��
{
	return q->tail->data;
}

int QueueSize(Queue* q)   //�ж�����Ԫ�ظ���
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
int QueueEmpty(Queue* q)    //�ж϶����Ƿ�Ϊ�� 
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