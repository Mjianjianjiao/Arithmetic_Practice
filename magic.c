#pragma warning(disable:4996)
#include <stdio.h>
#define N 3
int main()
{
	//ħ����ӦΪ����
	//�ڵ�һ�е��м��1Ȼ���2��ʼ��n,��һ������λ����ǰһ������������1������һ�����Ҫ�ŵ�����λ�������������������һ����������

	int a[15][15] = { 0 };
	int num = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	int flag = 0;
	do{
		scanf("%d", &num);
		if (num == 0 && num > 15 && num % 2 == 0){
			printf("���������룺");
			flag = 1;
		}
		else flag = 0;
	} while (flag);

	j = num / 2;

	//�ж���������ķ�Χ�Ƿ�Ϊ����
	if (num != 0 && num < 15 && num % 2 != 0)
	{

		//��ʼ�������������
		a[0][num / 2] = 1;
		for (k = 2; k <= num*num; k++)
		{
			if (i == 0)i = num;
			i--;
			if (j == num - 1)j = -1;
			j++;


			if (a[i][j] == 0)
				a[i][j] = k;
			else{
				if (i == num - 1)
					i = 1;
				else i += 2;
				if (j == 0)
					j = num;
				j--;
				a[i][j] = k;
			}
		}
		for (i = 0; i < num; i++)
		{

			for (j = 0; j < num; j++)
			{
				printf("%3d", a[i][j]);
			}
			printf("\n");
		}
	}

	//�������
	return 0;

}
