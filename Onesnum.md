```
int Onesnum(int key)
{
	int i = 0;
	int num = 0;
	
		for (i = 0; i < 32; i++)
		{
			if (key & 1 == 1)
				num++;
			key >>= 1;
		}
//将一个数右移与一	

	 unsigned int flag = 1;
	 while (flag)
	{
		if (key&flag)
			num++;
		flag =flag<< 1;
	}


//将一个数保持不动，将一个临时变量由一开始左移，计算每一位上一的个数
		while (key)
		{
			++num;
			key = key&(key - 1);
		}
		
//将数本身每次与自己减一，有几个一就计算几次
		
	return num;
}
```