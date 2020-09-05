//complexity is c(n)=(2n)!/((n+1)!n!)
#include<stdio.h>
#include<string.h>
static long c=0;
void catalan(char *a, int open, int close, int n)
{
	char t[201];
	if(open>n || close>n)
		return;
	if(close>open)
		return;
	if(strlen(a)==2*n)
	{
			printf("%s\n",a);
			c++;
	}		
	
	strcpy(t,a);
	strcat(t,")");
	catalan(t,open,close+1,n);
	strcpy(t,a);
	strcat(t,"(");
	catalan(t,open+1,close,n);
		
}
int main()
{
	int n,ch;
	do{
		printf("\nEnter the number:");
		scanf("%d",&n);
		catalan("(",1,0,n);
		printf("\nThe catalan number is: %ld\n",c);
		printf("\nWant to run again(1/0)?");
		scanf("%d",&ch);
	}
	while(ch==1);
	return 0;
}
