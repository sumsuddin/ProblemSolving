#include<stdio.h>

int main()
{
	long int a,b,c,n,p=1;

	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld%ld%ld",&a,&b,&c);

		if((a>=b && a<=c) || (a>=c && a<=b))
				printf("Case %ld: %ld\n",p++,a);
		else
		{
			if((b>=c && b<=a) || (b>=a && b<=c))
				printf("Case %ld: %ld\n",p++,b);
			else
				printf("Case %ld: %ld\n",p++,c);
		}

	}

	return 0;
}