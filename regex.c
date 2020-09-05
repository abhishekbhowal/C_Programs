#include<stdio.h>
#include<string.h>
int isRegEx(char *s, char *p)
{
	int i=0,j=0,n,ch,f=1,flag,flags=0;
	
	n=strlen(s);

	if(*(p+i)=='\0')
		ch=0;
	else
	if(*(p+i)=='*')
		ch=1;
	else
	if(*(p+i)=='?')
		ch=2;
	else
		ch=3;
	while(j<n)
	{
		
		switch(ch)
		{
			case 1:
						
				i++;
				if(*(p+i)=='\0')
				{
						j=n;
						break;
				}
				else
				{
					for(;j<n;j++)
					{
					
						if(*(s+j)==*(p+i))
						{
							flag=j;
							flags=1;
						}
					}
					if(flags==0)
						f=0;
					else
					{
						j=flag;
						i++;
						j++;
						if(*(p+i)=='*')
							ch=1;
						else
						if(*(p+i)=='?')
							ch=2;
						else
						if((*(p+i)!='\0' && *(s+j)=='\0')||(*(p+i)=='\0' && *(s+j)!='\0'))
							f=0;
						else
							ch=3;
					}
				}	
				break;
			case 2:
				if(*(s+j)=='\0')
					f=0;
				else
				{
					i++;j++;
					if(*(p+i)=='*')
						ch=1;
					else
					if(*(p+i)=='?')
						ch=2;
					else
					if((*(p+i)!='\0' && *(s+j)=='\0')||(*(p+i)=='\0' && *(s+j)!='\0'))
						f=0;
					else
						ch=3;
				}
				break;
			case 3:
				if(*(p+i)==*(s+j))
				{
					i++;
					j++;
				}
				else
				if(*(p+i)!=*(s+j))
					f=0;

				if(*(p+i)=='*')
					ch=1;
				else
				if(*(p+i)=='?')
				{
					if(*(s+j)=='\0')
						f=0;
					else
						ch=2;
				}
				else
				if((*(p+i)!='\0' && *(s+j)=='\0')||(*(p+i)=='\0' && *(s+j)!='\0'))
					f=0;
				else
					ch=3;
				break;
			default:
				printf("Default\n");
		}
		if(f==0)
			break;
	}
	if(f==0)
		return 0;
	else
		return 1;
}
int main()
{
	char str[100],p[20];
	int ch;
	do{
		printf("\nEnter pattern:");
		scanf("%s",p);
		printf("\nEnter string:");
		scanf("%s",str);
		if(isRegEx(str,p))
			printf("\nValid\n");
		else
			printf("\nInvalid\n");
		printf("\nRun it again 1/0?");
		scanf("%d",&ch);
	}
	while(ch==1);
	return 0;
}
