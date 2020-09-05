#include<stdio.h>
#include<string.h>
static long c=0;
void swap(char *a, char *b)
{
	char t=*a;
	*a=*b;
	*b=t;
}
void perm(char *a, int i, int n)
{
	int j;
	if(i==n)
	{
		printf("%s\n",a);
		c++;
	}
	else
	{
		for (j = i; j <= n; j++)
       		{
          		swap((a+i), (a+j));
          		perm(a, i+1, n);
          		swap((a+i), (a+j)); //backtrack
       		}
	}
}
int main()
{
	char a[20];
	int n;
	do{
		printf("Enter the string:");
		scanf("%s",a);
		perm(a,0,strlen(a)-1);
		printf("Count : %ld\n",c);
		c=0;
		printf("Enter 1/0?");
		scanf("%d",&n);
	}
	while(n==1);
	return 0;
}
