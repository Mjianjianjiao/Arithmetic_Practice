#pragma warning(disable:4996)
#include <stdio.h>
#define N 3
int main()
{
	//魔方阵应为奇数
	//在第一行的中间放1然后从2开始到n,后一个数的位置是前一个数的行数减1列数加一，如果要放的数的位置已有数，则将其放在下一个数的下面

	int a[15][15] = { 0 };
	int num = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	int flag = 0;
	do{
		scanf("%d", &num);
		if (num == 0 && num > 15 && num % 2 == 0){
			printf("请重新输入：");
			flag = 1;
		}
		else flag = 0;
	} while (flag);

	j = num / 2;

	//判断输入的数的范围是否为奇数
	if (num != 0 && num < 15 && num % 2 != 0)
	{

		//初始化数组放入数字
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

	//输出数组
	return 0;

}
