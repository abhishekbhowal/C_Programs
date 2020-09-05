#include<stdio.h>
int main()
{
	int a=0,b,c,d,e,f,g;
	b=a++ + a++;
	c= (++b) + (b++);
	printf("%d %d  %d\n",a,b,c);
	return 0;
}
