//not solved................

#include<stdio.h>
int output[100];
int Min(int a,int b)
{
	return (a<b?a:b);
}
int getCoin(int total, int n, int d[])
{
	int i;
	if(total<0)
		return -1;
	if(total==0)
		return 0;
	int ans=999999;
	for(i=0;i<n;i=i+1)
		return ans=Min(ans,getCoin(total-d[i],n,d)+1);
	
}
int main()
{
	int t,i,n,d[100];
	printf("Enter the total money:");
	scanf("%d",&t);
	printf("Enter the number of coins:");
	scanf("%d",&n);
	printf("Enter the denominations:");
	for(i=0;i<n;i++)
		scanf("%d",&d[i]);
	printf("Min Total: %d\n",getCoin(t,n,d));
	return 0;
}
