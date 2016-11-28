#include<stdio.h>
#include<math.h>

int main()
{
	long int a,b,c,ans,p,q,i;
	while(scanf("%ld%ld",&a,&b) && (a||b))
	{
		ans=0;
		if(a>b)
		{
			q=a;
			p=b;
		}
		else
		{
			p=a;
			q=b;
		}
		for(i=p;i<=q;i++)
		{
			c=(long int)sqrt(i);
			if(c*c==i)
				ans++;
		}
		printf("%ld\n",ans);
	}
	return 0;
}