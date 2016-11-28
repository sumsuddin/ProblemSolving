#include<stdio.h>
#include<math.h>

bool bu[10000005];
long long i,j,lst,prm[1000000],n,t,sq,cs=1,ans;

int main()
{
	scanf("%lld",&t);
	lst=0;
	for(i=3;i<10000000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=i*3;j<10000000;j+=2*i)
				bu[j]=1;
		}
	}

	while(t--)
	{
		scanf("%lld",&n);

		while(n%2==0)
			n/=2;

		sq=(long long)sqrt(n);

		ans=1;
		for(i=0;i<lst && prm[i]<=sq;i++)
		{
			if(n%prm[i]==0)
			{
				j=0;
				while(n%prm[i]==0)
					j++,n/=prm[i];
				ans*=j+1;
				sq=(long long)sqrt(n);
			}
		}
		if(n>1)
			ans*=2;

		printf("Case %lld: %lld\n",cs++,ans-1);
	}
	return 0;
}