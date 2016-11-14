#include<stdio.h>
#include<conio.h>
#define max 5

void main()
{
  int x[max];
  int i,j,tmp;

  for(i=0;i<max;i++)
  {
     printf("\n enter value :: %d :: ",i+1);
     scanf("%d",&x[i]);
  }

  for(i=0;i<max;i++)
  {
    for(j=0;j<max-i;j++)
    {
      if(x[j] > x[j+1])
       {
          tmp = x[j+1];
          x[j+1] = x[j];
          x[j] = tmp;
       }
    }
  }

  printf("\n your sortint is :: ");

  for(i=0;i<max;i++)
  {
    printf(" %d --> ",x[i]);
  }

  getch();
}