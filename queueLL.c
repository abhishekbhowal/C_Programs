#include<stdio.h>
#include<malloc.h>
struct LL
{
	int info;
	struct LL *next;
};
typedef struct LL node;
struct Queue
{
	node *front;
	node *rear;
};
typedef struct Queue Q;
Q *create()
{
	Q *q;
	node *tmp;
	q=(Q *)malloc(sizeof(Q));
	tmp=(node *)malloc(sizeof(node));
	q->front=q->rear=NULL;
	return q;
}
isEmpty(Q *q)
{
	return (q->front==NULL);
}
void enQueue(Q *q, int data)
{
	node *tmp=(node *)malloc(sizeof(node));
	if(!tmp)
	{
		printf("\nNo memory");
		return;
	}
	
	tmp->info=data;
	tmp->next=NULL;
	if(q->rear==NULL)
		q->front=q->rear=tmp;
	else
	{
		q->rear->next=tmp;
		q->rear=tmp;
	}
			
	
}
void deQueue(Q *q)
{
	if(isEmpty(q))
	{
		q->front=q->rear=NULL;
		printf("\nQueue is empty: No deletion.\n");
	}
	else
	{
		node *tmp=q->front;
		q->front=q->front->next;
		free(tmp);
	}
}
void display(Q *q)
{
	node *tmp=q->front;
	printf("\nThe Queue is:\n");
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->info);
		tmp=tmp->next;
	}
}
int main()
{
	Q *q;
	int ch,n;
	q=create();
	while(1)
	{
		printf("\n1. Enqueue \n2. Dequeue \n3.Exit\n");
		printf("Enter any option:");
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
					enQueue(q,n);
					display(q);
					break;
				case 2:
					deQueue(q);
					display(q);
					break;
				default:
					printf("\nRe-enter valid option.");
			}
		}
	}
	return 0;
}
