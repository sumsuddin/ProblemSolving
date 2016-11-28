#include<stdio.h>
#include<stack>
using namespace std;
char st[90][90],d,ch[3050];
long i,j,p,cs=1,n,m,sy[3050],q,sum;
stack<int>stk;
void dfs()
{
	for(i=65;i<91;i++)
	{
		sy[i]=0;
		ch[i]=(char)i;
	}

	sum=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(st[i][j]>64 && st[i][j]<91)
			{
				d=st[i][j];
				stk.push(i);
				stk.push(j);
				st[i][j]=1;
				sy[sum]=0;
				ch[sum]=d;
				while(!stk.empty())
				{
					q=stk.top();
					stk.pop();
					p=stk.top();
					stk.pop();
					st[p][q]=1;
					sy[sum]++;
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
				sum++;
			}
		}
	}
}
int main()
{
	while(gets(st[0]))
	{
		sscanf(st[0],"%ld%ld",&m,&n);
		
		if(m==0 && n==0)
			break;

		for(i=0;i<m;i++)
			gets(st[i]);
		for(i=0;i<50;i++)
			st[m][i]=0;
		for(i=65;i<91;i++)
			sy[i]=0;
		dfs();
		printf("Problem %ld:\n",cs++);
		for(i=0;i<sum;i++)
			for(j=i+1;j<sum;j++)
				if(sy[i]<sy[j])
				{
					p=sy[i];
					sy[i]=sy[j];
					sy[j]=p;

					d=ch[i];
					ch[i]=ch[j];
					ch[j]=d;
				}
				else
				{
					if(sy[i]==sy[j])
						if(ch[i]>ch[j])
						{
							p=sy[i];
							sy[i]=sy[j];
							sy[j]=p;

							d=ch[i];
							ch[i]=ch[j];
							ch[j]=d;
						}
				}
		for(i=0;i<sum;i++)
			printf("%c %ld\n",ch[i],sy[i]);
	}
	return 0;
}