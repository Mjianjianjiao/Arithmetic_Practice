```
使用数组或字符串模拟一个大数
void PrintNumR(char* str,int len,int n)
{//全排列进行打印
	int i = 0;
	if (n==len)  //到达字符串最后一位时打印
	{
 		printf("%s\n", str);
		return;
	}
	for (i = 0; i < 10; i++)    //从前往后通过递归由0到9进行全排列
	{
		str[n+1] = i + '0';
		PrintNumR(str,len,n + 1);
	}
}
//使用加法模拟
void PrintNum(int N)
{
	if (N <= 0)
		return;
	char *str=malloc(sizeof(char)*(N+1));
	int cur = N;
	int end;
	int tmp;
	int i = 0;
	str[cur--] = '\0';
	end = cur;
	for (i = 0; i < N; i++)   //先将所有数置零
		str[i] = '0';
	for (i = 0; i <pow(10, N) - 1; i++)
	{
		cur = end;
		str[cur] += 1;    //每次从最末位开始加一
		while (str[cur]>'9')//当该位大于9时进位
		{
			cur--;
			str[cur] += 1;
			tmp = cur;
			while (tmp != N - 1)  //将进位后数清零
			{
				str[++tmp] = '0';
			}
		}
		print(str,N);
	}
	free(str);
	str = NULL;
}
int main()
{
	int n = 3;
	int i = 0;
	char *str = malloc(sizeof(char)*(n + 1));
	memset(str, '0', n);
	str[n] = '\0';
	int len = n-1;
	for (i = 0; i < 10; i++)
	{
		str[0] = i + '0';   //第一位数的全排列
		PrintNumR(str, len, 0);
	}
	return 0;
}


```