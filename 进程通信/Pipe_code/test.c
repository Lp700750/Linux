#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int Pipefd[2]={0};
	if(pipe(Pipefd)<0)
	{
		perror("pipe");
		exit(1);
	}
	//printf("%d,%d\n",Pipefd[0],Pipefd[1]);
	if(fork()<0)
	{
		perror("fork");
		exit(1);
	}
	else if(fork()==0)
	{
		//子进程
		close(Pipefd[0]);
		int ret=0;
		const char* flow="from child_process:hello father_process";
		while(1)
		{
			//close(Pipefd[0]);
			//const char* flow="from child_process:hello father_process";
			//write(Pipefd[1],"flow",strlen(flow));
			write(Pipefd[1],"c",1);
			printf("%d\n",ret);
			ret++;
			//sleep(1);

		}
		close(Pipefd[0]);
	}
	//父进程
	close(Pipefd[1]);
	char buffer[100]={0};
	while(1)
	{
		//close(Pipefd[1]);
		//char buffer[100]={0};
		ssize_t number=read(Pipefd[0],buffer,sizeof(buffer));
		buffer[number]=0;
		//printf("%s\n",buffer);
		sleep(10);
	}

	return 0;
}
