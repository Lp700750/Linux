#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int i=0;
	int count=100;
	char bar[102];
	memset(bar,0,sizeof(bar));
	bar[i]='#';
	const char* rotate="-/-|\\";
	while(count)
	{
		printf("[%-100s][%d%%](%c)\r",bar,i+1,rotate[i%6]);
		fflush(stdout);
		usleep(50000);
		bar[++i]='#';
		--count;
	}
	printf("\n");
	return 0;
}
