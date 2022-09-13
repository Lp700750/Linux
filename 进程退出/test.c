#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	//验证exit的刷新缓冲区
	//printf("Jolly.Roger\n");
	//sleep(3);
	//_exit(0);
	
	//打印return返回值的退出码和错误码
	//int ret=140;
	//for(int i=0;i<ret;++i)
	//{
	//	printf("%d:%s\n",i,strerror(i));
	//}
	//return 0;
	
	//进程等待
	pid_t _pid=fork();
	if(0==_pid)
	{
		//child process
		int sum=5;
		while(sum)
		{
			printf("%d : child[%d] running\n",sum,getpid());
			--sum;
			sleep(1);
		}
		exit(0);
	}

    //如果此时没有进程的等待，那么此时的子进程将是一个孤儿进程
	sleep(10);
	pid_t child_pid=wait(NULL);
	
	//当子进程正常返回时
	if(child_pid>0)
	{
		printf("father wait : %d\n",child_pid);
	}
	else
	{	
		printf("father wait failed\n");
	}
	return 0;

}
