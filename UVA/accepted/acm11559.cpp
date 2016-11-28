#include<stdio.h>
long min,n,bud,h,w,hc,cap,i,j;
int main()
{
	while(~scanf("%ld%ld%ld%ld",&n,&bud,&h,&w))
	{
		min=99999999;
		for(i=0;i<h;i++)
		{
			scanf("%ld",&hc);
			if(min>hc)
			{
				for(j=0;j<w;j++)
				{
					scanf("%ld",&cap);
					if(cap>=n)
						if(n*hc<=bud)
							min=hc;
				}
			}
			else
			{
				for(j=0;j<w;j++)
					scanf("%ld",&cap);
			}
		}
		if(min*n>bud)
			printf("stay home\n");
		else
			printf("%ld\n",n*min);
	}
	return 0;
}