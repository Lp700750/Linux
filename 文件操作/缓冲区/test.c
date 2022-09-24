#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	//close(1);
	//int fp=open("Myfile",O_CREAT|O_WRONLY,0644);
	const char* flow="标准输出\n";
	write(1,flow,strlen(flow));
	//printf("fp=%d\n",fp);
	printf("this is a printf file!\n");
	fprintf(stdout,"this is a fprintf file!\n");
	fputs("this is a fputs file!\n",stdout);
	
	fork();
	//close(fp);
	return 0;
}
