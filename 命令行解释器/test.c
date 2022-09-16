#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#define MAX_NUM 100
#define NUM 50
int main()
{
	char instruct[MAX_NUM];
	for(;;)
	{
		char *argv[NUM]={NULL};
		instruct[0]=0;
		printf("[Zonda@VM-Virtual xshell]>: ");
		fflush(stdout);
		fgets(instruct,MAX_NUM,stdin);
		instruct[strlen(instruct-1)]='\0';
		printf("%s\n",instruct);
		const char* ret=" ";
		argv[0]=strtok(instruct,ret);
		int i=1;
		while(argv[i]=strtok(NULL,ret))
		{
			++i;
		}
		if(0==fork())
		{
			execvp(argv[0],argv);
			exit(1);
		}
		int status=0;
		waitpid(-1,&status,0);
		printf("%d\n",(status>8)&0xFF);
	}

	return 0;
}
