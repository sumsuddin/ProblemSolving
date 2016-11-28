#include<stdio.h>
long st[30][30],i,j,r,c,n,sq,cs,flag=1;
void check()
{
	if(r<1)
		r=n;
	if(r>n)
		r=1;
	if(c>n)
		c=1;
	if(c<1)
		c=n;
}

int main()
{
	while(~scanf("%ld",&n))
	{
		if(flag)
			printf("\n");
		else
			flag=0;

		sq=n*n;

		cs=0;

		while(sq)
		{
			cs++;
			sq/=10;
		}
		sq=n*n;

		for(i=0;i<=n;i++)
			for(j=1;j<=n;j++)
				st[i][j]=0;
		c=n/2+1;
		r=1;

		for(i=1;i<=sq;i++)
		{
			st[r][c]=i;

			r--;c++;

			check();

			if(st[r][c])
			{
				if(r==n && c==1)
				{
					r=2;
					c=n;
				}
				else if(c==1)
				{
					r+=2;
					c=n;
				}
				else
				{
					r+=2;
					c--;
				}
			}
			check();
		}
		sq=0;cs++;
		for(i=1;i<=n;i++)
			sq+=st[1][i];
		printf("n=%ld, sum=%ld\n",n,sq);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%*ld",cs,st[i][j]);
			printf("\n");
		}
	}
	return 0;
}