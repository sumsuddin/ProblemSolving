#include<stdio.h>
#include<queue>
using namespace std;

queue<long>que;
long i,j,n,strt,par[120],a,b,cs=1;
bool mat[120][120];

int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=1;i<=n;i++)
		{
			par[i]=0;
			for(j=1;j<=n;j++)
				mat[i][j]=0;
		}

		scanf("%ld",&strt);

		while(scanf("%ld%ld",&a,&b) && (a||b))
			mat[a][b]=1;

		que.push(strt);
		j=strt;
		par[strt]=0;

		while(!que.empty())
		{
			a=que.front();
			que.pop();

			for(i=1;i<=n;i++)
			{
				if(mat[a][i] && par[a]+1>par[i])
				{
					que.push(i);
					par[i]=par[a]+1;
				}
			}
		}
		j=strt;
		for(i=1;i<=n;i++)
			if(par[i]>par[j])
				j=i;

		printf("Case %ld: The longest path from %ld has length %ld, finishing at %ld.\n\n",cs++,strt,par[j],j);
	}
	return 0;
}
