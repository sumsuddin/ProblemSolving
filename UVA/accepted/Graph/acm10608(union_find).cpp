#include<stdio.h>

long i,x,y,a[30100],b[30100],p1,p2,n,max,t,m;

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
	scanf("%ld",&t);
	while(t--)
	{
		max=0;
		scanf("%ld%ld",&n,&m);

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
			b[x]++;
			if(b[x]>max)
				max=b[x];
		}
		printf("%ld\n",max);
	}
	return 0;
}