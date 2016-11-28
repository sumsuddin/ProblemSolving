#include<stdio.h>
bool M[500][500],F[500][500];
long D[500][500],i,j,k,n,s,m,a,b,d,t;
void check(long n)
{
	if(n<=1)
		return ;

	if(n%2==0)
		check(n/2);
	else
		check(n-1);
	if(n%2==0)
	{
		for(i=1;i<=t;i++)
		{
			for(j=1;j<=t;j++)
			{
				s=0;
				for(k=1;k<=t;k++)
				{
					s+=(M[i][k]*M[k][j]);
				}
				D[i][j]=s;
			}
		}
	}
	else
	{
		for(i=1;i<=t;i++)
		{
			for(j=1;j<=t;j++)
			{
				s=0;
				for(k=1;k<=t;k++)
				{
					s+=(M[i][k]*F[k][j]);
					s=s;
				}
				D[i][j]=s;
			}
		}
	}
	for(i=1;i<=t;i++)
		for(j=1;j<=t;j++)
			if(D[i][j])
				M[i][j]=1;
			else
				M[i][j]=0;
}

int main()
{
	while(~scanf("%ld%ld",&t,&m) && (t||m))
	{
		for(i=1;i<=t;i++)
			for(j=1;j<=t;j++)
				M[i][j]=F[i][j]=0;

		for(i=0;i<m;i++)
			scanf("%ld%ld",&a,&b),M[a][b]=F[a][b]=M[b][a]=F[b][a]=1;

		scanf("%ld%ld%ld",&a,&b,&d);

		check(d);

		if((d==0 && a==b) || (d && M[a][b]))
			printf("Yes, Teobaldo can travel.\n");
		else
			printf("No, Teobaldo can not travel.\n");
	}
	return 0;
}