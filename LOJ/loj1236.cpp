#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
map<long long ,long long >mp;
struct 
{
	long long fr,id;
}
nd[100000];
long long i,j,t,n,sq,temp[100000],tem[100000],divis[100000],dp[100000],prm[1000050],lst,last,pf,d,ff,add,cs=1,chk,l,h,mid;
bool bu[10000050];

long long gcd(long long a,long long b)
{
	long long c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
long long find(long long p)
{
    long long d;
    d=chk/p;
    while(((p/gcd(p,d))*d)!=chk)
        d*=chk/((p/gcd(p,d))*d);
    return d;
}

int main()
{
	prm[0]=2LL;
	lst=1LL;
	for(i=3LL;i<10000000LL;i+=2LL)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=i*3LL;j<10000000LL;j+=2LL*i)
				bu[j]=1;
		}
	}
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&n);

		pf=0LL;
		chk=n;
		sq=(long long)sqrt(n);
		for(i=0LL;i<lst && prm[i]<=sq;i++)
		{
			if(n%prm[i]==0)
			{
				nd[pf].id=prm[i];
				nd[pf].fr=0LL;
				while(n%prm[i]==0LL)
				{
					n/=prm[i];
					nd[pf].fr++;
				}
				pf++;
				sq=(long long)sqrt(n);
			}
		}
		if(n>1LL)
			nd[pf].id=n,nd[pf++].fr=1LL;

		last=1LL;
		divis[0]=1LL;
		dp[0]=1;
		mp[1]=0;
		for(i=0LL;i<pf;i++)
		{
			add=0LL;
			ff=nd[i].fr;
			d=1LL;
			for(ff=1;ff<=nd[i].fr;ff++)
			{
				d*=nd[i].id;			
		        for(j=0LL;j<last;j++)
				    tem[add]=dp[j]*(ff+1),temp[add++]=divis[j]*d;
			}
			for(j=0;j<add;j++)
				mp[temp[j]]=last,dp[last]=tem[j],divis[last++]=temp[j];
		}

		add=1LL;
		for(i=0LL;i<last;i++)
        {
            d=chk/find(divis[i]);
            add+=dp[mp[d]];
            d=mp[d];
        }
		printf("Case %lld: %lld\n",cs++,add/2);
	}
	return 0;
}
