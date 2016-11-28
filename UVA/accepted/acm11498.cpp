#include<stdio.h>
long a,b,x,y,n;
int main()
{
	while(scanf("%ld",&n) && n)
	{
		scanf("%ld%ld",&x,&y);
		while(n--)
		{
			scanf("%ld%ld",&a,&b);
			if(a==x || b==y)
				printf("divisa\n");
			else
				if(a>x && b>y)
					printf("NE\n");
				else
					if(a<x && b>y)
						printf("NO\n");
					else
						if(a>x && b<y)
							printf("SE\n");
						else
							printf("SO\n");
		}
	}
	return 0;
}
