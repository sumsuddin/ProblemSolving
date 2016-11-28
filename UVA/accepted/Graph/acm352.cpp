#include<stdio.h>
#include<stack>
using namespace std;
long cs=1,print,i,j,p,q,n;
char st[50][50],d;
stack<int>stk;

void dfs()
{
	print=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(st[i][j]==49)
			{
				print++;
				d=st[i][j];
				stk.push(i);
				stk.push(j);
				st[i][j]='0';
				while(!stk.empty())
				{
					q=stk.top();
					stk.pop();
					p=stk.top();
					stk.pop();
					if(st[p][q+1]==d)
					{
						stk.push(p);
						stk.push(q+1);
						st[p][q+1]='0';
					}
					if(st[p][q-1]==d)
					{
						stk.push(p);
						stk.push(q-1);
						st[p][q-1]='0';
					}
					if(st[p-1][q+1]==d)
					{
						stk.push(p-1);
						stk.push(q+1);
						st[p-1][q+1]='0';
					}
					if(st[p-1][q]==d)
					{
						stk.push(p-1);
						stk.push(q);
						st[p-1][q]='0';
					}
					if(st[p-1][q-1]==d)
					{
						stk.push(p-1);
						stk.push(q-1);
						st[p-1][q-1]='0';
					}
					if(st[p+1][q]==d)
					{
						stk.push(p+1);
						stk.push(q);
						st[p+1][q]='0';
					}
					if(st[p+1][q-1]==d)
					{
						stk.push(p+1);
						stk.push(q-1);
						st[p+1][q-1]='0';
					}
					if(st[p+1][q+1]==d)
					{
						stk.push(p+1);
						stk.push(q+1);
						st[p+1][q+1]='0';
					}
				}
			}
		}
	}
	printf("Image number %ld contains %ld war eagles.\n",cs++,print);
}
int main()
{
	while(gets(st[0]))
	{
		sscanf(st[0],"%ld",&n);
		for(i=0;i<n;i++)
			gets(st[i]);
		for(i=0;i<n;i++)
			st[n][i]=0;
		dfs();
	}
	return 0;
}