#include<stdio.h>
#include<queue>
using namespace std;

queue<int>que;
long i,j,p,q,n,m,t,par[1010];
bool st[1010][1010],vst[1010];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<=n;i++)
		{
			par[i]=0;
			vst[i]=1;
			for(j=0;j<=n;j++)
				st[i][j]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&p,&q);
			st[p][q]=1;
			st[q][p]=1;
		}
		que.push(0);
		while(!que.empty())
		{
			p=que.front();
			que.pop();
			for(i=1;i<n;i++)
			{
				if(st[p][i] && vst[i])
				{
					vst[i]=0;
					par[i]=par[p]+1;
					st[p][i]=0;
					st[i][p]=0;
					que.push(i);
				}
			}
		}
		for(i=1;i<n;i++)
			printf("%ld\n",par[i]);
		if(t)
			printf("\n");
	}
	return 0;
}