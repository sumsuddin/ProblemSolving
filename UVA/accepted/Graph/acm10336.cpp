#include<stdio.h>
#include<stack>
using namespace std;
char st[1000][1000],d,ch[300];
long i,j,p,cs=1,n,m,sy[300],q,t;
stack<int>stk;
void dfs()
{
	for(i=97;i<123;i++)
	{
		sy[i]=0;
		ch[i]=(char)i;
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<t;j++)
		{
			if(st[i][j]>96 && st[i][j]<123)
			{
				sy[st[i][j]]++;
				d=st[i][j];
				stk.push(i);
				stk.push(j);
				st[i][j]=1;
				while(!stk.empty())
				{
					q=stk.top();
					stk.pop();
					p=stk.top();
					stk.pop();
					st[p][q]=1;
					if(st[p][q+1]==d)
					{
						stk.push(p);
						stk.push(q+1);
						st[p][q+1]=1;
					}
					if(st[p][q-1]==d)
					{
						stk.push(p);
						stk.push(q-1);
						st[p][q-1]=1;
					}
					if(st[p-1][q]==d)
					{
						stk.push(p-1);
						stk.push(q);
						st[p-1][q]=1;
					}
					if(st[p+1][q]==d)
					{
						stk.push(p+1);
						stk.push(q);
						st[p+1][q]=1;
					}
				}
			}
		}
	}
}
int main()
{
	gets(st[0]);
	sscanf(st[0],"%ld",&n);
	while(n--)
	{
		gets(st[0]);
		sscanf(st[0],"%ld%ld",&m,&t);
		for(i=0;i<m;i++)
			gets(st[i]);
		for(i=0;i<p;i++)
			st[m][i]=0;
		dfs();
		printf("World #%ld\n",cs++);
		for(i=97;i<123;i++)
			for(j=i+1;j<123;j++)
				if(sy[i]<sy[j])
				{
					p=sy[i];
					sy[i]=sy[j];
					sy[j]=p;

					d=ch[i];
					ch[i]=ch[j];
					ch[j]=d;
				}

		for(i=97;i<123;i++)
			if(sy[i])
				printf("%c: %ld\n",ch[i],sy[i]);
	}
	return 0;
}