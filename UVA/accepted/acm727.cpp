#include<stdio.h>
#include<stack>
using namespace std;
stack<char>stk;
long p,n;
char st[100],c;
bool flag;
int main()
{
	gets(st);
	sscanf(st,"%ld",&n);
	getchar();
	while(n--)
	{
		p=0;flag=1;
		stk.push('(');
		while(scanf("%c",&c)==1 && c!='\n')
		{
				getchar();

			if(c>47 && c<58)
				st[p++]=c;
			else
			{
				if(((stk.top()=='*' || stk.top()=='/') && (c=='+' || c=='-')) || ((stk.top()=='*' || stk.top()=='/') && (c=='*' || c=='/')) || ((stk.top()=='+' || stk.top()=='-') && (c=='+' || c=='-')))
				{
					while(!stk.empty() && ((stk.top()=='*' || stk.top()=='/') && (c=='+' || c=='-')) || ((stk.top()=='*' || stk.top()=='/') && (c=='*' || c=='/')) || ((stk.top()=='+' || stk.top()=='-') && (c=='+' || c=='-')))
					{
						st[p++]=stk.top();
						stk.pop();
					}
					stk.push(c);
				}
				else if(c==')')
				{
					while(stk.top()!='(')
					{
						st[p++]=stk.top();
						stk.pop();
					}
					stk.pop();
				}
				else
					stk.push(c);
			}
		}

		while(stk.top()!='(')
		{
			st[p++]=stk.top();
			stk.pop();
		}
		stk.pop();
		st[p]=0;
		puts(st);
		if(n)
			printf("\n");
	}
	return 0;
}