#include<stdio.h>
#include<conio.h>
#define m 10

void main()
{
  int val;
  int x[m];
  int min,mid,max;
  int i;

  printf("\n please enter value accending order \n");

  for(i=0;i<m;i++)
  {
    printf("\n enter number value : %d :: ",i+1);
    scanf("%d",&x[i]);
  }

  printf("\n enter element to search :: ");
  scanf("%d",&val);

  min = 0;
  max = m-1;

  for(mid=(min+max)/2;max >= min;mid=(min+max)/2)
  {
    if(x[mid] == val)
    {
      printf("\n your value position is : %d :: ",mid+1);
    }
    else if(x[mid] > val)
    {
      max = mid - 1;
    }
    else
    {
      min = mid + 1;
    }
  }

  if(max < min)
  {
    printf("\n value not found");
  }

  getch();
}