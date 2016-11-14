#include<stdio.h>
#include<alloc.h>
#include<conio.h>

struct node
{
  int data;
  struct node *next;
}*first=NULL;

void push(int);
int pop();
int peep(int);
void display();

void main()
{
  int ch,val;
  int v;

  do
  {
     clrscr();

  printf("\n |----- menu ----| ");
  printf("\n    1. push  ");
  printf("\n    2. pop   ");
  printf("\n    3. peep  ");
  printf("\n    4. display ");
  printf("\n    5. exit  ");
  printf("\n |-----------------|");

  printf("\n enter your choice :: ");
  scanf("%d",&ch);

  switch(ch)
  {
     case 1:
             printf("\n enter push value :: ");
             scanf("%d",&val);

             push(val);
             break;
     case 2:
             v = pop();

             if(v != 0)
             {
              printf("\n your pop value is :: %d",v);
              getch();
             }

             break;
     case 3:
             printf("\n your which value peep :: ");
             scanf("%d",&val);

             v = peep(val);

             if(v != 0)
             {
              printf("\n your peep value is :: %d",peep(val));
              getch();
              }
             break;
     case 4:
             printf("\n ");
             display();
             break;
     case 5:
             printf("\n your program is exit");
             getch();
             break;

     default:
              printf("\n your choice is wrong ");
              getch();
  }
 }while(ch != 5);

 getch();
}

void push(int val)
{
   struct node *new1;

   new1 = (struct node *)malloc(sizeof(struct node));
   new1 -> data = val;

   new1 -> next = first;
   first = new1;
}

int pop()
{
  struct node *curt;
  int v;

  if(first == NULL)
  {
    printf("\n your link list is emtpy");
    getch();
    return 0;
  }

  curt = first;
  v = first -> data;
  first = first -> next;
  free(curt);

  return v;
}

int peep(int val)
{
  struct node *curt;
  int i,j=0;

  for(curt=first;curt!=NULL;curt=curt->next)
  {
    j++;
  }

  for(curt=first,i=1;i<=j;i++,curt=curt->next)
  {
    if(i == val)
    {
      return curt -> data;
    }
    else if(i >= 0 && i <= j)
    {
      printf("\n your peep value is worng ");
      getch();
      return 0;
    }
  }
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
    printf("\n %d --> ",curt -> data);
    curt = curt -> next;
  }

  getch();
}
