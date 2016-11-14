#include<stdio.h>
#include<conio.h>

 int q[10];
 int r=-1;
 int f=-1;

 void insert(int val)
{
  if(r==9)
	{
    	printf("\n queue is full");
	   return;
	}
   q[++r]=val;

   if(f==-1)
   {
     f=0;
   }
}

int del()
{
  int val;

  if(f==-1)
	{
   	printf("\n no value in queue");
	}

	val=q[f];

	if(f==r)
	{
	  f=r=-1;
   }
	else
	{
	  f++;
	}

	return val;
}

void dfs(int adj[5][5],int visited[],int start)
{
  int i=start,j,temp;
  insert(start);

  while(r!=-1)
	{
     temp=del();
	  if(visited[temp]==0)
		{
		   printf("\n Visited node is %c \t",temp+65);
		   visited[temp]=1;

		   for(j=4;j>=0;j--)
          {
			    if(adj[temp][j]==1)
			    insert(j);
			    printf("\nnode pushed %c",j+65);
			 }
      }
   }
}
void main()
{
  int adj[5][5];
  int visited[]={0,0,0,0,0};
  int i,j;

  for(i=0;i<5;i++)
   {
  	 for(j=0;j<5;j++)
		{
   		printf("enter the values of adjacency matrix[%d][%d]:",i,j);
	   	scanf("%d",&adj[i][j]);
		}
    }

    dfs(adj,visited,0);

   getch();
}