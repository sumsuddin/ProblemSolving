#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,j,r,c,mx,cs=1,h[]={0,0,1,-1},v[]={1,-1,0,0},wt[50][50],x,y,p,q,t;
bool vst[50][50];
char st[50][50];
void init()
{
	long i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			vst[i][j]=1,wt[i][j]=0;
}

void bfs()
{
	long i;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		for(i=0;i<4;i++)
		{
			x=p-h[i];
			y=q-v[i];
			if(x>=0 && x<r && y>=0 && y<c && vst[x][y] && st[x][y]!='#' && st[x][y]!='m')
			{
				if(st[x][y]=='h')
				{
					while(!que.empty())
						que.pop();
					if(wt[p][q]+1>mx)
						mx=wt[p][q]+1;
					break;
				}
				vst[x][y]=0;
				que.push(x);
				que.push(y);
				wt[x][y]=wt[p][q]+1;
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		mx=0;
		scanf("%ld%ld",&r,&c);

		for(i=0;i<r;i++)
			scanf("%s",st[i]);

		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				if(st[i][j]=='c' || st[i][j]=='a' || st[i][j]=='b')
				{
					init();
					que.push(i);
					que.push(j);
					bfs();
				}
			}
		printf("Case %ld: %ld\n",cs++,mx);
	}
	return 0;
}