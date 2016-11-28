#include<stdio.h>
#include<math.h>
long long prm[1000000],i,j,lst,t,a,b,l,p,sq,cs=1,ans;
bool bu[1000050];

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

int main()
{
	scanf("%lld",&t);

	lst=1;
	prm[0]=2;

	for(i=3;i<1000000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<1000000;j+=2*i)
				bu[j]=1;
		}
	}

	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&l);

		p=(a*b)/gcd(a,b);

		if(l%p)
			printf("Case %lld: impossible\n",cs++);
		else
		{
			l/=p;

			sq=(long long)sqrt(p);

			ans=1;
			for(i=0;i<lst && prm[i]<=sq;i++)
				if(l%prm[i]==0)
				{
					while(l%prm[i]==0)
						ans*=prm[i],l/=prm[i];
					while(p%prm[i]==0)
						ans*=prm[i],p/=prm[i];
				}
			if(l>1)
			{
                ans*=l;
                while(p%l==0)
                ans*=l,p/=l;
            }
			printf("Case %lld: %lld\n",cs++,ans);
		}
	}
	return 0;
}
