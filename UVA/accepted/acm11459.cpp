#include<stdio.h>
long i,a,t,b,c,x,y,pos[1000050],ind[130];
int flag;
int main()
{
	scanf ("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&a,&b,&c);

		for(i=1;i<=a;i++)
			pos[i]=1;

		for(i=0;i<=100;i++)
			ind[i]=i;

		while(b--)
		{
			scanf("%ld%ld",&x,&y);
			ind[x]=y;
		}
		for(i=1;i<=100;i++)
		{
			x=i;
			while(1)
			{
				x=ind[x];
				if(ind[x]==x)
					break;
			}
			ind[i]=x;
		}
		b=1;flag=0;
		while(c--)
		{
			scanf("%ld",&x);
			if(flag)
				continue;

			if(ind[pos[b]+x]>=100)
			{
				pos[b]=100;
				flag=1;
			}
			else
				pos[b]=ind[pos[b]+x];

			b++;
			if(b>a)
				b=1;
		}
		for(i=1;i<=a;i++)
			printf("Position of player %ld is %ld.\n",i,pos[i]);
	}
	return 0;
}