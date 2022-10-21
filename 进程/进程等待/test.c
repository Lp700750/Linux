#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{	
	//创建子进程
	pid_t _pid=fork();
	if(0==_pid)
	{
		int num=10;
		while(num)
		{
			printf("%d : child pid:%d\n",num,getpid());
			--num;
			sleep(1);
		}
		exit(0);
	}
	else if(_pid>0)
	{
		//如果此时父进程什么都不做的话就会退出，那么子进程就会变成孤儿进程
		sleep(10); //休息5秒钟
		int _status;
		pid_t child_pid=wait(&_status);
		//if(child_pid>0&&(_status&0XFF)==0)
		if(child_pid>0&&WIFEXITED(_status))
		{
			printf("########父进程开始执行#####\n");
			sleep(5);
			//printf("PID:%d 退出码：%d\n",child_pid,((_status>8)&0XFF));
			printf("PID:%d 退出码：%d\n",child_pid,WEXITSTATUS(_status));
		}
		else
		{
			printf("failed : %d\n",_status&0X7F);
		}
	}
	else
	{
		printf("process failed\n");
		perror("_pid");
		exit(1);
	}
	return 0;
}
