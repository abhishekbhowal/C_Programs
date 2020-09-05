#include<stdio.h>
int sum(int a[],int n)
{
	int i,sum=0,sumsofar=0,f=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
			sum=0;
		else
		{
			f=1;
			sum+=a[i];
			if(sum>sumsofar)
				sumsofar=sum;
		}
	}
	sumsofar=a[0];
	if(f==0)
		for(i=0;i<n;i++)
			if(sumsofar<a[i])
				sumsofar=a[i];

	return sumsofar;
}
int main()
{
	int a[20],i,n;
	printf("Enter the range:");
	scanf("%d",&n);
	printf("Enter the element:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Sum: %d\n",sum(a,n));
	return 0;
}
