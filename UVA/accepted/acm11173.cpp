#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;
stack<int>stk;

long n,k,c,i,sum;
int main()
{
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%*ld%ld",&k);

		c=i=sum=0;

		while(k)
		{
			stk.push(k%2);
			k/=2;
			i++;
		}
		while(!stk.empty())
		{
			sum+=pow(2,--i)*(c^stk.top());
			c=stk.top();
			stk.pop();
		}
		printf("%ld\n",sum);
	}
	return 0;
}