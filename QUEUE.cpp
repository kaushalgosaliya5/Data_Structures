#include<stdio.h>
#include<conio.h>
#define N 5

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

  printf("\n |--------- menu ---------|");
  printf("\n    1. QINSERT ");
  printf("\n    2. QDELETE ");
  printf("\n    3. DISPLAY ");
  printf("\n    4. EXIT    ");
  printf("\n |------------------------|");

  printf("\n enter your choice :: ");
  scanf("%d",&ch);

  switch(ch)
    {
      case 1:
              printf("\n enter vlaue of queue insert :: ");
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
              printf("\n ");
              display();
              break;
      case 4:
              printf("\n your program is exit ");
              getch();
              break;
      default:
              printf("\n your choice is wrong");
              getch();
   }
 }while(ch != 4);

 getch();
}

void qinsert(int val)
{
  if(r == N-1)
  {
    printf("\n your queue is over-flow");
    getch();
    return;
  }

  r = r + 1;

  q[r] = val;

  if(f == -1)
  {
    f = 0;
  }
}

int qdelate()
{
   int val;

    if(f == -1)
    {
      printf("\n your queue is under-flow");
      getch();
      return 0;
    }

    val = q[f];

    if(f == r)
    {
      f = -1;
      r = -1;
    }
    else
    {
      f = f + 1;
    }

  return val;
}

void display()
{
  int i;

  if(f == -1)
  {
    printf("\n your queue is empty ");
    getch();
    return;
  }

  for(i=f;i<=r;i++)
  {
    printf("\n %d --> ",q[i]);
  }

  getch();
}





