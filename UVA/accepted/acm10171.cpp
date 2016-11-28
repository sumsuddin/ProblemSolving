#include<algorithm>
#include<stdio.h>
using namespace std;
long i,j,k,mat[50][50],mt[50][50],n,inx,wt;
char sz,dr,a,b,sy[30];
long min(long a,long b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	while(scanf("%ld",&n),n)
	{
		getchar();
		for(i=0;i<=26;i++)
		{
			for(j=0;j<=26;j++)
				mat[i][j]=mt[i][j]=100000000;
			mat[i][i]=mt[i][i]=0;
		}		
		
		inx=1;
		for(i=0;i<n;i++)
		{
			gets(sy);
			sz=sy[0];
			dr=sy[2];
			a=sy[4];
			b=sy[6];
			a-=64;
			b-=64;
			sscanf(sy+7,"%ld",&wt);
						
			if(sz=='Y')
			{
				if(dr=='U')
				{
					if(mat[a][b]>wt)
						mat[a][b]=wt;
				}
				else
				{
					if(mat[a][b]>wt)
						mat[a][b]=wt;
					if(mat[b][a]>wt)
						mat[b][a]=wt;
				}
			}
			else
			{
				if(dr=='U')
				{
					if(mt[a][b]>wt)
						mt[a][b]=wt;
				}
				else
				{
					if(mt[a][b]>wt)
						mt[a][b]=wt;
					if(mt[b][a]>wt)
						mt[b][a]=wt;
				}			
			}
		}
		for(k=1;k<=26;k++)
		{
			for(i=1;i<=26;i++)
			{
				for(j=1;j<=26;j++)
				{
					mt[i][j]=min(mt[i][j],mt[i][k]+mt[k][j]);
					mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
				}
			}
		}
		inx=10000000;
		wt=1;
		scanf("%c %c",&a,&b);
		a-=64;
		b-=64;
		for(i=1;i<=26;i++)
		{
			if(mat[a][i]+mt[b][i]<inx)
				inx=mat[a][i]+mt[b][i];
		}
		if(inx!=10000000)
		{
			wt=0;
			for(i=1;i<=26;i++)
			{
				if(mat[a][i]+mt[b][i]==inx)
					sy[wt++]=i+64;
			}
		}
		sy[wt]=0;
		sort(sy,sy+wt);
		if(inx==10000000)
		{
			if(a==b)
				printf("0 %c\n",a);
			else
				printf("You will never meet.\n");
		}
		else
		{
			printf("%ld",inx);
			for(i=0;sy[i];i++)
				printf(" %c",sy[i]);
			printf("\n");
		}
	}
	return 0;
}
