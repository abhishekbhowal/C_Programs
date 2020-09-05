#include<stdio.h>
//#include<conio.h>

char pw[25],ch;
int i;
int main()
{
	clrscr();
	puts(“Enter password”);
	while(1)
	{	
		if(i<0)
			i=0;
		ch=getchar();
		if(ch==13)
			break; /*13 is ASCII value of ENTER*/
		if(ch==8) /*ASCII value of BACKSPACE*/
		{
			putchar(‘\b’);
			putchar(NULL);
			putchar(‘\b’);
			–i;
			continue;
		}
		pw[i++]=ch;
		ch=’*';
		putchar(ch);
	}
	pw[i]=’\0′;
	printf(“\n\n%s”,pw);
	return 0;
}
