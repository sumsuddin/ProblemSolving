#include<stdio.h>
#include<math.h>
int main()
{
	long n,sum,sum2,m,a,i;
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld",&m);

		sum=sum2=0;

		a=m;
		while(m)
		{
			sum+=(m%2);
			m/=2;
		}
		for(i=0;a;i++)
		{
			m+=(long)((a%10)*pow(16,i));
			a/=10;
		}
		while(m)
		{
			sum2+=(m%2);
			m/=2;
		}
		printf("%ld %ld\n",sum,sum2);
	}
	return 0;
}