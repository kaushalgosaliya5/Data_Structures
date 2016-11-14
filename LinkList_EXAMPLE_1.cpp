#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
}*first=NULL,*first1=NULL;

void ins_first(int);
void ins_last(int);
void insert(int,int);

void dlt_first();
void dlt_last();
void dalete(int);

void sorting();
void spliting(int);
void merging();
void count();

void display();

void main()
{
  int val,ch,num;

  do
  {
     clrscr();
     printf("\n |-------- menu --------|");
     printf("\n   1.insert first");
     printf("\n   2.insert last ");
     printf("\n   3.insert specified location");
     printf("\n   4.delete first ");
     printf("\n   5.delete lasst ");
     printf("\n   6.delete specified node  ");
     printf("\n   7.sorting ");
     printf("\n   8.spliting  ");
     printf("\n   9.merging   ");
     printf("\n  10.total node ,even-odd node");
     printf("\n  11 display");
     printf("\n  12.EXIT ");
     printf("\n |-----------------------| ");

     printf("\n enter your choice :: ");
     scanf("%d",&ch);

     switch(ch)
     {
       case 1 :
                printf("\n enter your first node value :: ");
                scanf("%d",&val);

                ins_first(val);
                break;

       case 2 :
                printf("\n enter your last node value :: ");
                scanf("%d",&val);

                ins_last(val);
                break;

       case 3 :
                printf("\n enter value which node after insert :: ");
                scanf("%d",&num);

                printf("\n enter value :: ");
                scanf("%d",&val);

                insert(num,val);
                break;

       case 4 :
                dlt_first();
                break;

       case 5 :
                dlt_last();
                break;

       case 6 :
                printf("\n enter deleter value :: ");
                scanf("%d",&val);

                dalete(val);
                break;

       case 7 :
                printf("\n ");
                sorting();
                break;

       case 8 :
                 printf("\n enter value form which node after spliting :: ");
                 scanf("%d",&val);

                 spliting(val);
                 break;

       case  9 :
                 merging();
                 break;
       case 10 :
                 printf("\n");
                 count();
                 break;

       case 11 :
                 printf("\n ");

                 display();
                 break;

       case 12 :
                printf("\n your programe is exit");
                getch();
                break;

       default :
                printf("\n your choice is wrong");
                break;
     }

  }while(ch != 12);
}

void ins_first(int val)
{
  struct node *new1;

  new1 = (struct node *)malloc(sizeof(struct node));
  new1 -> data = val;

  new1 -> next = first;
  first = new1;
}

void ins_last(int val)
{
  struct node *new1,*curt;

  new1 = (struct node *)malloc(sizeof(struct node));

  new1 -> data = val;
  new1 -> next = NULL;

  if(first == NULL)
  {
    first = new1;
    return;
  }

  curt = first;

  while(curt -> next != NULL)
  {
    curt = curt -> next;
  }

  curt -> next = new1;
}

void insert(int num,int val)
{
  struct node *new1,*curt;

  new1 = (struct node *)malloc(sizeof(struct node));
  new1 -> data = val;

  if(first == NULL)
  {
     printf("\n your link list is null");
     getch();
     return;
  }

  curt = first;

  while(curt -> data != num && curt != NULL)
  {
    curt = curt -> next;

    if(curt == NULL)
    {
      printf("\n your value is not found");
      getch();
      return;
    }
  }

   new1 -> next = curt -> next;
   curt -> next = new1;
}

void dlt_first()
{
   struct node *curt;

   if(first == NULL)
   {
     printf("\n your link list is NULL");
     getch();
     return;
   }

   curt = first;
   first = first -> next;

   free(curt);
}

void dlt_last()
{
  struct node *curt,*prev;

  if(first == NULL)
  {
    printf("\n your link list is NULL");
    getch();
    return;
  }

  curt = first;

  if(first -> next == NULL)
  {
    first = NULL;
    free(curt);
    return;
  }

  while(curt -> next != NULL)
  {
    prev = curt;
    curt = curt -> next;
  }

  prev -> next = NULL;
  free(curt);
}

void dalete(int val)
{
  struct node *curt,*prev;

  if(first == NULL)
  {
    printf("\n your link list is EMPTY ");
    getch();
    return;
  }

  curt = first;

  if(first -> next == NULL)
  {
     first = NULL;
     free(curt);
     return;
  }

  while(curt -> data != val && curt != NULL)
  {
     prev = curt;
     curt = curt -> next;

     if(curt == NULL)
     {
        printf("\n YOUR VALUE IS NOT FOUND");
        getch();
        return;
     }
  }

  prev -> next = curt -> next;
  free(curt);
}

void sorting()
{
  struct node *curt;
  int n=0,i,j,tmp;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return;
  }

  for(curt=first ; curt!=NULL ; curt=curt->next)
  {
     n++;
  }

  for(i=0; i<n-1 ;i++)
  {
    curt = first;
    for(j=0;j<n-1-i;j++)
    {
      if(curt->data > curt->next->data)
      {
        tmp = curt -> data;
        curt -> data = curt -> next -> data;
        curt -> next -> data = tmp;
      }
      curt = curt -> next;
    }
  }

  display();
}

void spliting(val)
{
  struct node *curt;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return;
  }

  curt = first;

  while(curt -> data != val && curt != NULL)
  {
    curt = curt -> next;

    if(curt == NULL)
    {
      printf("\n your value is not found");
      getch();
      return;
    }
  }

  first1 = curt -> next;
  curt -> next = NULL;

  printf("\n ");

  curt = first;

   while(curt != NULL)
   {
     printf("%d-->",curt -> data);
     curt = curt -> next;
   }

   printf("\n ");

   curt = first1;

   while(curt != NULL)
   {
     printf("%d-->",curt -> data);
     curt = curt -> next;
   }

   getch();
}

void merging()
{
   struct node *curt;

   if(first == NULL)
   {
     printf("\n your link list is empty");
     getch();
     return;
   }

   curt = first;

   while(curt -> next != NULL)
   {
     curt = curt -> next;
   }

   curt -> next = first1;

   printf("\n ");

   display();
}

void count()
{
  struct node *curt;
  int n=0,e=0,o=0;

  if(first == NULL)
  {
    printf("\n your link list is NULL");
    getch();
    return;
  }

  curt = first;

  for(curt=first ; curt!=NULL ; curt=curt->next)
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

  printf("\n number of node is :: %d",n);
  printf("\n total even number is :: %d",e);
  printf("\n total odd number is :: %d",o);
  getch();
}

void display()
{
   struct node *curt;

   if(first == NULL)
   {
      printf("\n link list is empty");
      getch();
      return;
   }

   curt = first;

   while(curt != NULL)
   {
     printf("%d-->",curt -> data);
     curt = curt -> next;
   }
   getch();
}