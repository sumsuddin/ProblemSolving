#include<stdio.h>
typedef unsigned long long lng;
lng i,j,t,a,b,n,sr[5000010];
bool bu[5000010];
long cs=1;

void sieve()
{
	for(i=2;i<5000001;i++)
		sr[i]=i;

	sr[2]=1;
	for(j=4;j<5000001;j+=2)
		sr[j]/=2;
	for(i=3;i<5000001;i+=2)
	{
		if(bu[i]==0)
		{
			sr[i]=i-1;

			for(j=2*i;j<5000001;j+=i)
			{
				bu[j]=1;
				sr[j]/=i;
				sr[j]*=(i-1);
			}
		}
	}
	for(i=2;i<5000001;i++)
		sr[i]=sr[i-1]+(sr[i]*sr[i]);
}

int main()
{
	scanf("%llu",&t);

	sieve();

	while(t--)
	{
		scanf("%llu%llu",&a,&b);
		printf("Case %ld: %llu\n",cs++,sr[b]-sr[a-1]);
	}
	return 0;
}
