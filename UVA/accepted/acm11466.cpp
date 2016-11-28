#include<stdio.h>
#include<math.h>
int main()
{
	long long n=0,m,i,p,pa;

	while(scanf("%lld",&n),n)
	{
		if(n<0)
			n*=-1;
		p=pa=-1;
		if(!(n%2))
		{
			if(n==2)
			{
				printf("%lld\n",p);
				continue;
			}
		
			p=2;
			while(!(n%2))
				n/=2;
			pa++;
		}

		m=sqrt(n);
		for(i=3;i<=m;i+=2)
		{
			if(!(n%i))
			{
				while(!(n%i))
				{
					p=i;
					n/=i;
				}
				pa++;
			}
		}
		if(n!=1)
		{
			p=n;
			pa++;
		}
		if(pa<1)
			p=-1;
		printf("%lld\n",p);
	}
	return 0;
}
