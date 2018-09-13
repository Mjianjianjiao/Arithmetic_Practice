二分查找的递归实现

```
#include <stdio.h>
#include <assert.h>
int  BinarySearchR(int* a,int n,int left,int right,int key) 
{
	assert(a);
	assert(left >= 0);
	assert(right < n);
	int mid = (left + right) >> 1;
	if (left < right)
		return -1;  //如果没找到返回-1
	if (a[mid] == key)
		return mid;  //找到了就返回下标
	else if (a[mid] < key)
		BinarySearchR(a,n, mid + 1, right, key);
	else if (a[mid]>key)
		BinarySearchR(a,n, left, mid-1, key);
}
int main()
{
	int a[] = { 1, 2, 3, 5, 6, 8, 15, 17, 20 };
	printf("%d", BinarySearchR(a, (sizeof(a) / sizeof(a[0])), 0, (sizeof(a) / sizeof(a[0])) - 1, 16));

	return 0;
}
```

