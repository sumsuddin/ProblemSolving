#include<stdio.h>
#include<queue>
using namespace std;
queue<long >que;

long st[100],i,n,m,x,y,par[100],sum,cs=1;
bool vst[100],mat[100][100],flag;

void search(long *x)
{
	flag=1;
	for(sum=0;sum<m;sum++)
		if(st[sum]==*x)
		{
			flag=0;
			*x=sum;
			break;
		}
	if(flag)
	{
		st[m]=*x;
		*x=m++;
	}
}

void srch()
{
	flag=1;
	for(i=0;i<m;i++)
		if(st[i]==n)
		{
			flag=0;
			x=i;
			break;
		}
	if(flag)
		x=90;
}

int main()
{
	while(scanf("%ld",&n),n)
	{
		m=0;
		for(i=0;i<35;i++)
			for(sum=0;sum<35;sum++)
				mat[i][sum]=0;

		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&x,&y);

			search(&x);
			search(&y);

			mat[x][y]=1;
			mat[y][x]=1;
		}

		while(scanf("%ld%ld",&n,&y) && (n || y))
		{
			for(i=0;i<m;i++)
				vst[i]=1;

			srch();
			par[x]=sum=0;
			if(x!=90)
				que.push(x);
			vst[x]=0;


			while(!que.empty())
			{
				x=que.front();
				que.pop();
				sum++;

				for(i=0;i<m;i++)
					if(mat[x][i] && vst[i])
					{
						par[i]=par[x]+1;

						if(par[i]<=y)
						{
							que.push(i);
							vst[i]=0;
						}
					}
			}
			printf("Case %ld: %ld nodes not reachable from node %ld with TTL = %ld.\n",cs++,m-sum,n,y);
		}
	}
	return 0;
}