#include<stdio.h>

int main()
{
	int n,count=0,i;
	printf("Enter the number:");
	scanf("%d",&n);	
	for (i = 5; i <n; i *= 5) 
		count += n / i;
	printf("\n %d",count);

return 0;

}
