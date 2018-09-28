#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void ReoderArray(int* a,int n)
{
    assert(a);
    assert(n>0);
    int start=0;
    int end=n-1;
    int t=0;
    while(start<end)
    {
        if(a[start]%2!=0)
        {
            start++;
        }
        else 
        {
            t=a[end];
            a[end]=a[start];
            a[start]=t;
            end--;
            }  
    }
}
void ReoderArray2(int *a,int n)
{
    int start=0;
    int end=n-1;
    int t=0;
    if(a==NULL&&n<=0)
        return ;
    while(start<end)
    {
        while(start<end)
        {
            if(a[start]%2!=0)
                start++;
            else 
                break;
        }
        while(start<end)
        {
            if(a[end]%2==0)
                end--;
            else
                break;
        }
        if(start<end)
        {
            t=a[start];
            a[start]=a[end];
            a[end]=t;
        }
    }

}
void Print(int *a,int n)
{
    assert(a);
    assert(n>0);
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(a[0]);
    int i=0;
   // ReoderArray(a,n);
    ReoderArray2(a,n);
    Print(a,n);
    return 0;
}
