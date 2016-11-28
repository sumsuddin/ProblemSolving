#include<stdio.h>
#include<queue>
using namespace std;
queue<long >que;
long i,j,x,y,r,c,sum;
int h[]={1,-1,0,0},v[]={0,0,1,-1};
bool flag,fg;
char st[60][60];
bool chk()
{
	fg=1;
	for(i=0;i<4;i++)
		if(x+h[i] >=0 && x+h[i]<r && y+v[i]>=0 &&y+v[i]<c && st[x+h[i]][y+v[i]]=='T')
		{
			fg=0;
			break;
		}
	return fg;
}

void bfs()
{
	while(!que.empty())
	{
		x=que.front();
		que.pop();
		y=que.front();
		que.pop();

		if(chk())
		{
			for(i=0;i<4;i++)
				if(st[x+h[i]][y+v[i]]=='G')
				{
					sum++;
					que.push(x+h[i]);
					que.push(y+v[i]);
					st[x+h[i]][y+v[i]]=1;
				}
				else if(st[x+h[i]][y+v[i]]=='.')
				{
					st[x+h[i]][y+v[i]]=1;
					que.push(x+h[i]);
					que.push(y+v[i]);
				}
		}
	}
}

int main()
{
	while(~scanf("%ld%ld",&c,&r))
	{
		for(i=0;i<r;i++)
			scanf("%s",st[i]);

		flag=1;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(st[i][j]=='P')
				{
					que.push(i);
					que.push(j);
					sum=0;
					bfs();
					flag=0;
					printf("%ld\n",sum);
					break;
				}
			}
			if(flag==0)
				break;
		}
	}
	return 0;
}