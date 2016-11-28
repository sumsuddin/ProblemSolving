#include<stdio.h>

long t,n,m,i,j,need[100050],a[150],c[150],cs=1;
bool bu[100050];

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<=m;i++)
			bu[i]=0;
		bu[0]=1;

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&c[i]);

		for(i=0;i<n;i++)
		{
			for(j=0;j<=m;j++)
				if(bu[j])
					need[j]=0;
				else
					need[j]=100000;

			for(j=a[i];j<=m;j++)
			{
				if(bu[j-a[i]] && need[j-a[i]]<c[i] && need[j]>need[j-a[i]]+1)
					bu[j]=1,need[j]=need[j-a[i]]+1;
			}
		}
		j=0;
		for(i=1;i<=m;i++)
			j+=bu[i];
		printf("Case %ld: %ld\n",cs++,j);
	}
	return 0;
}