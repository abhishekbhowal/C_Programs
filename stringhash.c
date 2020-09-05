#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct LL
{
	char *str;
	struct LL *next;
};
typedef struct LL node;
unsigned long hash(unsigned char *str)
{
	unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
   	unsigned int hash = 0;
   	unsigned int i    = 0;
	int n=strlen(str);
   	for(i = 0; i < n; str++, i++)
   	{
      		hash = (hash * seed) + (*str);
   	}

   return hash;   	

}
void hashed(node **a, char *b, int n)
{
	node *new=(node *)malloc(sizeof(node));
	printf("here");
	new->str=(char *)malloc(sizeof(strlen(b)));
	strcpy(new->str,b);
	new->next=NULL;
	if(a[n]==NULL)
	{
		
		a[n]=new;
	}
	else
	{
		node *tmp=a[n];
		while(tmp->next)
			tmp=tmp->next;
		tmp->next=new;
	}
}
void display(node **a, int n)
{
	if(a[n]==NULL)
		printf("\nEmpty.\n");
	else
	{
		node *tmp=a[n];
		while(tmp)
		{
			printf("%s\t",tmp->str);
		}
	}
}
int main()
{
	char str[][20]={"sir","madam","sir","madam","ripon","sir","ripon","patgiri","madam","ripon","sir","sir","madam"};
	node *array[13];
	int n,i;
	for(i=0;i<n;i++)
		array[i]=(node *)NULL;
	for(i=0;i<13;i++)
	{
		n=hash(str[i]);
		hashed(array,str[i],n);
	}
	
	printf("%d\n",n);
	return 0;
}
