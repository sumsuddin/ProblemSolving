#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
bool bu[1000050],fl;
long long i,j,n,t,sq,d,my[100050],prm[1000050],lst,ff[100050],pf[100050],fr,l,x,b,cs=1;

int main()
{
	prm[0]=2;
	lst=1;
	for(i=3;i<1000001;i+=2)
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<=1000001;j+=2*i)
				bu[j]=1;
		}

	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&n,&b);

		l=0;
		sq=(long long)sqrt(n);
		if(sq*sq==n)
		fl=1;
		else
		fl=0;
		for(i=0;i<lst && prm[i]<=sq;i++)
		{
			if(n%prm[i]==0)
			{
				fr=0;
				while(n%prm[i]==0)
					n/=prm[i],fr++;

				pf[l]=prm[i];
				ff[l++]=fr;
				sq=(long long)sqrt(n);
			}
		}
		if(n>1)
		{
			pf[l]=n;
			ff[l++]=1;
		}

		my[0]=1LL;
		fr=1;
		for(i=0;i<l;i++)
		{
			d=1;
			for(j=0,x=0;j<ff[i];j++)
			{
				d*=pf[i];

				for(n=0;n<fr;n++)
					my[fr+(x++)]=my[n]*d;
			}
			fr+=x;
		}
		sort(my,my+fr);
		for(i=0;i<fr;i++)
		if(my[i]>=b)
		break;
		fr=(fr-fl)/2-i;
		if(fr<0)
		fr=0;
		printf("Case %lld: %lld\n",cs++,fr);
	}
	return 0;
}
