#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
queue<int>que;

long i,j,p,a,b,n,t,m;
char st[50],sy[50],parent[50];
bool mat[50][50],vst[50];
void bfs()
{
	que.push(a);
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		for(i=0;i<26;i++)
		{
			if(mat[p][i]==1 && vst[i]==1)
			{
				if(i==b)
				{
					parent[i]=p;
					while(!que.empty())
						que.pop();
					break;
				}
				que.push(i);
				parent[i]=p;
				vst[i]=0;
			}
		}
	}
}
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				mat[i][j]=0;
		scanf("%ld%ld",&t,&m);
		for(i=0;i<t;i++)
		{
			scanf("%s%s",st,sy);
			a=st[0]-65;
			b=sy[0]-65;
			mat[a][b]=1;
			mat[b][a]=1;
		}
		for(t=0;t<m;t++)
		{
			for(i=0;i<26;i++)
				vst[i]=1;

			scanf("%s%s",st,sy);
			a=st[0]-65;
			b=sy[0]-65;
			bfs();
			st[0]=b+'A';
			for(i=1;;i++)
			{
				if(parent[b]==a)
				{
					st[i]=parent[b]+'A';
					st[i+1]=0;
					break;
				}
				else
				{
					st[i]=parent[b]+'A';
					b=parent[b];
				}
			}
			i=strlen(st);
			while(i--)
				printf("%c",st[i]);
			printf("\n");
		}
		if(n)
			printf("\n");
	}
	return 0;
}