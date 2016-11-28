#include<stdio.h>
bool flag,cor,cor2,change;
int a[150][150],i,j,n,c,sum,c1;
int main()
{
	while(scanf("%d",&n),n)
	{
		cor=change=flag=0;

		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);

				sum+=a[i][j];
			}
			if(sum%2)
			{
				change=1;

				if(flag)
					cor=1;
				c=i;
				flag=1;
			}
		}
		if(cor)
			printf("Corrupt\n");
		else
		{
			cor2=flag=0;
			for(i=0;i<n;i++)
			{
				sum=0;
				for(j=0;j<n;j++)
					sum+=a[j][i];

				if(sum%2)
				{
					if(flag)
						cor2=1;
					c1=i;
					flag=1;
				}
			}
			if(cor2)
				printf("Corrupt\n");
			else
				if(change)
					printf("Change bit (%d,%d)\n",c+1,c1+1);
				else
					printf("OK\n");
		}
	}
	return 0;
}