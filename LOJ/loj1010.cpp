#include<stdio.h>
long sum,r,c,cs=1,t;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&r,&c);
		sum=0;
		if(r<c)
			r^=c^=r^=c;
		if(c==1)
		{
			sum=r;
		}
		else if(c==2)
		{
			sum=(r/4)*4;
			if(r%4<2)
				sum+=(r%4)*2;
			else
				sum+=4;
		}
		else
		{
			sum=((c/2+c%2)+c/2)*(r/2);
			if(r%2)
				sum+=c/2+c%2;
		}
		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}
