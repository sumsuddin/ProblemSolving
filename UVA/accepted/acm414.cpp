#include<stdio.h>
long i,l,mn,ans,n,sum[1000];
char st[1000];
int main()
{
	while(~scanf("%ld",&n),n)
	{
		ans=0;
		getchar();
		mn=1000000;
		for(l=0;l<n;l++)
		{
			gets(st);
			sum[l]=0;
			for(i=0;st[i];i++)
				if(st[i]==' ')
					sum[l]++;
			if(sum[l]<mn)
				mn=sum[l];
		};
		for(i=0;i<n;i++)
			ans+=sum[i]-mn;
		printf("%ld\n",ans);
	}
	return 0;
}