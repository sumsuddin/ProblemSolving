#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

long i,b1,b2,a1,a2,sum,n;
char c,st[1000];
bool flag;
stack<long>stk;

int main()
{
	struct {
		long row,clm;
	}mat[200];

	gets(st);
	sscanf(st,"%ld",&n);
	for(i=0;i<n;i++)
	{
		gets(st);
		sscanf(st,"%c",&c);
		sscanf(st+1,"%ld%ld",&mat[c].row,&mat[c].clm);
	}
	while(gets(st))
	{
		flag=1;
		sum=0;
		for(i=0;st[i];i++)
		{
			if(st[i]>64 && st[i]<91)
			{
				stk.push(mat[st[i]].row);
				stk.push(mat[st[i]].clm);
			}
			else
				if(st[i]==')')
				{
					b1=stk.top();
					stk.pop();
					a1=stk.top();
					stk.pop();
					b2=stk.top();
					stk.pop();
					a2=stk.top();
					stk.pop();
					if(b2!=a1)
					{
						flag=0;
						while(!stk.empty())
							stk.pop();
						break;
					}
					else
					{
						sum+=(a2*b1*b2);
						stk.push(a2);
						stk.push(b1);
					}
				}
		}
		if(flag)
			printf("%ld\n",sum);
		else
			printf("error\n");
	}
	return 0;
}
