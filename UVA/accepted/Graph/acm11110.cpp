#include<stdio.h>
#include<stack>
using namespace std;

long i,j,n,p,q,st[200][200],vst[200],d;
bool flag;
char *ptbf,buf[5000];
stack<int>stk;

void dfs()
{
	flag=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(st[i][j]>0)
			{
				if(vst[st[i][j]]==1)
					vst[st[i][j]]=0;
				else
				{
					flag=0;
					while(!stk.empty())
						stk.pop();
					break;
				}

				d=st[i][j];
				stk.push(i);
				stk.push(j);
				st[i][j]=0;
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
						st[p][q+1]=0;
					}
					if(st[p][q-1]==d)
					{
						stk.push(p);
						stk.push(q-1);
						st[p][q-1]=0;
					}
					if(st[p-1][q]==d)
					{
						stk.push(p-1);
						stk.push(q);
						st[p-1][q]=0;
					}
					if(st[p+1][q]==d)
					{
						stk.push(p+1);
						stk.push(q);
						st[p+1][q]=0;
					}
				}
			}
		}
		if(flag==0)
			break;
	}
}
int main()
{
	while(scanf("%ld",&n) && n)
	{
		getchar();
		for(i=1;i<=n;i++)
		{
			vst[i]=1;
			for(j=1;j<=n;j++)
				st[i][j]=n;
			st[i][j+1]=0;
		}
		for(j=1;j<=n;j++)
			st[i][j]=0;
		st[i][j]=0;

		for(i=1;i<n;i++)
		{
			gets(buf);
			ptbf=buf;

			while(sscanf(ptbf,"%ld %ld %n",&p,&q,&j)==2)
			{
				st[p][q]=i;
				ptbf+=j;
			}
		}
		dfs();
		if(flag)
			printf("good\n");
		else
			printf("wrong\n");
	}
	return 0;
}
