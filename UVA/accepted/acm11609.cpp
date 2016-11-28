#include<stdio.h>
long long n,t,ans,rc,cs=1;
long long  pw(long long b)
{
	long long ans=2,rc=1;
	while(b>=2*rc)
		ans=(ans*ans)%1000000007,rc*=2;
	if(b-rc>0)
        return (ans*pw(b-rc)%1000000007);
	else
		return ans;
	
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)
		printf("Case #%lld: 1\n",cs++);
		else
		printf("Case #%lld: %lld\n",cs++,(pw(n-1)*n)%1000000007);
	}
	return 0;
}
