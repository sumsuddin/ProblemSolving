#include<stdio.h>
long i,j,n,m,sum,max,st[200],x,r,c,p=1;
char sy[50];
int main()
{
	scanf("%ld",&x);
	while(x--)
	{
		for(i=65;i<91;i++)
			st[i]=0;
		scanf("%ld%ld%ld%ld",&r,&c,&m,&n);

		for(i=0;i<r;i++)
		{
			scanf("%s",sy);
			for(j=0;sy[j];j++)
				st[sy[j]]++;
		}
		max=0;
		for(i=65;i<91;i++)
		{
			if(max<st[i])
				max=st[i];
		}
		sum=0;
		for(i=65;i<91;i++)
		{
			if(st[i]==max)
				sum++;
		}
		sum=(max*sum*m)+((r*c)-(max*sum))*n;
		printf("Case %ld: %ld\n",p++,sum);
	}
	return 0;
}