#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que,put;
long vst[550][550],wt[550][550],sum,t,m,i,j,cs=1,h[]={0,0,-1,1},v[]={1,-1,0,0},r,c,p,q,x,y;
char st[550][550];
void init()
{
	for(long i=0;i<r;i++)
		for(long j=0;j<c;j++)
			vst[i][j]=wt[i][j]=0;
}

void bfs()
{
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		put.push(p);
		put.push(q);

		for(long i=0;i<4;i++)
		{
			x=p-h[i];
			y=q-v[i];

			if(x>=0 && x<r && y>=0 && y<c && vst[x][y]==0 && st[x][y]!='#')
			{

				vst[x][y]=1;

				if(st[x][y]=='C')
					sum++;
				que.push(x);
				que.push(y);
			}
		}
	}
	while(!put.empty())
	{
		x=put.front();
		put.pop();
		y=put.front();
		put.pop();
		wt[x][y]=sum;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&r,&c,&m);

		for(i=0;i<r;i++)
			scanf("%s",st[i]);

		init();

		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				if(vst[i][j]==0 && st[i][j]!='#')
				{
					que.push(i);
					que.push(j);
					vst[i][j]=1;
					if(st[i][j]=='C')
						sum=1;
					else
						sum=0;
					bfs();
				}
			}
		printf("Case %ld:\n",cs++);
		while(m--)
		{
			scanf("%ld%ld",&i,&j);

			printf("%ld\n",wt[i-1][j-1]);
		}
	}
	return 0;
}