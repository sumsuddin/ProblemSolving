#include<stdio.h>
#include<queue>
using namespace std;

queue<long>que;
queue<int>lmm[305][305];
long i,j,p,q,pa,qa,par[305][305][5],lim,lt,r,c,t;
bool vst[305][305][5],flag,tru;
int x[]={0,0,1,-1},y[]={1,-1,0,0};
char st[305][305];

void bfs()
{	
	que.push(p);
	que.push(q);
	vst[p][q][1]=0;
	lmm[p][q].push(1);
	par[p][q][1]=0;
	tru=1;
	
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		lim=lmm[p][q].front();
		lmm[p][q].pop();		
		for(i=0;i<4;i++)
		{
			flag=1;
			pa=p;qa=q;
			for(j=0;j<lim;j++)
			{
				pa+=x[i];
				qa+=y[i];
				if(st[pa][qa]=='#')
				{
					flag=0;
					break;
				}
			}
			lt=lim+1;
			if(lt>3)
				lt=1;
			if(st[pa][qa]=='E')
			{
				tru=0;
				par[pa][qa][lt]=par[p][q][lim]+1;
				printf("%ld\n",par[pa][qa][lt]);
				while(!que.empty())
					que.pop();
				break;
			}
			else if(flag && vst[pa][qa][lt] && pa>=0 && qa>=0 && pa<r && qa<c)
			{
				par[pa][qa][lt]=par[p][q][lim]+1;
				lmm[pa][qa].push(lt);
				vst[pa][qa][lt]=0;
				que.push(pa);
				que.push(qa);
			}

		}
	}
	if(tru)
		printf("NO\n");
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&r,&c);
		for(i=0;i<r;i++)
			scanf("%s",st[i]);
		
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				vst[i][j][1]=vst[i][j][2]=vst[i][j][3]=1;
				while(!lmm[i][j].empty())
					lmm[i][j].pop();

				if(st[i][j]=='S')
				{
					p=i;
					q=j;
				}
			}
		}
		bfs();
	}			
	return 0;
}
