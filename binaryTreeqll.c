#include<stdio.h>
#include<malloc.h>
struct BinaryTree
{
	struct BinaryTree *left;
	int data;
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
struct Stack
{
	node *top;
};
typedef struct Stack Stack;
Q *create()
{
	Q *q=(Q *)malloc(sizeof(Q));
	q->front=NULL;
	q->rear=NULL;
	return q;
}
int isEmpty(Q *q)
{
	return(q->front==NULL);
}
void enQueue(Q *q, BT *data)
{
	node *new=(node *)malloc(sizeof(node));
	new->info=data;
	new->next=NULL;
	if(q->front==NULL)
	{
		q->rear=new;
		q->front=q->rear;
	}
	else
	{
		q->rear->next=new;
		q->rear=new;
	}
}
void deQueue(Q *q)
{
	if(isEmpty(q))
		printf("\nQueue is empty: No deletion.\n");
	else
	if(q->front==q->rear)
	{
		free(q->front);
		//free(q->rear);
		q->front=q->rear=NULL;
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
	return (q->front->info);
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
BT *insert(BT *T, int n)
{
	BT *tmp;
	Q *q=create();
	BT *new=(BT *)malloc(sizeof(BT));
	new->data=n;
	new->left=NULL;
	new->right=NULL;
	if(T==NULL)
	{
		T=new;
		return T;
	}
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
			return T;
		}
		if(tmp->right)
		{
			enQueue(q, tmp->right);
		}
		else
		{
			tmp->right=new;
			deleteQ(q);
			return T;
		}
	}
	return T;
}	
void inorder(BT *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d\t",T->data);
		inorder(T->right);
	}
}
void preorder(BT *T)
{
	if(T!=NULL)
	{
		printf("%d\t",T->data);
		preorder(T->left);
		preorder(T->right);
	}
}
void postorder(BT *T)
{
	if(T!=NULL)
	{
		
		postorder(T->left);
		postorder(T->right);
		printf("%d\t",T->data);
	}
}
void levelorder(BT *T)
{
	BT *tmp;
	Q *q=create();
	if(T==NULL)
	{
		printf("\nTree is empty.");
	}
	else
	{
		enQueue(q, T);
		while(!isEmpty(q))
		{
			tmp=peek(q);
			deQueue(q);
			printf("%d\t", tmp->data);
			if(tmp->left)
			{
				enQueue(q, tmp->left);
			}
			if(tmp->right)
			{
				enQueue(q, tmp->right);
			}
		}
	}
	deleteQ(q);
	
}	
Stack *createStack()
{
	Stack *s=(Stack *)malloc(sizeof(Stack));
	s->top=NULL;
	return s;
}
int isEmptyStack(Stack *s)
{
	return (s->top==NULL);
}
void push(Stack *s, BT *t)
{
	node *new;
	if(s->top==NULL)
	{
		new=(node *)malloc(sizeof(node));
		new->info=t;
		new->next=NULL;
		s->top=new;
	}
	else
	{
		new=(node *)malloc(sizeof(node));
		new->info=t;
		new->next=s->top;
		s->top=new;
	}
}
void pop(Stack *s)
{
	node *tmp;
	if(s->top==NULL)
		printf("\nStack is empty. No deletion.\n");
	else
	if(s->top->next==NULL)
	{
		free(s->top);
		s->top=NULL;
	}
	else
	{
		tmp=s->top;
		s->top=s->top->next;
		free(tmp);
	}
}
BT *peekStack(Stack *s)
{
	return (s->top->info);
}
void inorderStack(BT *root)
{
	
	Stack *s=createStack();
	while(1)
	{
		while(root)
		{
			push(s, root);
			root=root->left;
		}
		if(isEmptyStack(s))
			break;
		root=peekStack(s);
		pop(s);
		printf("%d\t",root->data);
		root=root->right;
	}	
}
void spiral(BT *T)
{
	Stack *s1,*s2;
	BT *tmp;
	s1=createStack();
	s2=createStack();
	int i=0;
	push(s1,T);
	while(1)
	{
		if(i==0)
		{
			i=1;
			while(!isEmptyStack(s1))
			{
				tmp=peekStack(s1);
				pop(s1);
				printf("%d\t",tmp->data);
				if(tmp->left)
					push(s2, tmp->left);
				if(tmp->right)
					push(s2, tmp->right);
			}
			if(isEmptyStack(s2))
				break;
		}
		else
		{
			i=0;
			while(!isEmptyStack(s2))
			{
				tmp=peekStack(s2);
				pop(s2);
				printf("%d\t",tmp->data);
				if(tmp->right)
					push(s1, tmp->right);
				if(tmp->left)
					push(s1, tmp->left);				
			}
			if(isEmptyStack(s1))
				break;
		}
		
	}
}
int findMax(BT *T)
{
	int val,left,right,max;
	if(T!=NULL)
	{
		val=T->data;
		left=findMax(T->left);
		right=findMax(T->right);
		if(left>right)
			max=left;
		else
			max=right;
		if(val>max)
			max=val;
	}
	return max;
}
int nodeNumber(BT *T)
{
	if(T!=NULL)
		return (nodeNumber(T->left)+nodeNumber(T->right)+1);
}
int leafNumber(BT *T)
{
	static int leaf;
	if(T==NULL)
		return 0;
	if(T->left==NULL && T->right==NULL)
		return 1;
	else
		return (leafNumber(T->left)+leafNumber(T->right));
		
}
int find(BT *T, int n)
{
	if(T==NULL)
		return 0;
	else
	{
		if(n==T->data)
			return 1;
		int tmp=find(T->left,n);
		if(tmp!=0)
			return 1;
		else
			return find(T->right,n);
	}
	return 0;
	
}

