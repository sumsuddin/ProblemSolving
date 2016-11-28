#include<stdio.h>
#include<math.h>
long long sum,n;
long long i,j,t,sq,cs=1,prm[1000050],lst,fr;
bool bu[1000050];
void siv()
{
	prm[0]=2;
	lst=1;
	for(i=3;i<1000000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=3*i;j<1000000;j+=2*i)
				bu[j]=1;
			prm[lst++]=i;
		}
	}
}

int main()
{
	scanf("%lld",&t);

	siv();

	while(t--)
	{
		scanf("%lld",&n);

		sq=(long long)sqrt(n);
		sum=1;

		for(i=0;n > 1 && i<lst && prm[i]<=sq;i++)
		{
			if(n%prm[i]==0)
			{
				fr=1;
				while(n>1 && n%prm[i]==0)
					n/=prm[i],fr++;
				sum*=fr;
				sq=sqrt(n);
			}
		}
		if(n>1)
			sum*=2;

		printf("Case %lld: %lld\n",cs++,sum-1);
	}
	return 0;
}