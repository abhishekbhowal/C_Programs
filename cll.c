#include<stdio.h>
#include<malloc.h>
struct CLL
{
	int info;
	struct CLL *next;
};
typedef struct CLL node;
node *create();
void divide(node *);
void display(node *);

int main()
{
	node *head=NULL;
        head=create();
	printf("\nThe list:\n");
        display(head);
	printf("\n");
	divide(head);	
	return 0;
}
node *create()
{
	node *start=NULL,*new, *tmp;
	int n;
        printf("Enter number (-999 to exit):");
	scanf("%d",&n);
	
	while(n!=-999)
	{
		if(start==NULL)
		{
			start=(node *)malloc(sizeof(node));
			start->info=n;
			start->next=start;
			tmp=start;
		}
		else
		{
			new=(node *)malloc(sizeof(node));
			new->info=n;
			tmp->next=new;
			new->next=start;
			tmp=new;
			
		}
		printf("Enter a number(-999 to exit):");
		scanf("%d",&n);
	}
	return start;
}
void display(node *head)
{
	node *start=head;
		
	do{
		printf("->%d",start->info);
		start=start->next;
		
	}while(start!=head);
	printf("->%d",start->info);
}
//finding middle of a list.
void divide(node *start)
{
	node *s=start, *f=start, *head;
	if(start==NULL || start->next==NULL)
			printf("No middle");
	else{
		while(1)
		{
			//s=s->next;
			f=f->next;
			if(f->next==start)
			{
				printf("The middle element is: %d\n",s->info);
				break;
			}	
			s=s->next;
			f=f->next;
			if(f->next==start)
			{
				printf("The middle element is:%d\n",s->info);
				break;
			}
			
		}
	}
	head=s->next;
	f->next=head;
	s->next=start;
	printf("\nCircular list1:\n");
	display(start);
	printf("\nCircular list2:\n");
	display(head);
	printf("\n");

}

