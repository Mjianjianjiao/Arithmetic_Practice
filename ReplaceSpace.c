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
	}    //���ҳ��ո����
	cur2 = cur;  //ָ����ǰ��β
	cur2--;
	cur += size * 2;
	//���ӿռ䣬����ָ���Ƶ����
	if (cur - str > n)  //��Ҫ�滻�Ŀռ䳬������Ԥ���Ŀռ䣬����
		return 0;
	*(cur--) = '\0';
	while (cur2 != str)  //�Ӻ���ǰ�������ǿո�����%20
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
	if (*str == ' ')  //���ַ�������Ԫ��Ϊ��ʱ�����⴦��
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
//ʹ��ָ���������������㣬�����±���в���

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
