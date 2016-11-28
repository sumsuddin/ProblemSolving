#include<stdio.h>
int main()
{
	int a,c,n,i,per[1005];
	float ans,ave;

	scanf("%d",&c);

	while(c--)
	{
		scanf("%d",&n);
		ans=ave=0;a=n;
		while(n--)
		{

			scanf("%d",&per[n]);
			ave+=per[n];
		}
		ave/=a;
		for(i=0;i<a;i++)
		{
			if(per[i]>ave)
				ans++;
		}

		ans=(ans/a)*100;

		printf("%.3f%%\n",ans);
	}
	return 0;
}