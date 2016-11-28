#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;
long i,j,n,x,y,c,r,par[300][300],p,q,l;
bool mat[300][300],flag;
int h[]={0,0,1,-1},v[]={1,-1,0,0};
queue<long>que;
void bfs()
{
	flag=1;
	que.push(1);
	que.push(1);
	mat[1][1]=0;
	while(!que.empty())
	{
		x=que.front();
		que.pop();
		y=que.front();
		que.pop();
		for(i=0;i<4;i++)
		{
			p=x-h[i];
			q=y-v[i];
			if(p>0 &&p<=r && q<=c && q>0 && mat[p][q])
			{
				mat[p][q]=0;
				par[p][q]=par[x][y]+1;
				que.push(p);
				que.push(q);
				if(p==r && q==c)
				{
					while(!que.empty())
						que.pop();
					flag=0;
					printf("%ld\n",par[p][q]);
					break;
				}
			}
		}
	}
}

int main()
{
	while(~scanf("%ld%ld",&r,&c) && (r||c))
	{
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				mat[i][j]=1;

		scanf("%ld",&n);
		while(n--)
		{
			scanf("%ld%ld",&x,&y);
			mat[x][y]=0;
		}
		scanf("%ld",&n);
		while(n--)
		{
			scanf("%ld%ld%ld",&x,&y,&l);

			for(i=x-l;i<=x+l;i++)
				for(j=y-l;j<=y+l;j++)
				{
					if(sqrt((i-x)*(i-x)+(j-y)*(j-y))<=(double)l)
						mat[i][j]=0;
				}
		}
		bfs();
		if(flag)
			printf("Impossible.\n");
	}
	return 0;
}