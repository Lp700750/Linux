#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* pthreadFunc(void* args)
{
	int p=*(int*)args;
	printf("%d pthread pid=%d id=%lu\n",p,getpid(),pthread_self());
	if(3==p)
	{
		int* ptr=NULL;
		*ptr=10;
	}
	sleep(1);
}
int main()
{
	pthread_t p[5];
	while(1)
	{
		for(int i=0;i<5;++i)
		{
		    pthread_create(p+i,NULL,pthreadFunc,(void*)&i);
		}

		printf("parentPhtread pid=%d id=%lu\n",getpid(),pthread_self());
		sleep(1);
	}

	return 0;
}
