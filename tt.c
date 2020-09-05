#include<stdio.h>
int main()
{
	char s[]="hello worldz";
	char *p;
	p=s;
	printf("%s\n");
	while(*p!='\0')
	{
		++*p++;
	}
	printf("%s %s  %d\n",s,p,(int)main);
	return 0;
}
