#include<stdio.h>
#include<algorithm>
using namespace std;

long i,j,u,l,a,n,m,st[50010];
bool flag;
void bsearch()
{
	l=0;u=n-1;
	while(1)
	{
		i=(u+l)/2;
		if(u<=l || st[i]==a)
		{
			u=i;
			flag=0;
			while(st[i]>=a)
			{
				i--;
				if(i==-1)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				printf("X ");
			else
				printf("%ld ",st[i]);
			flag=0;
			while(st[u]<=a)
			{
				u++;
				if(u==n)
				{
					flag=1;
					break;
				}
			}

			if(flag)
				printf("X\n");
			else
				printf("%ld\n",st[u]);
			break;
		}
		else
			if(st[i]<a)
			{
				l=i+1;
			}
			else
				if(st[i]>a)
				{
					u=i-1;
				}
	}
}

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&st[i]);

		sort(st,st+n);

		scanf("%ld",&m);
		for(j=0;j<m;j++)
		{
			scanf("%ld",&a);
			bsearch();
		}
	}
	return 0;
}