#include<stdio.h>
#include<queue>
using namespace std;
#define C 0.78539816339744830961566084581988
#define R 2.4292036732051033807686783083602
queue<long>que;
double sum,area[250][250];
char st[150][150];
bool vst[250][250];
long h[]={0,0,2,-2,-2,-2,2,2},v[]={2,-2,0,0,-2,2,-2,2},c,cc,r,rr,i,t,j,q,cs=1;

void check_corner(long xx, long yy)
{
	long x,y;
	x=xx/2;
	y=yy/2;

	if((x==0 && y==0) || (x==0 && y==c) || (x==r && y==0) || (x==r && y==c) )
	{
		if((x==0 && y==0 && st[x][y]=='0') || (x==0 && y==c && st[x][y-1]=='1') || (x==r && y==0 && st[x-1][y]=='1') || (x==r && y==c && st[x-1][y-1]=='0') )
			area[xx][yy]=C,vst[xx][yy]=0;
	}
	else if(x==0)
	{
		if(st[0][y-1]=='1' && st[0][y]=='0')
			area[xx][yy]=2.0 * C,vst[xx][yy]=0;
	}
	else if(x==r)
	{
		if(st[r-1][y-1]=='0' && st[r-1][y]=='1')
			area[xx][yy]=2.0 * C,vst[xx][yy]=0;
	}
	else if(y==0)
	{
		if(st[x-1][y]=='1' && st[x][y]=='0')
			area[xx][yy]=2.0 * C,vst[xx][yy]=0;
	}
	else if(y==c)
	{
		if(st[x-1][c-1]=='0' && st[x][c-1]=='1')
			area[xx][yy]=2.0 * C,vst[xx][yy]=0;
	}
	else
	{
		if(st[x-1][y-1]=='0' && st[x-1][y]=='1' && st[x][y-1]=='1' && st[x][y]=='0')
			area[xx][yy]=4.0* C,vst[xx][yy]=0;
	}
}

void check_mid(long xx,long yy)
{
	long x,y,i,p,q;
	x=xx/2;
	y=yy/2;
	sum+=R;
	que.push(xx);
	que.push(yy);
	
	for(i=0;i<8;i++)
	{
		p=xx-h[i];
		q=yy-v[i];
		if(p>=0 && p<=rr && q>=0 && q<=cc)
		{
			if(st[x][y]=='0' && h[i]* v[i]>0)
				continue;
			else if(st[x][y]=='1' && h[i]*v[i]<0)
				continue;

			if(((x==p/2 || y==q/2 ) && st[x][y]==st[p/2][q/2]) || ((x!=p/2 && y!=q/2 ) && st[x][y]!=st[p/2][q/2]) )
				sum+=C;
			else if(vst[p][q])
			{
				vst[p][q]=0;
				check_mid(p,q);
			}
		}
	}
}
int main()
{
	long p;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&r,&c);

		for(i=0;i<r;i++)
			scanf("%s",st[i]);

		rr=r*2;
		cc=c*2;

		for(i=0;i<=rr;i++)
			for(j=0;j<=cc;j++)
				vst[i][j]=1,area[i][j]=0.0;

		for(i=0;i<=rr;i++)
			for(j=0;j<=cc;j++)
			{
				if(vst[i][j]==0)
					continue;

				if(i%2 != j%2)
					area[i][j]=0.0,vst[i][j]=0;
				else if(i%2==0)
					check_corner(i,j);
				else
				{
					sum=0;
					vst[i][j]=0,check_mid(i,j);
					while(!que.empty())
					{
						p=que.front();
						que.pop();
						q=que.front();
						que.pop();

						if(st[p/2][q/2]=='1')
							vst[p+1][q+1]=vst[p-1][q-1]=0,area[p+1][q+1]=area[p-1][q-1]=sum;
						else
							vst[p-1][q+1]=vst[p+1][q-1]=0,area[p-1][q+1]=area[p+1][q-1]=sum;

						vst[p][q]=0;area[p][q]=sum;
					}
				}
			}
		printf("Case %ld:\n",cs++);
		scanf("%ld",&q);

		while(q--)
		{
			scanf("%ld%ld",&rr,&cc);
			printf("%.10lf\n",area[rr][cc]);
		}
	}
	return 0;
}
