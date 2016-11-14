#include<stdio.h>
#include<conio.h>
# define MAX 5

void breath(int a[][MAX],int v[],int s)
{
  int q[MAX],i;
  int r=-1,f=-1;

  q[++r] = s;
  v[s] = 1;

  while(r != f)
  {
    s = q[++f];

    printf("\t %c ",s+65);

    for(i=0;i<MAX;i++)
    {
      if(a[s][i] == 1 && v[i] == 0)
      {
         q[++r]=i;
         v[i] = 1;
      }
    }
  }
}

void main()
{
  int v[MAX]={0};
  int a[MAX][MAX],i,j;

  printf("\n eenter adjacency matrix :: ");

  for(i=0;i<MAX;i++)
  {
    printf("\n related of  %c :: ",i+65);

    for(int j=0;j<MAX;j++)
    {
      printf("\n enter value [%c][%c] :: ",i+65,j+65);
      scanf("%d",&a[i][j]);
    }
  }

  breath(a,v,0);

  getch();
}