#include<stdio.h>
int main()
{
	int i,a,b,t,p=1,max,min,n;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		max=min=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a>b && i)
				max++;
			else
			{
				if(a<b && i)
					min++;
			}
			b=a;
		}
		printf("Case %d: %d %d\n",p++,max,min);
	}
	return 0;
}