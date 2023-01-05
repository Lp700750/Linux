#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void* pthreadFunc(void* argc)
{
  //const char* j=(const char*)argc;
  while(1)
  {
    printf("newPthread\n");
    sleep(1);
  }
}
int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,pthreadFunc,(void*)"newPthread");
  while(1)
  {
    printf("pthread\n");
    sleep(1);
  }
  
  return 0;
}
