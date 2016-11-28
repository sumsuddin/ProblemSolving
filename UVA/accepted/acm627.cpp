#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
stack<long>stk;
queue<long>que;
long i,j,p,x,y,par[350],n,m;
char c;
bool st[350][350],vst[350],tru;
int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				st[i][j]=0;
		}

		for(i=0;i<n;i++)
		{
			scanf("%ld-",&x);
			y=0;

			while(scanf("%c",&c) && c!='\n')
			{
				if(c>47 && c<58)
					y=y*10+(c-48);
				else
				{
					st[x][y]=1;
					y=0;
				}
			}
			if(y)
				st[x][y]=1;
		}
		scanf("%ld",&m);
		printf("-----\n");
		while(m--)
		{
			tru=1;
			for(i=1;i<=n;i++)
				vst[i]=1;
			scanf("%ld%ld",&p,&y);

			que.push(p);

			while(!que.empty())
			{
				x=que.front();
				que.pop();

				for(i=1;i<=n;i++)
				{
					if(st[x][i] && i==y)
					{
						tru=0;
						par[i]=x;
						while(i!=p)
						{
							stk.push(i);
							i=par[i];
						}
						while(!que.empty())
							que.pop();
						break;
					}
					if(st[x][i] && vst[i])
					{
						vst[i]=0;
						par[i]=x;
						que.push(i);
					}
				}
			}
			if(tru)
				printf("connection impossible\n");
			else
			{
				printf("%ld",p);
				while(!stk.empty())
				{
					printf(" %ld",stk.top());
					stk.pop();
				}
				printf("\n");
			}
		}
	}
	return 0;
}
