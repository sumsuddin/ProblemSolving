#include<stdio.h>
#include<algorithm>
using namespace std;

long mat[40][40],i,j,k,p,n,t,m,a[40],cs=1;
bool fl[40],no;
void chk(long x)
{
	long i,j;
	for(i=1;i<=n;i++)
	{
		if(fl[i])
		{
			for(j=0;j<k;j++)
				if(mat[i][j]==x)
					fl[i]=0;
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&n,&m,&k);

		for(i=1;i<=n;i++)
		{
			fl[i]=1;
			for(j=0;j<k;j++)
				scanf("%ld",&mat[i][j]);
		}

		scanf("%ld",&p);

		for(i=0;i<p;i++)
			scanf("%ld",&a[i]);

		sort(a,a+p);

		for(i=1,j=0;i<=m;i++)
			if(j<p && a[j]==i)
				chk(i),j++;
			else
				chk(-i);

		no=0;
		for(i=1;i<=n;i++)
			if(fl[i])
				no=1;
		if(no)
			printf("Case %ld: No\n",cs++);
		else
			printf("Case %ld: Yes\n",cs++);
	}
	return 0;
}