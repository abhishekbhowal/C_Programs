#include<stdio.h>
#include<malloc.h>
struct list
{
	int vno;
	struct list *next;
};
typedef struct list node;
struct graph 
{
	int V;
	int E;
	int *Adj;
};
typedef struct graph G;

G *create()
{
	int i,j,u,v;
	G *g=(G *)malloc(sizeof(G));
	printf("\nEnter vetex number:");
	scanf("%d",&g->V);
	printf("Enter edge number:");
	scanf("%d",&g->E);
	g->Adj=malloc(g->V*sizeof(node));
	for(i=0;i<g->V;i++)
	{
		g->Adj[i]=(node *)malloc(sizeof(node));
		g->Adj[i]=i;
		g->Adj[i]->next=NULL;
	}
	for(i=0;i<g->E;i++)
	{
		printf("Reading Edges:");
		scanf("%d%d",&x,&y);
		
	
	
	return g;
}

int main()
{
	G *g=NULL;
	g=create();
	display(g);
	printf("\n");
	return 0;
}
