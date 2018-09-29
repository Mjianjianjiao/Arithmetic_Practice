#include "FindKth.h"
#include <stdio.h>
#include <assert.h>

int FindKthNode (pNode list,int k)
{
    assert(list);
    assert(k>=0||k<=Length(list));
    pNode cur=list ;
    pNode Kth=list;
    k--;
    while(k--)
    {
     cur=cur->next;
    }
    while(cur->next!=NULL)
    {
        cur=cur->next;
        Kth=Kth->next;
    }
    
    return Kth->data;

}
int main()
{
    pNode list;
    list=NULL;
    BackPush(&list,1);
    BackPush(&list,2);
    BackPush(&list,3);
    BackPush(&list,4);
    BackPush(&list,5);
    BackPush(&list,6);
    Print(list);
    printf("%d \n",FindKthNode(list,3));
    Destory(&list);
}
