#include "linklist.h"
void InitLinkList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}
pNode BuyNode(DataType d)
{
	pNode newnode = (pList)malloc(sizeof(Node));
	newnode->data = d;
	newnode->next = NULL;
	return newnode;

}
void DestroyLinkList(pList* pplist)
{
	assert(pplist);
	free(*pplist);
	*pplist = NULL;
}
void PushBack(pList* pplist, DataType d)
{
	pNode newnode = NULL;
	pNode cur = NULL;
	assert(pplist);
	cur = *pplist;
	newnode = BuyNode(d);
	if (*pplist == NULL)
	{
		newnode->next = *pplist;
		*pplist = newnode;
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
}
void PopBack(pList* pplist){
	pNode del = NULL;
	pNode cur = NULL;
	assert(pplist);
	cur = *pplist;
	if (*pplist == NULL)
	{
		return;
	}
	if (cur->next == NULL)
	{
		*pplist = NULL;
		free(cur);
		cur = NULL;
		return;
	}
	while (cur->next->next)cur = cur->next;
	free(cur->next);
	cur->next = NULL;
}
void PushFront(pList* pplist, DataType d){
	pNode newnode = NULL;
	assert(pplist);
	newnode = BuyNode(d);
	newnode->next = *pplist;
	*pplist = newnode;
}
void PopFront(pList* pplist)
{
	assert(pplist);
	assert(*pplist);

	pNode del = *pplist;
	*pplist = del->next;
	free(del);
	del = NULL;
}

pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	if (plist == NULL)
		return NULL;
	while (cur&&cur->data != d)
		cur = cur->next;
	if (cur)
		return cur;
	return NULL;


	

}


void Insert(pList* pplist, pNode pos, DataType d)
{
	assert(pos);
	assert(pplist);
	pNode newnode = BuyNode(d);
		pNode cur = *pplist;
	if (*pplist==NULL)
		return;
	if (cur == pos)
	{
		newnode->next = *pplist;
		*pplist = newnode;
		return;
	}
	while (cur&&cur->next != pos)
		cur = cur->next;
	if (cur)
	{
		newnode->next = pos;
		cur->next = newnode;
	}
	return;
}
void Erase(pList* pplist, pNode pos)
{
	assert(pplist);
	assert(pos);
	assert(*pplist);
	pNode del = NULL;
	pNode cur = *pplist;
	if (*pplist == pos)
	{
		del = *pplist;
		*pplist= del->next;
		free(del);
		del == NULL;
		return;
	}
	while (cur&&cur->next != pos)
	{
		cur = cur->next;
	}
	if (cur)
	{
		del = pos;
		cur->next = pos->next;
		free(del);
		del = NULL;
	}
}
void Remove(pList* pplist, DataType d)
{
	assert(pplist);
	pNode del = NULL;
	pNode cur = *pplist;
	pNode prev = cur;
	if(*pplist == NULL)
		return;
	while (cur){	
		if (cur->data == d)
		{

			if (cur == *pplist)
			{
				*pplist = cur->next;
				free(cur);
				cur = NULL;
				return;
			}
			else{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
				return;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void PrintLinkList(pList plist)
{
	pNode cur = plist;
	/*if (plist == NULL)
		return;*/
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("over\n");

}
void RemoveAll(pList* pplist, DataType d)
{
	assert(pplist);
	pNode cur = *pplist;
	pNode prev = cur;
	pNode del = NULL;
	if (*pplist == NULL)
		return;
	while (cur)
	{
		if (cur->data == d)
		{
			if (cur == *pplist)
			{
				del = *pplist;
				*pplist = del->next;
				cur = *pplist;
				free(del);
				del = NULL;
			}
			else
			{
				prev->next = cur->next;
				del = cur;
				cur = cur->next;
				free(del);
				del = NULL;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}



void EraseNotTailNode(pNode pos)
{
	assert(pos);
	assert(pos->next);
	pNode del = pos->next;
	pos->data = del->data;
	pos->next = del->next;
	free(del);
	del = NULL;
}
int GetListLength(pList plist)
{
	int count=0;
	pNode cur = plist;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;

}

//链表面试题 

//1. 逆序打印单项链表 
void PrintTailToHead(pList plist)
{
	pNode tail = NULL;
	pNode cur = plist;
	if (plist == NULL)
		return;
	while (cur != tail)
	{
		
		while (cur->next!=tail)
			cur = cur->next;
		printf("%d-->", cur->data);
		tail = cur;
		cur = plist;
	}
	printf("over\n");
}
void PrintTailToHead_R(pList plist)
{
	pNode cur = plist;
	if (cur==NULL)
	{
		return;
	}
	PrintTailToHead_R(cur->next);
	printf("%d-->", cur->data);
}
void JosephusCycle(pList* pplist, int k)
{
	assert(pplist);
	*pplist = BuyNode(0);
	pNode cur=*pplist;
	pNode del = NULL;
	pNode prev = NULL;
	int count = 0;
 	int i = 0;
		for (i = 1; i <= 41 ; i++)
		{
			cur->next = BuyNode(i);
			cur = cur->next;
		}
		cur->next = (*pplist)->next;
		del = *pplist;
		*pplist = del->next;
		free(del);
		del = NULL;
		cur = *pplist;
	/*while (cur->next)
		cur = cur->next;
	cur->next = *pplist;
	cur = *pplist;*/
	while (cur != cur->next)
	{
		count = k;
		while (--count)
		{
			cur = cur->next;
		}
		del = cur->next;
		printf("删除者：%d\n", cur->data);
		cur->data = del->data;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("幸存者：%d\n", cur->data);
}