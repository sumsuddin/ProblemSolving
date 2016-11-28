#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
bool vst[50][50],flag;
char st[50][50],c;
long wt[50][50],h[]={1,-1,0,0},v[]={0,0,1,-1},x,y,p,q,t,n,i,j,sum,mx,cs=1;
void init()
{
	long p,q;
	for(p=0;p<n;p++)
		for(q=0;q<n;q++)
			vst[p][q]=1;
}

void bfs(char c)
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
			x=p+h[i];
			y=q+v[i];
			if(x>=0 && x<n && y>=0 && y<n && vst[x][y] && (st[x][y]=='.' || (st[x][y]<=c && st[x][y]>='A')))
			{
				wt[x][y]=wt[p][q]+1;
				vst[x][y]=0;
				if(st[x][y]==c)
				{
					if(c==mx)
					{
						flag=0;
						while(!que.empty())
							que.pop();
						printf("Case %ld: %ld\n",cs++,wt[p][q]+1);
					}
					init(),c++;
					while(!que.empty())
						que.pop();
					
					que.push(x);
					que.push(y);
					bfs(c);
					break;
				}
				que.push(x);
				que.push(y);
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",st[i]);
			for(j=0;st[i][j];j++)
				if(st[i][j]>='A' && st[i][j]<='Z' && st[i][j]>mx)
					mx=st[i][j];
		}

		c='A';flag=1;
		for(i=0;i<n && flag;i++)
			for(j=0;j<n;j++)
			{
				if(st[i][j]==c)
				{
					init();
					c++;
					que.push(i);
					que.push(j);
					wt[i][j]=0;
					vst[i][j]=0;
					if(mx=='A')
						printf("Case %ld: %ld\n",cs++,0),flag=0;
					else
						bfs(c);
					if(flag)
					{
						printf("Case %ld: Impossible\n",cs++);
						flag=0;
					}
					while(!que.empty())
						que.pop();
					break;
				}
			}
	}
	return 0;
}