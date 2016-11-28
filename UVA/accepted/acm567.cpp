#include<stdio.h>
#include<queue>
using namespace std;

long i,j,sum,s,e,p,q,n,m,t,parent[50],cs=1;
bool flag,vst[50],st[50][50];
queue<long>stk;

void bfs()
{
	stk.push(s);
	vst[s]=0;
	parent[s]=0;
	flag=0;
	while(!stk.empty())
	{
		p=stk.front();
		stk.pop();
		for(i=1;i<=20;i++)
			if(st[p][i]==1 && vst[i]==1)
			{
				
				parent[i]=parent[p]+1;
				
				if(i==e)
				{
					while(!stk.empty())
						stk.pop();

					printf("%2ld to %2ld:%2ld\n",s,e,parent[i]);
					flag=1;

				}
				if(flag)
					break;
				stk.push(i);
				vst[i]=0;
			}
	}
}
void clean()
{
	for(p=1;p<21;p++)
		for(q=1;q<21;q++)
			st[p][q]=0;
}
void refresh()
{
	for(p=1;p<21;p++)
		vst[p]=1;
}
int main()
{
	while(~scanf("%ld",&n))
	{
		clean();
		while(n--)
		{
			scanf("%ld",&p);
			st[p][1]=1;
			st[1][p]=1;
		}
		for(q=2;q<20;q++)
		{
			scanf("%ld",&n);
			while(n--)
			{
				scanf("%ld",&p);
				st[p][q]=1;
				st[q][p]=1;
			}
		}
		scanf("%ld",&n);
		printf("Test Set #%ld\n",cs++);
		while(n--)
		{
			refresh();
			scanf("%ld%ld",&s,&e);
			bfs();
		}
		printf("\n");
	}
	return 0;
}
