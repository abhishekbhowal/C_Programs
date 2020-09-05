#include<stdio.h>
#include<string.h>
int F[100];
void prefix(char P[])
{
	int i,j,m=strlen(P);
	F[0]=0;
	i=1;
	j=0;
	while(i<m)
	{
		if(P[i]==P[j])
		{
			F[i]=j+1;
			i++;
			j++;
		}
		else
		if(j>0)
		{
			j=F[j-1];
		}
		else
		{
			F[i]=0;
			i++;
		}
	}
}
int kmp(char s[], char p[])
{
	int n=strlen(s),m=strlen(p),i,j;
	prefix(p);
	i=0;j=0;
	while(i<n)
	{
		if(s[i]==p[j])
		{
			if(j==m-1)
				return i-j;
			else
			{
					i++;
				j++;
			}
		}
		else
		if(j>0)
			j=F[j-1];
		else
			i++;
	}
	return -1;
}
int main()
{
	char s[100],p[100];
	printf("Enter the string:");
	scanf("%s",s);
	printf("Enter the pattern:");
	scanf("%s",p);
	if(kmp(s,p))
		printf("Match\n");
	else
		printf("no\n");
	return 0;
}