int height(BT *T)
{
	int left,right;
	if(T==NULL)
		return 0;
	else
	{
		left=height(T->left);
		right=height(T->right);
		if(left>=right)
			return left+1;
		else
			return right+1;
	}
}
BT *findNode(BT *T, int n)
{
	BT *tmp;
	if(T==NULL)
		return NULL;
	else
	{
		if(n==T->data)
			return T;
		tmp=findNode(T->left,n);
		if(tmp!=NULL)
			return tmp;
		else
			return findNode(T->right,n);
	}
	return NULL;
	
}
BT *findLast(BT *T)
{

	BT *tmp,*last=T;
	Q *q=create();
	if(T==NULL)
	{
		printf("\nTree is empty.");
		return NULL;
	}
	else
	if(T->left==NULL && T->right==NULL)
		return T;
	else
	{
		enQueue(q, T);
		while(!isEmpty(q))
		{
			tmp=peek(q);
			deQueue(q);
			//printf("%d\t", tmp->data);
			if(tmp->left)
			{
				last=tmp;
				enQueue(q, tmp->left);
			}
			if(tmp->right)
			{
				enQueue(q, tmp->right);
			}
			
		}
	}
	deleteQ(q);
	return last;
}
void deleteNode(BT *T, int n)
{
	BT *tmp,*t,*last;
	if(T==NULL)
	{
		printf("\nTree is empty.\n");
		return;
	}
	else
	if(T->left==NULL && T->right==NULL)
	{
		free(T);
		T=NULL;
		return;
	}
	t=findNode(T,n);
	last=findLast(T);
	if(last->right)
	{
		t->data=last->right->data;
		tmp=last->right;
		last->right=NULL;
		free(tmp);
	}
	else
	{
		t->data=last->left->data;
		tmp=last->left;
		last->left=NULL;
		free(tmp);
	}
}
void print(int array[], int n,int k)
{
	int i=0;
	int sum=0;
	printf("\nPath %d:  ", k);
	for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]);
		sum+=array[i];
	}
	printf("  : sum : %d",sum);
}	
void path(BT *T, int array[], int n)
{
	static int k;
	if(T==NULL)
		return;
	array[n]=T->data;
	n++;
	if(T->left==NULL && T->right==NULL)
	{
		k++;
		print(array,n,k);
	}
	else
	{
		path(T->left, array, n);
		path(T->right,array,n);
	}
}
void maxSum(BT *T)
{
	BT *tmp;
	Q *q=create();
	int sum=0,max=0;
	enQueue(q, T);
	enQueue(q, NULL);
	//sum=T->data;
	while(!isEmpty(q))
	{
		tmp=peek(q);
		deQueue(q);
		if(tmp==NULL)
		{
			if(sum>max)
				max=sum;	
			//level++;
			if(!isEmpty(q))			
				enQueue(q, NULL);
			sum=0;
		}
		else
		{
			sum=sum+tmp->data;
			if(tmp->left)
			{
				enQueue(q, tmp->left);
			
			}
			if(tmp->right)
			{
				enQueue(q, tmp->right);
			
			}
		}
	}
	printf("\nThe max sum is: %d\n",max);
		
}	
int main()
{
	BT *T=NULL;
	int n, ch;
	int array[20];
	while(1)
	{
		printf("\n1. Insert\n2. Inorder \n3. Preorder \n4. Postorder \n5. Level-order Traversal \n6. Inorder Stack \n7. Spiral Traversal \n8. Max finding \n9. Number of nodes \n10. Number of leaf \n11. Find a number \n12. Height \n13. delete a node \n14. Path \n15. Max sum of level \n16. Exit\n");
		printf("Enter any one option:");
		scanf("%d",&ch);
		if(ch==16)
			break;
		else
		{
			switch(ch)
			{
				case 1:
					printf("\nEnter the number:");
					scanf("%d",&n);
					T=insert(T, n);
					break;
				case 2:
					printf("\nThe inorder traversal is:\n");
					inorder(T);
					break;
				case 3:
					printf("\nThe preorder traversal is:\n");
					preorder(T);
					break;
				case 4:
					printf("\nThe postorder traversal is:\n");
					postorder(T);
					break;
				case 5:
					printf("\nThe level-order traversal is:\n");
					levelorder(T);
					break;
				case 6:
					printf("\nThe inorder traversal by stack is:\n");
					inorderStack(T);
					break;
				case 7:
					printf("\nThe spiral traversal is:\n");
					spiral(T);
					break;
				case 8:
					printf("\nThe max number is: %d\n",findMax(T));
					break;
				case 9:
					printf("\nThe number of nodes is: %d\n",nodeNumber(T));
					break;
				case 10:
					printf("\nThe number of leaf is: %d\n",leafNumber(T));
					break;
				case 11:
					printf("\nEnter a number:");
					scanf("%d",&n);
					if(find(T,n))
						printf("\nFound");
					else
						printf("\nNot found");
					break;
				case 12:
					printf("\nThe height of the tree is: %d\n",height(T));
					break;
				case 13:
					printf("\nEnter the number to delete:");
					scanf("%d",&n);
					deleteNode(T, n);
					break;
				case 14:
					path(T,array,0);
					break;
				case 15:
					maxSum(T);
					break;
				default:
					printf("\nRe-enter valid option.\n");
			}
		}
	}
	return 0;
}

