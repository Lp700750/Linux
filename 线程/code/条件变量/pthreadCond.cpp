#include<iostream>
#include<unistd.h>
#include<string>
#include<pthread.h>
#include<cstdio>
using namespace std;
pthread_cond_t cond;
pthread_mutex_t mtx;
void* pthreadFunc1(void* argc)
{
  sleep(2);
  pthread_cond_signal(&cond);
}
void* pthreadFunc2(void* argc)
{
  pthread_cond_wait(&cond,&mtx);
  cout<<"Jolly.Roger"<<endl;
}
int main()
{
  pthread_t t1,t2;
  pthread_cond_init(&cond,nullptr);
  pthread_mutex_init(&mtx,nullptr);
  
  pthread_create(&t1,nullptr,pthreadFunc1,nullptr);
  pthread_create(&t2,nullptr,pthreadFunc2,nullptr);

  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mtx);
  
  return 0;
}
