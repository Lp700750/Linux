#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
void* pthreadFunc(void* args)
{
	//printf("newPthread\n");
	const char* str=(const char*)args;
	printf("%s:pid=%d tid=%lu\n",str,getpid(),pthread_self());
	//printf("new:pid=%d tid=%lu\n",getpid(),pthread_self());
	
	return (void*)30; 
}
int main()
{
	pthread_t tid;
	void* ret=NULL;
	pthread_create(&tid,NULL,pthreadFunc,(void*)"newPthread");
	
	printf("pthread:pid=%d tid=%lu\n",getpid(),pthread_self());
	pthread_join(tid,&ret);
	printf("%d\n",(int)ret);

	return 0;
}
