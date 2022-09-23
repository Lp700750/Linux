#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
	int fp=open("Myfile",O_WRONLY|O_CREAT,0666);
	if(fp<0)
	{
		perror("open");
		exit(1);
	}

	//文件的写操作
	const char* flow="this is write operation!\n"; 
	ssize_t ret=write(fp,flow,strlen(flow));
	
	//文件的读操作
	char _flow[50];
	//const char* _flow="thid is read operation!\n";
	ssize_t _ret=read(fp,_flow,strlen(flow));
	//_flow[_ret]=0;
	printf("%d %s\n",fp,_flow);
	fflush(stdout);
	close(fp);

	return 0;
}
