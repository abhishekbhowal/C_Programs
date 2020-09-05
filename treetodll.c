#include<stdio.h>
#include<malloc.h>
struct BST 
{
	struct BST *left;
	int info;
	struct BST *right;
};
typedef struct BST node;
node *insert(node *T, int data)
{
	if(T==NULL)
	{
		T=(node *)malloc(sizeof(node));
		T->info=data;
		T->left=NULL;
		T->right=NULL;
		return T;
	}
	else
	{
		node *root=T;
		node *new=(node *)malloc(sizeof(node));
		new->info=data;
		new->left=NULL;
		new->right=NULL;
		while(1)
		{
			if(new->info < T->info && T->left!=NULL)
				T=T->left;
			else
			if(new->info>=T->info && T->right!=NULL)
				T=T->right;
			else
			if(new->info<T->info)
			{
				T->left=new;
				break;
			}
			else
			{
				T->right=new;
				break;
			}
		}
		return root;
	}
				
				
}
void inOrder(node *T)
{
	if(T!=NULL)
	{
		inOrder(T->left);
		printf("%d\t",T->info);
		inOrder(T->right);
	}
}
void preOrder(node *T)
{
	if(T!=NULL)
	{
		printf("%d\t",T->info);
		preOrder(T->left);
		preOrder(T->right);
	}
}
void postOrder(node *T)
{
	if(T!=NULL)
	{
		postOrder(T->left);
		postOrder(T->right);
		printf("%d\t",T->info);
	}
}

node *findMax(node *T)
{
	if(T->right==NULL)
		return T;
	else
		findMax(T->right);
}
node *findMin(node *T)
{
	if(T->left==NULL)
		return T;
	else
		findMin(T->left);
}
node *deleteT(node *T, int n)
{
	node *tmp=NULL;
	if(T==NULL)
		printf("\nData not found in the tree.\n");
	else
	if(n>T->info)
		T->right=deleteT(T->right,n);
	else
	if(n<T->info)
		T->left=deleteT(T->left,n);
	else
	{
		if(T->left && T->right)
		{
			tmp=findMax(T->left);
			T->info=tmp->info;
			T->left=deleteT(T->left, T->info);
		}
		else
		{
			tmp=T;
			if(T->left==NULL)
				T=T->right;
			else
				T=T->left;
			free(tmp);
		}
	}
	return T;
}
node *findLCA(node *T, int a, int b)
{
	if(T==NULL)
	{
		printf("\nNo LCA possible.\n");
		return NULL;
	}
	else
	if(a<T->info && b>T->info)
		return T;
	else
	if(a<T->info && b<T->info)
		findLCA(T->left, a, b);
	else
		findLCA(T->right, a, b);
}



void treeToDoublyLinkedList(node *p, node **prev, node **head)
{
 	if (!p) 
		return;
  	treeToDoublyLinkedList(p->left, prev, head);
  	p->left = prev;
  	if (prev)
    		prev->right = p; 
  	else
    		*head = p; 
  	node *right = p->right;
  	head->left = p;
  	p->right = head;
  	*prev = p;
  	treeToDoublyLinkedList(right, prev, head);
}
 
node *treeToDoublyList(node *root) {
  node *prev = NULL;
  node *head = NULL;
  treeToDoublyLinkedList(root, prev, head);
  return head;
}
void display(node *h)
{
	printf("\nThe double linked list is:\n");
	while(h->right!=NULL)
		printf("%d\t",h->info);
}


int main()
{
	int ch, n, m;
	node *T=NULL, *tmp=NULL;
	node *h=NULL;
	while(1)
	{
		printf("\n1. Insert \n2. Inorder \n3. Preoder \n4. Postorder\n5. Find max\n6. Find Min\n7. Delete a node \n8. LCA \n9. Tree to Double Linked List \n10. Exit\n");
		printf("Enter any option:");
		scanf("%d",&ch);
		if(ch==10)
			break;
		else
		{
			switch(ch)
			{
				case 1:
					printf("\nEnter number:");
					scanf("%d",&n);
					T=insert(T, n);
					break;
				case 2:
					printf("\nThe inorder traversal of tree is:\n");
					inOrder(T);
					break;
				case 3:
					printf("\nThe preorder traversal of tree is:\n");
					preOrder(T);
					break;
				case 4:
					printf("\nThe postorder traversal of tree is:\n");
					postOrder(T);
					break;
				case 5:
					tmp=findMax(T);
					printf("\nThe maximum number is: %d",tmp->info);
					break;
				case 6:
					tmp=findMin(T);
					printf("\nThe minimum number is: %d",tmp->info);
					break;
				case 7:
					printf("\nEnter the number to delete:");
					scanf("%d",&n);
					T=deleteT(T, n);
					break;
				case 8:
					printf("\nEnter the two numbers to find LCA:");
					scanf("%d%d",&n, &m);
					tmp=findLCA(T, n, m);
					printf("\nTheLCA between %d and %d is: %d",n,m,tmp->info);
					break;
				case 9:
					h=treeToDoublyList(T);
					display(h);
					break;
				default:
					printf("\nRe-enter valid option.");
			}
		}
	}
	return 0;
}

