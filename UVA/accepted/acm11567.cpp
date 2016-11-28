#include<stdio.h>
#include<map>
using namespace std;
map<long long,long long>mp;

long long n;

long long call(long long n)
{
	if(n==0 || n==1 || mp[n]>0)
		return mp[n];
	if(n%2)
	{
		long long a=call(n-1)+1;
		long long b=call(n+1)+1;

		return mp[n]=(a>b)?b:a;
	}
	else
		return mp[n]=call(n/2)+1;
}

int main()
{
	mp[1]=1;
	while(~scanf("%lld",&n))
	{
		printf("%lld\n",call(n));
	}
	return 0;
}