#include <stdio.h>
#include <math.h>
#include<string.h>
void printPowerSet(char *set, int n)
{
    	unsigned int pow_set_size = pow(2, n);
    	int counter, j,c=0;
 
    	for(counter = 0; counter < pow_set_size; counter++)
    	{
      		for(j = 0; j < n; j++)
       		{
            		if(counter & (1<<j))
			{
          			printf("%c", set[j]);
				
			}
       		}
       	printf("\n");
	c++;
    	}
	printf(" The count: %d \n",c);
	
}

int main()
{
    	char set[100];
	printf("Enter the string:");
	scanf("%s",set);
    	printPowerSet(set, strlen(set));
 
    	getchar();
    	return 0;
}
