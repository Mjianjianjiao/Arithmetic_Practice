#include <stdio.h>
#pragma warning(disable:4996)
#include <assert.h>
int my_strcmp(char *dest, char *str)
{
	assert(dest);
	assert(str);
	int ret = 0;
	while (*dest == *str&&*dest)
	{
		dest++;
		str++;
	}
	return *dest - *str;
}
int main()
{
	char a[] = "abcd";
	char b[] = "abc";
	int ret =my_strcmp(a, b);
	if (ret == 0)
	{
		printf("�ַ������");

	}
	else if (ret > 0)
		printf("�ַ���a����b");
	else
		printf("�ַ���aС��b");
	return 0;
}