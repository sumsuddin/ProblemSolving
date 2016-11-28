#include<stdio.h>
long maxi(long a,long b)
{
	return a>b?a:b;
}
char st[55],sy[55],sr[55];
long mat[55][55][55],i,j,k,t,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s%s%s",st,sy,sr);

		for(i=0;st[i];i++)
			for(j=0;sy[j];j++)
				for(k=0;sr[k];k++)
				{
					if(st[i]==sy[j] && st[i]==sr[k])
						mat[i+1][j+1][k+1]=mat[i][j][k]+1;
					else
						mat[i+1][j+1][k+1]=maxi(maxi(mat[i+1][j+1][k],mat[i+1][j][k+1]),mat[i][j+1][k+1]);
				}
		printf("Case %ld: %ld\n",cs++,mat[i][j][k]);
	}
	return 0;
}