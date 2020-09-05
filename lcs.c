#include<stdio.h>
#include<string.h>
#include<malloc.h>
void lcs(char *x, char *y)
{
	int m,n,i,j;
	int a[20][20];
	m=strlen(x);
	n=strlen(y);
	/*a=(int **)malloc(sizeof(int)*m);
	for(i=0;i<m;i++)
		a[i]=(int *)malloc(sizeof(int)*n);*/
	for(i=0;i<=m;i++)
		a[i][0]=0;
	for(j=0;j<=n;j++)
		a[0][j]=0;
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(*(x+i)==*(y+j))
			{
				a[i][j]=a[i-1][j-1]+1;
			}
			else
			if(a[i][j-1]>a[i-1][j])
				a[i][j]=a[i][j-1];
			else
				a[i][j]=a[i-1][j];
		}
	}
	i=0; j=0;
	while(i<m&&j<n)
	{
		if(x[i]==y[j])
		{
			printf("%c",x[i]);
			i++; j++;
		}
		else
		if(a[i+1][j]>a[i][j+1])
			i++;
		else
			j++;
	}
}
int main()
{
	char x[20],y[30];
	printf("Enter the two sting:");
	scanf("%s%s",x,y);
	lcs(x,y);
	printf("\n");
	return 0;
}
