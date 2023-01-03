#include<iostream>
#include<string>
#include<pthread.h>
#include<cstdio>
#define NUM 1000
int ticketSum=1000;
void* pthreadFunc(void* argc)
{
	//std::cout<<"hello world"<<std::endl;
	int j=*(int*)argc;
	//std::cout<<"hello world"<<std::endl;
	while(1)
  {
    if(j>0)
	  {
		  //抢票
		  std::cout<<"pthread["<<pthread_self()<<"]:"<<j<<std::endl;
		  j--;
	  }
	  else
	  {
		  //没有票，停止抢票
		  return nullptr;
	  }
  }
}
int main()
{
	//int ticketSum=1000;
	pthread_t tid[3];
	for(int i=0;i<3;i++)
	{
    int *ticketId=new int(i);
    //std::cout<<"1"<<std::endl;
		pthread_create(tid+i,nullptr,pthreadFunc,(void*)ticketId);
    //std::cout<<"2"<<std::endl;
	}
	std::cout<<"hello world"<<std::endl;
	return 0;
}
