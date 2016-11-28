#include<stdio.h>
#include<string.h>
long i,j,k,l,sum,mx,a[50][50],n,T;
char st[50][50];
int main()
{
	scanf("%ld",&T);
	while(T--)
	{
		scanf("%s",st[0]);
		mx=0;
		n=strlen(st[0]);
		for(i=0;st[0][i];i++)
			if(st[0][i]=='0')
				st[0][i]=-50;
			else
				st[0][i]=1;

		for(i=1;i<n;i++)
		{
			scanf("%s",st[i]);
			for(j=0;st[i][j];j++)
				if(st[i][j]=='0')
					st[i][j]=-50;
				else
					st[i][j]=1;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=i;k<n;k++)
				{
					if(k==i)
						a[j][k]=st[j][k];
					else
						a[j][k]=a[j][k-1]+st[j][k];

					if(mx<a[j][k])
						mx=a[j][k];
				}
			}
			for(l=0;l<n;l++)
			{
				for(j=0;j<n;j++)
				{
					for(k=l;k<n;k++)
					{
						if(k==l)
							sum=a[k][j];
						else
							sum+=a[k][j];

						if(mx<sum)
							mx=sum;
					}
				}
			}
		}
		printf("%ld\n",mx);
		if(T)
			printf("\n");
	}
	return 0;
}