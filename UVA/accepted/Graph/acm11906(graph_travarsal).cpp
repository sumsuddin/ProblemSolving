#include<stdio.h>
#include<queue>
using namespace std;

queue<long>que;
long i,j,x,y,p,q,wt,t,n,r,c,h[50],v[50],dir,odd,even,cs=1;
bool vst[150][150],mat[150][150];
void bfs()
{
	que.push(0);
	que.push(0);

	vst[0][0]=0;

	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		wt=0;

		for(i=0;i<dir;i++)
		{
			x=p-h[i];
			y=q-v[i];

			if(x>=0 && x<r && y<c && y>=0 && mat[x][y])
			{
				if(vst[x][y])
				{
					vst[x][y]=0;
					que.push(x);
					que.push(y);
				}
				wt++;
			}
		}
		if(wt%2)
			odd++;
		else
			even++;
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld%ld",&r,&c,&x,&y);

		if(x==y || x==0 || y==0)
		{
			dir=4;
			h[0]=x,h[1]=-x,h[2]=y,h[3]=-y;
			v[0]=y,v[1]=-y,v[2]=-x,v[3]=x;
		}
		else
		{
			dir=8;
			h[0]=x,h[1]=-x,h[2]=y,h[3]=-y,h[4]=y,h[5]=-y,h[6]=x,h[7]=-x;
			v[0]=y,v[1]=-y,v[2]=-x,v[3]=x,v[4]=x,v[5]=-x,v[6]=-y,v[7]=y;
		}

		for(i=0;i<=r;i++)
			for(j=0;j<=c;j++)
				vst[i][j]=mat[i][j]=1;

		scanf("%ld",&n);
		while(n--)
		{
			scanf("%ld%ld",&x,&y);
			mat[x][y]=0;
		}
		odd=even=0;
		if(mat[0][0]==0)
		{
			printf("Case %ld: %ld %ld\n",cs++,0,0);
			continue;
		}
		bfs();
		printf("Case %ld: %ld %ld\n",cs++,even,odd);
	}
	return 0;
}