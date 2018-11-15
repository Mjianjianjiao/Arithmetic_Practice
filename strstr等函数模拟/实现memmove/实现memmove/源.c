#include <stdio.h>
#include <assert.h>
#pragma warning(disable:4996)
void* memmove(void *dst, void *src, size_t count)
{
	void* ret = dst;
	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst+1;
			src = (char*)src + 1;

		}

	else
	{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst -1;
			src = (char*)src - 1;
		}
	}
	}
}
int main()
{
	char a[] = "abcd";
	char b[] = "cdef";
	int count;
	scanf("%d", &count);
	char* ret;
	ret=my_memmove();
	return 0;
}