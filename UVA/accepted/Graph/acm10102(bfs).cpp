#include<stdio.h>
#include<queue>
using namespace std;
queue<long>quex,quey;
long i,j,p,q,x,y,n,sum,mx,par[105][105],h[]={0,0,1,-1},v[]={1,-1,0,0};
bool vst[1005][1005];
char st[105][105];
void bfs()
{
	while(!quex.empty())
	{
		x=quex.front();
		quex.pop();
		y=quey.front();
		quey.pop();

		for(i=0;i<4;i++)
		{
			p=h[i]+x;
			q=v[i]+y;
			if(p==3 && q==2)
				p=p;
			if(p>=0 && p<n && q>=0 && q<n && vst[p][q])
			{
				par[p][q]=par[x][y]+1;
				vst[p][q]=0;
				if(st[p][q]=='1')
					if(par[p][q]>mx)
						mx=par[p][q];
				st[p][q]='.';
				quex.push(p),quey.push(q);
			}
		}
	}
}

int main()
{
	while(~scanf("%ld",&n))
	{
		sum=mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",st[i]);
			for(j=0;st[i][j];j++)
			{
				vst[i][j]=1;
				if(st[i][j]=='3')
					quex.push(i),quey.push(j),par[i][j]=0,st[i][j]='.',vst[i][j]=0;
			}
		}

		bfs();
		printf("%ld\n",mx);
	}
	return 0;
}