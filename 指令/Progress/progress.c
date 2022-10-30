#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
	int i=0;
	int num=0;
	char ret[110]={0};
	char a='#';
	memset(ret,0,sizeof(ret));
	//srand((unsigned)time(NULL));
	const char* _ret="-/-|";
	for(i=0;i<100;i++)
	{
		int b=i%4;
	//	num=rand()%50000+10000;
		ret[i]=a;
		printf("[%-100s](%3d%%)[%c]\r",ret,i+1,_ret[b]);
		fflush(stdout);
		sleep(1);
	}
	printf("\n");	
	return 0;
}
