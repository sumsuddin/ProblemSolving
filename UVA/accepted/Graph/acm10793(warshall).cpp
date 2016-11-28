#include<stdio.h>

long i,j,e,w[120][120],a,b,c,t,mx,mxc,n,cs=1;

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=1;i<=n;i++)
			for(j=0;j<=n;j++)
				w[i][j]=1000000000;

		while(e--)
		{
			scanf("%ld%ld%ld",&a,&b,&c);

			if(w[a][b]>c)
			{
				w[a][b]=c;
				w[b][a]=c;
			}
		}
		for(i=1;i<=n;i++)
			w[i][i]=0;

		for(e=1;e<=n;e++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if(w[i][j]>w[i][e]+w[e][j])
						w[i][j]=w[i][e]+w[e][j];
				}
		mx=1000000000;
		for(i=1;i<=n;i++)
		{
			mxc=-1;
			if(w[1][i]==w[2][i] && w[2][i]==w[3][i] && w[3][i]==w[4][i] && w[4][i]==w[5][i])
			{
				for(j=1;j<=n;j++)
					if(mxc<w[j][i])
						mxc=w[j][i];
			}
			if(mx>mxc &&mxc!=-1)
				mx=mxc;
		}
		if(mx==1000000000)
			printf("Map %ld: -1\n",cs++);
		else
			printf("Map %ld: %ld\n",cs++,mx);
	}
	return 0;
}
				