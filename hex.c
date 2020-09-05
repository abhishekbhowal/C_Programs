#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct LL
{
	char info;
	struct LL *next;
};
typedef struct LL node;


node *create(char *str)
{
	node *start=NULL,*new;
	int i=0;
	while(str[i]!='\0')
	{
		if(start==NULL)
		{
			start=(node *)malloc(sizeof(node));
			start->info=str[i];;
			start->next=NULL;
		}
		else
		{
			new=(node *)malloc(sizeof(node));
			new->info=str[i];
			new->next=start;
			start=new;
		}
		i++;
	}
	return start;
}
void display(node *head)
{
	if(head!=NULL)
	{
		printf("->%c",head->info);
		display(head->next);
	}
}

char *strrev(char *str)
{
	int n,i=0;
	n=strlen(str);
	n--;
	while(i<n)
	{
		str[i]=str[i] ^ str[n];
		str[n]=str[i] ^ str[n];
		str[i]=str[i] ^ str[n];
		i++;
		n--;
	}
	return str;
}
int map(char ch)
{
	char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};//,"10","11","12","13","14","15","16","17","18","19","1A","1B","1C","1D","1E","1F"};
	int i,f=0;
	for(i=0;i<16;i++)
	{
		if(hex[i]==ch)
		{
			f=1;
			break;
		}
	}
	if(f==1)
		return i;
}

node *rev(node *head)
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

node *add(node *head, node *start)
{
	char hex[32][3]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","10","11","12","13","14","15","16","17","18","19","1A","1B","1C","1D","1E","1F"};
	node *result,*tmp;
	char carry='0',str[3];
	int i,j,sum;
	result=(node *)malloc(sizeof(node));
	tmp=result;
	while(head && start)
	{
		i=map(head->info);
		j=map(start->info);
		sum=i+j+carry-48;
		strcpy(str,hex[sum]);
		if(strlen(str)==1)		
		{
			tmp->info=str[0];
			tmp->next=(node *)malloc(sizeof(node));
			tmp=tmp->next;
			
			head=head->next;
			start=start->next;
		}
		else
		{
			carry=str[0];
			tmp->info=str[1];
			tmp->next=(node *)malloc(sizeof(node));
			tmp=tmp->next;
			
			head=head->next;
			start=start->next;
		}
	}
	tmp->info=carry;
	tmp->next=NULL;
	result=rev(result);
	return result;
}
	
int main()
{
	node *head1=NULL,*head2=NULL,*head3=NULL;
	char str1[100],str2[100],*tmp;
	int m=strlen(str1),n=strlen(str2);
	printf("\nEnter the first Hexadecimal Number:");
	scanf("%s",str1);
	printf("\nEnter the second Hexadecimal Number:");
	scanf("%s",str2);
	//tmp=strrev(str1);
        head1=create(str1);
	printf("\nThe list:\n");
        display(head1);
	printf("\n");
	
	//tmp=strrev(str2);
        head2=create(str2);
	printf("\nThe list:\n");
        display(head2);
	printf("\n");

	printf("Adding two Hexadecimal Numbers:");
	head3=add(head1,head2);
	display(head3);
	printf("\n");
	return 0;
}
















	
