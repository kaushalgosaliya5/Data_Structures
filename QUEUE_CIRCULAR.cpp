#include<stdio.h>
#include<conio.h>
# define N 5

int q[N];
int f=-1;
int r=-1;

void qinsert(int);
int qdelate();
void display();

void main()
{
  int ch,val;

  do
  {
    clrscr();

  printf("\n |------ menu ------|");
  printf("\n   1. Q INSERT ");
  printf("\n   2. Q DELATE ");
  printf("\n   3. DISPLAY  ");
  printf("\n   4. EXIT     ");
  printf("\n |------------------|");

  printf("\n enter your choice :: ");
  scanf("%d",&ch);

  switch(ch)
   {
     case 1:
             printf("\n enter value of insert queue :: ");
             scanf("%d",&val);

             qinsert(val);
             break;
     case 2:
             val = qdelate();

             if(val != 0)
             {
                printf("\n your delate value is :: %d",val);
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

     default:
             printf("\n your choice is worng");
             getch();
   }
 }while(ch != 4);

 getch();
}

void qinsert(int val)
{
   if((f==0 && r==N-1) || (r == f-1))
   {
     printf("\n your queue is over-flow");
     getch();
     return;
   }

   r = (r+1) % N;

   q[r] = val;

   if(f == -1)
   {
      f = 0;
   }
}

int qdelate()
{
  int val;

  if(f==-1)
  {
    printf("\n queue is under-flow");
    getch();
    return 0;
  }

  val = q[f];

  if(f==r)
  {
    f = -1;
    r = -1;
  }
  else
  {
     if(f==N-1)
     {
       f = 0;
     }
     else
     {
       f = f+1;
     }
  }

  return val;
}

void display()
{
  int i;

   if(f == -1)
   {
     printf("\n your queue is empty");
     getch();
     return;
   }


 if(f!=-1 && r!=-1)
 {
   if(f <= r)
     {
       for(i=f;i<=r;i++)
       {
         printf(" %d --> ",q[i]);
       }
     }
   else
     {
        for(i=f;i<=(N-1);i++)
        {
          printf(" %d --> ",q[i]);
        }
        for(i=0;i<=r;i++)
        {
          printf(" %d --> ",q[i]);
        }
     }
  }
  getch();
}