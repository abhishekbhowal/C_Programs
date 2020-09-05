#include <stdio.h>
void main(void)
{
#if defined(_MSC_VER)
printf("Microsoft compiler\n");
#endif
#if defined(__GNUC__)
printf("GNU compiler\n");
#endif
#if defined(__WIN32__)
printf("__WIN32__ defined\n");
#endif
#if defined(_WIN32)
printf("_WIN32 defined\n");
#endif
#if defined(__NUTC__)
printf("NuTCRACKER defined\n");
#endif
}

