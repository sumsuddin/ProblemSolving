#include<stdio.h>
#include<math.h>
long i,flag,t;
long double a,b,c;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%llf%llf",&a,&b);

		flag=0;
		for(i=1;i<100;i+=2)
		{
			if(b==0)
			{
				flag=1;
				break;
			}
			else
				if(a==0)
				{
					flag=1;
					i++;
					break;
				}
				else
				{
					c=a*a-b*b;
					b=2*a*b;
					a=c;
					if(c>pow(2,30))
						break;
				}
		}
		if(flag)
			printf("%ld\n",i);
		else
			printf("TOO COMPLICATED\n");
	}
	return 0;
}