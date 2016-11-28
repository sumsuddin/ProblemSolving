#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,j,a,end,par[1000000],n,m,sch[110],t,cs=1;
bool flag,vst[1000000];
void bfs()
{
	flag=1;
	que.push(0);
	vst[0]=0;
	par[0]=0;
	while(!que.empty())
	{
		a=que.front();
		que.pop();
		for(i=0;i<m;i++)
		{
			j=a^sch[i];
			if(j<end && vst[j])
			{
				vst[j]=0;
				par[j]=par[a]+1;
				que.push(j);
			}
			else if(j==end)
			{
				while(!que.empty())
					que.pop();
				flag=0;
				printf("%ld\n",par[a]+1);
				break;
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

		end=0;
		for(i=0;i<n;i++)
			end=end|1<<i;
		for(i=0;i<=end;i++)
			vst[i]=1;

		for(i=0;i<m;i++)
		{
			sch[i]=0;
			for(j=0;j<n;j++)
			{
				scanf("%ld",&a);
				sch[i]=sch[i] | a<<j;
			}
		}
		printf("Case %ld: ",cs++);
		bfs();
		if(flag)
			printf("IMPOSSIBLE\n");
	}
	return 0;
}