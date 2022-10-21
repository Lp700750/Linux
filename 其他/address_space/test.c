#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int val=10;
int main()
{
	pid_t ret=fork();
//	int ret =1;
    if(ret<0)
	{
		printf("error pid");
	}
	else if(0==ret)
	{	
		val=100;
		printf("child pid=%d,val=%d,address=%p\n",getpid(),val,&val);
	}
	else
	{	
		printf("father pid=%d,val=%d,address=%p\n",getpid(),val,&val);
	}

	return 0;
}
