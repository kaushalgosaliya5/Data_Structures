#include<iostream.h>
#include<conio.h>
# define SIZE 10

int st[SIZE];
int top=-1;

void push(int val)
{
  if(top == SIZE)
  {
    cout << "\n array is full";
    getch();
    return;
  }

  st[++top] = val;
}

int pop()
{
  if(top == -1)
  {
    cout << "\n array is empty";
    getch();
    return 0;
  }
  return st[top--];
}

void main()
{
  int i=0;
  char post[21];

  cout << "\n enter post fix expression :: ";
  cin >> post;

  while(post[i] != NULL)
  {
    int a=post[i];
    int b=post[i];

    if(post[i] >= '0' && post[i] <= '9')
    {
      push(post[i]-'0');
    }
    else if(post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '%')
    {
      int a = pop();
      int b = pop();

      switch(post[i])
      {
        case '+' :
                   push(b+a);
                   break;

        case '-' :
                   push(b-a);
                   break;

        case '*' :
                   push(b*a);
                   break;

        case '/' :
                   push(b/a);
                   break;

        case '%' :
                   push(b%a);
       }
    }
    else
    {
       cout << "\n INVALIDE EXPRESSION";
    }

    i++;
   }

    if(top != 0)
    {
      cout << "\n invlide ";
    }
    else
    {
      cout << "\n result is :: " << pop();
    }

  getch();
}



