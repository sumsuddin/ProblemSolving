#include<stdio.h>
long long t,n,m,sum,a,cs=1,l,p,x;
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&n,&m);

		x=(m*(m+1))/2;
		p=(n/(2*m))-1;
		l=(m*m*(p+1)*p)+((p+1)*x);
		printf("Case %lld: %lld\n",cs++,(n*(n+1))/2-(2*l));
	}
	return 0;
}