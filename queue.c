#include<stdio.h>
#include<malloc.h>
struct Queue
{
	int front;
	int rear;
	int capacity;
	int *array;
};
typedef struct Queue Q;
Q *create(int c)
{
	Q *q=(Q *)malloc(sizeof(Q));
	q->front=-1;
	q->rear=-1;
	q->capacity=c;
	q->array=(int *)malloc(q->capacity);
	return q;
}
int isFull(Q *q)
{
	return (q->rear==q->capacity-1);
}
int isEmpty(Q *q)
{
	return ((q->rear==q->front)||(q->front==-1&&q->rear==-1));
}
void enQueue(Q *q, int data)
{
	if(!isFull(q))
	{
		q->array[++q->rear]=data;
		if(q->front==-1)
			q->front=q->rear;
	}
	else
		printf("\nQueue is full. No insertion.\n");
}
void deQueue(Q *q)
{
	
	if(!isEmpty(q))
		q->front++;
	else
	{
		printf("Queue is empty. No Deletion.\n");
		q->front=-1;
		q->rear=-1;
	}
	
}
void display(Q *q)
{
	int i=q->front-1;
	printf("\nQueue is :\n");
	while(i<q->rear)
	{	
		printf("%d\t",q->array[++i]);
	}
}
int main()
{
	int n, ch,c;
	Q *q=NULL;
	printf("\nEnter capacity of the Queue:");
	scanf("%d",&c);
	q=create(c);
	while(1){
		printf("\n1. Enqueue\n2.Deque\n3.Exit");
		printf("\nEnter any one option:");
		scanf("%d",&ch);
		if(ch==3)
			break;
		else
		{
			switch(ch)
			{
				case 1:
					printf("\nEnter new number:");
					scanf("%d",&n);
					enQueue(q, n);
					display(q);
					break;
				case 2:
					deQueue(q);
					display(q);
					break;
				default:
					printf("Enter valid option");
			}
		}
	}
	return 0;
}
