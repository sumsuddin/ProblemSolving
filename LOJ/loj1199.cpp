#include<stdio.h>

long i,j,k,gn[10005],t,n,cs=1;
bool ind[130];

int main()
{
	for(i=3;i<10001;i++)
	{
		for(j=0;j<128;j++)
			ind[j]=0;

		for(j=1,k=i-1;j<k;j++,k--)
			ind[gn[j]^gn[k]]=1;
		for(j=0;j<128;j++)
			if(ind[j]==0)
				break;
		gn[i]=j;
	}

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&j);
			k^=gn[j];
		}

		if(k)
			printf("Case %ld: Alice\n",cs++);
		else
			printf("Case %ld: Bob\n",cs++);
	}
	return 0;
}