#include<stdio.h>


void merge(int a[], int left, int mid, int right)
{
    int m = mid - left + 1;
    int n = right - mid;
    int array1[m];
    int array2[n];
    int i = 0;
    int j = 0;
 
    // Copy both sub-arrays to auxilary arrays.
 
    	for (i = 0; i < m; i++)
    	{
        	array1[i] = a[left + i];
     	}
 
        for (j = 0; j < n; j++)
        {
        	array2[j] = a[mid + j + 1];
        }
 
        i = 0;
        j = 0;
 
 
        int k;
 
        for (k = left; k <= right; k ++)
        {
            	if ( j== n )
            	{
            		a[k] = array1[i];
            		i++;
            	}
            	else if ( i == n )
            	{	
            		a[k] = array2[j];
            		j++;
            	}
            	else if (array1[i] <= array2[j])
            	{
            		a[k] = array1[i];
            		i++;
            	}
            	else
            	{
            		a[k] = array2[j];
            		j++;
            	}
    	}
}
void mergesort(int a[], int left, int right)
{
    int mid;
 
    if (left < right)
    {
        
        mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
      }
}

int main()
{
	int a[8]={6,3,7,4,1,2,8,0};
	int i;
	mergesort(a,0,7);
	for(i=0;i<8;i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
