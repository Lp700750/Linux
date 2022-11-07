#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int value=10;
int main()
{
	pid_t pid_num=fork();
	if(pid_num<0)
	{
		perror("fork");
		exit(1);
	}
	else if(pid_num==0)
	{
		//child process
		value=20;
		printf("child[%d]->%d %p\n",getpid(),value,&value);
	}
	else
	{
		//father process
		sleep(3);
		printf("father[%d]->%d %p\n",getpid(),value,&value);
	}

	return 0;
}
