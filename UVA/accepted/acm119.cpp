#include<stdio.h>
#include<string.h>
char st[25][25],sy[25];
long sum[25],i,j,am,m,n;
bool r=0;
int main()
{
	while(scanf("%ld",&n)==1)
	{

		if(r)
			printf("\n");
		r=1;

		for(i=0;i<n;i++)
		{
			scanf("%s",st[i]);
			sum[i]=0;
		}

		for(i=0;i<n;i++)
		{
			scanf("%s %ld %ld",sy,&am,&m);
			for(j=0;j<n;j++)
			{
				if(m && !strcmp(sy,st[j]))
				{
					sum[j]=sum[j]-am+(am%m);	
					break;
				}
			}

			if(m)
				am/=m;

			while(m--)
			{
				scanf("%s",sy);
				for(j=0;j<n;j++)
				{
					if(!strcmp(sy,st[j]))
					{
						sum[j]+=am;
						break;
					}
				}
			}
		}
		for(i=0;i<n;i++)
			printf("%s %ld\n",st[i],sum[i]);
	}
	return 0;
}