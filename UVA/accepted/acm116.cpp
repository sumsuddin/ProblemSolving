#include<stdio.h>
long i,j,r,c,gv[150][150],wt[150][150],par[10][150],pr;
int main()
{
	while(~scanf("%ld%ld",&r,&c))
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%ld",&gv[i][j]);
				if(j==c-1)
					wt[i][j]=gv[i][j];
				else
					wt[i][j]=100000000;
			}
		}

		for(i=c-1;i>0;i--)
		{
			if(wt[0][i-1]>gv[0][i-1]+wt[0][i])
			{
				wt[0][i-1]=gv[0][i-1]+wt[0][i];
				par[0][i-1]=0;
			}
				
			if(wt[r-1][i-1]>gv[r-1][i-1]+wt[0][i])
			{
				wt[r-1][i-1]=gv[r-1][i-1]+wt[0][i];
				par[r-1][i-1]=0;
			}

			if(wt[1][i-1]>gv[1][i-1]+wt[0][i])
			{
				wt[1][i-1]=gv[1][i-1]+wt[0][i];
				par[1][i-1]=0;
			}
			for(j=1;j<r-1;j++)
			{
				if(wt[j][i-1]>gv[j][i-1]+wt[j][i])
				{
					wt[j][i-1]=gv[j][i-1]+wt[j][i];
					par[j][i-1]=j;
				}
				
				if(wt[j-1][i-1]>gv[j-1][i-1]+wt[j][i])
				{
					wt[j-1][i-1]=gv[j-1][i-1]+wt[j][i];
					par[j-1][i-1]=j;
				}

				if(wt[j+1][i-1]>gv[j+1][i-1]+wt[j][i])
				{
					wt[j+1][i-1]=gv[j+1][i-1]+wt[j][i];
					par[j+1][i-1]=j;
				}
			}

			if(wt[r-1][i-1]>gv[r-1][i-1]+wt[r-1][i])
			{
				wt[r-1][i-1]=gv[r-1][i-1]+wt[r-1][i];
				par[r-1][i-1]=r-1;
			}
				
			if(wt[r-2][i-1]>gv[r-2][i-1]+wt[r-1][i])
			{
				wt[r-2][i-1]=gv[r-2][i-1]+wt[r-1][i];
				par[r-2][i-1]=r-1;
			}

			if(wt[0][i-1]>gv[0][i-1]+wt[r-1][i])
			{
				wt[0][i-1]=gv[0][i-1]+wt[r-1][i];
				par[0][i-1]=r-1;
			}
		}
		pr=wt[0][0];
		j=0;
		for(i=0;i<r;i++)
			if(pr>wt[i][0])
			{
				pr=wt[i][0];
				j=i;
			}

		printf("%ld",j+1);
		pr=par[j][0];
		for(i=1;i<c;i++)
		{
			printf(" %ld",pr+1);
			pr=par[pr][i];
		}
		printf("\n%ld\n",wt[j][0]);
	}
	return 0;
}