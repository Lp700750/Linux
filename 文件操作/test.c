#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
//	//int fp=open("File",O_RDONLY);
//	/	if(fp<0)
//	/	{
//	/		perror("open");
//	/		exit(1);
//	/	}
//	/	char flow[20];
//	/	ssize_t ret=read(fp,flow,strlen(flow)-1);
//	/	flow[ret]=0;
//	/	printf("%s\n",flow);
//	/
//
	//const char* flow="minitor\n";
	//write(1,flow,strlen(flow));
	char flow[20];
	read(0,flow,sizeof(flow));
	printf("%s\n",flow);

	//int fp=open("File",O_CREAT|O_WRONLY,0666);
//	if(fp<0)
//	{
//		perror("open");
//		exit(1);
//	}
//	const char* write_file="write page in file";
//	write(fp,write_file,strlen(write_file));
//	close(fp);
//
	return 0;
}
