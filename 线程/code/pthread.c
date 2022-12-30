#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* pthreadFunc(void* args)
{
	int num=*(int*)args;
	printf("%d\n",num);
	printf("%d pthread pid=%d id=%lu\n",num,getpid(),pthread_self());
	if(3==num)
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
			//printf("%d\n",i);
		    pthread_create(p+i,NULL,pthreadFunc,(void*)&i);
		}
		//printf("p=%lu\n",p);
		printf("parentPthread pid=%d id=%lu\n",getpid(),pthread_self());
		sleep(1);
	}

	return 0;
}
