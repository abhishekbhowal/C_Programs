#include<stdio.h>
//#include<conio.h>
int main()
{
	int i=0;
	for(i=0;i<1000;i++)
	{
		printf("--");
		for(i=0;i<1000;i++);
		printf("--");
		for(i=0;i<10;i++)
		printf("--\r");
		printf("\b");
		for(i=0;i<100;i++);
		printf("\b");
	}
	return 0;
}
