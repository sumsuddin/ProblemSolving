#include<stdio.h>
long t,m,mat,x1,x2,y1,y2,d,e;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&m,&mat);

		while(m--)
		{
			scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);

			if(x1==x2 && y1==y2)
				printf("0\n");
			else
			if((x1%2==y1%2 && x2%2==y2%2) || (x1%2!=y1%2 && x2%2!=y2%2) && x1>=1 && x2>=1 && y1>=1 && y2>=1 && x1<=mat && x2<=mat && y1<=mat && y2<=mat)
			{
				d=x1-x2;
				e=y1-y2;
				if(d<0)
					d*=-1;
				if(e<0)
					e*=-1;

				if(d==e)
					printf("1\n");
				else
					printf("2\n");
			}
			else
				printf("no move\n");
		}
	}
	return 0;
}