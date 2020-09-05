#include<stdio.h>
int main()
{
	char *ptr=" Cisco System";
	*ptr++;
	printf("%s\n",ptr);
	ptr++;
	printf("%s\n",ptr);
	return 0;
}
