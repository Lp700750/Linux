#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	close(1);
	int fp=open("Myfile1",O_CREAT|O_WRONLY,0644);
	if(fp<0)
	{
		perror("open");
		exit(1);
	}
	printf("fp=%d\n",fp);
	fflush(stdout);
	close(fp);

	return 0;
}
