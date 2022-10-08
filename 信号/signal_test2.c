#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void show(sigset_t* pending)
{
	printf("pending show:");
	for(int i=1;i<32;++i)
	{
		if(sigismember(pending,i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}
int main()
{
	//屏蔽掉对应的信号
	sigset_t new_signal,old_signal;
	sigemptyset(&new_signal);
	sigemptyset(&old_signal);
	
	//将2号信号给屏蔽掉
	sigaddset(&new_signal,2);
	sigprocmask(SIG_SETMASK,&new_signal,&old_signal);
	
	sigset_t pending;
	
	//清空初始pending位图
	//sigemptyset(&pending);

	while(1)
	{
		//清空初始pending位图
		sigemptyset(&pending);
		sigpending(&pending);
		//show(&pending);
		//printf("Jolly.Roger\n");
		sleep(1);
	}

	return 0;
}
