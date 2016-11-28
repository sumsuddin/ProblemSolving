#include<stdio.h>
#include<string.h>

int main()
{
	long a,b,c,n;

	while(scanf("%ld%ld",&a,&b)==2)
	{
		n=a;
		while(a>=b)
		{
			c=a%b;
			a/=b;
			n+=a;
			a+=c;
		}
		printf("%ld\n",n);
	}
	return 0;
}