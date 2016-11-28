#include<stdio.h>
int main()
{
	long int a,b[99999],c[99999],i,j,k,l;

	scanf("%ld",&a);

	for(i=0;i<a;i++)
	{
		printf("\n");
		scanf("%ld%ld",&b[i],&c[i]);
	}

	for(i=0;i<a;i++)
	{
		for(j=0;j<c[i];j++)
		{
			if(i!=0 || j!=0)
			printf("\n");

			for(k=1;k<=b[i];k++)
			{
				for(l=1;l<=k;l++)
					printf("%ld",k);
				printf("\n");
			}
			for(k=b[i]-1;k>0;k--)
			{
				for(l=k;l>0;l--)
					printf("%ld",k);
				printf("\n");
			}

		}
	}
	return 0;
}