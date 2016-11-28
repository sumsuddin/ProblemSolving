#include<stdio.h>

long cs=1,h[]={-1,-1,-2,-3,-2,1};
long v[]={-3,-2,-1,-1,1,-2};

long t,i,j,gn[550][550],n,x,y,nim;

long call(long x,long y)
{
	if(gn[x][y]>=0)
		return gn[x][y];
	long i,p,q;
	bool ind[8];
	gn[x][y]=0;
	for(i=0;i<=6;i++)
		ind[i]=0;
	for(i=0;i<6;i++)
	{
		p=x+h[i];
		q=y+v[i];

		if(p>=0 && q>=0)
			ind[call(p,q)]=1;
	}
	for(i=0;i<=6;i++)
		if(ind[i]==0)
			break;

	return gn[x][y]=i;
}

int main()
{
	for(i=0;i<505;i++)
		for(j=0;j<505;j++)
			gn[i][j]=-1;

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		nim=0;

		while(n--)
		{
			scanf("%ld%ld",&x,&y);

			nim^=call(x,y);
		}
		if(nim==0)
			printf("Case %ld: Bob\n",cs++);
		else
			printf("Case %ld: Alice\n",cs++);
	}
	return 0;
}