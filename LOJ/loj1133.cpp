#include<stdio.h>
#include<string.h>
char st[20];
long a[105],d,e,i,t,n,m,cs=1;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&n,&m);

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		while(m--)
		{
			scanf("%s",st);
			if(strcmp(st,"S")==0)
			{
				scanf("%ld",&d);
				for(i=0;i<n;i++)
					a[i]+=d;
			}
			else if(strcmp(st,"M")==0)
			{
				scanf("%ld",&d);

				for(i=0;i<n;i++)
					a[i]*=d;
			}
			else if(strcmp(st,"D")==0)
			{
				scanf("%ld",&d);
				for(i=0;i<n;i++)
					a[i]/=d;
			}
			else if(strcmp(st,"P")==0)
			{
				scanf("%ld%ld",&d,&e);

				a[d]^=a[e]^=a[d]^=a[e];
			}
			else
				for(i=0,d=n-1;i<n/2;i++,d--)
					a[i]^=a[d]^=a[i]^=a[d];
		}
		printf("Case %ld:\n%ld",cs++,a[0]);
		for(i=1;i<n;i++)
			printf(" %ld",a[i]);
		printf("\n");
	}
	return 0;
}