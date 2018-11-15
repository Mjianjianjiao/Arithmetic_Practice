#include <stdio.h>
#pragma warning(disable:4996)
#include <assert.h>
char* mystrchr(const  char* str, char ch)
{
	assert(str);
	while (*str!=ch)
	{
		str++;
	}
	return str;

}
int main()
{
	char a[] = "abcdef";
	char ch;
	scanf("%c", &ch);
	char * ret=mystrchr(a,ch);
	printf("%s", ret);
	return 0;
}