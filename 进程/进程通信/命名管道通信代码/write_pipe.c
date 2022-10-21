#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int ret=mkfifo("Mypipe",0666);
	if(ret==-1)
	{
		perror("mkfifo");
		exit(1);
	}

	//打开文件
	int file_fd=open("Mypipe",O_WRONLY);
	if(file_fd<0)
	{
		perror("open");
		exit(1);
	}
	while(1)
	{
		printf("please enter:\n");
		char flow[100]={0};
		ssize_t num=read(1,flow,sizeof(flow));
		if(num>0)
		{
			write(file_fd,flow,strlen(flow)-1);
		}
	}
	close(file_fd);

	return 0;
}
