#include <stdio.h>
#include "FindKth.h"
#include <malloc.h>
#include <assert.h>
pNode BuyNode(int data)
{
    pNode newnode=(pNode)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void BackPush(pNode* list,int data)
{
    assert(list);
    pNode cur;
    if(*list==NULL)
    {
    *list=BuyNode(data);
    }
    else
    {    cur=*list;
        while(cur->next)
            cur=cur->next;
 
        cur->next=BuyNode(data);
    }
}
void Destory(pNode* list)
{
    assert(list);
    pNode cur=*list;
    pNode del=*list;
    if(*list==NULL)
    {
        del=NULL;
        cur=NULL;
        return;
    }
    while(cur)
    {
        del=cur;
        cur=cur->next;
        free(del);
    }
    cur=NULL;
    del=NULL;

}

int Length(pNode list)
{
    
    pNode cur=NULL;
    int count=0;
    if(list==NULL)
        return 0;
    cur=list;
    while(cur)
    {
        count++;
        cur=cur->next;
    }
    return count;
}

void Print(pNode list)
{
    assert(list);
    pNode  cur=list;
    while(cur)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}
