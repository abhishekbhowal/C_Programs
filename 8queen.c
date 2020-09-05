#include <stdio.h>
#define N 8
int a[N][N];
int check(int,int);
int main()
{
	int n=8,row,col,prev,flag,count=0,i,j;
	for(row=0;row<N;row++)
	{
		for(prev=0;prev<N;prev++)
		{
			flag=0;
			if(a[row][prev]==1)
			{
				a[row][prev]=0;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			prev=-1;
		}
		flag=0;
		for(col=prev+1;col<N;col++)
		{
			if(check(row,col))
			{
				a[row][col]=1;
				flag=1;
				break;
			}
		}
		if(row==0&&flag==0)
			break;
		else if(col==N)
			row=row-2;
		else if(row==N-1&&flag==1)
		{
			count++;
			printf("\t \t \t \t solution found %d\n",count);
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
					if(a[i][j]==1)
						printf(" \n %d row %d col",i,j);
				row=row-1;
		}
	}
	printf(" \ntotal solutions are %d",count);
	return 0;
}
int check(int row,int col)
{
	int i;
	for(i=0;i<row;i++)
	{
		if((a[row-1-i][col]==1)||(a[row-1-i][col-1-i]==1&&(col-i-1)>=0)||(a[row-1-i][col+1+i]==1&&(col+1+i<=N-1)))
			return 0;
	}
	return 1;
}
