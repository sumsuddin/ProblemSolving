#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;

long i,j,prs,dis,par[15][15],mn,r,c,cnt,t,d,cs=1,x,y,h[] = { 1,1,-1,-1,2,2,-2,-2 },v[] = { 2,-2,2,-2,1,-1,1,-1 };
bool vst[15][15];
char st[15][15];

long bfs(long p,long q)
{
	long i,j;

	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			vst[i][j]=1;
	
	que.push(p);
	que.push(q);

	par[p][q]=vst[p][q]=0;
	dis=prs=0;

	if(st[p][q]>'0' && st[p][q]<='9')
		prs=1;

	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		for(i=0;i<8;i++)
		{
			x=p+h[i];
			y=q+v[i];

			if(x>=0 && x<r && y>=0 && y<c && vst[x][y])
			{
				vst[x][y]=0;
				par[x][y]=par[p][q]+1;
				que.push(x);
				que.push(y);
				if(st[x][y]>='1' && st[x][y]<='9')
				{
					prs++;
					if(par[x][y]%(st[x][y]-'0'))
						dis++;
					dis+=par[x][y]/(st[x][y]-'0');
				}
			}
		}
	}
	if(prs==cnt)
		return dis;
	else
		return 1000000000;
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		mn=1000000000;
		scanf("%ld%ld",&r,&c);

		cnt=0;

		for(i=0;i<r;i++)
		{
			scanf("%s",st[i]);
			for(j=0;st[i][j];j++)
				if(st[i][j]>'0' && st[i][j]<='9')
					cnt++;
		}

		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				d=bfs(i,j);
				if(mn>d)
					mn=d;
			}
		if(mn==1000000000)
			printf("Case %ld: -1\n",cs++);
		else
			printf("Case %ld: %ld\n",cs++,mn);
	}
	return 0;
}