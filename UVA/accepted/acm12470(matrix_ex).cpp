#include<stdio.h>
long long M[10][10],F[10][10],D[10][10],i,j,k,n,s,a,b,mm[]={0,0,1,2},m=1000000009;
void check(long long n)
{
	if(n<=1)
		return ;

	if(n%2==0)
		check(n/2);
	else
		check(n-1);
	if(n%2==0)
	{
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				s=0;
				for(k=1;k<=3;k++)
				{
					s+=(M[i][k]*M[k][j])%m;
				}
				D[i][j]=s%m;
			}
		}
	}
	else
	{
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				s=0;
				for(k=1;k<=3;k++)
				{
					s+=(M[i][k]*F[k][j])%m;
				}
				D[i][j]=s%m;
			}
		}
	}
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			M[i][j]=D[i][j];
}

int main()
{
	F[1][1]=1,F[1][2]=1,F[1][3]=1;
	F[2][1]=1,F[2][2]=0,F[2][3]=0;
	F[3][1]=0,F[3][2]=1,F[3][3]=0;

	while(~scanf("%lld",&n) && n)
	{

		if(n<4)
		{
			printf("%lld\n",mm[n]);
			continue;
		}

		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
				M[i][j]=F[i][j];

		check(n-3);
		printf("%lld\n",(mm[3]*M[1][1]+mm[2]*M[1][2]+mm[1]*M[1][3])%m);
	}
	return 0;
}