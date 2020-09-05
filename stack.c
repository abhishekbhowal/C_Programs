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
		return (s->array[s->top-1]);
	else
		printf("\nStack is Empty.\n");
}
void display(stack *s)
{
	printf("\nThe stack is:\n");
	int i=s->top;	
	while(i!=-1)
		printf("%d\t", s->array[i--]);
	
}
void doubleStack(stack *s)
{
	s->capacity=s->capacity*2;
	s->array=(int *)realloc(s->array,s->capacity);
}

int main()
{
	int n;
	int ch,c;
	stack *s=NULL;
	printf("\nEnter capacity of the stack:");
	scanf("%d",&c);
	s=create(c);

	while(1)
	{
		
		printf("\n Main Menu\n");
		printf("1. Push\n2. Pop\n3.Peek\n4.Double the capacity of stack \n5.Exit\n");
		printf("\nEnter a option:");
		scanf("%d",&ch);
		if(ch==5)
		break;
		else
		{
			switch(ch)
			{
				case 1:
					printf("\nEnter a number:");
					scanf("%d",&n);
					push(s, n);
					display(s);
					break;
				case 2:
					pop(s);
					display(s);
					break;
				case 3:
					printf("Peeking the stack: %d\n",peek(s));
					break;
				case 4:
					doubleStack(s);
					break;
				default:
					printf("Re-enter valid option");
			}
		}
	}
	return 0;
}
	
