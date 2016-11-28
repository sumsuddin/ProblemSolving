#include<stdio.h>
#include<math.h>
long i,a[1010],b[1010],p1,p2,n,max,rank[1010],t,j,cs=1;

double dis,xq[1010],yq[1010],kk;

void init()
{
	for(i=0;i<=n;i++)
	{
		a[i]=i;
		b[i]=0;
		rank[i]=0;
	}
}

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%lf",&n,&dis);
		init();
		for(i=0;i<n;i++)
			scanf("%lf%lf",&xq[i],&yq[i]);

		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(dis>=sqrt((xq[i]-xq[j])*(xq[i]-xq[j])+(yq[i]-yq[j])*(yq[i]-yq[j])))
				{
					p1=parent(i);
					p2=parent(j);
					if(p1!=p2)
					{
						if(rank[p1]>rank[p2])
						{
							a[p2]=p1;
							rank[p1]++;
						}
						else
						{
							a[p1]=p2;
							rank[p2]++;
						}
					}
				}
			}
		}
		p2=0;
		for(i=0;i<n;i++)
		{
			p1=parent(i);
			if(b[p1]==0)
			{
				p2++;
				b[p1]=1;
			}
		}
		printf("Case %ld: %ld\n",cs++,p2);
	}
	return 0;
}