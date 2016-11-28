#include<stdio.h>

long t,n,r,p,q,tw,fv,i,ind,sum,cs=1,two[1000050],five[1000050];

int main()
{
	scanf("%ld",&t);

	for(i=1;i<1000001;i++)
	{
		ind=i;

		while(ind>1 && ind%2==0)
			ind/=2 , tw++;
		two[i]=tw;
		while(ind>1 && ind%5==0)
			ind/=5,fv++;
		five[i]=fv;
	}

	while(t--)
	{
		scanf("%ld%ld%ld%ld",&n,&r,&p,&q);

		tw=fv=0;
		while(p>1 && p%2==0)
			tw++,p/=2;

		while(p>1&& p%5==0)
			fv++,p/=5;

		tw*=q;
		fv*=q;

		fv+=five[n]-five[r]-five[n-r];
		tw+=two[n]-two[r]-two[n-r];

		sum=fv<tw?fv:tw;

		printf("Case %ld: %ld\n",cs++,sum);
	}
	return 0;
}