#include<stdio.h>
long p=1,k,n,h,m,m1,h1,m2,min;
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%ld%ld:%ld",&k,&h,&m);
		m+=(h*60);
		min=999999999;
		while(k--)
		{
			scanf("%ld:%ld%ld",&h1,&m1,&m2);
			m1=(m1+(h1*60))-m;
			if(m1<0)
				m1+=1440;
			m2+=m1;
			if(min>m2)
				min=m2;
		}
		printf("Case %ld: %ld\n",p++,min);
	}
	return 0;
}