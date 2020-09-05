//best Answer....................

#include<stdio.h>
void addupto(int a[],int n, int k)
{
	int hash[701][2];
	int i,diff;
	for(i=0;i<n;i++)
	{
		diff=k-a[i];
		if(diff<=0)
			continue;
		hash[a[i]%701][0]=a[i];
		hash[a[i]%701][1]=diff;
		if(hash[diff][0]==diff)
			printf("\nThe number is : %d  %d\n",a[i],diff);
	}
}
int main()
{
	int a[100];
	int i,n,k;
	printf("Enter the range:");
	scanf("%d",&n);
	printf("Enter the array element:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the sum:");
	scanf("%d",&k);
	addupto(a,n,k);
	return 0;
}
