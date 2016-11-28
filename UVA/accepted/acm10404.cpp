#include<stdio.h>
long i,j,n,m,a[15];
bool bu[1000050];
int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		for(i=0;i<m;i++)
			scanf("%ld",&a[i]);

		for(i=0;i<=n;i++)
			bu[i]=0;

		bu[0]=0;

		for(i=0;i<=n;i++)
		{
			if(bu[i]==0)
			{
				for(j=0;j<m;j++)
					if(i+a[j]<=n)
						bu[i+a[j]]=1;
			}
		}
		if(bu[n])
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}