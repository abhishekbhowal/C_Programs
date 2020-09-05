#include<stdio.h>
void countsort(int a[], int n,int k)
{
	int i;
	int b[k+1],c[n];
	for(i=0;i<=k;i++)
		b[i]=0;
	for(i=0;i<n;i++)
		b[a[i]]+=1;
	for(i=1;i<=k;i++)
		b[i]=b[i]+b[i-1];
	for(i=n-1;i>=0;i--)
	{
		c[b[a[i]]]=a[i];
		b[a[i]]-=1;
	}
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
		printf("%d   ",c[i]);
	printf("\n");
}
int main()
{
	int a[18]={5,3,4,2,1,0,0,2,0,1,3,4,3,2,1,0,1,5};
	countsort(a,18,5);
	return 0;
}

