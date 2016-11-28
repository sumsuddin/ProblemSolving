#include<stdio.h>
long i,n,sum,d;

long ls(long a)
{
	while(a)
		if(a%10)
			return a%10;
		else
			a/=10;
	return 0;
}

void ans(long i,long n)
{
	for(;i%10 && i<=n;i++)
	{
		sum+=ls(i);
	}

	for(;n%10 && n>i;n--)
	{
		sum+=ls(n);
	}
	d=n-i;
	sum+=(d/10*45);
	if(i/10>0 || n/10>0)
		ans(i/10,n/10);
}


int main()
{
	while(scanf("%ld%ld",&i,&n) && (i>-1 && n>-1))
	{
		sum =0;
		ans(i,n);

		printf("%ld\n",sum);
	}
	return 0;
}