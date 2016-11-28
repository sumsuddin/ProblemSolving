#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
set<long>vc[20005];
long i,n,t,a,b,time,cs=1,wt[20050];
bool vst[20005];
struct sss
{
	long ind,fin;
}sr[20050];


bool cmpr(sss a,sss b)
{
	return a.fin>b.fin;
}

long dfs(long a)
{
	long ret=0;
	if(vc[a].size()==0)
		return 0;

	set<long>::iterator k;
	for(k=vc[a].begin();k!=vc[a].end();k++)
		if(vst[*k])
		{
			vst[*k]=0;
			ret+=(dfs(*k)+1);
		}
		else
			ret+=(sr[*k].fin+1);
	sr[a].fin=ret;
	return sr[a].fin;
}

long dfs1(long a)
{
	long ret=0;
	set<long>::iterator k;
	if(vc[a].size()==0)
	{
		wt[a]=0;
		return 1;
	}

	for(k=vc[a].begin();k!=vc[a].end();k++)
	{
		if(vst[*k])
			vst[*k]=0,ret+=wt[*k]=dfs1(*k),wt[*k]--;
		else if(wt[*k])
			wt[*k]--;
		else
			ret++;
	}
	return ret;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		vst[0]=1;sr[0].fin=0;
		for(i=1;i<n;i++)
		{
			vst[i]=1;
			sr[i].fin=0;
			scanf("%ld%ld",&a,&b);

			vc[b].insert(a);
		}

		for(i=0;i<n;i++)
			if(vst[i])
				vst[i]=0,dfs(i);

		for(i=0;i<n;i++)
			vst[i]=1,sr[i].ind=i;

		sort(sr,sr+n,cmpr);
		time=0;
		for(i=0;i<n;i++)
			if(vst[sr[i].ind])
				vst[sr[i].ind]=0,time+=wt[sr[i].ind]=dfs1(sr[i].ind);
		for(i=0;i<n;i++)
			vc[i].clear();

		printf("Case %ld: %ld\n",cs++,time);
	}
	return 0;
}