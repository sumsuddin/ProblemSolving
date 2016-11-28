#include<stdio.h>
#include<algorithm>
using namespace std;

long cs=1,rank[250],a[250],cst,i,n,e,g,lst,t,j;
bool vst[250];
struct ss
{
	long u,v,w;
}
sr[250];

bool cmp(ss a,ss b)
{
	return a.w<b.w;
}

void init()
{
	long i;
	for(i=0;i<=n;i++)
	{
		a[i]=i;
		rank[i]=0;
	}
}

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}

void mst()
{
	long i,p1,p2;
	cst=0;
	for(i=0;i<lst;i++)
	{
		p1=parent(sr[i].u);
		p2=parent(sr[i].v);

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
			vst[i]=1;
			cst+=sr[i].w;	
		}
		else
			vst[i]=0;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&e);

		printf("Case %ld:\n",cs++);
		lst=0;

		for(i=0;i<e;i++)
		{
			scanf("%ld%ld%ld",&sr[lst].u,&sr[lst].v,&sr[lst].w);

			if(sr[lst].u>sr[lst].v)
			{
				g=sr[lst].u;
				sr[lst].u=sr[lst].v;
				sr[lst].v=g;
			}
			lst++;
			sort(sr,sr+lst,cmp);

			init();
			mst();
			g=0;

			for(j=0;j<lst;j++)
				if(vst[j])
					sr[g++]=sr[j];
			lst=g;
			if(lst==n-1)
				printf("%ld\n",cst);
			else
				printf("-1\n");
		}
	}
	return 0;
}