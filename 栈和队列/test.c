#include "stackandqueue.h"

void test1()
{
	Stack S;
	StackInit(&S);
	StackPush(&S,1);
	StackPush(&S, 2);
	StackPush(&S, 3);
	StackPush(&S, 4);
	StackPop(&S);
	printf("%d \n", StackTop(&S));
	Stackprint(&S);

}

void test2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePop(&q);
	QueuePrint(&q);

	printf("%d \n", QueueFront(&q));
	printf("%d \n", QueueBack(&q));
		printf("%d \n", QueueSize(&q));
}
int main()
{/*test1();*/
	test2();
	return 0;
}