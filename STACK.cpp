#include<stdio.h>
#include<conio.h>

void push(int);
int pop();
void display();
int peep(int);

int st[5];
int top = -1;

void main()
{
   int ch,val,i;

   do
   {
     clrscr();

     printf("\n  |------- menu -------|");
     printf("\n     1. p u s h    ");
     printf("\n     2. p o p      ");
     printf("\n     3. p e e p    ");
     printf("\n     4. display    ");
     printf("\n     5. exit       ");
     printf("\n  |--------------------|");

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
               printf("\n your pop value is :: %d",pop());
               getch();
               break;

       case 3:
               printf("\n enter which number value peep :: ");
               scanf("%d",&i);

               printf("\n your peep value is :: %d",peep(i));
               getch();
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
               printf("\n your choice is wrong");
               getch();
               break;
   }
  }while(ch != 5);
}

void push(int val)
{
   if(top == 4)
   {
     printf("\n over flow ");
     getch();
     return;
   }

 //  top = top + 1;

   st[++top] = val;
}

int pop()
{
   if(top == -1)
   {
     printf("\n under flow ");
     getch();
     return 0;
   }

   return st[top--];
}

int peep(int i)
{
  if(top-i+1 < 0)
  {
    printf("\n under-flow peep");
  }
  else
  {
    return (st[top-i+1]);
  }
}

void display()
{
  int i;

   if(top == -1)
   {
     printf("\n array is empty ");
     getch();
     return;
   }

   for(i=top;i>=0;i--)
    {
       printf("\n %d-->",st[i]);
    }

    getch();
}
