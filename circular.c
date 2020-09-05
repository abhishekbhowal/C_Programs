#include<stdio.h>
int shift(int a[],int i,int n,int k)
{
	int mid=(i+n)/2;
	if(i>n)
		return -1;
	if(a[mid]==k)
		return mid;
	
	if(a[i]<=a[mid])
	{
		if(k<=a[mid] && k>=a[i])
			return shift(a,i,mid-1,k);
		else
			return shift(a,mid+1,n,k);
	}
	else	
	{
		if(k>=a[mid] && k<=a[n])
			return shift(a,mid+1,n,k);
		else
			return shift(a,i,mid-1,k);
	}

}
void shift(int a[],int n,int k)
{
	int
	for(i=0;i<n;i++)
	{
		tmp=a[(i+k)%n];
		a[(i+k)%n]=a[i];
	}
	
int main()
{
	int a[12]={7,8,9,10,11,12,1,2,3,4,5,6};
	printf("%d\n",shift(a,0,11,3));
	return 0;
}
