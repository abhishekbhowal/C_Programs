#include<stdio.h>
#include<malloc.h>
struct graph 
{
	int V;
	int E;
	int **Adj;
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
	g->Adj=malloc(g->V);
	for(i=0;i<g->V;i++)
		g->Adj[i]=malloc(g->V);
	if(g->Adj==NULL)
		printf("NULL");
	for(i=0;i<g->V;i++)
		for(j=0;j<g->V;j++)
			g->Adj[i][j]=0;
	for(i=0;i<g->E;i++)
	{
		printf("Enter the edges:");
		scanf("%d%d",&u,&v);
		g->Adj[u][v]=1;
		g->Adj[v][u]=1;
	}
	return g;
}

void display(G *g)
{
	int i,j;
	for(i=0;i<g->V;i++)
	{
		for(j=0;j<g->V;j++)
			printf("%d   ",g->Adj[i][j]);
		printf("\n");
	}
}

int main()
{
	G *g=NULL;
	g=create();
	display(g);
	printf("\n");
	return 0;
}
