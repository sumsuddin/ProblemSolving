#include<stdio.h>
long n,t,a,sum,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		sum=0;
		while(n--)
		{
			scanf("%ld",&a);
			if(a>0)
				sum+=a;
		}
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}