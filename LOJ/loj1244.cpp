#include<stdio.h>
#define M 10007

long ff[5][5],mat[5][5],temp[5][5],t,n,cs=1,x;

void rec(long n)
{
	if(n==1)
		return ;

	if(n%2)
		rec(n-1);
	else
		rec(n/2);

	long i,j,k,d;
	if(n%2)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				d=0;
				for(k=0;k<4;k++)
					d+=(ff[i][k]*mat[k][j])%M;
				temp[i][j]=d%M;
			}
		}
	}
	else
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				d=0;
				for(k=0;k<4;k++)
					d+=(ff[i][k]*ff[k][j])%M;
				temp[i][j]=d%M;
			}
		}
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			ff[i][j]=temp[i][j];
}

int main()
{
	long f[10];
	f[1]=1;
	f[2]=2;
	f[3]=5;
	x=1;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);

		if(n<4)
			printf("Case %ld: %ld\n",cs++,f[n]%M);
		else
		{
			mat[0][0]=1;mat[0][1]=1;mat[0][2]=2;mat[0][3]=2;
			mat[1][0]=1;mat[1][1]=0;mat[1][2]=0;mat[1][3]=0;
			mat[2][0]=0;mat[2][1]=0;mat[2][2]=1;mat[2][3]=1;
			mat[3][0]=0;mat[3][1]=1;mat[3][2]=0;mat[3][3]=0;

			ff[0][0]=1;ff[0][1]=1;ff[0][2]=2;ff[0][3]=2;
			ff[1][0]=1;ff[1][1]=0;ff[1][2]=0;ff[1][3]=0;
			ff[2][0]=0;ff[2][1]=0;ff[2][2]=1;ff[2][3]=1;
			ff[3][0]=0;ff[3][1]=1;ff[3][2]=0;ff[3][3]=0;

			rec(n-3);
			printf("Case %ld: %ld\n",cs++,((ff[0][0]*f[3])%M+(ff[0][1]*f[2])%M+(ff[0][2]*x)%M+(ff[0][3]*f[1])%M)%M);
		}
	}
	return 0;
}