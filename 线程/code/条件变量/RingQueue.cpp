#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<ctime>
#include<unistd.h>
#include<pthread.h>
#include"RingQueue.hpp"
void* consumer(void* argc)
{
	RQueue<int>* _rq = (RQueue<int>*)argc;
	while (true)
	{
		//_rq->pop();
		int value = 0;
		_rq->pop(&value);
		std::cout << "ȡ������������: " << value << std::endl;
	}
}
void* producter(void* argc)
{
	RQueue<int>* _rq = (RQueue<int>*)argc;
	while (true)
	{
		//_rq->push();
		int value = rand() % 20 + 1;
		std::cout << "�Ž�ȥ��������: " << value << std::endl;
		_rq->push(value);
		sleep(1);
	}
}
int main()
{
	//���ֽ�ɫ
	pthread_t c, p;

	//һ�ֳ���
	RQueue<int>* rq = new RQueue<int>();

	//�����������
	srand((long long)time(nullptr));
	pthread_create(&c, nullptr, consumer, (void*)rq);
	pthread_create(&p, nullptr, producter, (void*)rq);

	pthread_join(&c, nullptr);
	pthread_join(&p, nullptr);

	return 0;
}