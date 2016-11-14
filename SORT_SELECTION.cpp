#include<stdio.h>
#include<conio.h>

void main()
{
  int x[5];
  int i,j,tmp;

  for(i=0;i<5;i++)
  {
    printf("\n enter number :: ");
    scanf("%d",&x[i]);
  }

  printf("\n array before sorting :: ");

  for(i=0;i<5;i++)
  {
    printf("%d --> ",x[i]);
  }

  for(i=0;i<4;i++)
  {
    for(j=i+1;j<=4;j++)
    {
      if(x[i] > x[j])
      {
        tmp = x[i];
        x[i] = x[j];
        x[j] = tmp;
      }
    }
  }

  printf("\n array after sorting :: ");

  for(i=0;i<5;i++)
  {
    printf(" %d--> ",x[i]);
  }

  getch();
}