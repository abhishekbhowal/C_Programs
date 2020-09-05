#include<stdio.h>
#include<time.h>
#include<math.h>
#define a 16807
#define m 2147483647
#define q (m / a)
#define r (m % a)
time_t now;


long int PMrand(int i)
{
	long int seed = abs((long int)time(&now))*i;
	long int hi = seed / q;
	long int lo = seed % q;
	long int test = a * lo - r * hi;
	if(test > 0)
		seed = test;
	else	seed = test + m;
	return seed;
}
int main()
{
	int i;
	for(i=0;i<100;i++)
	printf("%ld\n",PMrand(i+13));
	printf("\n");
	return 0;
}
