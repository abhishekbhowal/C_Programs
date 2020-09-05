#include<stdio.h>
int match(char *pat, char *str)
{
	switch(*pat) {
	case '\0':  return !*str;
	case '*':   return match(pat+1, str) || *str && match(pat, str+1);
	case '?':   return *str && match(pat+1, str+1);
	default:    return *pat == *str && match(pat+1, str+1);
	}
}
int main()
{
	char s[200],p[10];
	printf("Enter the pattern:");
	scanf("%s",p);
	printf("Enter the string:");
	scanf("%s",s);
	if(match(p,s))
		printf("Matched\n");
	else
		printf("MissMatched\n");
	return 0;
}
