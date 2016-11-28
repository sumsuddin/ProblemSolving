#include<stdio.h>
#include<math.h>
long n,a,k;
int main()
{
	while(~scanf("%ld",&n))
	{
		a=1;k=0;
		while(n>=a)
			a*=2,k++;
		printf("%ld\n",k);
	}
	return 0;
}