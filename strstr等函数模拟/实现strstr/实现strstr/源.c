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
		
		while ((*str1 == *str2) && *str1&&*str2)    //�����Ӵ�
		{
			str1++;
			str2++;
		}
		if (*(str2) == '\0')// �ж��Ƿ��ҵ��Ӵ�
			return 1;  
		start1++;  //����λ�ú���һλ
		str2 = start2;//�Ӵ����س�ʼλ��
	}
	return 0;
}
int main()
{
	char str1[] = "abcdef";
	char str2[]= "cdeG";
	int ret = my_strstr(str1, str2);
	if (ret == 1)
		printf("�ҵ���");
	else if(ret == 0)
		printf("û�ҵ�");

	return 0;
}