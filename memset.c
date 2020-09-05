#include <stdio.h>
#include <string.h>

char message1[60] = "Four#score# and# seven years ago ...";
char message2[60] = "abcdefgh";
char temp[60];
int main()
{
	char str[11] = "0123456789";
	memmove(str+2, str+1, 3);
	printf("%s\n",str);
	//memcpy(str+2, str+1, 3);

//Read more: http://wiki.answers.com/Q/Difference_between_memcpy_and_memmove_in_C_with_example#ixzz1cXYwuhVA

	printf("\nmessage1[] before memset():\t%s", message1);
    	memset(message1 + 5, '@', 10);
    	printf("\nmessage1[] after memset():\t%s", message1);

    	strcpy(temp, message2);
   	printf("\n\nOriginal message: %s", temp);
   	memcpy(temp + 4, temp + 6, 2);
   	printf("\nAfter memcpy() without overlap:\t%s", temp);
   	strcpy(temp, message2);
   	memcpy(temp +2, temp + 4, 2);
   	printf("\nAfter memcpy() with overlap:\t%s", temp);

    	strcpy(temp, message2);
   	printf("\n\nOriginal message: %s", temp);
    	memmove(temp + 2, temp + 6, 2);
   	printf("\nAfter memmove() without overlap:\t%s", temp);
   	strcpy(temp, message2);
    	memmove(temp + 4, temp + 2, 2);
    	printf("\nAfter memmove() with overlap:\t%s\n", temp);

}
