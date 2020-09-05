#include <stdio.h>
#include <string.h>

  int main()
  {
    char *p;

    p = strpbrk("this is a test","absj");
    printf(p);
	printf("\n");
    return 0;
  }
