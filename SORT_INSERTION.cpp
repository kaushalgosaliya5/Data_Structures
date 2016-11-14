#include<stdio.h>
#include<conio.h>

void main()
{
  int i,j;
  int x[5],tmp;

  for(i=0;i<5;i++)
  {
    printf("\n enter value : %d :: ",i+1);
    scanf("%d",&x[i]);
  }

  for(i=1;i<=4;i++)
  {
     j = i;

     while( j > 0 && x[j] < x[j-1])
     {
       tmp = x[j-1];
       x[j-1] = x[j];
       x[j] = tmp;

       j--;
     }
  }

  printf("\n your accending order is :: ");

  for(i=0;i<5;i++)
  {
    printf(" %d --> ",x[i]);
  }

  getch();
}