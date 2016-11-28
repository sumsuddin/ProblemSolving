#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;

stack<int>stk;
stack<int>stk1;
stack<int>stk2;
long i,j,p,q,print,sl[70][70],sum,r,c,cs=1,pr[1000];
char st[70][70];

void dfs1(long pd,long qd)
{
	sum++;
				stk1.push(pd);
				stk1.push(qd);
				st[pd][qd]=1;
				while(!stk1.empty())
				{
					q=stk1.top();
					stk1.pop();
					p=stk1.top();
					stk1.pop();
					if(st[p][q+1]=='X')
					{
						stk1.push(p);
						stk1.push(q+1);
						st[p][q+1]=1;
					}
					if(st[p][q-1]=='X')
					{
						stk1.push(p);
						stk1.push(q-1);
						st[p][q-1]=1;
					}
					if(st[p-1][q]=='X')
					{
						stk1.push(p-1);
						stk1.push(q);
						st[p-1][q]=1;
					}
					if(st[p+1][q]=='X')
					{
						stk1.push(p+1);
						stk1.push(q);
						st[p+1][q]=1;
					}
				}
}

void dfs2()
{
				sum=0;
				stk2.push(i);
				stk2.push(j);
				st[i][j]=1;
				while(!stk2.empty())
				{
					q=stk2.top();
					stk2.pop();
					p=stk2.top();
					stk2.pop();
					st[p][q]=1;
					if(st[p][q+1]=='X')
					{
						dfs1(p,q+1);
						stk2.push(p);
						stk2.push(q+1);
						st[p][q+1]=1;
						sl[p][q+1]=0;
					}
					else
						if(sl[p][q+1]==print)
						{
							stk2.push(p);
							stk2.push(q+1);
							sl[p][q+1]=0;
						}

					if(st[p][q-1]=='X')
					{
						dfs1(p,q-1);
						stk2.push(p);
						stk2.push(q-1);
						st[p][q-1]=1;
						sl[p][q-1]=0;
					}
					else
						if(sl[p][q-1]==print)
						{
							stk2.push(p);
							stk2.push(q-1);
							sl[p][q-1]=0;
						}


					if(st[p-1][q]=='X')
					{
						dfs1(p-1,q);
						stk2.push(p-1);
						stk2.push(q);
						st[p-1][q]=1;
						sl[p-1][q]=0;
					}
					else
						if(sl[p-1][q]==print)
						{
							stk2.push(p-1);
							stk2.push(q);
							sl[p-1][q]=0;
						}


					if(st[p+1][q]=='X')
					{
						dfs1(p+1,q);
						stk2.push(p+1);
						stk2.push(q);
						st[p+1][q]=1;
						sl[p+1][q]=0;
					}
					else
						if(sl[p+1][q]==print)
						{
							stk2.push(p+1);
							stk2.push(q);
							sl[p+1][q]=0;
						}

				}
				pr[print]=sum;

}

void dfs()
{
	print=1;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(st[i][j]=='*')
			{
				stk.push(i);
				stk.push(j);
				sl[i][j]=print;
				st[i][j]=1;
				while(!stk.empty())
				{
					q=stk.top();
					stk.pop();
					p=stk.top();
					stk.pop();
					if((st[p][q+1]=='*'|| st[p][q+1]=='X') && sl[p][q+1]==0)
					{
						if(st[p][q+1]=='*')
							st[p][q+1]=1;
						sl[p][q+1]=print;
						stk.push(p);
						stk.push(q+1);
						
					}
					if((st[p][q-1]=='*'||st[p][q-1]=='X') && sl[p][q-1]==0)
					{
						if(st[p][q-1]=='*')
							st[p][q-1]=1;
						sl[p][q-1]=print;
						stk.push(p);
						stk.push(q-1);
						
					}
					if((st[p-1][q]=='*'||st[p-1][q]=='X')&& sl[p-1][q]==0)
					{
						if(st[p-1][q]=='*')
							st[p-1][q]=1;
						sl[p-1][q]=print;
						stk.push(p-1);
						stk.push(q);
						
					}
					if((st[p+1][q]=='*'||st[p+1][q]=='X')&& sl[p+1][q]==0)
					{
						if(st[p+1][q]=='*')
							st[p+1][q]=1;
						sl[p+1][q]=print;
						stk.push(p+1);
						stk.push(q);
						
					}
				}
				dfs2();
				print++;
			}
		}
	}
}
int main()
{
	while(gets(st[0]))
	{
		sscanf(st[0],"%ld%ld",&c,&r);
		if(r==0&&c==0)
			break;

		for(i=0;i<r;i++)
		{
			for(j=0;j<=c;j++)
				sl[i][j]=0;
			gets(st[i]);
		}
		for(i=0;i<=c;i++)
		{
			st[r][i]=0;
			sl[r][i]=0;
		}
		printf("Throw %ld\n",cs++);
		dfs();
		sort(pr,pr+print);
		printf("%ld",pr[1]);
		for(i=2;i<print;i++)
			printf(" %ld",pr[i]);
		printf("\n\n");
	}
	return 0;
}

