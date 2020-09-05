#include<stdio.h>
#include<malloc.h>
struct CLL
{
	int info;
	struct CLL *next;
};
typedef struct CLL node;
node *create();
node *loopStart(node *);
int loopExist(node *);
//void mid(node *);
void display(node *);
node *loop=NULL;

int main()
{
	node *head=NULL;
        head=create();
	printf("\nThe list:\n");
        display(head);
	printf("\n");
	if(loopExist(head))
		printf("LoopExist\n");
	else
		printf("Loop does not exist");
	node *tmp=loopStart(head);
	printf("\nStarting of loop:%d",tmp->info);
	printf("\n");
	
	return 0;
}
node *create()
{
	node *start=NULL,*new, *tmp;
	int n,i=0,c;
        printf("Enter the number of node for start snail:");
	scanf("%d",&c);
	printf("Enter number (-999 to exit):");
	scanf("%d",&n);
	
	i++;
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
		if(i==c)
		{
			new=(node *)malloc(sizeof(node));
			new->info=n;
			tmp->next=new;
			if(c==0||c==1)
				loop=start;
			new->next=loop;
			tmp=new;
		}
		else
		{
			new=(node *)malloc(sizeof(node));
			new->info=n;
			tmp->next=new;
			new->next=start;
			tmp=new;
			i++;
			if(i==c)
				loop=tmp;
		}
		printf("Enter a number(-999 to exit):");
		scanf("%d",&n);
	}
	return start;
}
void display(node *head)
{
	node *start=head;
	//int loopexist=loopExist(start);
	int j=0, k=0;
	//loopstart=loopStart(start);
	
	do{
		printf("->%d",start->info);
		start=start->next;
		if(start==loop)
			j++;
		
	}while(j!=2);
	printf("->%d",start->info);
}
int loopExist(node *start)
{
	node *s=start, *f=start;
	while(1)
	{
		if(s==f)
			return 1;
		s=s->next;
		f=f->next;
		f=f->next;
		if(s==NULL||f==NULL)
			return 0;
	}
}
node *loopStart(node *head)
{
	node *s=head, *f=head;
	
	while(1)
	{
		
		s=s->next;
		f=f->next;
		f=f->next;
		if(s==f)
			break;
	}
	s=head;
	while(s!=f)
	{
		s=s->next;
		f=f->next;
	}
	return s;
}
