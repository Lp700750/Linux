#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	//while(1)
	//{
	//	printf("hello Zonda pid:%d :ppid:%d\n",getpid(),getppid());
	//	sleep(1);
	//}
	int ret=fork();
	//printf("hello proc:%d,ret:%d\n",getpid(),ret);
	if(0==ret)
	{
		printf("child progress:%d ret:%d\n",getpid(),ret);
	}
	else
	{
		printf("father progress:%d ret:%d\n",getpid(),ret);
	}
	sleep(1);
	return 0;
}
