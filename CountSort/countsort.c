#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <memory.h>
void CountSort(int* a,int n)
 {
    assert(a);
    assert(n>0);
    int min=0;
    int max=0;
    int i=0;
    int index=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
   
    int* count=(int*)malloc(sizeof(int)*(max-min+1));
    if(count==NULL)
          return;
    memset(count,0,sizeof(int)*(max-min+1));
   // 
    for(i=0;i<n;i++) 
     count[a[i]-min]++;
    
    for(i=0;i<(max-min+1);i++)
     { 
      while(count[i]--)   
      a[index++]=min+i;
     }

}
void Print(int* a,int n)
{
    assert(a);
    assert(n>0);
    int i=0;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    
}
int main(_)
{
    int a[]={2,45,7,3,8,9,3,0,6,34,35 };
    int n=sizeof(a)/sizeof(a[0]);
    CountSort(a,n);
    Print(a,n);
}
