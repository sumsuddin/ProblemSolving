#include<stdio.h>
#include<queue>
#include<stack>
#include<string.h>
using namespace std;
queue<int>que;
stack<int>stk;

long i,j,p,a,b,n,t,m,s,parent[1000];
char st[10],sy[10],name[1000][10];
bool mat[1000][1000],vst[1000],flag,drag=0;;
void bfs()
{
	flag=1;
	s=b=-6;
	for(i=0;i<p;i++)
		if(strcmp(st,name[i])==0)
		{
			s=i;
			break;
		}
	for(i=0;i<p;i++)
		if(strcmp(sy,name[i])==0)
		{
			b=i;
			break;
		}

	if(s>=0 && b>=0)
	{
		que.push(s);
		while(!que.empty())
		{
			a=que.front();
			vst[a]=0;
			que.pop();
			for(i=0;i<p;i++)
			{
				if(mat[a][i]==1 && vst[i]==1)
				{
					parent[i]=a;
					if(i==b)
					{
						while(!que.empty())
							que.pop();
						
						while(b!=s)
						{
							flag=1;
							stk.push(b);stk.push(a=parent[b]);
							b=a;
						}

						break;
					}
					que.push(i);
					vst[i]=0;
				}
			}
		}

		while(!stk.empty())
		{
			a=stk.top();
			stk.pop();
			b=stk.top();
			stk.pop();
			printf("%s %s\n",name[a],name[b]);
			flag=0;
		}
	}

	if(flag)
		printf("No route\n");
}
int main()
{
	while(~scanf("%ld",&n))
	{
		a=2*n;
		if(a>999)
			a=999;

		for(i=0;i<a;i++)
		{
			vst[i]=1;
			name[i][0]=0;
			for(j=0;j<a;j++)
				mat[i][j]=0;	
		}
		p=0;
		while(n--)
		{
			scanf("%s",st);
			flag=1;
			for(i=0;i<p;i++)
			{
				if(strcmp(st,name[i])==0)
				{
					a=i;
					flag=0;
					break;
				}
			}
			if(flag)
			{
				strcpy(name[p],st);
				a=p++;
			}
			scanf("%s",st);
			flag=1;
			for(i=0;i<=p;i++)
			{
				if(strcmp(st,name[i])==0)
				{
					b=i;
					flag=0;
					break;
				}
			}
			if(flag)
			{
				strcpy(name[p],st);
				b=p++;
			}
			mat[a][b]=1;
			mat[b][a]=1;
		}
		scanf("%s%s",st,sy);
		if(drag)
			printf("\n");
		else
			drag=1;
		if(strcmp(st,sy)==0)
			printf("%s %s\n",st,sy);
		else
			bfs();
	}
	return 0;
}