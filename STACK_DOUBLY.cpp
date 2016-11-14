#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
  struct node *lptr;
  int data;
  struct node *rptr;
}*first=NULL;


void push(int);
int pop();
int peep();
void display();

void main()
{
  int ch,val;

  do
  {
    clrscr();

  printf("\n |------ menu ------|");
  printf("\n   1. push   ");
  printf("\n   2. pop    ");
  printf("\n   3. peep   ");
  printf("\n   4. display");
  printf("\n   5. exit   ");
  printf("\n |------------------|");

  printf("\n enter your choice  :: ");
  scanf("%d",&ch);

  switch(ch)
   {
     case 1:
             printf("\n enter push value :: ");
             scanf("%d",&val);

             push(val);
             break;
     case 2:
             printf("\n your pop value is :: %d",pop());
             getch();
             break;
     case 3:
             printf("\n your peep value is :: %d",peep());
             getch();
             break;
     case 4:
             printf("\n");
             display();
             break;
     case 5:
             printf("\n your program is exit ");
             getch();
             break;
     default:
             printf("\n your choice is wrong ");
             getch();
   }
  }while(ch != 5);
}

void push(int val)
{
  struct node *new1,*curt;

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

int pop()
{
  struct node *curt;
  int v;

  if(first == NULL)
  {
    printf("\n your link list is empty");
    getch();
    return 0;
  }

  curt = first;

  if(curt -> rptr == NULL)
  {
    v = curt -> data;
    first = curt -> rptr;
    free(curt);

    return v;
  }

  while(curt -> rptr != NULL)
  {
    curt = curt -> rptr;
  }

  v = curt -> data;
  curt -> lptr -> rptr = NULL;
  curt -> lptr = NULL;

  return v;
}

int peep()
{
   struct node *curt;
   int v;

   if(first == NULL)
   {
     printf("\n your link list is empty");
     getch();
     return 0;
   }

  curt = first;

  while(curt -> rptr != NULL)
  {
    curt = curt -> rptr;
  }

  v = curt -> data;
  return v;
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

   while(curt -> rptr != NULL)
   {
     curt = curt -> rptr;
   }

   while(curt != NULL)
   {
     printf("\n %d --> ",curt->data);
     curt = curt -> lptr;
   }

  getch();
}


