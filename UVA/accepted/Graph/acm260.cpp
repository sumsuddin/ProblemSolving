#include<stdio.h>
#include<stack>
using namespace std;

stack<int>stk;
long i,p,q,n,cs=1;
bool flag;
char d,st[500][500];

bool check(long pst)
{
	if(pst==n-1)
	{
		while(!stk.empty())
			stk.pop();
		flag=1;
	}
	return flag;
}

void dfs()
{
	flag=0;

	for(i=0;i<n;i++)
	{
		if(st[0][i]=='b' && flag==0)
		{
			d=st[0][i];
			stk.push(0);
			stk.push(i);
			st[0][i]='0';
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
					if(check(p+1))
						break;
					stk.push(p+1);
					stk.push(q);
					st[p+1][q]='0';
				}
				if(st[p+1][q+1]==d)
				{
					if(check(p+1))
						break;
					stk.push(p+1);
					stk.push(q+1);
					st[p+1][q+1]='0';
				}
			}
		}
	}
}

int main()
{
	while(gets(st[0]))
	{
		sscanf(st[0],"%ld",&n);
		if(n==0)
			break;

		for(i=0;i<n;i++)
			gets(st[i]);
		for(i=0;i<=n;i++)
			st[n][i]=0;

		dfs();
		if(flag)
			printf("%ld B\n",cs++);
		else
			printf("%ld W\n",cs++);
	}
	return 0;
}