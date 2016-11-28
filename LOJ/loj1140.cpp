#include<stdio.h>
long long a,b,t,cs=1LL;

long long powr(long long a,long long b)
{
    if(b<0)
    return 0;
    long long d=1;
    while(b--)
    d*=a;
    return d;
}

long long make1(long long bit)
{
	long long ret=1LL;
	while(bit--)
		ret=ret*10LL+1LL;
	return ret;
}

long long eql(long long n,long long bit)
{
	if(bit<0LL)
		return 1LL;

	long long x=make1(bit)*9LL;
	if(n<=x)
		return n=n+1LL+eql(n%(x+1LL),bit-1LL);
	else
		return x+1LL+( (n/(x+1LL))*(bit+1LL)*(long long)powr(10,bit) )+eql(n%(x+1),bit-1LL);
}

long long rec(long long p)
{
	if(p==-1LL)
		return 0LL;

	long long bit,x,l,sum=1LL;
	bool tru;

	tru=1;
	bit=0LL;
	l=10;
	while(tru)
	{
		tru=0;
		x=make1(bit)*9LL;
		if(p>=x)
			tru=1,sum+=9LL*bit*(long long)powr(10,bit-1),bit++;
	}

	bit--;
	if(bit<0)
	bit=0;
	l=make1(bit)*9LL;
	l++;
	if(p>=l)
	{
    	if(p/l==1LL)
    		sum+=eql(p%l,bit-1LL);
    	else
    		sum+=((p/l)-1LL)*(bit+1LL)*(long long)powr(10,bit) + eql(p%l,bit-1LL);
    }

	return sum;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&a,&b);

		printf("Case %lld: %lld\n",cs++,rec(b)-rec(a-1LL));
	}
	return 0;
}
