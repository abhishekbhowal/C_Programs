#include<stdio.h>
#include<math.h>
void swap(int a[],int i,int n)
{
	a[i]=a[i] ^ a[n];
	a[n]=a[i] ^ a[n];
	a[i]=a[i] ^ a[n];
}
int Rand_Partition(int a[],int i,int n)
{
	int p=(rand()%n)+i;
	printf(" P is:%d",p);
	int tmp=a[p];
	while(1)
	{
		do{
			i++;
		}while(a[i]<tmp);
		do{
			n--;
		}while(a[i]>tmp);
			
		if(i>=n)	
			break;
		swap(a,i,n);

	}
	return p;
}
int Rand_Select(int A[], int p, int r, int i)
{
	if(p==r)
		return A[p];
	int q=Rand_Partition(A,p,r);
	int k=q-p+1;
	if(k==i)
		return A[k];
	if(i<k)
		return Rand_Select(A,p,q-1,i);
	else
		return Rand_Select(A,q+1,r,i-k);
}
int main()
{
	int a[100],i,n,k;
	printf("Enter the range:");
	scanf("%d",&n);
	printf("Enter the array element:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the kth element:");
	scanf("%d",&k);
	printf("\nThe kth element is: %d \n",Rand_Select(a,0,n,k));
	return 0;
}
