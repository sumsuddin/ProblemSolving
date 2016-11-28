#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
long i,j,sum,r,c,p,q;
char st[150][150];
bool sl[150][150];
int main()
{
	stack<int>stk;

	while(scanf("%ld%ld",&r,&c) && (r || c))
	{
		getchar();

		for(i=0;i<r;i++)
			gets(st[i]);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				sl[i][j]=1;

		sum=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(st[i][j]=='@' && sl[i][j])
				{
					sum++;
					stk.push(i);
					stk.push(j);
					sl[i][j]=0;
					while(!stk.empty())
					{
						q=stk.top();
						stk.pop();
						p=stk.top();
						stk.pop();
						st[p][q]='*';
						if(st[p][q+1]=='@')
						{
							stk.push(p);
							stk.push(q+1);
							sl[p][q+1]=0;
						}
						if(st[p][q-1]=='@')
						{
							stk.push(p);
							stk.push(q-1);
							sl[p][q-1]=0;
						}
						if(st[p-1][q+1]=='@')
						{
							stk.push(p-1);
							stk.push(q+1);
							sl[p-1][q+1]=0;
						}
						if(st[p-1][q]=='@')
						{
							stk.push(p-1);
							stk.push(q);
							sl[p-1][q]=0;
						}
						if(st[p-1][q-1]=='@')
						{
							stk.push(p-1);
							stk.push(q-1);
							sl[p-1][q-1]=0;
						}
						if(st[p+1][q]=='@')
						{
							stk.push(p+1);
							stk.push(q);
							sl[p+1][q]=0;
						}
						if(st[p+1][q-1]=='@')
						{
							stk.push(p+1);
							stk.push(q-1);
							sl[p+1][q-1]=0;
						}
						if(st[p+1][q+1]=='@')
						{
							stk.push(p+1);
							stk.push(q+1);
							sl[p+1][q+1]=0;
						}
					}
				}
			}
		}
		printf("%ld\n",sum);
	}
	return 0;
}