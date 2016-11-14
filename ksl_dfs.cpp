#include<stdio.h>
#include<conio.h>
# define MAX 5

void dfs(int a[][MAX],int v[MAX],int s)
{
   int st[MAX];
   int top=-1;
   int i;

   v[s] = 1;
   printf(" %c ",s+65);
   st[++top] = s;

   while(top != -1)
   {
     s = st[top];

     for(i=0;i<MAX;i++)
     {
       if(a[s][i] == 1 && v[i] == 0)
       {
         st[++top] = i;
         printf(" %c ",i+65);
         v[i] = 1;
         break;
       }
     }

     if(i==MAX)
     {
       top--;
     }
   }
}

void main()
{
  int a[MAX][MAX];
  int v[MAX]={0};
  int i,j;


  for(i=0;i<MAX;i++)
  {
    printf("\n value in enter %c ",i+65);

    for(j=0;j<MAX;j++)
    {
      printf("\n enter value [%c][%c] :: ",i+65,j+65);
      scanf("%d",&a[i][j]);
    }
  }

  printf("\n dfs is :: ");

  dfs(a,v,0);

 getch();
}