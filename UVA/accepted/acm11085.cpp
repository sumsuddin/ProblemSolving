#include<stdio.h>

long i,j,k,mat[15][15],all,chk[100],mn,a,b,root,count,cs=1;

void backtrk(long vst,long ud,long ld,long sum,long col)
{
	long k;
	if(vst==255)
	{
		chk[all++]=sum;
		return;
	}

	for(k=0;k<8;k++)
	{
		if((ud>>k & 1)==0  && (vst>>k & 1)==0 && (ld>>k & 1)==0)
		{
			backtrk((vst | 1<<k),(ud | 1<<k)>>1,(ld | 1<<k)<<1,sum*10+mat[k][col],col+1);
		}
	}
}

int main()
{
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			mat[i][j]=i+1;

	all=0;
	backtrk(0,0,0,0,0);

	while(~scanf("%ld",&j))
	{
		root=j;
		for(i=1;i<8;i++)
			scanf("%ld",&j),root=root*10+j;

		mn=8;
		for(i=0;i<all;i++)
		{
			a=root;
			b=chk[i];
			count=0;
			for(j=0;j<8;j++)
			{
				if(a%10!=b%10)
					count++;
				a/=10;b/=10;
			}
			if(count<mn)
				mn=count;
		}
		printf("Case %ld: %ld\n",cs++,mn);
	}
	return 0;
}