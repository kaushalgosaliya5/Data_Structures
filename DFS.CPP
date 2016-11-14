/* Take Any graph of 5 vertices make adjacency array and input it */
#include<stdio.h>
#include<conio.h>
int top=-1;
int stack[10];
void push(int val)
{
	if(top==9)
		return;
	top++;
	stack[top]=val;
}
int pop ()
{
        int val;
	if(top==-1)
	{
		return 0;
	}
	val=stack[top];
        top--;
	return val;
}
void dfs(int adj[][5],int visited[],int start)
{
     int i=start,j,tmp;
     push(start);

     while(top!=-1)
     {
	     tmp=pop();
	     if(visited[tmp]==0)
       	{
		printf("\nVisited Node is---------%c\t",tmp+65);
		visited[tmp]=1;
		for(j=0;j<=4;j++)
		{
			if(adj[tmp][j]==1)
			{
				push(j);
			}
		}

	}
     }
}


void main()
{
	int visited[5]={0,0,0,0,0};
	int adj[5][5],i,j;
	printf("\nEnter Ajacency Matrix");
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			printf("\nEnter Value for Matrix[%d][%d]",i,j);
			scanf("%d",&adj[i][j]);
		}
		dfs(adj,visited,0);
      getch();
}
