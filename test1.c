#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("pid:%d ppid:%d\n",getpid(),getppid());
	sleep(5);
	fork();
	printf("pid:%d ppid:%d\n",getpid(),getppid());
	sleep(1);
	return 0;
}
