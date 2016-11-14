#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define max 100

char st[max];
int top=-1;

void push(char);
char pop();
void infixtopostfix(char [],char []);
int getpriority(char);

void main()
{
  char infix[max],postfix[max];
  clrscr();

  printf("\n enter any infix expression :: ");
  gets(infix);

  infixtopostfix(infix,postfix);

  printf("\n your postfix expression is :: ");
  puts(postfix);

  getch();
}

void infixtopostfix(char sorce[],char target[])
{
   int i=0,j=0;
   char tmp;

   while(sorce[i] != '\0')
   {
      if(sorce[i] == '(')
      {
        push(sorce[i]);
        i++;
      }
      else if(sorce[i] == ')')
      {
        while((top != -1) && (st[top] != '('))
        {
          target[j] = pop();
          j++;
        }

        if(top == -1)
        {
          printf("\n incorrect expression ");
          getch();
          break;
        }

        tmp = pop();

       i++;
      }
      else if(isdigit(sorce[i]) || isalpha(sorce[i]) )
      {
        target[j] = sorce[i];
        j++;
        i++;
      }
      else if(sorce[i] == '+' || sorce[i] == '-' || sorce[i] == '*' || sorce[i] == '/' || sorce[i] == '%')
      {
        while((top != -1) && (st[top] != '(') && (getpriority(st[top]) > getpriority(sorce[i])))
        {
           target[j] = pop();
           j++;
        }

        push(sorce[i]);
        i++;
      }
      else
      {
        printf("\n incorrect element in expression");
        getch();
      }
   }

   while((top != -1) && (st[top] != '('))
   {
     target[j] = pop();
     j++;
   }

  target[j] = '\0';
}

int getpriority(char op)
{
  if(op == '*' || op == '/' || op == '%')
  {
    return 1;
  }
  else if(op == '+' || op == '-')
  {
    return 0;
  }
}

void push(char val)
{
  if(top == max-1)
  {
    printf("\n your stack is over-flow");
    getch();
    return;
  }

  st[++top] = val;
}

char pop()
{
  if(top == -1)
  {
    printf("\n stack under flow");
    getch();
    return ' ';
  }

  return st[top--];
}