#include<stdio.h>
long i,j,mat[1050][1050],sum[1050][1050],s,m,n;
bool flag;
int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		if(flag)
			printf("\n");
		else
			flag=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%ld",&mat[i][j]);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				sum[i][j]=sum[i][j-1]+mat[i][j];

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				sum[i][j]+=sum[i-1][j];

		s=0;
		for(i=m;i<=n;i++)
			for(j=m;j<=n;j++)
			{
				s+=sum[i][j]-sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m];
				printf("%ld\n",sum[i][j]-sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m]);
			}
		printf("%ld\n",s);
	}
	return 0;
}