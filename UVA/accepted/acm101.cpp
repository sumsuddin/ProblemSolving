#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
vector<long>vc[100];
stack<long>que;
long i,j,n,a,b,i1,i2,j1,j2;
char st[100];

void find(long a)
{
	for(i=0;i<n;i++)
		for(j=0;j<vc[i].size();j++)
			if(vc[i][j]==a)
			{
				return;
			}
}

void send(long i,long k)
{
	long a;
	for(j=vc[i].size()-1;j>=k;j--)
		a=vc[i][j],vc[i].pop_back(),vc[a].push_back(a);
}

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=0;i<n;i++)
		{
			vc[i].clear();
			vc[i].push_back(i);
		}
		while(scanf("%s",st) && st[0]!='q')
		{
			if(st[0]=='m')
			{
				scanf("%ld%s%ld",&a,&st,&b);
				if(st[1]=='v')
				{
					find(a);
					i1=i;
					j1=j;
					find(b);
					i2=i;
					j2=j;
					if(i1==i2)
						continue;

					send(i1,j1+1);
					vc[i1].pop_back();

					vc[i2].push_back(a);
				}
				else
				{
					find(a);
					i1=i;
					j1=j;
					find(b);
					i2=i;
					j2=j;
					if(i1==i2)
						continue;

					send(i1,j1+1);
					vc[i1].pop_back();

					send(i2,j2+1);
					vc[i2].push_back(a);
				}
			}
			else
			{
				scanf("%ld%s%ld",&a,&st,&b);
				if(st[1]=='v')
				{
					find(a);
					i1=i;
					j1=j;
					find(b);
					i2=i;
					j2=j;
					if(i1==i2)
						continue;
					for(j=vc[i1].size()-1;j>=j1;j--)
						que.push(vc[i1][j]),vc[i1].pop_back();
					
					while(!que.empty())
						vc[i2].push_back(que.top()),que.pop();
				}
				else
				{
					find(a);
					i1=i;
					j1=j;
					find(b);
					i2=i;
					j2=j;
					if(i1==i2)
						continue;

					for(j=vc[i1].size()-1;j>=j1;j--)
						que.push(vc[i1][j]),vc[i1].pop_back();
					
					send(i2,j2+1);
					while(!que.empty())
						vc[i2].push_back(que.top()),que.pop();
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%ld:",i);

			for(j=0;j<vc[i].size();j++)
				printf(" %ld",vc[i][j]);
			printf("\n");
		}
	}
	return 0;
}