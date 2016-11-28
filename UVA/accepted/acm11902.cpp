#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long cs=1,i,j,p,n,t,flag;
int mat[150][150];
char st[150][150];
bool vst[150],vs[150];
void bfs()
{
	que.push(0);
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		
		for(j=1;j<n;j++)
		{
			if(mat[p][j] && vst[j])
			{
				que.push(j);
				vst[j]=0;
			}
		}
	}
	for(j=1;j<n;j++)
	if(vst[j])
	st[i][j]='Y';
}
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&mat[i][j]);
				st[i][j]='N';
			}
		st[0][0]='Y';
		que.push(0);
		
		while(!que.empty())
		{
			p=que.front();
			que.pop();
			for(i=1;i<n;i++)
			if(mat[p][i] && vs[i]==0)
			{
				vs[i]=1;
				que.push(i);
			}
		}
		for(i=1;i<n;i++)
		{
			if(vs[i])
			{
				st[0][i]=st[i][i]='Y';
				for(j=0;j<n;j++)
					vst[j]=1;
				vst[i]=0;
				bfs();
			}
		}
		
		printf("Case %ld:\n+",cs++);
		for(i=1;i<n*2;i++)
			printf("-");
		printf("+\n");

		for(i=0;i<n;i++)
		{
			printf("|");
			for(j=0;j<n;j++)
				printf("%c|",st[i][j]);
			printf("\n");
			printf("+");
			for(j=1;j<n*2;j++)
				printf("-");
			printf("+\n");
		}

	}
	return 0;
}
