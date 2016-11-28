#include<stdio.h>

long i,j,lst,t,n,prm[700000],sum,cs=1;
bool bu[10000050],prs[10000050];

int main()
{
	scanf("%ld",&t);

	lst=1;
	prm[0]=2;
	prs[2]=1;
	for(i=3;i<10000000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			prs[i]=1;
			for(j=i*3;j<10000000;j+=2*i)
				bu[j]=1;
		}
	}

	while(t--)
	{
		scanf("%ld",&n);

		sum=0;
		for(i=0;prm[i]<=n/2;i++)
			if(prs[n-prm[i]])
				sum++;
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}