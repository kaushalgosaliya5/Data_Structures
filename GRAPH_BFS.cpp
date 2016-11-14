#include<stdio.h>
#include<conio.h>
# define M 4

void breath(int x[][M],int v[],int start)
{
  int q[M],rear=-1,front=-1,i;

  q[++rear]=start;
  v[start]=1;

  while(rear != front)
  {
    start = q[++front];

    if(start==4)
    {
      printf("5--> ");
    }
    else
    {
      printf("%c \t",start+65);
    }

    for(i=0;i<M;i++)
    {
      if(x[start][i]==1 && v[i]==0)
      {
        q[++rear] = i;
        v[i] = 1;
      }
    }
  }
}

void main()
{
  int v[M] = {0};
  int x[M][M];
  int i,j;

  for(i=0;i<M;i++)
  {
    printf("\n releted of :: %c",i+65);

    for(j=0;j<M;j++)
    {
      printf("\n enter value %c:: ",j+65);
      scanf("%d",&x[i][j]);
    }
  }

  breath(x,v,0);

  getch();
}
