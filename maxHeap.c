#include<stdio.h>
void maxHeapify(int a[], int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	if(l<n && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<n && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		a[i]=a[i] ^ a[largest];
		a[largest]=a[i] ^ a[largest];
		a[i]=a[i] ^ a[largest];
		maxHeapify(a,largest,n);
	}
}

void buildheap(int a[], int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		maxHeapify(a,i,n);
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
}
int main()
{
	int a[]={4,1,3,2,6,9,8,7,0};
	buildheap(a,9);
	printf("\n");
	return 0;
}
