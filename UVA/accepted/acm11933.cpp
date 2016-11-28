#include<stdio.h>
#include<math.h>
long long a,b,i,n;
bool flag;
int main()
{
	while(scanf("%lld",&n),n)
	{
		flag=1;
		a=b=0;
		for(i=0;n;i++)
		{
			if(n%2==1)
			{
				if(flag)
				{
					flag=0;
					a+=(long long)pow(2,i);
				}
				else
				{
					flag=1;
					b+=(long long)pow(2,i);
				}
			}
			n/=2;
		}
		printf("%lld %lld\n",a,b);
	}
	return 0;
}