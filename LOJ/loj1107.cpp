#include<stdio.h>
long x1,x2,y1,y2,x,y,cs=1,q,t;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);

		if(x1>x2)
		{
			q=x1;
			x1=x2;
			x2=q;
		}

		if(y1>y2)
		{
			q=y1;
			y1=y2;
			y2=q;
		}

		scanf("%ld",&q);

		printf("Case %ld:\n",cs++);

		while(q--)
		{
			scanf("%ld%ld",&x,&y);

			if(x<=x2 && x>=x1 && y<=y2 && y>=y1)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}