#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
queue<long>que;
vector<long>par[3050];
long i,m,n,b,a,l,sum,p,mx,day,tt,cnt;
bool sst[3050];
void bfs()
{
	day=mx=sum=0;
	que.push(a);
	cnt=1;
	
	tt=1;
	while(!que.empty())
	{
		cnt--;
		p=que.front();
		que.pop();
		for(i=0;i<par[p].size();i++)
		{
			if(sst[par[p][i]])
			{
				sum++;
				que.push(par[p][i]);
				sst[par[p][i]]=0;
			}
		}
		if(cnt==0)
		{
			if(sum>mx)
			{
				mx=sum;
				day=tt;
			}
			cnt=sum;
			sum=0;
			tt++;
		}
	}
	if(mx==0)
		printf("0\n");
	else
		printf("%ld %ld\n",mx,day);
}

int main()
{
	while(~scanf("%ld",&n))
	{
		for(m=0;m<n;m++)
		{
			scanf("%ld",&a);
			while(a--)
			{
				scanf("%ld",&b);
				par[m].push_back(b);
			}
		}
		scanf("%ld",&m);
		while(m--)
		{
			scanf("%ld",&a);
			for(i=0;i<=n;i++)
				sst[i]=1;
			sst[a]=0;
			bfs();
		}
		for(i=0;i<=n;i++)
			par[i].clear();
	}
	return 0;
}