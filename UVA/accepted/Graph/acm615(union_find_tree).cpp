#include<stdio.h>
long i,x,y,cs=1,tru,a[1000010],rank[1000010],mx,p1,p2;
bool vst[1000010];
void init()
{
	for(i=0;i<=1000000;i++)
	{
		a[i]=i;
		vst[i]=1;
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
	init();
	tru=1;
	mx=0;

	while(scanf("%ld%ld",&x, &y) && (x>=0 ||y>=0))
	{
		if(x==0 && y==0)
		{
			if(tru)
			{
				for(i=1;i<=mx;i++)
				{
					if(vst[i]==0)
					{
						x=parent(i);
						break;
					}
				}
				for(i=i;i<=mx;i++)
				{
					if(vst[i]==0)
					{
						if(x!=parent(i))
						{
							tru=0;
							break;
						}
					}
				}
			}
			if(tru)
				printf("Case %ld is a tree.\n",cs++);
			else
				printf("Case %ld is not a tree.\n",cs++);

			tru=1;mx=0;
			init();
		}
		else if(tru)
		{
			if(x>mx)
				mx=x;
			if(y>mx)
				mx=y;

			vst[x]=0;
			vst[y]=0;
			p1=parent(x);
			p2=parent(y);
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
			else
				tru=0;
		}
	}
	return 0;
}
