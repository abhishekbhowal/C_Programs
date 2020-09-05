#include <stdio.h>
#include <time.h>

int main()
{
	time_t now;
	time(&now);
	printf("It's %d\n",abs((int) ctime(&now)));
	return 0;
}
