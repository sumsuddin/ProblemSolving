#include<stdio.h>
#include<math.h>
long i,d,c,a,b,sum,t,ex,inc;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&a,&b);

		c=1;
		sum=d=0;

		if(b>a/2 || (b==a/2 && a%2==0))
		{
			i=0;
			inc=1;
		}
		else
		{
			i=a+b-1;
			inc= -1;
		}



		while(a||b)
		{
			if(((c==1 && d==0) || (c==0 && d==1)) && a>0)
			{
				a--;
				ex=1;
			}
			else
				if(c==1 && d==1 && b>0)
				{
					b--;
					ex=0;

				}
				else
				{
					if(a<1)
					{
						b--;
						ex=0;
					}
					else
					{
						a--;
						ex=1;
					}
				}
				d=c;
				c=ex;
			sum+=(ex*(long)pow(2,i));
			i+=inc;
		}
		printf("%ld\n",sum);
	}
	return 0;
}