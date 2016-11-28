#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,k,j,p,q,h[]={0,0,1,-1},v[]={-1,1,0,0},n,m,mx,sum;
char st[50][50],c;
int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		for(i=0;i<n;i++)
			scanf("%s",st[i]);

		scanf("%ld%ld",&p,&q);
		mx=0;

		que.push(p);
		que.push(q);
		c=st[p][q];
		st[p][q]=1;

		while(!que.empty())
		{
			p=que.front();
			que.pop();
			q=que.front();
			que.pop();
			if(q==0 && st[p][m-1]==c)
			{
				st[p][m-1]=1;
				que.push(p);
				que.push(m-1);
			}
			if(q==m-1 && st[p][0]==c)
			{
				st[p][0]=1;
				que.push(p);
				que.push(0);
			}
			for(k=0;k<4;k++)
			{
				if(p+h[k]>=0 && p+h[k]<n && q+v[k]>=0 && q+v[k]<m && st[p+h[k]][q+v[k]]==c)
				{
					st[p+h[k]][q+v[k]]=1;
					que.push(p+h[k]);
					que.push(q+v[k]);
				}
			}
		}

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(st[i][j]==c)
				{
					sum=0;
					que.push(i);
					que.push(j);
					sum++;
					st[i][j]=1;

					while(!que.empty())
					{
						p=que.front();
						que.pop();
						q=que.front();
						que.pop();
						if(q==0 && st[p][m-1]==c)
						{
							sum++;
							st[p][m-1]=1;
							que.push(p);
							que.push(m-1);
						}
						else
						if(q==m-1 && st[p][0]==c)
						{
							sum++;
							st[p][0]=1;
							que.push(p);
							que.push(0);
						}
						for(k=0;k<4;k++)
						{
							if(p+h[k]>=0 && p+h[k]<n && q+v[k]>=0 && q+v[k]<m && st[p+h[k]][q+v[k]]==c)
							{
								sum++;
								st[p+h[k]][q+v[k]]=1;
								que.push(p+h[k]);
								que.push(q+v[k]);
							}
						}
					}
					if(sum>mx)
						mx=sum;
				}
			}
			printf("%ld\n",mx);
	}
	return 0;
}