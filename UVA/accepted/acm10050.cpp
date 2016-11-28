#include<stdio.h>

int main()
{
	int a[105],i,ans,j,k,man,day,n;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{

		scanf("%d%d",&day,&man);

		for(j=0;j<man;j++)
		{
			scanf("%d",&a[j]);
		}


		ans=0;
		for(k=1;k<=day;k++)
		{
			for(j=0;j<man;j++)
			{
				if(k%a[j]==0)
				{
					if((k+1)%7 && k%7)
						ans++;
					break;
				}
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}