#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,n,m,a,b,t,mx,nd,p,sum,weight[10010],par[10010],l;
bool vst[10010];
vector <long > mat[10010];

void bfs()
{
	while(!que.empty())
	{
		p=que.front();
		que.pop();

		l=mat[p].size();
		for(i=0;i<l;i++)
		{
			if(vst[mat[p][i]])
			{
				vst[mat[p][i]]=0;
				par[mat[p][i]]=par[p]+1;

				if(weight[mat[p][i]]>1 )
					sum+=par[mat[p][i]];

				que.push(mat[p][i]);
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		for(i=0;i<=n;i++)
		{
			weight[i]=0;
			mat[i].clear();
		}

		while(m--)
		{
			scanf("%ld",&a);
			weight[a]++;
			if(a)
			while(scanf("%ld",&b),b)
			{
				mat[a].push_back(b);
				mat[b].push_back(a);
				
				a=b;
				weight[a]++;
			}
		}
		mx=1000000000;
		nd=1;
		for(m=1;m<=n;m++)
		{
			if(weight[m]>1)
			{
				for(i=0;i<=n;i++)
					vst[i]=1;
				que.push(m);
				par[m]=0;
				sum=0;
				bfs();
				if(mx>sum)
				{
					mx=sum;
					nd=m;
				}
			}
		}
		printf("Krochanska is in: %ld\n",nd);
	}
	return 0;
}