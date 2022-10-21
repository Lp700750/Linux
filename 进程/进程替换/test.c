#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
	pid_t child_pid=fork();
	if(0==child_pid)
	{
		//char* const argv[]={"ls","-a","-l",NULL};
		printf("hihihihihihihi\n");
		sleep(5);
		//execl("/usr/bin/ls","ls","-a","-l",NULL);
		//execlp("ls","ls","-a","-l",NULL);
		execl("./test1","test1",NULL);
		//printf("hahahahahahaha\n");
		
	}
	waitpid(-1,NULL,0);
	return 0;
}
