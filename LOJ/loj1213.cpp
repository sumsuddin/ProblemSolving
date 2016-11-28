#include<stdio.h>

long long n,k,m,t,a,p,i,cs=1;

long long  pw(long long a,long long b,long long c)
{
	long long ans=a,rc=1;
	while(b>=2*rc)
		ans=(ans*ans)%c,rc*=2;
	if(b-rc>0)
        return (ans*pw(a,b-rc,c)%c);
	else
		return ans;
	
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&m);

		p=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a);
			p+=a;
		}
		if(k>1)
		n=pw(n,k-1,m);
		else
		n=1;

		n=(n*p)%m;

		n=(n*k)%m;
		printf("Case %lld: %lld\n",cs++,n);
	}
	return 0;
}
