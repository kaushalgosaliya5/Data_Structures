#include<stdio.h>
#include<conio.h>

void quicksort(int*,int,int);
int split(int*,int,int);

void main()
{
  int arr[10];
  int i;

  for(i=0;i<10;i++)
  {
    printf("\n enter value %d :: ",i+1);
    scanf("%d",&arr[i]);
  }

  printf("\n array before sorting :: ");

  for(i=0;i<10;i++)
  {
    printf(" %d ",arr[i]);
  }

  quicksort(arr,0,9);

  printf("\n array after sorting :: ");

  for(i=0;i<10;i++)
  {
    printf(" %d ",arr[i]);
  }

  getch();
}

void quicksort(int *arr,int lower,int upper)
{
   int mid;

   if(lower < upper)
   {
     mid = split(arr,lower,upper);

     quicksort(arr,lower,mid-1);
     quicksort(arr,mid+1,upper);
   }
}

int split(int *arr,int lower,int upper)
{
  int i,p,q,t;

  p = lower + 1;
  q = upper;

  i = arr[lower];

  while(p < q)
  {
    while(arr[p] < i)
    {
      p++;
    }

    while(arr[q] > i)
    {
      q--;
    }

    if(q > p)
    {
      t = arr[p];
      arr[p] = arr[q];
      arr[q] = t;
    }
  }

  t = arr[lower];
  arr[lower] = arr[q];
  arr[q] = t;

  return q;
}




