#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
long i,j,p,q,n,la,cs;
char st[40][100];
bool flag,sl[40][100];
stack<int>stk;

void dfs(long a)
{
	for(i=0;i<a;i++)
	{
		for(j=0;st[i][j];j++)
		{
			if(st[i][j]=='*')
			{
				stk.push(i);
				stk.push(j);
				sl[i][j]=0;
				st[i][j]='#';
				while(!stk.empty())
				{
					flag=1;
					q=stk.top();
					stk.pop();
					p=stk.top();
					stk.pop();
					if(st[p][q]==' ')
						st[p][q]='#';
					else
						if(st[p][q]!='#')
						{
							sl[p][q]=0;
							flag=0;
						}
					if(st[p][q+1]!='_' &&sl[p][q+1]==1)
					{
						if(flag || st[p][q+1]!=' ')
						{
						stk.push(p);
						stk.push(q+1);
						sl[p][q+1]=0;
						}
					}
					if(st[p][q-1]!='_' &&sl[p][q-1]==1)
					{
						if(flag || st[p][q-1]!=' ')
						{
						stk.push(p);
						stk.push(q-1);
						sl[p][q-1]=0;
					
						}
					}
					if(st[p-1][q+1]!='_' &&sl[p-1][q+1]==1)
					{
						if(flag || st[p-1][q+1]!=' ')
						{
						stk.push(p-1);
						stk.push(q+1);
						sl[p-1][q+1]=0;
						}
					}
					if(st[p-1][q]!='_' &&sl[p-1][q]==1)
					{
						if(flag || st[p-1][q]!=' ')
						{
						stk.push(p-1);
						stk.push(q);
						sl[p-1][q]=0;
						}
					}
					if(st[p-1][q-1]!='_' &&sl[p-1][q-1]==1)
					{
						if(flag || st[p-1][q-1]!=' ')
						{
						stk.push(p-1);
						stk.push(q-1);
						sl[p-1][q-1]=0;
						}
					}
					if(st[p+1][q]!='_' &&sl[p+1][q]==1)
					{
						if(flag || st[p+1][q]!=' ')
						{
						stk.push(p+1);
						stk.push(q);
						sl[p+1][q]=0;
						}
					}
					if(st[p+1][q-1]!='_' &&sl[p+1][q-1]==1)
					{
						if(flag || st[p+1][q-1]!=' ')
						{
						stk.push(p+1);
						stk.push(q-1);
						sl[p+1][q-1]=0;
						}
					}
					if(st[p+1][q+1]!='_' &&sl[p+1][q+1]==1)
					{
						if(flag || st[p+1][q+1]!=' ')
						{
						stk.push(p+1);
						stk.push(q+1);
						sl[p+1][q+1]=0;
						}
					}
				}
				break;
			}
		}
	}
}
int main()
{
	scanf("%ld",&n);
	getchar();

	while(n--)
	{
		cs=0;
		while(gets(st[cs]))
		{
			if(st[cs][0]=='_')
			{
				la=strlen(st[cs]);
				for(i=0;i<la;i++)
					sl[cs][i]=0;
				sl[cs][la]=0;
				cs++;
				dfs(cs);
				for(i=0;i<cs;i++)
					puts(st[i]);
				cs=0;
				break;
			}
			else
			{
				la=strlen(st[cs]);
				for(i=0;i<la;i++)
					sl[cs][i]=1;
				sl[cs][la]=0;
				cs++;
			}
		}
	}
	return 0;
}
