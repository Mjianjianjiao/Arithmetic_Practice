#include "linklist.h"

test()
{
	pList plist;
	pNode pos;
	int len = 0;
	/*InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);*/
	/*PopBack(&plist);
	PrintLinkList(plist);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	PopFront(&plist);
	PrintLinkList(plist);*/
	/*if ((pos = Find(plist, 1)) != NULL)
		printf("%d\n", Find(plist, 2)->data);
	else
		printf("meizhaodao\n");*/
	/*Insert(&plist, pos, 5);*/
	/*PrintLinkList(plist);*/
	/*    Erase(&plist, pos);
		PrintLinkList(plist);
		Remove(&plist, 3);
		PrintLinkList(plist);
		Remove(&plist, 4);
		PrintLinkList(plist);*/
		/*Remove(&plist, 1);
		PrintLinkList(plist);*/
	/*	RemoveAll(&plist,1);
		PrintLinkList(plist);*/
		/*pos = Find(plist, 1);
		EraseNotTailNode(pos);
		PrintLinkList(plist);
		len = GetListLength(plist);
		printf("len= %d", len);*/
	//PrintTailToHead(plist);
	//PrintTailToHead_R(plist);
	JosephusCycle(&plist, 3);

}
int main()
{
	test();

	return 0;
}