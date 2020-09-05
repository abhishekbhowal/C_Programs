#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	int value=0;
	pid_t pid;
	pid=fork();
	if(pid<=0)
		value+=15;
	else
	if(pid>0)
	{
		wait(NULL);
		printf("\n Parent value: %d\n",value);
		//exit(0);
	}
	return 0;
}
