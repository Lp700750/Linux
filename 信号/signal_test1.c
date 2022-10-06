#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void sig_function(signo)
{
	printf("this is %d command\n",signo);
	exit(1);
}
int main()
{
	signal(2,sig_function);
	while(1)
	{
		printf("this is a signal!\n");
		sleep(3);
	}

	return 0;
}
