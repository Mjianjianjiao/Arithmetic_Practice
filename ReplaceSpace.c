#include <stdio.h>
void Replace(char* str, int n)
{
	assert(str&&n > 0);
	int size = 0;
	char* cur = str;
	char * cur2;
	while (*cur != '\0')
	{
		if (*cur == ' ')
			size++;
		cur++;
	}    //先找出空格个数
	cur2 = cur;  //指到当前结尾
	cur2--;
	cur += size * 2;
	//增加空间，并将指针移到最后
	if (cur - str > n)  //当要替换的空间超过数组预留的空间，返回
		return 0;
	*(cur--) = '\0';
	while (cur2 != str)  //从后往前拷贝，是空格就输出%20
	{
		if (*cur2 == ' ')
		{
			*cur-- = '0';
			*cur-- = '2';
			*cur = '%';
		}
		else
			*cur = *cur2;
		cur--;
		cur2--;
	}
	if (*str == ' ')  //当字符串的首元素为空时，特殊处理
	{
		*cur-- = '0';
		*cur-- = '2';
		*cur = '%';
	}
	return 0;
}

int main()
{
	char str[30];
	gets(str);
	Replace(str, 30);
	printf("%s", str);
	return 0;
}
//使用指针对数组进行作不便，采用下标进行操作

void Replace(char* str, int n)
{
	assert(str&&n > 0);
	int size = 0;
	int count = 0;
	int left = 0;
	int left2 = 0;
	char* cur = str;
	while (*cur != '\0')
	{
		if (*cur == ' ')
			size++;
		count++;
		cur++;
	}
	left2 = count - 1;
	left = left2 + size * 2;
	str[left + 1] = '\0';
	while (left2 >= 0)
	{
		if (str[left2] == ' ')
		{
			str[left--] = '0';
			str[left--] = '2';
			str[left] = '%';
		}
		else
			str[left] = str[left2];

		left--;
		left2--;
	}

	return 0;
}
