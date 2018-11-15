#include <stdio.h>
#include <assert.h>
int my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	char *start1 = str1;
	char *start2 = str2;

	while (*str1)
	{
		str1 = start1;
		
		while ((*str1 == *str2) && *str1&&*str2)    //查找子串
		{
			str1++;
			str2++;
		}
		if (*(str2) == '\0')// 判断是否找到子串
			return 1;  
		start1++;  //主串位置后移一位
		str2 = start2;//子串返回初始位置
	}
	return 0;
}
int main()
{
	char str1[] = "abcdef";
	char str2[]= "cdeG";
	int ret = my_strstr(str1, str2);
	if (ret == 1)
		printf("找到了");
	else if(ret == 0)
		printf("没找到");

	return 0;
}