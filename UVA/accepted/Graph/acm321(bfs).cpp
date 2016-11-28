#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<long>vc[20],sw[20];
queue<long>que;
bool vst[20][3050],flag;
long i,a,b,vs,p,n,m,s,d,j,cs=1;
struct ss
{
	long path,p,vs;
}
par[20][3050];

void bc(long a,long b)
{
	if(a==1 && b==1)
		return ;

	long i,p,vs;
	p=par[a][b].p;
	vs=par[a][b].vs;

	bc(p,vs);

	if(p==a)
	{
		for(i=0;i<n;i++)
		{
			if(((vs>>i)&1) != ((b>>i)&1))
			{
				if(((b>>i) & 1))
					printf("- Switch on light in room %ld.\n",i+1);
				else
					printf("- Switch off light in room %ld.\n",i+1);
				break;
			}
		}
	}
	else
		printf("- Move to room %ld.\n",a);
}

void bfs(long p,long vs)
{
	long i;
	que.push(p);
	que.push(vs);

	vst[p][vs]=0;
	while(!que.empty() && flag)
	{
		p=que.front();
		que.pop();
		vs=que.front();
		que.pop();

		for(i=0;i<vc[p].size();i++)
		{
			if(vst[vc[p][i]][vs] && (vs>>(vc[p][i]-1) & 1))
			{
				par[vc[p][i]][vs].p=p;
				par[vc[p][i]][vs].vs=vs;
				par[vc[p][i]][vs].path=par[p][vs].path+1;

				vst[vc[p][i]][vs]=0;
				que.push(vc[p][i]);
				que.push(vs);

				if(vc[p][i]==n && vs==(1<<(n-1)))
				{
					while(!que.empty())
						que.pop();
					flag=0;
					printf("The problem can be solved in %ld steps:\n",par[n][vs].path);
					bc(n,vs);
					break;
				}
			}
		}
		if(flag)
		{
			for(i=0;i<sw[p].size();i++)
			{
				if(sw[p][i]==p)
					continue;
				d=vs ^ (1<<(sw[p][i]-1));
			
				if(vst[p][d])
				{
					par[p][d].p=p;
					par[p][d].vs=vs;
					par[p][d].path=par[p][vs].path+1;

					que.push(p);
					que.push(d);
					vst[p][d]=0;

					if(p==n && d==(1<<(n-1)))
					{
						while(!que.empty())
							que.pop();
						s=que.size();
						flag=0;
						printf("The problem can be solved in %ld steps:\n",par[n][d].path);
						bc(n,d);
						break;
					}
				}
			}
		}
	}
}

int main()
{
	while(scanf("%ld%ld%ld",&n,&m,&s) && (n|| m|| s))
	{
		for(i=0;i<=n;i++)
		{
			vc[i].clear();
			sw[i].clear();
			for(j=0;j<3000;j++)
				vst[i][j]=1;
		}

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&a,&b);
			vc[a].push_back(b);
			vc[b].push_back(a);
		}
		while(s--)
		{
			scanf("%ld%ld",&a,&b);

			sw[a].push_back(b);
		}
		for(i=0;i<n;i++)
			sort(vc[i].begin(),vc[i].end()),sort(sw[i].begin(),sw[i].end());

		par[1][1].path=0;
		flag=1;
		vst[1][1]=0;
		printf("Villa #%ld\n",cs++);
		if(n<=1)
		{
			flag=0;
			printf("The problem can be solved in 0 steps:\n");
		}
		else
			bfs(1,1);
		if(flag)
			printf("The problem cannot be solved.\n");
		printf("\n");
	}
	return 0;
}
