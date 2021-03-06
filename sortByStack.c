#include<stdio.h>
#include<malloc.h>

struct Stack
{
	int top;
	int capacity;
	int *array;
};
typedef struct Stack stack;
stack *create(int c)
{
	
	stack *s=(stack *)malloc(sizeof(stack));
	s->capacity=c;
	s->array=(int *)malloc(s->capacity*sizeof(int));
	s->top=-1;
	return s;
}
int isEmpty(stack *s)
{
	return (s->top==-1);
}
int isFull(stack *s)
{
	return (s->top==(s->capacity-1));
}
void push(stack *s, int data)
{
	if(!isFull(s))
		s->array[++s->top]=data;
	else
		printf("\nStack is full.\n");
}
void pop(stack *s)
{
	if(!isEmpty(s))
		s->top--;
	else
		printf("\nStack is Empty.\n");
}
int peek(stack *s)
{
	if(!isEmpty(s))
		return (s->array[s->top]);
	//else
	//	printf("\nStack is Empty.\n");
}
void display(stack *s)
{
	printf("\nThe stack is:\n");
	int i=s->top;	
	while(i!=-1)
		printf("%d\t", s->array[i--]);
	printf("\n");
}

int main()
{
	int n;
	int ch,c;
	stack *s1=NULL,*s2=NULL ;
	printf("\nEnter capacity of the stack:");
	scanf("%d",&c);
	s1=create(c);
	s2=create(c);
	printf("\nEnter number:");
	scanf("%d",&n);
	while(n!=-999)
	{
		if(isEmpty(s1))
			push(s1, n);		
		else
		{
			while((peek(s1)<n)&& !isEmpty(s1))
			{
				push(s2, peek(s1));
				pop(s1);
				
			}
			push(s1, n);
		}
		while(!isEmpty(s2))
		{
			push(s1, peek(s2));
			pop(s2);
			
		}
	
		printf("\nEnter numbe (-999 to exit):");
		scanf("%d",&n);
	}
	display(s1);
	
	
	return 0;
}
	
