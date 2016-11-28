#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<long>v[100005];
long vst[100005],vstit[100005],path[100005],nd,mx,p,st[100005],sr,tpm;

void dfs(long x)
{
	long l,i;
	l=v[x].size();
	vst[x]=1;
	vstit[x]=1;
	p++;
	for(i=0;i<l;i++)
	{
		if(vst[v[x][i]]==0)
		{
			path[v[x][i]]=path[x]+1;
			if(path[v[x][i]]>mx)
			{
				mx=path[v[x][i]];
				nd=v[x][i];
			}
			vstit[v[x][i]]=1;
			vst[v[x][i]]=1;
			dfs(v[x][i]);
		}
	}
	path[x]=0;
	vst[x]=0;
}
int main()
{
	long t,n,i,j,x,y,cs=1,q;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&q);
		tpm=0;
		for(i=0;i<q;i++)
		{
			scanf("%ld%ld",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		j=0;
		for(i=1;i<=n;i++)
		{
			if(vstit[i]==0)
			{
				p=0;
				mx=0;
				dfs(i);
				mx=0;
				sr=p;
				dfs(nd);
				mx++;
				if(st[sr]<mx)
					st[sr]=mx;
				if(tpm<sr)
					tpm=sr;
			}
		}

		mx=0;
		for(i=tpm;i>0;i--)
		{
			if(st[i]>mx)
				mx=st[i];
			st[i]=mx;
		}

		scanf("%ld",&q);
		printf("Case %ld:\n",cs++);
		while(q--)
		{
			scanf("%ld",&x);
			if(x<=tpm)
			{
				if(x<=st[x])
					printf("%ld\n",x-1);
				else
					printf("%ld\n",(st[x]-1)+((x-st[x])<<1));
			}
			else
				printf("impossible\n");
		}
		for(i=0;i<=n;i++)
		{
			vstit[i]=st[i]=0;
			v[i].clear();
		}
	}
	return 0;
}