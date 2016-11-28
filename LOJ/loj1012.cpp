#include<stdio.h>
#include<queue>
using namespace std;

queue<long>que;
long i,j,r,c,flag,t,h[]={0,0,1,-1},v[]={1,-1,0,0},p,q,x,y,sum,cs=1;
char st[50][50];
void bfs()
{
	sum=1;
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
			if(x<r && x>=0 && y<c && y>=0 && st[x][y]=='.')
			{
				sum++;
				st[x][y]='*';
				que.push(x);
				que.push(y);
			}
		}
	}
	printf("Case %ld: %ld\n",cs++,sum);
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&c,&r);

		for(i=0;i<r;i++)
			scanf("%s",st[i]);

		flag=1;
		for(i=0;i<r,flag;i++)
			for(j=0;j<c;j++)
			{
				if(st[i][j]=='@')
				{
					flag=0;
					que.push(i);
					que.push(j);
					break;
				}
			}
		bfs();
	}
	return 0;
}