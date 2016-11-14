#include<stdio.h>
#include<conio.h>
# define MAX 10

void merge(int *arr,int beg,int mid,int end)
{
   int i=beg;
   int j=mid+1;
   int index = beg;
   int tmp[MAX],k;

   while((i <= mid) && (j <= end))
   {
     if(arr[i] < arr[j])
     {
       tmp[index] = arr[i];
       i++;
     }
     else
     {
       tmp[index] = arr[j];
       j++;
     }

     index++;
   }

   if(i > mid)
   {
     while(j <= end)
     {
       tmp[index] = arr[j];
       j++;
       index++;
     }
   }
   else
   {
     while(i <= mid)
     {
       tmp[index] = arr[i];
       i++;
       index++;
     }
   }

   for(k=beg;k<index;k++)
   {
     arr[k] = tmp[k];
   }
}

void mergesort(int *arr,int beg,int end)
{
  int mid;

  if(beg < end)
  {
    mid = (beg+end) / 2;

    mergesort(arr,beg,mid);
    mergesort(arr,mid+1,end);

    merge(arr,beg,mid,end);
  }
}

void main()
{
  int arr[MAX],i;

  printf("\n enter 10 element :: ");

  for(i=0;i<MAX;i++)
  {
    printf("\n enter element :: ");
    scanf("%d",&arr[i]);
  }

  printf("\n before sorting :: ");

  for(i=0;i<MAX;i++)
  {
      printf(" %d ",arr[i]);
  }

  mergesort(arr,0,MAX-1);

  printf("\n after sorting :: ");

  for(i=0;i<MAX;i++)
  {
    printf(" %d ",arr[i]);
  }

 getch();
}