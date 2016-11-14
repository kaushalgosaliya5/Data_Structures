#include<stdio.h>
#define MAX 3

void main()
{
  int i,x[MAX],key;

  printf("\n | ----- linear searching ----- | \n");


  for(i=0;i<MAX;i++)
  {
     printf("\n enter number %d :: ",i+1);
     scanf("%d",&x[i]);
  }

  printf("\n enter element to search :: ");
  scanf("%d",&key);

  for(i=0;i<MAX;i++)
  {
    if(x[i] == key)
    {
      printf("\n value is found on %d position ",i+1);
      break;
    }
  }

  if(i==MAX)
  {
    printf("\n value not found");
  }

  scanf("%d");
}