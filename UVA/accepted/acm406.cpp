#include<stdio.h>
int main()
{

	int a,b,c=0,d,st[1000],i,j;
	while(scanf("%d%d",&a,&b)==2)
	{
		printf("%d %d:",a,b);
		c=0;
		for(i=1;i<=a;i++)
		{
			d=1;
			for(j=2;j<i/2+1;j++)
			{
				if(i%j==0)
				d=d*0;
			}
			if(d!=0)
			{
				c++;
				st[c]=i;
			}
		}


		if(c%2)
		{
			for(i=c/2-b+2;i<c/2+b+1;i++)
			{
				if(i<1 || i>c)
					continue;
				printf(" %d",st[i]);
			}
		}
		else
		{
			for(i=c/2-b+1;i<c/2+b+1;i++)
			{
				if(i<1 || i>c)
					continue;
				printf(" %d",st[i]);
			}
		}
		printf("\n\n");
	}
return 0;
}