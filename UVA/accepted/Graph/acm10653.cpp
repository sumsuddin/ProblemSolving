#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;

bool st[1010][1010],vst[1010][1010];
long parent[1010][1010],i,j,x,p,q,x1,x2,y1,y2,m,n;
int h[]={0,0,-1,1};
int v[]={1,-1,0,0};

long bfs()
{

	if(x1==x2 && y1==y2)
		return 0;
	else
	{
		parent[x1][y1]=0;

		que.push(x1);
		que.push(y1);

		while(!que.empty())
		{
			p=que.front();
			que.pop();
			q=que.front();
			que.pop();
			if(p==x2 && q==y2)
			{
				while(!que.empty())
					que.pop();
				return parent[p][q];
			}
			else
			{
				for(x=0;x<4;x++)
					if(p+h[x]>=0 && p+h[x]<n && q+v[x]>=0 && q+v[x]<m && vst[p+h[x]][q+v[x]] && st[p+h[x]][q+v[x]])
					{
						vst[p+h[x]][q+v[x]]=0;
						parent[p+h[x]][q+v[x]]=parent[p][q]+1;
						que.push(p+h[x]);
						que.push(q+v[x]);
					}
			}

		}
	}
	return -1;
}

int main()
{
	while(scanf("%ld%ld",&n,&m) && (n||m))
	{
		scanf("%ld",&p);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				st[i][j]=1;
				vst[i][j]=1;
			}

		while(p--)
		{
			scanf("%ld%ld",&x,&y1);

			while(y1--)
			{
				scanf("%ld",&q);
				st[x][q]=0;
			}
		}
		scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
		printf("%ld\n",bfs());
	}
	return 0;
}