#include<stdio.h>
#include<math.h>

long long sq,n,t,cs=1;

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&n);

		sq=(long long)sqrt(n);

		printf("Case %lld: ",cs++);

		if(sq*sq==n)
		{
			if(n%2)
				printf("%lld %lld\n",1LL,sq);
			else
				printf("%lld %lld\n",sq,1LL);
		}
		else
		{
			sq++;
			if(sq%2)
			{
				if(n-(sq-1)*(sq-1)<=sq)
					printf("%lld %lld\n",sq,n-(sq-1)*(sq-1));
				else
					printf("%lld %lld\n",2*sq-n+(sq-1)*(sq-1),sq);
			}
			else
			{
				if(n-(sq-1)*(sq-1)<sq)
					printf("%lld %lld\n",n-(sq-1)*(sq-1),sq);
				else
					printf("%lld %lld\n",sq,2*sq-n+(sq-1)*(sq-1));
			}
		}
	}
	return 0;
}
