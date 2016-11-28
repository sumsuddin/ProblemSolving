#include<stdio.h>
#include<math.h>
typedef long long lng;
lng a,b,bb,i,sq;
lng  pw(lng b)
{
	lng ans=a,rc=1;
	while(b>=2*rc)
		ans=(ans*ans)%bb,rc*=2;
	if(b-rc>0)
        return (ans*pw(b-rc)%bb);
	else
		return ans;
}

bool chk(lng a)
{
	if(a%2==0)
		return 0;
	sq=sqrt(a);
	for(i=3;i<=sq;i+=2)
		if(a%i==0)
			return 0;
	return 1;
}

int main()
{
	while(scanf("%lld%lld",&bb,&a) && (a||bb))
	{
		if(chk(bb))
		{
			printf("no\n");
			continue;
		}

		if(pw(bb)%bb==a)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
