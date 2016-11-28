#include<stdio.h>
#include<queue>
using namespace std;
queue<int>que;
long i,j,k,n,m,par[150][150],p,q,a,b,t;
char st[150][150];
bool flag;
int h[] = { 1,1,-1,-1,2,2,-2,-2 };
int v[] = { 2,-2,2,-2,1,-1,1,-1 };
int hh[]={0,0,1,-1,1,-1,1,-1};
int vv[]={1,-1,0,0,1,1,-1,-1};

void bfs()
{
	flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(st[i][j]=='A')
			{
				que.push(i);
				que.push(j);
				par[i][j]=0;

				while(!que.empty())
				{
					p=que.front();
					que.pop();
					q=que.front();
					que.pop();
					for(k=0;k<8;k++)
					{
						a=p+hh[k];
						b=q+vv[k];

						if(st[a][b]=='B')
						{
							flag=1;
							par[a][b]=par[p][q]+1;
							while(!que.empty())
								que.pop();
							printf("Minimal possible length of a trip is %ld\n",par[a][b]);
							break;
						}
						else
							if(st[a][b]=='.')
							{
								st[a][b]='0';
								par[a][b]=par[p][q]+1;
								que.push(a);
								que.push(b);
							}
					}
				}

				break;
			}
		}
		if(flag)
			break;
	}
	if(flag==0)
		printf("King Peter, you can't go now!\n");
}

int main()
{
	gets(st[0]);
	sscanf(st[0],"%ld",&t);
	while(t--)
	{
		gets(st[0]);
		sscanf(st[0],"%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			gets(st[i]);

		for(j=0;j<=m;j++)
			st[i][j]=0;

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(st[i][j]=='Z')
				{
					st[i][j]='0';

					for(k=0;k<8;k++)
					{
						p=i+h[k];
						q=j+v[k];
						if(st[p][q]=='.')
							st[p][q]='0';
					}
				}
			}
		}
		bfs();
	}
	return 0;
}