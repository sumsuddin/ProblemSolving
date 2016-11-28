#include<stdio.h>
#include<math.h>
long long i,j,lst,n,t,m,sq,prm[100050],fr[100050],ans,cs=1,d;
bool bu[100050],flag;
int main()
{
	prm[0]=2;
	lst=1;

	for(i=3;i<100000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;

			for(j=3*i;j<100000;j+=2*i)
				bu[j]=1;
		}
	}

	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<lst && prm[i]<=n;i++)
			fr[prm[i]]=0;

		for(i=0;i<lst && prm[i]<=n;i++)
		{
			d=n;
			while(d>0)
				d/=prm[i],fr[prm[i]]+=d;
		}
		ans=1LL;
		flag=1;
		for(i=0;prm[i]<=n;i++)
		{
			d=fr[prm[i]]/m;
			while(d--)
				flag=0,ans=((ans*prm[i])%10000019LL+10000019LL)%10000019LL;
		}
		if(flag)
			printf("Case %lld: -1\n",cs++);
		else
			printf("Case %lld: %lld\n",cs++,ans);
	}
	return 0;
}
