#include<stdio.h>

long i,x,y,a[50010],b[50010],p1,p2,n,max,cs=1,m;

void init()
{
	for(i=0;i<=n;i++)
	{
		a[i]=-1;
		b[i]=0;
	}
}
long parent(long p)
{
	if(a[p]==-1)
		return p;
	else
		parent(a[p]);
}
int main()
{
	while(scanf("%ld%ld",&n,&m) && (m|| n))
	{
		init();
		while(m--)
		{
			scanf("%ld%ld",&x,&y);
			p1=parent(x);
			p2=parent(y);
			if(p1!=p2)
				a[p2]=p1;
		}
		for(i=1;i<=n;i++)
		{
			x=parent(i);
			b[x]=1;
		}
		max=0;
		for(i=1;i<=n;i++)
		{
			if(b[i])
				max++;
		}
		printf("Case %ld: %ld\n",cs++,max);
	}
	return 0;
}