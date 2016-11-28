#include<stdio.h>
long long ans,d,lst,n,m,i,a,f[15],fn[15][15],j,ff[15];
void rec_all(long long n)
{
    d=1;
    lst=0;
    while(d*10<=n)
    lst++,d*=10;

    for(i=1;i<10;i++)
    f[i]=0;
    while(n)
    {
        a=n/d;
        n%=d;

        for(i=0;i<a;i++)
        {
            for(j=1;j<10;j++)
            f[j]+=fn[lst][j];

            if(i)
            f[i]+=d;
        }
//            ans+=fn[lst],ans+=i*d;
        d/=10;
        f[a]+=(n+1);
//        f[0]+=lst;
        lst--;
    }
}

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
    for(i=0;i<10;i++)
    fn[0][i]=0;

    for(i=0;i<10;i++)
    fn[1][i]=1;
    d=1;
    for(i=2;i<9;i++)
    {
        d*=10;

        fn[i][0]=9*fn[i-1][0]+d;

        for(j=1;j<10;j++)
        fn[i][j]=d+10*fn[i-1][j];
    }

    while(scanf("%lld%lld",&n,&m) && (n||m))
    {
        rec_all(n-1);
        f[0]=rec(n-1);
        for(i=0;i<10;i++)
        ff[i]=f[i];

        rec_all(m);
        f[0]=rec(m);

        for(i=0;i<9;i++)
        printf("%lld ",f[i]-ff[i]);

        printf("%lld\n",f[9]-ff[9]);
    }
    return 0;
}
