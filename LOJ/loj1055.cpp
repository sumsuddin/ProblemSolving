#include<stdio.h>
#include<queue>
using namespace std;
queue<int>qx,qy;
bool vst[12][12][12][12][12][12];
int i,j,par[12][12][12][12][12][12],h[]={0,0,1,-1},v[]={1,-1,0,0},x[5],y[5],p[5],q[5],flag,n,cs=1,t,k;
char st[12][12];

bool call(long x1,long y1, long x2, long y2, long x3, long y3)
{
	vst[x1][y1][x2][y2][x3][y3]=0;
	if((x1 == x2 && y1==y2) || (x1==x3 && y1==y3) || (x2==x3 && y2==y3))
		return 0;

	par[x1][y1][x2][y2][x3][y3]=par[p[0]][q[0]][p[1]][q[1]][p[2]][q[2]]+1;

	if(st[x1][y1]=='X' && st[x2][y2]=='X' && st[x3][y3]=='X')
	{
		while(!qx.empty())
			qx.pop(),qy.pop();
		flag=0;
		printf("Case %d: %d\n",cs++,par[x1][y1][x2][y2][x3][y3]);
		return 1;
	}

	qx.push(x1);
	qx.push(x2);
	qx.push(x3);
	
	qy.push(y1);
	qy.push(y2);
	qy.push(y3);
	return 0;
}

void bfs()
{
	long i,ii,j,k;
	while(!qx.empty())
	{
		p[0]=qx.front();
		qx.pop();
		p[1]=qx.front();
		qx.pop();
		p[2]=qx.front();
		qx.pop();

		q[0]=qy.front();
		qy.pop();
		q[1]=qy.front();
		qy.pop();
		q[2]=qy.front();
		qy.pop();

		for(i=0;i<4 && flag;i++)
		{
			x[0]=p[0]+h[i];
			y[0]=q[0]+v[i];

			if(x[0]<0 || x[0]>=n || y[0]<0 || y[0]>=n || st[x[0]][y[0]]=='#')
				x[0]=p[0],y[0]=q[0];

			x[1]=p[1]+h[i];
			y[1]=q[1]+v[i];

			if(x[1]<0 || x[1]>=n || y[1]<0 || y[1]>=n || st[x[1]][y[1]]=='#' || (x[1]==x[0] && y[1]==y[0]))
				x[1]=p[1],y[1]=q[1];

			x[2]=p[2]+h[i];
			y[2]=q[2]+v[i];

			if(x[2]<0 || x[2]>=n || y[2]<0 || y[2]>=n || st[x[2]][y[2]]=='#' || (x[1]==x[2] && y[1]==y[2]) || (x[2]==x[0] && y[2]==y[0]) || (x[1]==x[0] && y[1]==y[0]))
				x[2]=p[2],y[2]=q[2];

			if(vst[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]])
			{
				for(ii=0;ii<3 && flag;ii++)
					for(j=0;j<3 && flag;j++)
						for(k=0;k<3;k++)
							if(ii!=j && j!=k && ii!=k)
								if(vst[x[ii]][y[ii]][x[j]][y[j]][x[k]][y[k]])
									if(call(x[ii],y[ii],x[j],y[j],x[k],y[k]))
										break;
			}
		}
	}
}



int main()
{
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);

		for(i=0;i<n;i++)
			scanf("%s",st[i]);

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(long ii=0;ii<n;ii++)
					for(long jj=0;jj<n;jj++)
						for(long k=0;k<n;k++)
							for(long k1=0;k1<n;k1++)
								vst[i][j][ii][jj][k][k1]=1;

		flag=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(st[i][j]=='A' || st[i][j]=='B' || st[i][j]=='C')
				{
					st[i][j]='.';
					x[flag]=i;
					y[flag++]=j;
				}
		flag=1;

		if(vst[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]])
		{
			for(i=0;i<3 && flag;i++)
				for(j=0;j<3 && flag;j++)
					for(k=0;k<3;k++)
					{
						if(i!=j && j!=k && i!=k)
						{
							vst[x[i]][y[i]][x[j]][y[j]][x[k]][y[k]]=par[x[i]][y[i]][x[j]][y[j]][x[k]][y[k]]=0;
							qx.push(x[i]);
							qx.push(x[j]);
							qx.push(x[k]);

							qy.push(y[i]);
							qy.push(y[j]);
							qy.push(y[k]);
						}
					}
		}

		bfs();

		while(!qx.empty())
			qx.empty(),qy.empty();

		if(flag)
			printf("Case %d: trapped\n",cs++);
	}
	return 0;
}