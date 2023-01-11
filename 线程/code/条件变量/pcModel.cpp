#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<cstdlib>
void* consumer(void* argc)
{
  Queue<int>* q=(Queue<int>*)argc;
  while(true)
  {
    int value=0;
    q.pop(&value);
    std::cout<<消费者取到一个值:<<value<<std::endl;
  }
}
void* producter(void* argc)
{
  Queue<int>* q=(Queue<int>*)argc;
  while(true)
  {
    srand((unsigned)time(nullptr));
    int data=rand()%10+1;
    std::cout<<生产者生产了一个数据:<<data<<std::endl;
    p.push(data);
  }
}
int main()
{
  pthread_t c,p;
  Queue<int>* que=new Queue<int>();

  pthread_create(&c,nullptr,consumer,(void*)que);
  pthread_create(&p,nullptr,producter,(void*)que);

  pthread_join(c,nullptr);
  pthread_join(p,nullptr);
}
