#include<stdio.h>
long t,n,m,a,b,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		b=9+10;

		a=n-m;
		if(a<0)
			a*=-1;
		else
			a*=1;
		a+=n;
		a*=4;

		printf("Case %ld: %ld\n",cs++,a+b);
	}
	return 0;
}