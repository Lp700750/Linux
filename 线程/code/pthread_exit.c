#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
//pthread_t tid;
void* pthreadFunc(void* argc)
{
	int num=5;
	const char* str=(const char*)argc;
	//long long int ret=(long long int)argc;
	while(num)
	{
		printf("newPthread:pid=%d id=%lu\n",getpid(),pthread_self());
		num--;
		sleep(1);
		//if(3==num)
		//{
		//	pthread_cancel(ret);
		//}
	}
	//return (void*)30;
	//pthread_exit((void*)25);
}
//pthread_t tid;
int main()
{
	pthread_t tid;
	long long int id=pthread_self();

	int cnt=5;
	void* ret=NULL;
	pthread_create(&tid,NULL,pthreadFunc,(void*)&tid);
	while(cnt)
	{
		printf("pthread:pid=%d id=%lu\n",getpid(),pthread_self());
		cnt--;
		sleep(1);
		//if(3==cnt)
		//{
		//	pthread_cancel(id);
		//}
	}
	pthread_join(tid,&ret);
	printf("%d\n",(int)ret);
	printf("%lu=?=%lu\n",tid,id);	

	return 0;
}
