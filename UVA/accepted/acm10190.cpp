#include<stdio.h>
#include<math.h>
int main()
{
	long a,b,c;
	while(scanf("%ld%ld",&a,&b)==2)
	{
		if((a==0 || a==1) || (b==0))
		{
			printf("Boring!\n");
			continue;
		}
		else if(a==1&&b==1)
		{
			printf("1\n");
			continue;
		}

		c=(long)(log(a)/log(b));
		if(a==(long)pow(b,c))
			c++;
		else
			if(a==(long)pow(b,c+1))
				c+=2;
			else
				c=0;


		if(c)
		{
			while(c--)
			{
				printf("%.0lf",pow(b,c));
				if(c)
					printf(" ");
			}
			printf("\n");
		}
		else
			printf("Boring!\n");
	}
	return 0;
}