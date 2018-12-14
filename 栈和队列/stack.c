#include "stackandqueue.h"

void StackInit(Stack* s)        //ջ�ĳ�ʼ��
{
	s->array =(Stack* )malloc(sizeof(DataType)*MAX);
	memset(s->array, 0, sizeof(DataType)*MAX);
		s->end = -1;
	s->top = s->end;
}
void StackPush(Stack* s, DataType x)   //��ջ
{
	assert(s);
	if (s->top >= MAX - 1)
	{
		printf("ջ����");
		return;
	}
	s->top ++;
	*(s->array + s->top) = x;
}
void StackPop(Stack* s)       //��ջ
{
	assert(s);
	if (s->end == s->top)
	{
		printf("ջ��");
		return;
	}
	*(s->array + s->top) = 0;
	s->top--;

}
size_t StackSize(Stack* s)    //���ջ�Ĵ�С
{
	return s->top + 1;
	
}

int StackEmpty(Stack* s)       //�ж�ջ�Ƿ�Ϊ��
{
	if (s->top == s->end)
		return 1;
	else return 0;

	
}
DataType StackTop(Stack* s)    //ȡ��ջ��Ԫ��
{
	int t = 0;
	if (s->end == s->top)
	{
		printf("ջ��");
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
//��ջ ��ջ ������Сֵ��ʱ���Ӷ�ΪO��1����



	void StackPush3(Stack* data, Stack* min,DataType t)
	{
		assert(data&&min);
		StackInit(data);
		StackInit(min);
		//��ջ
		StackPush(data,t );
		if (min->top == -1)
			StackPush(min, t);
		else if (t <= min->array[min->top])
			StackPush(min, t);
		return StackTop(min);
	}
	//��ջ
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
//�жϳ�ջ��ջ�ĺϷ���
//�Ϸ�����Ϊ1 ���Ϸ�����Ϊ0

	void judgestack(Stack *s,int* a1,int n1, int* a2,int n2)
	{
		assert(s);
		int i= 1;
		int j = 0;
		if (n1 != n2)
			return 0;   //�����������ջ���г��Ȳ���ͬ��Ϊ�Ƿ�
		StackPush(s, a1[0]);
		while (i!=n1||j!=n2)
		{

		
			if (StackTop(s) == a2[j])  //�ж�ջ��Ԫ���Ƿ����ջ������ͬ�������ͬ�ͳ�ջ����ͬ�ͼ�����ջ
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
		return StackEmpty(s) == 1 ? 1 : 0;   //���ջΪ����֤���Ϸ�
	}