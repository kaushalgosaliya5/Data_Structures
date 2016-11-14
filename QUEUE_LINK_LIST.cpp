#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
  int data;
  struct node *next;
}*first=NULL;

void qinsert(int);
int qdelate();
void display();

void main()
{
  int ch,val;

  do
  {
    clrscr();

  printf("\n |------- menu -------|");
  printf("\n   1. Q INSERT    ");
  printf("\n   2. Q DELETE    ");
  printf("\n   3. DISPLAY     ");
  printf("\n   4. EXIT        ");
  printf("\n |--------------------|");

  printf("\n enter your choice :: ");
  scanf("%d",&ch);

  switch(ch)
   {
     case 1:
              printf("\n enter value in a queue insert :: ");
              scanf("%d",&val);

              qinsert(val);
              break;
     case 2:
              val = qdelate();
              if(val != 0)
              {
               printf("\n your delate value in a queue is :: %d",val);
               getch();
              }
              break;
     case 3:
              display();
              break;
     case 4:
              printf("\n your program is exit ");
              getch();
              break;
    default :
              printf("\n your choice is wrong ");
              getch();
     }
   }while(ch!=4);

 getch();
}

void qinsert(int val)
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

int qdelate()
{
  struct node *curt;
  int val;

  if(first == NULL)
  {
    printf("\n your queue is empty");
    getch();
    return 0;
  }

  curt = first;
  val = first -> data;
  first = first -> next;
  free(curt);

  return val;
}

void display()
{
  struct node *curt;

  if(first == NULL)
  {
    printf("\n your queue is emtpy");
    getch();
    return;
  }

  curt = first;

  while(curt != NULL)
  {
    printf("\n %d --> ",curt -> data);
    curt = curt -> next;
  }

  getch();
}