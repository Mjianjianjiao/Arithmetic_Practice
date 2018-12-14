#include "stackandqueue.h"

void StackInit(Stack* s)        //栈的初始化
{
	s->array =(Stack* )malloc(sizeof(DataType)*MAX);
	memset(s->array, 0, sizeof(DataType)*MAX);
		s->end = -1;
	s->top = s->end;
}
void StackPush(Stack* s, DataType x)   //入栈
{
	assert(s);
	if (s->top >= MAX - 1)
	{
		printf("栈已满");
		return;
	}
	s->top ++;
	*(s->array + s->top) = x;
}
void StackPop(Stack* s)       //出栈
{
	assert(s);
	if (s->end == s->top)
	{
		printf("栈空");
		return;
	}
	*(s->array + s->top) = 0;
	s->top--;

}
size_t StackSize(Stack* s)    //输出栈的大小
{
	return s->top + 1;
	
}

int StackEmpty(Stack* s)       //判断栈是否为空
{
	if (s->top == s->end)
		return 1;
	else return 0;

	
}
DataType StackTop(Stack* s)    //取出栈顶元素
{
	int t = 0;
	if (s->end == s->top)
	{
		printf("栈空");
		return;
	}
	t = *(s->array + s->top);
	return t;
}

void Stackprint(Stack* s)
{
	int i = 0;
	for (i = 0; i <= s->top; i++)
		printf("%d ", s->array[i]);

}



////////////////////////////////////////////////////////////////////////
//出栈 入栈 返回最小值的时复杂度为O（1）；



	void StackPush3(Stack* data, Stack* min,DataType t)
	{
		assert(data&&min);
		StackInit(data);
		StackInit(min);
		//入栈
		StackPush(data,t );
		if (min->top == -1)
			StackPush(min, t);
		else if (t <= min->array[min->top])
			StackPush(min, t);
		return StackTop(min);
	}
	//出栈
	void StackPop(Stack* data, Stack* min )
{	
		if (StackTop(data) == StackTop(min))
	{
		StackPop(data);
		Stackpop(min);
	}
	else
		StackPop(min);


	return StackTop(min);
}


	///////////////////////////////////////////////////////
//判断出栈入栈的合法性
//合法返回为1 不合法返回为0

	void judgestack(Stack *s,int* a1,int n1, int* a2,int n2)
	{
		assert(s);
		int i= 1;
		int j = 0;
		if (n1 != n2)
			return 0;   //如果两个出入栈序列长度不相同则为非法
		StackPush(s, a1[0]);
		while (i!=n1||j!=n2)
		{

		
			if (StackTop(s) == a2[j])  //判断栈定元素是否与出栈序列相同，如果相同就出栈，不同就继续入栈
			{
				StackPop(s);
				j++;
			}
			else
			{
				if (i!=n1)
				{
					StackPush(s, a1[i]);
					i++;
				}
			}
		}
		return StackEmpty(s) == 1 ? 1 : 0;   //如果栈为空则证明合法
	}