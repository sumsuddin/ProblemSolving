#include<stdio.h>
int main()
{
	long long a,b,c,d,n,p=1;

	scanf("%lld",&d);
	while(d--)
	{
		scanf("%lld",&n);
		if(n==0)
		{
			printf("Scenario #%lld:\n1\n\n",p++);
			continue;
		}

		a=1;
		b=2;
		while(n--)
		{
			c=b;
			b+=a;
			a=c;

		}
		printf("Scenario #%lld:\n%lld\n\n",p++,c);
	}
	return 0;
}