#include<stdio.h>
#include<math.h>
long n,a,b,count,i,sq,j,st[10500];
bool flag;
long double ans;
int main()
{

	for(i=0;i<10001;i++)
	{
		flag=1;
		n=i*i+i+41;
		sq=(long)sqrt(n);

		if((n%2)==0)
			flag=0;
		if(flag)
		{
			for(j=3;j<=sq;j+=2)
			{
				if((n%j)==0)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			st[i+1]=st[i]+1;
		else
			st[i+1]=st[i];
	}

	while(scanf("%ld%ld",&a,&b)==2)
	{
		count=st[b+1]-st[a];
		ans=((double)count/(double)(b-a+1))*100;
		printf("%.2llf\n",ans+(1e-8));
	}
	return 0;
}