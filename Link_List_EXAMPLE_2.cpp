#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *lptr;
  struct node *rptr;
}*first=NULL,*first1=NULL;

void ins_first(int);
void ins_last(int);
void ins_after(int,int);
void ins_before(int,int);

void dlt_first();
void dlt_last();
void dalete(int);

void sorte();
void splite(int);
void merge();
void count();

void display();

void main()
{
  int val,ch,num;

  do
  {
    clrscr();

  printf("\n |--------- menu ---------|");
  printf("\n   1.insert first ");
  printf("\n   2.insert last  ");
  printf("\n   3.insert after ");
  printf("\n   4.insert before");
  printf("\n   5.delete first ");
  printf("\n   6.delete last  ");
  printf("\n   7.delete specific node ");
  printf("\n   8.sorting  ");
  printf("\n   9.spliting ");
  printf("\n  10.merging  ");
  printf("\n  11.counting ");
  printf("\n  12.display ");
  printf("\n  13.EXIT");
  printf("\n |------------------------|");

  printf("\n enter your choice :: ");
  scanf("%d",&ch);

  switch(ch)
  {
     case 1:
              printf("\n insert first node value :: ");
              scanf("%d",&val);

              ins_first(val);
              break;

     case 2:
             printf("\n insert last node value :: ");
             scanf("%d",&val);

             ins_last(val);
             break;

     case 3:
             printf("\n enter value which node after insert :: ");
             scanf("%d",&num);

             printf("\n enter value :: ");
             scanf("%d",&val);

             ins_after(num,val);
             break;

     case 4:
             printf("\n enter value which node before insert :: ");
             scanf("%d",&num);

             printf("\n enter value :: ");
             scanf("%d",&val);

             ins_before(num,val);
             break;

     case 5:
             dlt_first();
             break;

     case 6:
             dlt_last();
             break;

     case 7:
             printf("\n enter your delete node vaue :: ");
             scanf("%d",&val);

             dalete(val);
             break;

     case 8:
             sorte();
             break;

     case 9:
             printf("\n enter value which node to splite :: ");
             scanf("%d",&num);

             splite(num);
             break;

     case 10:
              merge();
              break;

     case 11:
              count();
              break;

    case 12:
             printf("\n ");
             display();
             break;

    case 13:
             printf("\n your program is EXIT");
             getch();
             break;

    defalut :
             printf("\n your choice is wrong");
             getch();
             break;
  }

 }while(ch != 13);
}

void ins_first(int val)
{
  struct node *new1;

  new1 = (struct node *)malloc(sizeof(struct node));
  new1 -> data = val;
  new1 -> lptr = NULL;

  if(first == NULL)
  {
    new1 -> rptr = NULL;
    first = new1;
    return;
  }

  new1 -> rptr = first;
  first -> lptr = new1;
  first = new1;
}

void ins_last(int val)
{
  struct node *curt,*new1;

  new1 = (struct node *)malloc(sizeof(struct node));
  new1 -> data = val;
  new1 -> rptr = NULL;

  if(first == NULL)
  {
    new1 -> lptr = NULL;
    first = new1;
    return;
  }

  curt = first;

  while(curt -> rptr != NULL)
  {
    curt = curt -> rptr;
  }

  new1 -> lptr = curt;
  curt -> rptr = new1;
}

void ins_after(int num,int val)
{
  struct node *new1,*curt;

  new1 = (struct node *)malloc(sizeof(struct node));
  new1 -> data = val;

  if(first == NULL)
  {
     printf("\n your link list is NULL");
     getch();
     return;
  }

  curt = first;

  while(curt -> data != num && curt != NULL)
  {
     curt = curt -> rptr;

     if(curt == NULL)
     {
       printf("\n your value is not found");
       getch();
       return;
     }
  }

  new1 -> lptr = curt;
  new1 -> rptr = curt -> rptr;
  curt -> rptr = new1;
  if(new1 -> rptr != NULL)
  {
    new1 -> rptr -> lptr = new1;
  }
}

void ins_before(int num,int val)
{
  struct node *new1,*curt;

  new1 = (struct node *)malloc(sizeof(struct node));
  new1 -> data = val;

  if(first == NULL)
  {
    printf("\n your link list is EMPTY");
    getch();
    return;
  }

  curt = first;

  while(curt -> data != num && curt != NULL)
  {
    curt = curt -> rptr;

    if(curt == NULL)
    {
      printf("\n your value is not found");
      getch();
      return;
    }
  }

  new1 -> lptr = curt -> lptr;
  new1 -> rptr = curt;
  curt -> lptr = new1;

  if(new1 -> lptr != NULL)
  {
    new1 -> lptr -> rptr = new1;
  }
  else
  {
     first = new1;
  }
}

