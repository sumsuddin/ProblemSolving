#include<stdio.h>
long i;
long double st[1000009],d,t;
int main()
{
	d=2;t=2;
	st[3]=0;st[4]=1;st[5]=3;
	for(i=6;i<1000001;i+=2)
	{
		st[i]=st[i-1]+t+d;
		st[i+1]=st[i]+t+(d*2);
		t+=d*2;
		d++;
	}
	while(scanf("%ld",&i),i>2)
	{
		printf("%.0llf\n",st[i]);
	}
	return 0;
}