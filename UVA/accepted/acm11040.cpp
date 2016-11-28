#include<stdio.h>
long i,j,t,a[100];
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		for(i=0;i<9;i+=2)
		{
			for(j=(i*(i+1))/2;j<((i+1)*(i+2))/2;j+=2)
				scanf("%ld",&a[j]);
		}
		for(i=0;i<9;i++)
		{
			for(j=(i*(i+1))/2;j<((i+1)*(i+2))/2;j+=2)
			{
				a[j+2*i+4]=(a[j]-(a[j+2*i+3]+a[j+2*i+5]))/2;
			}
		}

		for(i=1;i<9;i+=2)
		{
			for(j=(i*(i+1))/2;j<((i+1)*(i+2))/2;j++)
				a[j]=a[i+j+2]+a[i+j+1];
		}
		for(i=0;i<9;i++)
		{
			printf("%ld",a[j=(i*(i+1))/2]);
			for(j=j+1;j<((i+1)*(i+2))/2;j++)
				printf(" %ld",a[j]);
			printf("\n");
		}
	}
	return 0;
}