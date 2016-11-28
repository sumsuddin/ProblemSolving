/*#include<stdio.h>
long i,j,k,ud[15][15],ld[15][15],base[15][15],t,mat[15][15],cst[300];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		for(i=0;i<300;i++)
			cst[i]=0;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
			{
				scanf("%ld",&mat[i][j]);
				ud[i][j]=ld[i][j]=base[i][j]=0;
				if(j==7)
					base[i][j]=1<<i,ud[i][j]=(1<<i)>>1,ld[i][j]=(1<<i)<<1,cst[base[i][j]]=mat[i][j];
			}

		for(i=7;i>0;i--)
		{
			for(j=0;j<8;j++)
			{
				for(k=0;k<8;k++)
				{
					for(l=0;l<8;l++)
					{
						if(cst[l][base[k][i-1]]<cst[k][base[j][i]]+mat[k][i-1] && (ud[j][i]>>k & 1)==0  && (base[j][i]>>k & 1)==0 && (ld[j][i]>>k & 1)==0)
						{
							ud[k][i-1]=(ud[j][i] | 1<<k)>>1;

							base[k][i-1]=base[j][i] | 1<<k;

							ld[k][i-1]=(ld[j][i] | 1<<k)<<1;

							cst[k][base[k][i-1]]=cst[base[j][i]]+mat[k][i-1];
						}
					}
				}
				printf("%ld ",cst[base[j][i]]);
			}
			printf("\n");
			scanf("%*ld");
		}
		for(i=0;i<8;i++)
			printf("%ld ",cst[base[i][0]]);
	}
	return 0;
}
*/

#include<stdio.h>

long i,j,k,t,mat[15][15],mx;

void backtrk(long vst,long ud,long ld,long sum,long col)
{
	long k;
	if(vst==255)
	{
		if(mx<sum)
			mx=sum;
		return;
	}

	for(k=0;k<8;k++)
	{
		if((ud>>k & 1)==0  && (vst>>k & 1)==0 && (ld>>k & 1)==0)
		{
			backtrk((vst | 1<<k),(ud | 1<<k)>>1,(ld | 1<<k)<<1,sum+mat[k][col],col+1);
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				scanf("%ld",&mat[i][j]);

		mx=0;
		backtrk(0,0,0,0,0);

		printf("%5ld\n",mx);
	}
	return 0;
}