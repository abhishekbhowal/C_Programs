/* Rabin-Karp String Matching Algorithm
   RabinKarpMatch(T,P,d,q) 
   - Assume T and P consist only a..z and A..Z
   - radix d, prime q
   - match whether P is a substring of T
   - return the starting index of the first occurence of P in T
   - n = length(T)
   - m = length(P)

    Worst Case : O((n-m+1)*m)
    Best Case : O(n+m)
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int RabinKarpMatch(char *T,char *P,int d,int q)
{
     int i,j,p,t,n,m,h,found;
     n = strlen(T);
     m = strlen(P);
     h = 1;
	for(i=0;i<m;i++)
		h*=d;
	h=h%q;
     p = t = 0;

     for (i=0; i<m; i++)
     {
          p = (d*p + P[i]) % q;
          t = (d*t + T[i]) % q;
     }

     for (i=0; i<=n-m; i++)
     {
          if (p == t)
          {
               found = 1;
               for (j=0; j<m; j++)
                   if (P[j] != T[i+j])
                   {
                       found = 0;
                       break;
                   }
               if (found) return i;
          } else {
               t = (d*(t - ((T[i]*h) % q)) + T[i+m]) % q;
          }
     }
     return -1;
}
int main()
{
	char *s="reoheroheroehreprrr";
	char *p="roher";
	printf("Index: %d",RabinKarpMatch(s,p,47,17));
	return 0;
}
