#include<stdio.h>
#include<malloc.h>
struct BinaryTree
{
	struct BinaryTree *left;
	int info;
	struct BinaryTree *right;
};
typedef struct BinaryTree BT;
struct LL
{
	BT *info;
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
void enQueue(Q *q, BT *data)
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
BT *peek(Q *q)
{
	node *tmp=q->front;
	return tmp->info;
}
void deleteQ(Q *q)
{
	node *tmp;
	while(q->front!=NULL)
	{
		tmp=q->front;
		q->front=q->front->next;
		free(tmp);
	}
	q->front=q->rear=NULL;
}
BT *insertBT(BT *T, int data)
{
	Q *q=NULL;
	BT *new=(BT *)malloc(sizeof(BT));
	new->left=new->right=NULL;
	new->info=data;
	BT *tmp=NULL;
	if(T==NULL)
		T=new;
	else
	{
		q=create();
		enQueue(q, T);
		while(!isEmpty(q))
		{
			tmp=peek(q);
			deQueue(q);
			if(tmp->left)
			{
				enQueue(q, tmp->left);
			}
			else
			{
				tmp->left=new;
				deleteQ(q);
			}
			if(tmp->right)
			{
				enQueue(q, tmp->right);
			}
			else
			{
				tmp->right=new;
				deleteQ(q);
			}
		}
	}
	return T;
}
void inorder(BT *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d\t", T->info);
		inorder(T->right);
	}
}
void preorder(BT *T)
{
	if(T!=NULL)
	{		
		printf("%d\t", T->info);
		preorder(T->left);
		preorder(T->right);
	}
}
int main()
{
	BT *T=NULL;
	int ch,n;
	while(1)
	{
		printf("\n1. Insert binary tree \n2. Inorder\n3. Preorder\n4. Exit\n");
		printf("\nEnter any one option:");
		scanf("%d",&ch);
		if(ch==4)
			break;
		else
		{
			switch(ch)
			{
				case 1:
					printf("\nEnter new number:");
					scanf("%d",&n);
					T=insertBT(T, n);
					break;
				case 2:
					printf("\nThe inorder traversal is:\n");
					inorder(T);
					break;
				case 3:
					printf("\nThe inorder traversal is:\n");
					preorder(T);
					break;
				default:
					printf("\nRe-enter valid option\n");
			}
		}
	}
	return 0;
}
