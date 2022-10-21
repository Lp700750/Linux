#include<stdio.h>
#include<unistd.h>
int main()
{
	int i=5;
	while(i)
	{
		printf("%d",i);
		--i;
		sleep(1);
	}
	retrun 0;
}
