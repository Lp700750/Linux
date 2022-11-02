#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{	
	pid_t id=fork();
	if(id<0)
	{
		perror("fork");
		exit(1);
	}
	//while(1)
	//{
	else if(id==0)
	{
		//while(1)
		//{
			//child process
			printf("pid=%d ppid=%d\n",getpid(),getppid());
			sleep(15);
			exit(0);
		//}
	}
	else
	{
		//while(1)
		//{
			//father process
			printf("pid=%d\n",getpid());
			sleep(30);
			exit(0);
		//}
	}
	return 0;
}

