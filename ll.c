#include<stdio.h>
#include<malloc.h>
struct LL
{
	int info;
	struct LL *next;
};
typedef struct LL node;
node *create();
void mid(node *);
void display(node *);
node *reverse(node *);
void palindrome(node *);
int isEqual(node *, node *);
int main()
{
	node *head=NULL;
        head=create();
	printf("\nThe list:\n");
        display(head);
	printf("\n");
	mid(head);
	printf("\n");
	head=reverse(head);
	printf("\nThe reverse list is:\n");
	display(head);
	printf("\n");
	palindrome(head);
	return 0;
}
node *create()
{
	node *start=NULL,*new;
	int n;
	printf("Enter number (-999 to exit):");
	scanf("%d",&n);
	while(n!=-999)
	{
		if(start==NULL)
		{
			start=(node *)malloc(sizeof(node));
			start->info=n;
			start->next=NULL;
		}
		else
		{
			new=(node *)malloc(sizeof(node));
			new->info=n;
			new->next=start;
			start=new;
		}
		printf("Enter a number(-999 to exit):");
		scanf("%d",&n);
	}
	return start;
}
void display(node *head)
{
	if(head!=NULL)
	{
		printf("->%d",head->info);
		display(head->next);
	}
}

//finding middle of a list.
void mid(node *start)
{
	node *s=start, *f=start;
	if(start==NULL || start->next==NULL)
			printf("No middle");
	else{
		while(1)
		{
			//s=s->next;
			f=f->next;
			if(f->next==NULL)
			{
				printf("The middle element is: %d",s->info);
				break;
			}	
			s=s->next;
			f=f->next;
			if(f->next==NULL)
			{
				printf("The middle element is:%d",s->info);
				break;
			}
			
		}
	}
}

//check whether a list is palindrome or not.

void palindrome(node *head)
{
	node *start=head, *rev;
	rev=reverse(start);
	if(isEqual(start, rev)==1)
		printf("List is palindrome\n");
	else
		printf("List is not palindrome\n");
}

//reversing a list.
node *reverse(node *head)
{
	node *curr=head, *prev=NULL,*temp=head;
	while(temp)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	return prev;
}




int isEqual(node *head, node *start)
{
	
	if((head->info!=start->info)||(head!=NULL && start==NULL) || (head==NULL && start!=NULL))
		return 0;
	if(head==NULL && start==NULL)
		return 1;
	if(head->info==start->info)
	isEqual(head->next, start->next);
	return 0;
	
}
















	
