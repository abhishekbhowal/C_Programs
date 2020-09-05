
//No. of possibility to represent 1 cent , 5 cent, 10 cent, 25 cent for n cent.
#include<stdio.h>
int makeChange(int n, int denom) {
	
	int next_denom = 0,i,ways=0;
	
	switch (denom) {
	
		case 25:
		
			next_denom = 10;

			break;
	
		case 10:
		
			next_denom = 5;
		
			break;
	
		case 5:
		
			next_denom = 1;
		
			break;
	
		case 1:
		
			return 1;
	
	}
	
	
	
	for ( i = 0; i * denom <=n;i++)
		
		ways += makeChange(n - i*denom, next_denom);
	
	
	return ways;
}
	
int main()
{
	int n;
	printf("Enterthe cent:");
	scanf("%d",&n);
	printf("%d\n",makeChange(n,25));
	return 0;
}


