#include<stdio.h>
#include<string.h>
#include<queue>
#include<string>
#include<vector>
#include<map>
using namespace std;
queue<long>que;
map<string,long>mp;
vector<long>vc[100];
long i,j,n,d,m,mmx,mx,par[1000],p,cs=1;
char st[1000],sy[1000],sr[100][1000];
bool vst[10000];
long bfs(long s)
{
	n=d;
	mmx=0;
	for(j=0;j<=d;j++)
		vst[j]=1;
	que.push(s);
	par[s]=0;
	vst[s]=0;
	n--;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		if(par[p]>mmx)
			mmx=par[p];

		for(j=0;j<vc[p].size();j++)
		{
			if(vst[vc[p][j]])
			{
				n--;
				par[vc[p][j]]=par[p]+1;
				que.push(vc[p][j]);
				vst[vc[p][j]]=0;

				if(par[vc[p][j]]>mmx)
					mmx=par[vc[p][j]];
			}
		}
	}
	if(n==0)
		return mmx;
	else
		return 100000000;
}

int main()
{
	while(~scanf("%ld%ld",&n,&m) && (n||m))
	{
		d=n;
		for(i=0;i<=n;i++)
			vst[i]=1;
		for(i=0;i<m;i++)
		{
			scanf("%s%s",st,sy);
			if(mp[st]==0)
			{
				strcpy(sr[n],st);
				mp[st]=n--;
			}
			if(mp[sy]==0)
			{
				strcpy(sr[n],sy);
				mp[sy]=n--;
			}
			vc[mp[sy]].push_back(mp[st]);
			vc[mp[st]].push_back(mp[sy]);
		}

		mx=0;
		for(i=1;i<=d;i++)
		{
			if(sr[i][0])
			{
				n=bfs(i);
				if(n>mx)
					mx=n;
				if(mx==100000000)
					break;
			}
		}
		if(mx==100000000)
			printf("Network %ld: DISCONNECTED\n\n",cs++);
		else
			printf("Network %ld: %ld\n\n",cs++,mx);
		for(i=0;i<=d;i++)
			vc[i].clear();
		mp.clear();
	}
	return 0;
}