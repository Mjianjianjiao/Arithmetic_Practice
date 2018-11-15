#include <stdio.h>
#pragma warning(disable:4996)
int my_strncmp(const char* p1, const char* p2, size_t count)
{
	while ((*p1 == *p2) && (count--))
	{
		
		p1++; 
		p2++;
	}
	if ((*p1-*p2) == 0)
		return 0;
	else if ((*p1 - *p2 )< 0)
		return -1;
	else if ((*p1 - *p2) > 0)
		return 1;
}
int main()
{
	char *p1 = "sdasd";
	char *p2 = "sdbsd";
	int count=0;;
	scanf("%d", &count);
	int ret = my_strncmp(p1, p2, count);
	if (ret == 0)
		printf("p1==p2");
	else if (ret < 0)
		printf("p1<p2");
	else if (ret>0)
		printf("p2>p1");


}