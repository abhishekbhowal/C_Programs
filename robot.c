#include<stdio.h>
int perm(int i, int j,int n)
{
	
	if(i==n||j==n)
		return 1;
	else
		return perm(i+1,j,n)+perm(i,j+1,n);
	
	
}
int main()
{
	int n;
	printf("\nEnter the grid:");
	scanf("%d",&n);
	printf("%d\n",perm(0,0,n-1));
	return 0;
}
