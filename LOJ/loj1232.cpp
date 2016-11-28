#include<stdio.h>
long i,j,n,m,sol[10050],coin[140],t,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=1;i<=m;i++)
			sol[i]=0;
		sol[0]=1;

		for(i=0;i<n;i++)
			scanf("%ld",&coin[i]);

		for(i=0;i<n;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(j+coin[i]<=m)
					sol[j+coin[i]]=(sol[j+coin[i]]+sol[j])%100000007;
			}
		}
		printf("Case %ld: %ld\n",cs++,sol[m]%100000007);
	}
	return 0;
}