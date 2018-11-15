#include "mergesort.h"
void Merge(int *a ,int left ,int mid,int right,int *tmp)
{
    assert(a&&tmp);
    int left1=left;
    int left2=mid+1;
    int start=left;
    int end=right;
    int index=left;
    int i=0;

    while(left1<=mid&&left2<=end)
    {
        if(a[left1]<a[left2])
            tmp[index++]=a[left1++];
        else
            tmp[index++]=a[left2++];
        
    }

    while(left1<=mid)
        tmp[index++]=a[left1++];
    while(left2<=end)
        tmp[index++]=a[left2++];

    for(i=start;i<=end;i++)
        a[i]=tmp[i];

}
void _MergeSort(int* a,int left,int right,int* tmp)
{
    assert(a&&tmp);
    int mid=(left+right)>>1;
    if(left<right)
    {
        _MergeSort(a,left,mid,tmp);
        _MergeSort(a,mid+1,right,tmp);
        Merge(a,left,mid,right,tmp);
    }
}
void MergeSort(int*a,int n)
{   
    assert(a&&n>0);
     int left=0;
    int right=n-1;
    int *tmp=malloc(sizeof(int)*n);
    _MergeSort(a,left,right,tmp);
    free(tmp);
    tmp=NULL;
}
    int main()
{

    int a[]={7,2,76,2,1,8,3,9};
    int n=sizeof(a)/sizeof(a[0]);
    int i=0;
    MergeSort(a,n);
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
