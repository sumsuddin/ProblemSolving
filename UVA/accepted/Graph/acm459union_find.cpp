#include<stdio.h>

long i,x,y,a[100],b[100],p1,p2,n,max,t;
bool flag=1;

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
	scanf("%ld%*c%*c",&t);
	while(t--)
	{
		scanf("%c%*c",&n);
		n-=64;
		init();
		while(~scanf("%c",&x))
		{
			if(x=='\n')
			{
				break;
			}
			else
				scanf("%c%*c",&y);
			x-=64;
			y-=64;
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
		if(flag)
		{
			printf("%ld\n",max);
			flag=0;
		}
		else
			printf("\n%ld\n",max);
	}
	return 0;
}