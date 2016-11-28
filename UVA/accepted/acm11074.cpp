#include<stdio.h>
long sum,i,j,s,n,t,l,k,p=1;
int main()
{
	while(scanf("%ld%ld%ld",&s,&t,&n) && (s||t||n))
	{
		printf("Case %ld:\n",p++);
		sum=s*n+(n+1)*t;
		for(k=0;k<n;k++)
		{
			for(i=0;i<t;i++)
			{
				for(j=0;j<sum;j++)
					printf("*");
				printf("\n");
			}
			for(i=0;i<s;i++)
			{
				for(l=0;l<n;l++)
				{
					for(j=0;j<t;j++)
						printf("*");
					for(j=0;j<s;j++)
						printf(".");
				}
				for(j=0;j<t;j++)
					printf("*");
				printf("\n");
			}
		}
		for(i=0;i<t;i++)
		{
			for(j=0;j<sum;j++)
				printf("*");
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
