#include<stdio.h>
int main()
{
	int i=0,n,r,k;
	char first[19][20]={"Zero","One","Ttwo","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Seventeen","Eighteen","Nineteen"};
	char second[9][20]={"Ten","Twenty","Thirty","Fourty","Fifity","Sixty","Seventy","Eighty","Ninety"};
	char third[4][20]={"Hundred","Thousand","Lakh","Crore"};
	printf("\nEnter the(max of 9-digit) number:");
	scanf("%d",&n);
		if(i==0 && n)
		{
			i++;
			r=n%100;
			if(r<=19&&r!=0)
				printf("%s \n",first[r]);	
			else
			if(r!=0)
			{
				k=r%10;
				r=r/10;
				printf("%s %s\n ",second[r-1],first[k]);	
			}
			n=n/100;
		}
		if(i==1 && n)
		{
			
			r=n%10;
			n=n/10;
			if(r!=0)
				printf("%s %s \n",first[r],third[i-1]);
			i++;
		}
		if(i==2&& n)
		{
			r=n%100;
			if(r<=19&&r!=0)
				printf("%s %s \n",first[r],third[i-1]);
			else if(r!=0)
			{
				k=r%10;
				r=r/10;
				printf("%s %s %s\n",second[r-1],first[k],third[i-1]);
			}
			i++;
			n=n/100;
		}
		if(i==3 && n)
		{
			r=n%100;
			if(r<=19&&r!=0)
				printf("%s %s \n",first[r],third[i-1]);
			else if(r!=0)
			{
				k=r%10;
				r=r/10;
				printf("%s %s %s\n",second[r-1],first[k],third[i-1]);
			}
			i++;
			n=n/100;
		}
		if(i==4 && n)
		{
			//r=n%100;
			if(n<=19&&r!=0)
				printf("%s %s \n",first[n],third[i-1]);
			else if(r!=0)
			{
				k=n%10;
				n=n/10;
				printf("%s %s %s\n ",second[n-1],first[k],third[i-1]);
			}
			
		}
		printf("\n");
	return 0;
}
