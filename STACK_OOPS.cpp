#include<iostream.h>
#include<conio.h>
#define size 5

class stack
{
  int st[size];
  int top;
  int i;

  public:

  stack()
  {
    top=-1;
  }

  void push(int);
  int pop();
  int peep();
  void display();
};

void stack :: push(int val)
{
   if(top == size-1)
   {
     cout << "\n your stack is over-flow";
     getch();
     return;
   }

   st[++top] = val;
}

int stack :: pop()
{
  if(top == -1)
  {
    cout << "\n your stack is under-flow";
    getch();
    return 0;
  }

  return st[top--];

}

int stack :: peep()
{
  if(top == -1)
  {
    cout << "\n your link list is empty";
    getch();
    return 0;
  }

  return st[top];
}

void stack :: display()
{
  if(top == -1)
  {
     cout << "\n you stack is empty";
     getch();
     return;
  }

  for(i=top;i>= 0;i--)
  {
    cout << st[i] << " --> ";
  }

  getch();
}


void main()
{
  stack s;
  int ch,val;

  do
  {
    clrscr();

  cout << "\n |------ menu ------|";
  cout << "\n   1. push   ";
  cout << "\n   2. pop    ";
  cout << "\n   3. peep   ";
  cout << "\n   4. display";
  cout << "\n   5. exit   ";
  cout << "\n |------------------|";

  cout << "\n enter your choice :: ";
  cin >> ch;

  switch(ch)
  {
    case 1:
             cout << "\n enter your push value :: ";
             cin >> val;

             s.push(val);
             break;
    case 2:
             cout << "\n your pop value is :: " << s.pop();
             getch();
             break;
    case 3:
             cout << "\n your peep value is :: " << s.peep();
             getch();
             break;
    case 4:
             s.display();
             break;
    case 5:
             cout << "\n your program is exit ";
             getch();
             break;
    default:
             cout << "\n your choice is wrong ";
             getch();
    }

  }while(ch != 5);

  getch();
}