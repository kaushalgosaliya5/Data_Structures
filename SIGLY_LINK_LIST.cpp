#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
  int data;
  struct node *next;
}*first=NULL;

void insert(int);
void display();
void delate(int);
void begginsert(int);

void main()
{
  int val,ch;

  do
  {
    clrscr();

  printf("\n |----- menu -----|");
  printf("\n  1. insert   ");
  printf("\n  2. display  ");
  printf("\n  3. delete   ");
  printf("\n  4. begging insert ");
  printf("\n  5. exit     ");
  printf("\n |---------------|");

  printf("\n enter your choice :: ");
  scanf("%d",&ch);

  switch(ch)
  {
    case 1:
            printf("\n enter inert element value :: ");
            scanf("%d",&val);

            insert(val);
            break;
    case 2:
            printf("\n ");
            display();
            break;
    case 3:
            printf("\n enter delete value :: ");
            scanf("%d",&val);

            delate(val);
            break;
    case 4:
            printf("\n enter begging insert value :: ");
            scanf("%d",&val);

            begginsert(val);
            break;
    case 5:
            printf("\n your program is exit ");
            getch();
            break;
   default:
            printf("\n your choice is wrong ");
            getch();
    }

  }while(ch!=5);

  getch();
}

void insert(int val)
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

void delate(int val)
{
   struct node *curt,*prev;

   if(first == NULL)
   {
     printf("\n your link list is empty");
     getch();
     return;
   }

   curt = first;

   if(first -> data == val)
   {
     first = first -> next;
     free(curt);
     return;
   }

   while(curt -> data != val && curt != NULL)
   {
     prev = curt;
     curt = curt -> next;

     if(curt == NULL)
     {
        printf("\n your value is not found");
        getch();
        return;
     }
   }

  prev -> next = curt -> next;
  free(curt);
}

void begginsert(int val)
{
  struct node *new1;

  new1 = (struct node *)malloc(sizeof(struct node));

  new1 -> data = val;
  new1 -> next = first;

  first = new1;

}


