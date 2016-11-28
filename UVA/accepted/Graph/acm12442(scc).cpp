#include<stdio.h>
#include<algorithm>
using namespace std;
struct ss
{
	long st,ind;
}
fin[50050];
long i,j,adj[50050],time,cont[50050],found,cycle,child[50050],ans,mx,k,t,n,cs=1,clr[50050];
bool vst[50050];
bool cmp(ss a,ss b)
{
	return a.st>b.st;
}

void dfs(long p)
{
	if(adj[p]<0)
		return;

	if(vst[adj[p]])
	{
		time++;
		vst[adj[p]]=0;
		dfs(adj[p]);
	}
	fin[p].st=++time;
}

void dfn(long p,long cnt,long cclr)
{
	cont[p]=cnt;
	clr[p]=cclr;

	if(adj[p]==-1)
		child[p]=0;

	if(vst[adj[p]]==0)
	{
		if(clr[adj[p]]==clr[p])
			k=cont[p]-cont[adj[p]]+1,cycle=1,found=adj[p];
		else
			;
	}
	else
		vst[adj[p]]=0,dfn(adj[p],cnt+1,cclr);
	if(cycle)
		child[p]=k;
	else
		child[p]=child[adj[p]]+1;

	if(found==p)
		cycle=0;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		time=0;
		scanf("%ld",&n);

		for(i=1;i<=n;i++)
			adj[i]=-1,clr[i]=0;

		for(i=1;i<=n;i++)
		{
			vst[i]=1;
			fin[i].st=0;
			scanf("%ld%ld",&k,&cycle);

			adj[k]=cycle;
		}

		for(i=1;i<=n;i++)
		{
			if(vst[i])
			{
				vst[i]=0;
				dfs(i);
			}
		}

		for(i=1;i<=n;i++)
			vst[i]=1,fin[i].ind=i;

		sort(fin+1,fin+n+1,cmp);

		for(i=1;i<=n;i++)
		{
			if(vst[fin[i].ind])
			{
				k=0;found=-1;
				cycle=0;
				vst[fin[i].ind]=0;
				dfn(fin[i].ind,0,i);
			}
		}
		mx=child[1];
		ans=1;
		for(i=2;i<=n;i++)
			if(mx<child[i])
				mx=child[i],ans=i;
		printf("Case %ld: %ld\n",cs++,ans);
	}
	return 0;
}