#include<stdio.h>
#include<string.h>

int main()
{
	long a,b,c,n,ad,m;

	scanf("%ld",&m);
	while(m--)
	{
		scanf("%ld%ld%ld",&a,&ad,&b);
		n=0;
		a+=ad;
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