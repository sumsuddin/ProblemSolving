#include<stdio.h>

long i,j,t,n,sum,a[500];
bool bu[1000000];
char c;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		n=sum=0;
		while(scanf("%ld%c",&a[n],&c) && c!='\n')
			sum+=a[n++];

		sum+=a[n];
		bu[0]=1;
		bu[sum/2]=0;
		if(sum%2==0)
		{
			for(i=0;i<=sum/2;i++)
				bu[i]=0;
			bu[0]=1;
			for(i=0;i<=n;i++)
			{
				for(j=sum/2;j>=0;j--)
					if(bu[j])
						bu[j+a[i]]=1;
			}
		}
		if(bu[sum/2])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}