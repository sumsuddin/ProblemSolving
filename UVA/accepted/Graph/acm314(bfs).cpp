#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
queue<long>que;
long i,j,x,y,ex,ey,bx,by,mat[100][100],dir,p,q,r,c,par[100][100][10],h[]={1,0,-1,0},v[]={0,-1,0,1};
bool flag,vst[100][100][10];
char st[20];
void bfs()
{
	que.push(bx);
	que.push(by);
	que.push(dir);
	vst[bx][by][dir]=0;
	par[bx][by][dir]=0;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();
		dir=que.front();
		que.pop();

		for(i=1;i<=3;i++)
		{
			x=p-(i*h[dir]);
			y=q-(i*v[dir]);
			if(x>0 && x<=r && y>0 && y<=c)
			{
				if(x+1>r || y+1>c || mat[x][y] || mat[x][y+1] || mat[x+1][y] || mat[x+1][y+1])
				{
					vst[x][y][dir]=0;
					break;
				}
				else if(vst[x][y][dir])
				{
					par[x][y][dir]=par[p][q][dir]+1;
					vst[x][y][dir]=0;
					que.push(x);
					que.push(y);
					que.push(dir);

					if(x==ex && y==ey)
					{
						flag=0;
						while(!que.empty())
							que.pop();
						printf("%ld\n",par[x][y][dir]);
					}
				}
			}
		}
		if(flag && vst[p][q][(dir+1)%4])
		{
			vst[p][q][(dir+1)%4]=0;
			par[p][q][(dir+1)%4]=par[p][q][dir]+1;
			que.push(p);
			que.push(q);
			que.push((dir+1)%4);
		}
		bx=dir-1;
		if(bx<0)
			bx=3;
		if(flag && vst[p][q][bx])
		{
			vst[p][q][bx]=0;
			par[p][q][bx]=par[p][q][dir]+1;
			que.push(p);
			que.push(q);
			que.push(bx);
		}

	}
}

int main()
{
	while(~scanf("%ld%ld",&r,&c) && (r||c))
	{
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				vst[i][j][0]=vst[i][j][1]=vst[i][j][2]=vst[i][j][3]=1,scanf("%ld",&mat[i][j]);

		scanf("%ld%ld%ld%ld%s",&bx,&by,&ex,&ey,st);

		if(strcmp(st,"north")==0)
			dir=0;
		else if(strcmp(st,"east")==0)
			dir=1;
		else if(strcmp(st,"south")==0)
			dir=2;
		else
			dir=3;
		flag=1;

		if(bx==ex && by==ey)
		{
			if(ex>=r || ex<1 || ey>=c || ey<1 || mat[ex][ey] || mat[ex+1][ey] || mat[ex][ey+1] || mat[ex+1][ey+1])
				printf("-1\n");
			else
				printf("0\n");
			continue;
		}
		if(bx<r && bx>=1 && by<c && by>=1 && !(mat[bx][by] || mat[bx][by+1] || mat[bx+1][by] || mat[bx+1][by+1]))
			bfs();
		if(flag)
			printf("-1\n");
	}
	return 0;
}