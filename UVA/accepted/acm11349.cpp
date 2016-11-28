#include<stdio.h>
long long i,j,flag , mat[120][120],sym[120][120],t,n,k,l,cs=1;
int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%*s%*s%lld",&n);

		for(i=0,k=n-1;i<n;i++,k--)
			for(j=0,l=n-1;j<n;j++,l--)
			{
				scanf("%lld",&mat[i][j]);
				sym[k][l]=mat[i][j];
			}

		flag=1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(mat[i][j]!=sym[i][j] || mat[i][j]<0)
				{
					flag=0;
					break;
				}
		if(flag)
			printf("Test #%lld: Symmetric.\n",cs++);
		else
			printf("Test #%lld: Non-symmetric.\n",cs++);
	}
	return 0;
}