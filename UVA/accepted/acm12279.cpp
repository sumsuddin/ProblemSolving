#include<stdio.h>
long n,cs=1,a,sum;
int main()
{
 	while(scanf("%ld",&n),n)
 	{
	 						sum=0;
		while(n--)
        {
		   	 scanf("%ld",&a);
		   	 if(a)
		   	 sum++;
		   	 else
		   	 sum--;
	     }
	     printf("Case %ld: %ld\n",cs++,sum);
	  }
	  return 0;
  }
