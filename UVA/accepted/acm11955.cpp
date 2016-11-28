#include<stdio.h>
long double r,c,d,e,cs=1,ii;
long i,j,t,n;
char st[110],sy[110],sr[110];

long double combination(long double n,long double r)
{
	c=n-r;
	d=e=1;
	if(c>r)
	{
		for(ii=c+1;ii<=n;ii++)
			d*=ii;
		for(ii=1;ii<=r;ii++)
			e*=ii;
	}
	else
	{
		for(ii=r+1;ii<=n;ii++)
			d*=ii;
		for(ii=1;ii<=c;ii++)
			e*=ii;
	}
	d/=e;
	return d;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",st);

		for(i=1,j=0;st[i]!='+';i++,j++)
			sy[j]=st[i];
		sy[j]=0;
		for(i=i+1,j=0;st[i]!=')';i++,j++)
			sr[j]=st[i];
		sr[j]=0;

		n=0;
		for(i=i+2;st[i];i++)
			n=n*10+(st[i]-'0');


		printf("Case %.0llf: ",cs++);
		for(i=0,j=n;i<=n;i++,j--)
		{
			d=combination(n,i);
			if(d>1)
			{
				printf("%.0llf",d);
				if(i || j)
					printf("*");
			}
			if(j==1)
				printf("%s",sy);
			else
				if(j>1)
					printf("%s^%ld",sy,j);

			if(i==1)
			{
				if(j)
					printf("*");
				printf("%s",sr);
			}
			else
			{
				if(i>1)
				{
					if(j)
						printf("*");
					printf("%s^%ld",sr,i);
				}
			}

			if(i==n)
				printf("\n");
			else
				printf("+");
		}
	}
	return 0;
}