#include<stdio.h>
void qsort(int a[],int m,int n)
{
	int i,j,v,x,k;
	if(n<=m)
		return;
	i=m-1;
	j=n;
	v=a[n];
	while(1)
	{
		do{
			i++;
		}while(a[i]<v);
		do{
			j--;
		}while(a[j]>v);
		if(i>=j)
			break;
		a[i]=a[i] ^ a[j];
		a[j]=a[i] ^ a[j];
		a[i]=a[i] ^ a[j];

	}
	a[i]=a[i] ^ a[n];
	a[n]=a[i] ^ a[n];
	a[i]=a[i] ^ a[n];
	qsort(a,m,j);
	qsort(a,i+1,n);
}
int main()
{
	int i,a[]={6,2,1,4,7,9,5,8,0,3};
	qsort(a,0,9);
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	printf("\n");
	return 0;
}
