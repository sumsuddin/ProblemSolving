#include<stdio.h>
#include<math.h>
long i,j,sq,n,sum,prm[100005],lst,m,l,d;
bool bu[100005];

void sieve()
{
	lst=0;
	prm[lst++]=2;
	for(i=3;i<100000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<100000;j+=(2*i))
				bu[j]=1;
		}
	}
}

int main()
{
	sieve();

	while(~scanf("%ld",&n))
	{
		sq=sqrt(n);

		sum=0;
		m=n;
		d=0;
		l=1;
		for(i=0;prm[i]<=sq;i++)
			if(n%prm[i]==0)
			{
				d=((n-l)/prm[i]);
				l+=d;
				sum+=d;
				while(m%prm[i]==0)
					m/=prm[i];
			}
		if(m>1)
			sum+=(n-l)/m;
		if(sq*sq==n && n!=1)
			sum++;
		for(i=2;i<=sq;i++)
			if(n%i==0)
				sum-=2;
		printf("%ld\n",sum);
	}
	return 0;
}