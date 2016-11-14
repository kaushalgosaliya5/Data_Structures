
#include<stdio.h>
#include<alloc.h>
#include<conio.h>

struct node
{
  int data;
  struct node *lptr;
  struct node *rptr;
};

struct node *first=NULL;

void ins_frunt (int);
void ins_last (int);
void ins_after(int,int);
void ins_before(int,int);
void dlt_frunt();
void dlt_last();
void dlt_after(int);
void dlt_before(int);
void display();

void main()
{
  int ch,val,num;

  do
  {
    clrscr();

  printf("\n |-------- menu -------|");
  printf("\n    1. insert frunt  ");
  printf("\n    2. insert last   ");
  printf("\n    3. insert after  ");
  printf("\n    4. insert before ");
  printf("\n    5. delete frunt  ");
  printf("\n    6. delete last   ");
  printf("\n    7. delete after  ");
  printf("\n    8. delete before ");
  printf("\n    9. display       ");
  printf("\n   10. exit          ");
  printf("\n |--------------------|");

  printf("\n enter choice :: ");
  scanf("%d",&ch);

  switch(ch)
   {
     case 1 :
               printf("\n enter value to frunt :: ");
               scanf("%d",&val);

               ins_frunt(val);
               break;
     case 2 :
              printf("\n  enter value ot last :: ");
              scanf("%d",&val);

              ins_last(val);
              break;
     case 3 :
              printf("\n enter value which number after add :: ");
              scanf("%d",&num);

              printf("\n enter value :: ");
              scanf("%d",&val);

              ins_after(val,num);
              break;
    case 4 :
             printf("\n enter value which number before add :: ");
             scanf("%d",&num);

             printf("\n enter value :: ");
             scanf("%d",&val);

             ins_before(val,num);
             break;
    case 5 :
             dlt_frunt();
             break;
    case 6 :
             dlt_last();
             break;
    case 7 :
             printf("\n enter number frome which node after to delete :: ");
             scanf("%d",&num);

             dlt_after(num);
             break;
    case 8 :
             printf("\n enter number frome which node before to delete :: ");
             scanf("%d",&num);

             dlt_before(num);
             break;
    case 9 :
             printf("\n ");

             display();
             break;
    case 10 :
              printf("\n your program is EXIT");
              getch();
              return;
    default :
              printf("\n your value is not correct ");
              getch();
              break;
    }

   }while(ch != 10);

 scanf("%d");
}

void ins_frunt(int val)
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

void ins_after(int val,int num)
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

void ins_before(int val,int num)
{
  struct node *curt,*new1;

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

void dlt_frunt()
{
   struct node *curt;

   if(first == NULL)
   {
     printf("\n your link list is empty ");
     getch();
     return;
   }

   curt = first;

   if(first -> rptr == NULL)
   {
      first = NULL;
      free(curt);
      return;
   }

   first = first -> rptr;
   first -> lptr = NULL;
   curt -> rptr = NULL;
   free(curt);
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

  if(first -> rptr == NULL)
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
}

void dlt_after(int num)
{
  struct node *curt,*next;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return;
  }

  curt = first;

  while(curt -> data != num && curt != NULL)
  {
    curt = curt -> rptr;

    if(curt == NULL)
    {
      printf("\n your number is not found");
      getch();
      return;
    }
  }

  if(curt -> rptr == NULL)
  {
    printf("\n no node to delete");
    getch();
    return;
  }

  next = curt -> rptr;
  curt -> rptr = next -> rptr;

  if(next -> rptr != NULL)
  {
    next -> rptr -> lptr = curt;
    next -> lptr = next -> rptr = NULL;
  }

  free(next);
}

void dlt_before(int num)
{
   struct node *curt,*prev;

   if(first == NULL)
   {
     printf("\n link list is empty");
     getch();
     return;
   }

   curt = first;

   while(curt -> data != num && curt != NULL)
   {
      curt = curt -> rptr;

      if(curt == NULL)
      {
         printf("\n your number is not found");
         getch();
         return;
      }
   }

  if(curt -> lptr == NULL)
  {
     printf("\n no node delelted");
     getch();
     return;
  }

  if(curt -> lptr == first)
  {
    curt -> lptr = NULL;
    prev = first;
    prev -> rptr = NULL;
    first = curt;

    free(prev);
    return;
  }

  prev = curt -> lptr;
  curt -> lptr = prev -> lptr;
  prev -> lptr -> rptr = curt;
  prev -> lptr = prev -> rptr = NULL;

  free(prev);
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