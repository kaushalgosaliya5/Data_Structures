#include<stdio.h>
#include<alloc.h>
#include<conio.h>

struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
};

struct tree *insert(struct tree *root,int val)
{
   struct tree *new1,*par,*ptr;

   new1 = (struct tree *)malloc(sizeof(struct tree));
   new1 -> data = val;
   new1 -> right = NULL;
   new1 -> left = NULL;

   if(root == NULL)
   {
     return new1;
   }

   ptr = root;

   while(ptr != NULL)
   {
     par = ptr;

     if(new1 -> data < ptr -> data)
     {
       ptr = ptr -> left;
     }
     else
     {
       ptr = ptr -> right;
     }
   }

   if(new1 -> data < par -> data)
   {
     par -> left = new1;
   }
   else
   {
     par -> right = new1;
   }

   return root;
}

void preorder(struct tree *root)
{
  if(root == NULL)
  {
    printf("\n YOUR TREE IS EMPTY");
    return;
  }

  printf(" %d ",root -> data);

  if(root -> left != NULL)
  {
    preorder(root -> left);
  }

  if(root -> right != NULL)
  {
    preorder(root -> right);
  }
}

void inorder(struct tree *root)
{
  if(root == NULL)
  {
    printf("\n YOUR TREE IS EMPTY");
    return;
  }

  if(root -> left != NULL)
  {
    inorder(root -> left);
  }

  printf(" %d ",root -> data);

  if(root -> right != NULL)
  {
    inorder(root -> right);
  }
}

void postorder(struct tree *root)
{
  if(root == NULL)
  {
    printf("\n YOUR TREE IS EMPTY");
    return;
  }

  if(root -> left != NULL)
  {
    postorder(root -> left);
  }

  if(root -> right != NULL)
  {
    postorder(root -> right);
  }

  printf(" %d ",root -> data);
}

void main()
{
  int ch,val;
  struct tree  *root;

  do
  {
    clrscr();

    printf("\n |-------- menu ------|");
    printf("\n      1. INSERT ");
    printf("\n      2. PRE-ORDER ");
    printf("\n      3. IN-ORDER  ");
    printf("\n      4. POST-ORDER");
    printf("\n      5. EXIT ");
    printf("\n |--------------------|");

    printf("\n enter your choice :: ");
    scanf("%d",&val);

    switch(val)
    {
      case 1:
               printf("\n you are enter any value :: ");
               scanf("%d",&val);

               root = insert(root,val);
               break;
      case 2:
               preorder(root);
               getch();
               break;

      case 3:
               inorder(root);
               getch();
               break;

      case 4:
               postorder(root);
               getch();
               break;

      case 5:
              printf("\n YOUR PROGREAM IS EXIT ");
              getch();
              break;

     default:
              printf("\n your choice is wrong");
              getch();
    }

  }while(ch != 5);

 getch();
}