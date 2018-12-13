```

void InsertSort(int *a, int n)//插入排序
{
	assert(a&&n >= 0);
	int i = 0;
	int j = 0;
	int end = 0;
	int tmp = 0;
	while (end<n)
	{
		j = end;
		tmp = a[j];
		i = j - 1;
		while (i>=0)
		{
			i = j - 1;
			if (a[i] > tmp)
				a[j] = a[i];
			else
				break;
			i--;
			j--;
		}
		a[j] = tmp;
		end++;
	}
}

void ShellSort(int* a, int n)//希尔排序
{
	int k = 5;
	int i = 0;
	int j = 0;
	int tmp = 0;
	int end = 0;
	while (k>=1)
	{
		end = 0;
		while (end<n)
		{
			j = end;
			tmp = a[j];
			i = j - k;
			while (i >= 0)
			{
				if (a[i]>tmp)
					a[j] = a[i];
				else
					break;
				i-=k;
				j-=k;
			}
			a[j] = tmp;
			end+=k;
		}
		k-=2;
	}

}
void SelectSort(int *a, int n)//选择排序
{
	assert(a&&n>=0);
	int i = 0;
	int tmp = 0;
	int key = 0;
	int start = 0;
	while (start<n)
	{
		i = start;
		key = a[i];
		while (i<n)
		{
			if (a[i] < key)
			{
				tmp = key;
				key = a[i];
				a[i] = tmp;
			}
			i++;
		}
		a[start] = key;
		start++;
	}
}
void HeapSort(int* a, int n)
{
	assert(n&&n >= 0);
	//调整堆
	int end = n;
	int child = end;
	int parent = 0;
	int tmp = 0;
	while (end > 0)
	{
		child = end;
		while (child > 1)
		{
			parent = child / 2;
			if (a[child - 1] > a[parent - 1])
			{
				tmp = a[parent - 1];
				a[parent - 1] = a[child - 1];
				a[child - 1] = tmp;
			}
			child--;
		}
		tmp = a[end - 1];
		a[end - 1] = a[0];
		a[0] = tmp;
		end--;
	}
}
void BubbleSort(int *a, int n)  //冒泡排序
{
	assert(a&&n >= 0);
	int i = 0;
	int j = 0;
	int tmp = 0;
	int flag = 0;
	for (i = 0; i < n; i++)
	{

		for (j = 0; j < n - 1 - i; j++)
		{
			flag = 0;
			if (a[j]>a[j + 1])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
void OneSort(int left, int right,int* a,int n)  //一次排序
{
	assert(left >= 0 && right < n&&a&&n>=0);

	if (left>= right)
		return;
	int start = left;
	int end = right;
	int key = a[left];
	while (left<right)
	{

		while (a[right]>key)
			right--;
		a[left] = a[right];
		left++;
		while (a[left] < key)
			left++;
		a[right] = a[left];
		right--;
	}
	a[(right+left)/2] = key;
	OneSort(start,right,a,right+1);//先从左边开始
	OneSort(left,end, a,end+1);
}
void QuickSort(int *a, int n)//快速排序
{
	assert(a&&n>=0);
	OneSort(0,n - 1,a,n);
}
```

