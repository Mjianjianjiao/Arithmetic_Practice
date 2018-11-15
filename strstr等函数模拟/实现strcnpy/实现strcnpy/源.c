#include <stdio.h>
#pragma warning(disable:4996)
char* my_strncpy(char* dest, char* src, size_t count)
{
	int sz = strlen(src);
	char* start = dest;
	int t = count;
	while ((count--)&&(*dest = *src))
	{
		dest++;
		src++;
	}
	if (t > sz){

		int ret = t - sz;
		while (ret--)
		{ 
			*dest = NULL;
		    dest++;
		
		}

	}
	return start;
}
int main()
{
	char arr[10] = "asdfg";
	char *p = "klmnfdfd";
	int count = 0;
	scanf("%d", &count);
		printf("%s\n",my_strncpy(arr, p, count));
	return 0;
}