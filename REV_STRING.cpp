#include<stdio.h>
#include<conio.h>

char st[20],top=-1;
void main()
{
	char str[15];
        int i=0;
	printf("\n Enter String : ");
	scanf("%s",str);
	while(str[i]!=NULL)
		st[++top]=str[i++];
        printf("\n");
	while(top!=-1)
		printf("%c",st[top--]);

  getch();
}
