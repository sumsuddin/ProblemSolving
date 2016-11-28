#include<stdio.h>
long long a,b,c,t;
long long  pw(long long b)
{
	long long ans=a,rc=1;
	while(b>=2*rc)
		ans=(ans*ans)%c,rc*=2;
	if(b-rc>0)
        return (ans*pw(b-rc)%c);
	else
		return ans;
	
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);

		printf("%lld\n",pw(b)%c);

	}
	scanf("%*ld");
	return 0;
}
