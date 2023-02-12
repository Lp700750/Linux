#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void* pthread_run(void* ret)
{
	const char* id=(const char*)ret;
	//while(1)
	//{
		printf("%s id:%d\n",id,pthread_self());
		sleep(6);
		break;
	//}
	
	return (void*)1014; 
}
int main()
{
	pthread_t pth_id;
	void* status=NULL;
	pthread_create(&pth_id,NULL,pthread_run,NULL);
	pthread_join(pth_id,&status);
	printf("return code:%d\n",(int)status);
	//while(1)
	//{
	//	printf("main pthread  id:%d\n",pth_id);
	//	sleep(1);
	//}

	return 0;
}
