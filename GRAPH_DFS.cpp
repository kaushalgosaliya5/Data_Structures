#include<stdio.h>
#include<conio.h>
# define M 3

void depth(int x[][M],int v[],int a)
{
  int s[M];
  int top=-1,i;

  printf(" %c --> ",a+65);
  v[a] = 1;
  s[++top] = a;

  while(top != -1)
  {
    a = s[top];

    for(i=0;i<M;i++)
    {
      if(x[a][i] && v[i] == 0)
      {
        s[++top] = i;
        printf(" %c --> ",i+65);
        v[i] = 1;
        break;
      }
    }

    if(i == M)
    {
      top--;
    }
  }
}

void main()
{
  int x[M][M];
  int v[M]={0};
  int i,j;

  printf("\n enter edjency matrixx :: ");

  for(i=0;i<M;i++)
  {
    printf("\n releted avlue is %c :: ",i+65);

    for(j=0;j<M;j++)
    {
       printf("\n enter %c :: ",j+65);
       scanf("%d",&x[i][j]);
    }
  }

  printf("\n dfs is :: ");

  depth(x,v,0);

  getch();
}