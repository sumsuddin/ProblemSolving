#include<stdio.h>
#include<math.h>
long long n,i,sq;
int main()
{
	while(scanf("%lld",&n) && n>=0)
	{
		sq=(long double)sqrt(n);
		for(i=2;i<sq;i++)
			while((n%i)==0)
			{
				printf("    %lld\n",i);
				n/=i;
			}
		if(n==1)
			printf("\n");
		else
			printf("    %lld\n\n",n);
	}
	return 0;
}
