#include<stdio.h>
	long prime[505][505],p[105],i,j,a,n;
int main()
{
	for(i=2;i<101;i++)
	{
		a=i;

		prime[i][2]=p[2];
		for(j=3;j<=i;j+=2)
			prime[i][j]=p[j];

		while(a%2==0)
		{
			if(p[2]<0)
				p[2]=0;
			prime[i][2]=++p[2];
			a/=2;
		}
		for(j=3;j<=i;j+=2)
		{
			while(a%j==0)
			{
				if(p[j]<0)
					p[j]=0;
				prime[i][j]=++p[j];
				a/=j;
			}
		}
	}
	while(scanf("%ld",&n),n)
	{
		j=0;
		printf("%3ld! =",n);
		if(prime[n][2]>0)
			printf("%3ld",prime[n][2]);
		for(i=3;i<=n;i+=2)
		{
			if(prime[n][i]>0)
			{
				if(j==14)
				{
					printf("\n      ");
					j++;
				}
				printf("%3ld",prime[n][i]);
				j++;
			}

		}
		printf("\n");
	}
	return 0;
} 