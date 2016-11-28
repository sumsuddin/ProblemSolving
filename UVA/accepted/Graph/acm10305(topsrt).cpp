#include<stdio.h>
#include<queue>
using namespace std;

queue<long>stk;
long i,print,n,m,j,p,q,rear,indeg[120];
char c;
bool flag,st[120][120];

void topsort()
{
	for(i=1;i<=n;i++)
		if(indeg[i]==0)
			stk.push(i);

	flag=1;
	while(!stk.empty())
	{
		print=stk.front();
		if(flag)
		{
			printf("%ld",print);
			flag=0;
		}
		else
			printf(" %ld",print);

		stk.pop();

		for(i=1;i<=n;i++)
		{
			if(st[print][i]==1)
			{
				indeg[i]--;
				if(indeg[i]==0)
					stk.push(i);
			}
		}
	}

}

int main()
{
	while(scanf("%ld%ld",&n,&m)==2)
	{
		for(i=1;i<=n;i++)
		{
			indeg[i]=0;
			for(j=1;j<=n;j++)
				st[i][j]=0;
		}

		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&p,&q);
			st[p][q]=1;
			indeg[q]++;
		}
		topsort();
		printf("\n");
	}
	return 0;
}