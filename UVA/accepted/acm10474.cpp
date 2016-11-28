#include<stdio.h>
#include<algorithm>
using namespace std;

bool d;
long i,u,l,n,q,m,st[10005],j,cas=1;

long bsearch()
{
	d=1;
	l=0;u=m;i=(u-l)/2;
	while(u>=l)
	{

		if(st[i]==n)
		{
			d=0;
			for(j=i;j>=l;j--)
			{
				if(st[j]==n)
					u=j;
				else
					break;
			}
			return u+1;
		}
		else
			if(st[i]<n)
			{
				l=i+1;
				i=(u+l)/2;
			}
			else
				if(st[i]>n)
				{
					u=i-1;
					i=(u+l)/2;
				}
	}
	if(d)
		return -1;
}

int main()
{
	while(scanf("%ld%ld",&m,&q) && (m||q))
	{
		for(i=0;i<m;i++)
			scanf("%ld",&st[i]);

		sort(st,st+m);
		printf("CASE# %ld:\n",cas++);

		while(q--)
		{
			scanf("%ld",&n);
			i=bsearch();
			if(i>0)
				printf("%ld found at %ld\n",n,i);
			else
				printf("%ld not found\n",n);
		}
	}
	return 0;
}