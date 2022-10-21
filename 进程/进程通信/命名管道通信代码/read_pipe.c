#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	char flow1[100]={0};
	int file_fd=open("Mypipe",O_RDONLY);
	while(1)
	{
		ssize_t num=read(file_fd,flow1,sizeof(flow1));
		flow1[num]=0;
		printf("%s\n",flow1);
	}

	return 0;
}
