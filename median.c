#include<stdio.h>
 
int median(int arr[], int n)
{
  if(n%2 == 0)
    return (arr[n/2] + arr[n/2-1])/2;
  else
    return arr[n/2];
}

int max(int x, int y)
{
    return x > y? x : y;
}
 
int min(int x, int y)
{
    return x > y? y : x;
}

int getMedian(int a[], int alo, int ahi, int b[], int blo, int bhi)
{
  	int m1;
  	int m2;
 	int amid=alo+(ahi-alo)/2;
	int bmid=blo+(bhi-blo)/2;
  	if((ahi-alo+bhi-blo)<= 0)
    		return -1;
 
  	if((ahi-alo+bhi-blo) == 1)
    		return (a[alo] + b[blo])/2;
 
  	if ((ahi-alo+bhi-blo) <=4)
    		return (max(a[alo], b[blo]) + min(a[ahi], b[bhi])) / 2;
 
  	m1 = median(a, ahi-alo); 
  	m2 = median(b, bhi-blo); 
 
 
  	if(m1 == m2)
    		return m1;
 
 
  	if (m1 < m2)
    		return getMedian(a, amid+1,ahi,b,blo,bmid);
 
 
  	return getMedian(a,alo,amid,b,bmid+1,bhi);
}
 

int main()
{
  int ar1[] = {1, 2, 4, 6, 8};
  int ar2[] = {0,3,5,7,9};
  printf("%d\n", getMedian(ar1,0,5, ar2,0,5)) ;
 
  //getchar();
  return 0;
}
 


 


