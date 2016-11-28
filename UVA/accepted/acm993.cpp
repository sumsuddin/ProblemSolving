#include<stdio.h>
#include<stack>
using namespace std;
stack<long>stk;
long i,n,t,flag,to;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		flag=1;
		scanf("%ld",&n);

		if(n==1)
		{
			printf("1");
			flag=0;
		}
		else if(n==0)
		{
			printf("0");
			flag=0;
		}
		else
		{
			while(n>1)
			{
				to=1;
				for(i=9;i>1;i--)
				{
					if(n%i==0)
					{
						stk.push(i);
						n/=i;
						to=0;
					}
				}
				if(to)
				{
					while(!stk.empty())
						stk.pop();
					break;
				}

			}
			while(!stk.empty())
			{
				printf("%ld",stk.top());
				stk.pop();
				flag=0;
			}
		}
		if(flag)
			printf("-1\n");
		else
			printf("\n");
	}
	return 0;
}
