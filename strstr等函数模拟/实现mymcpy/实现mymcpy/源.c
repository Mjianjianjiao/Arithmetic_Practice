#include <stdio.h>
#include <assert.h>
#pragma warning(disable:4996)
char* my_memcpy(char *a, char* b,size_t count )
{
	assert(a);
	assert(b);
	void* ret = a;
	while (count--)
	{
		*(char*)a = *(char*)b;
		a = (char*)a + 1;
		b = (char*)b + 1;

	}
	return ret;
}
int main()
{
	char a[] = "abcd";
	char b[] = "cdef";
	int count = 0;
	scanf("%d", &count);
	char* ret=my_memcpy(a, b,count);
	printf("%s", ret);
	return 0;
	
}