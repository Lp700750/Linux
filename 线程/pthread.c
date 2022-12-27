#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* pthreadFunc(void* args)
{
	const char* p=(const char*)args;
	while(1)
	{
		printf("childPthread pid=%d\n",getpid());
		sleep(1);
	}
}
int main()
{
	pthread_t p;
	pthread_create(&p,NULL,pthreadFunc,(void*)"childPthread");
	while(1)
	{
		printf("parentPhtread pid=%d\n",getpid());
		sleep(1);
	}

	return 0;
}
