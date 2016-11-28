#include<stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	char st[120][120],sy[120];
	long i,j,k,n,a,b,sum[120];
	gets(st[0]);
	sscanf(st[0],"%ld",&n);
	while(n--)
	{
		getchar();

		gets(st[0]);
		sscanf(st[0],"%ld%ld",&b,&a);
		for(i=0;i<a;i++)
			gets(st[i]);

		for(i=0;i<a;i++)
		{
			sum[i]=0;
			for(j=0;j<b;j++)
				for(k=j+1;k<b;k++)
					if(st[i][j]>st[i][k])
						sum[i]++;
		}
		for(i=0;i<a;i++)
		{
			for(j=1;j<a;j++)
			{
				if(sum[j-1]>sum[j])
				{
					swap(sum[j-1],sum[j]);
					
					strcpy(sy,st[j-1]);
					strcpy(st[j-1],st[j]);
					strcpy(st[j],sy);
				}
			}
		}
		for(i=0;i<a;i++)
			puts(st[i]);
		if(n)
			printf("\n");
	}
	return 0;
}