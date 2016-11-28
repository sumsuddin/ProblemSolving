#include<stdio.h>
long i,n,a,b,c,d,e,f,fn[10050],t,cs=1;
long fun(long n)
{
	if(n==0)
		return a;
	else if(n==1)
		return b;
	else if(n==2)
		return c;
	else if(n==3)
		return d;
	else if(n==4)
		return e;
	else if(n==5)
		return f;
	else if(fn[n])
		return fn[n];
	else
		return fn[n]=(fun(n-1)+fun(n-2)+fun(n-3)+fun(n-4)+fun(n-5)+fun(n-6))%10000007;
}
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld%ld%ld%ld%ld",&a,&b,&c,&d,&e,&f,&n);
		for(i=0;i<=n;i++)
			fn[i]=0;
		printf("Case %ld: %ld\n",cs++,fun(n)%10000007);
	}
	return 0;
}
