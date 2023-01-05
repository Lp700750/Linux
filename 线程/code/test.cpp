#include<iostream>
#include<string>
#include<cstdio>
#include<pthread.h>
void* pthreadFunc(void* argc)
{
  int j=*(int*)argc;
  //std::cout<<j<<std::endl;
  printf("%d\n",j);
}
int main()
{
  pthread_t tid[3];
  for(int i=0;i<3;i++)
  {

    pthread_create(tid+i,nullptr,pthreadFunc,(void*)i);
  }
  return 0;
}
