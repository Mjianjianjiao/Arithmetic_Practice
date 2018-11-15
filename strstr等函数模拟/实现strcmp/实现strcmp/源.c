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
		printf("字符串相等");

	}
	else if (ret > 0)
		printf("字符串a大于b");
	else
		printf("字符串a小于b");
	return 0;
}