#include<stdio.h>
int main()
{
	long i,n,m,e,d;
	while(scanf("%ld",&n),n)
	{
		while(n--)
		{
			d=0;
			for(i=1;i<6;i++)
			{
				scanf("%ld",&m);

				if(m<128)
				{
					d++;
					e=i;
				}
			}
			if(d==1)
				printf("%c\n",e+64);
			else
				printf("*\n");
		}
	}
	return 0;
}