void dlt_first()
{
  struct node *curt;

  if(first == NULL)
  {
    printf("\n your link list is EMPTY");
    getch();
    return;
  }

  curt = first;

  if(curt -> rptr == NULL)
  {
    first = first -> rptr;
    free(curt);
    printf("\n your first node is delete.....");
    getch();
    return;
  }

  first = curt -> rptr;
  curt -> rptr -> lptr = NULL;
  curt -> rptr = NULL;

  free(curt);

  printf("\n your first node is delete.....");
  getch();
}

void dlt_last()
{
  struct node *curt;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return;
  }

  curt = first;

  if(curt -> rptr == NULL)
  {
     first = NULL;
     free(curt);
     return;
  }

  while(curt -> rptr != NULL)
  {
    curt = curt -> rptr;
  }

  curt -> lptr -> rptr = NULL;
  curt -> lptr = NULL;
  free(curt);

  printf("\n your last node is delete......");
  getch();
}

void dalete(int val)
{
  struct node *curt;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return;
  }

  curt = first;

  if(first -> data == val)
  {
    first = first -> rptr;
      if(curt -> rptr != NULL)
       {
         curt -> rptr -> lptr = NULL;
         curt -> rptr = NULL;
       }
    free(curt);
    return;
  }

  while(curt -> data != val && curt != NULL)
  {
     curt = curt -> rptr;

     if(curt == NULL)
     {
       printf("\n your value is not found");
       getch();
       return;
     }
  }

  curt -> rptr -> lptr = curt -> lptr;
  curt -> lptr -> rptr = curt -> rptr;
  curt -> lptr = curt -> rptr = NULL;
}

void sorte()
{
  struct node *curt;
  int i=0,j=0,n=0,tmp;

  if(first==NULL)
  {
     printf("\n your link list is EMPTY");
     getch();
     return;
  }

  for(curt=first; curt!=NULL ;curt=curt->rptr)
  {
    n++;
  }

  curt =first;

  for(i=0;i<n-1;i++)
  {
    curt = first;
     for(j=0;j<n-i-1;j++)
     {
       if(curt->data > curt->rptr->data)
       {
         tmp = curt->data;
         curt->data = curt ->rptr->data;
         curt->rptr->data = tmp;
       }
       curt = curt -> rptr;
     }
  }

  printf("\n ");
  display();
}

void splite(int num)
{
  struct node *curt;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return;
  }

  curt = first;

  if(first -> rptr == NULL)
  {
     printf("\n sorting is not possible");
     getch();
     return;
  }

  while(curt -> data != num && curt != NULL)
  {
    curt = curt -> rptr;

    if(curt == NULL)
    {
      printf("\n your value is not found");
      getch();
      return;
    }
  }

  if(curt -> rptr == NULL)
  {
    printf("\n splite is not posible");
    getch();
    return;
  }

  first1 = curt -> rptr;
  curt -> rptr = NULL;

  printf("\n");

  curt = first;

   while(curt != NULL)
   {
     printf("%d--> ",curt -> data);
     curt = curt -> rptr;
   }

  printf("\n");

  curt = first1;

   while(curt != NULL)
   {
     printf("%d--> ",curt -> data);
     curt = curt -> rptr;
   }

  getch();
}

void merge()
{
  struct node *curt;

  if(first == NULL || first1 == NULL)
  {
    printf("\n your link list is EMPTY");
    getch();
    return;
  }

  curt = first;

  while(curt -> rptr != NULL)
  {
     curt = curt -> rptr;
  }

  curt -> rptr = first1;
  first1 -> lptr = curt;

  printf("\n ");
  display();
}

void count()
{
  struct node *curt;
  int n=0,e=0,o=0;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return;
  }

  for(curt=first; curt != NULL ;curt=curt->rptr)
  {
    n++;

    if(curt -> data % 2 == 0)
    {
      e++;
    }
    else
    {
      o++;
    }
  }

  printf("\n total number of node is :: %d",n);
  printf("\n total even node is :: %d",e);
  printf("\n total odd node is :: %d",o);

  getch();
}

void display()
{
  struct node *curt;

   if(first == NULL)
   {
      printf("\n your link list is empty");
      getch();
      return;
   }

   curt = first;

   while(curt != NULL)
   {
     printf("%d--> ",curt -> data);
     curt = curt -> rptr;
   }

  getch();
}
