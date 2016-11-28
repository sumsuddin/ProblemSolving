#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
long i,j,sum,p,q,t,r,ma;
char st[100][100];
bool sl[100][100],flag=1;
stack<int>stk;
int main()
{
	scanf("%ld",&t);
	getchar();
	getchar();
	
	while(t--)
	{
		ma=0;

		r=0;
		while(gets(st[r]))
		{
			if(st[r][0]==0)
				break;

			for(i=strlen(st[r]);i<26;i++)
				st[r][i]=0;
			r++;
		}
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				sl[i][j]=1;

		sum=0;
		for(i=0;i<r;i++)
		{
			for(j=0;st[i][j];j++)
			{
				if(st[i][j]=='1' && sl[i][j])
				{
					sum=0;
					stk.push(i);
					stk.push(j);
					sl[i][j]=0;
					while(!stk.empty())
					{
						q=stk.top();
						stk.pop();
						p=stk.top();
						stk.pop();
						sum++;
						st[p][q]='*';
						if(st[p][q+1]=='1' && sl[p][q+1])
						{
							stk.push(p);
							stk.push(q+1);
							sl[p][q+1]=0;
						}
						if(st[p][q-1]=='1' && sl[p][q-1])
						{
							stk.push(p);
							stk.push(q-1);
							sl[p][q-1]=0;
						}
						if(st[p-1][q+1]=='1' && sl[p-1][q+1])
						{
							stk.push(p-1);
							stk.push(q+1);
							sl[p-1][q+1]=0;
						}
						if(st[p-1][q]=='1' && sl[p-1][q])
						{
							stk.push(p-1);
							stk.push(q);
							sl[p-1][q]=0;
						}
						if(st[p-1][q-1]=='1' && sl[p-1][q-1])
						{
							stk.push(p-1);
							stk.push(q-1);
							sl[p-1][q-1]=0;
						}
						if(st[p+1][q]=='1' && sl[p+1][q])
						{
							stk.push(p+1);
							stk.push(q);
							sl[p+1][q]=0;
						}
						if(st[p+1][q-1]=='1' && sl[p+1][q-1])
						{
							stk.push(p+1);
							stk.push(q-1);
							sl[p+1][q-1]=0;
						}
						if(st[p+1][q+1]=='1' && sl[p+1][q+1])
						{
							stk.push(p+1);
							stk.push(q+1);
							sl[p+1][q+1]=0;
						}
					}
					if(sum>ma)
						ma=sum;
				}
			}
		}
		if(flag)
		{
			printf("%ld\n",ma);
			flag=0;
		}
		else
			printf("\n%ld\n",ma);
	}
	return 0;
}