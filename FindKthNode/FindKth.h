#ifndef __FindKth_h_
#define __FindKth_h_


typedef  struct listnode
{
    int data;
    struct listnode* next;
}*pNode,Node;
void BackPush(pNode* list,int data);
void Destory(pNode* list);
int FindKthNode (pNode list,int k);

int Length(pNode list);

void Print(pNode list);
#endif
