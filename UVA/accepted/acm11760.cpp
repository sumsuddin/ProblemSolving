#include<stdio.h>
long i,n,r,c,x,y,cs=1;
bool xx[10050],yy[10050];

bool chk(long x,long y)
{
	if(x<0 || x>=r || y<0 || y>=c)
		return 0;

	if(xx[x]==0 && yy[y]==0)
		return 1;
	else
		return 0;
}

int main()
{
	while(scanf("%ld%ld%ld",&r,&c,&n) && (r || c || n))
	{
		for(i=0;i<r;i++)
			xx[i]=0;
		for(i=0;i<c;i++)
			yy[i]=0;

		for(i=0;i<n;i++)
			scanf("%ld%ld",&x,&y),xx[x]=1,yy[y]=1;
		scanf("%ld%ld",&x,&y);
		if(chk(x+1,y) || chk(x,y+1) || chk(x-1,y) || chk(x,y-1) || chk(x,y))
			printf("Case %ld: Escaped again! More 2D grid problems!\n",cs++);
		else
			printf("Case %ld: Party time! Let's find a restaurant!\n",cs++);
	}
	return 0;
}