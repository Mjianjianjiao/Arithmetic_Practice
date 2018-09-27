
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct ListNode
{
	int value;
	struct ListNode * next;
}*plNode, LNode;


void DeleteNode(plNode* plhead, plNode delnode)
{
	assert(plhead&&*plhead&&delnode);
	plNode del;
	plNode cur;
	if (delnode->next != NULL)
	{
		del = delnode->next;
		delnode->value = delnode->next->value;
		delnode->next = delnode->next->next;
		free(del);
	}

	else if (*plhead == delnode)
	{
		free(delnode);
		*plhead = NULL;
	}
	else
	{
		cur = *plhead;
		while (cur->next != delnode)
			cur = cur->next;
		cur->next = NULL;
		free(delnode);
		delnode = NULL;
		cur = NULL;
	}


}
plNode buynode(int value)
{
	plNode cur;

	if ((cur = (plNode)malloc(sizeof(LNode))) == NULL)
		return;
	cur->value = value;
	cur->next = NULL;
	return cur;

}
void Listpush(plNode* list, int value)

{
	assert(list);
	plNode cur;
	cur = *list;
	if (*list == NULL)
	{
		cur = buynode(value);
		*list = cur;
		return;
	}
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = buynode(value);
}
plNode Find(plNode* list, int value)
{
	plNode cur;
	if (*list == NULL)
		return NULL;
	cur = *list;
	while (cur->value != value)
		cur = cur->next;
	if (cur)
		return cur;
	return cur;
}
void destory(plNode* list)
{
	assert(list);
	plNode del;
	plNode cur;
	if (*list)
		return;
	cur = *list;
	del = *list;
	while (del->next)
		del = del->next;
	while (cur->next)
	{
		cur = *list;
		while (cur->next != del)
		{
			free(del);
			del = cur;
			cur->next = NULL;
		}
	}
	free(cur);
	*list = NULL;
	cur = NULL;

}
void print(plNode list)
{
	assert(list);
	plNode cur = list;
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
}
int main()
{

	plNode cur;
	plNode plist = NULL;
	Listpush(&plist, 3);
	Listpush(&plist, 4);
	Listpush(&plist, 5);
	Listpush(&plist, 6);
	Listpush(&plist, 6);
	cur = Find(&plist, 5);
	DeleteNode(&plist, cur);
	print(plist);
	destory(&plist);
	return 0;
}
