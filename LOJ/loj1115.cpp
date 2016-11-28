#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<long>que;

long i,j,t,m,n,k,l,kk,ll,cs=1,p,q;
char st[100][100],sy[100][100],c;
bool digit[15],flag,vst[100][100];
int h[]={0,0,1,-1,1,-1,1,-1};
int v[]={1,-1,0,0,1,1,-1,-1};
bool check(long i,long j)
{
	que.push(i);
	que.push(j);

	c=st[i-1][j];

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			vst[i][j]=1;

	while(!que.empty())
	{
		i=que.front();
		que.pop();
		j=que.front();
		que.pop();

		if(i<=0 || i>=m-1 || j<=0 || j>=n-1)
		{
			while(!que.empty())
				que.pop();

			return 0;
		}
		else
		{
			if(st[i-1][j]!=c && vst[i-1][j])
			{
				vst[i-1][j]=0;
				que.push(i-1);
				que.push(j);
			}
			if(st[i+1][j]!=c && vst[i+1][j])
			{
				vst[i+1][j]=0;
				que.push(i+1);
				que.push(j);
			}
			if(st[i][j-1]!=c && vst[i][j-1])
			{
				vst[i][j-1]=0;
				que.push(i);
				que.push(j-1);
			}
			if(st[i][j+1]!=c && vst[i][j+1])
			{
				vst[i][j+1]=0;
				que.push(i);
				que.push(j+1);
			}
		}
	}
	while(!que.empty())
		que.pop();
	return 1;
}


int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&m,&n);

		for(i=0;i<m;i++)
			scanf("%s",st[i]);

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(check(i,j))
				{
					if(st[i-1][j]!='.')
						st[i][j]=st[i-1][j];
				}
			}
		}
		for(i=0;i<m;i++)
			strcpy(sy[i],st[i]);

		flag=0;

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(st[i][j]>64 && st[i][j]<91)
				{
					for(kk=0;kk<m;kk++)
						for(ll=0;ll<n;ll++)
							vst[i][j]=1;
					que.push(i);
					que.push(j);
					c=sy[i][j];
					sy[i][j]=1;
					while(!que.empty())
					{
						p=que.front();
						que.pop();
						q=que.front();
						que.pop();
						for(k=0;k<8;k++)
							if(vst[p+h[k]][q+v[k]] && sy[p+h[k]][q+v[k]]==c)
							{
								vst[p+h[k]][q+v[k]]=0;
								que.push(p+h[k]);
								que.push(q+v[k]);
								sy[p+h[k]][q+v[k]]=1;
							}
						
					}
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}

		printf("Case %ld:\n",cs++);

		for(i=0;i<m;i++)
			puts(st[i]);
	}
	return 0;
}
