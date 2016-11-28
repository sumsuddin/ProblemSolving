#include<stdio.h>
#include<queue>
using namespace std;

queue<int>stk;
long i,j,k,l,m,n,p,q,r,pa,qa,ra,apa[50][50][50];
char st[50][50][50];
bool flag;
int h[] = { 0,0,0,0,1,-1};
int v[] = { 1,-1,0,0,0,0};
int g[] = { 0,0,1,-1,0,0};

void bfs()
{
	for(i=0;i<l;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<n;k++)
			{
				if(st[i][j][k]=='S')
				{
					flag=0;
					stk.push(i);
					stk.push(j);
					stk.push(k);
					apa[i][j][k]=0;

					while(!stk.empty())
					{
						p=stk.front();
						stk.pop();
						q=stk.front();
						stk.pop();
						r=stk.front();
						stk.pop();

						for(i=0;i<6;i++)
						{
							pa=p+h[i];
							qa=q+v[i];
							ra=r+g[i];
							if(st[pa][qa][ra]=='E')
							{
								apa[pa][qa][ra]=apa[p][q][r]+1;
								while(!stk.empty())
									stk.pop();

								printf("Escaped in %ld minute(s).\n",apa[pa][qa][ra]);
								flag=1;
							}
							else
								if(st[pa][qa][ra]=='.')
								{
									apa[pa][qa][ra]=apa[p][q][r]+1;
									stk.push(pa);
									stk.push(qa);
									stk.push(ra);
									st[pa][qa][ra]='0';
								}
						}
						if(flag)
							break;
					}
					if(flag==0)
						printf("Trapped!\n");
					break;
				}
			}
		}
	}
}
int main()
{
	while(gets(st[0][0]))
	{
		sscanf(st[0][0],"%ld%ld%ld",&l,&m,&n);
		if(l==0 && m==0 && n==0)
			break;

		for(i=0;i<l;i++)
		{
			for(j=0;j<m;j++)
				gets(st[i][j]);
			for(k=0;k<=n;k++)
				st[i][j][k]=0;
			getchar();
		}
		for(j=0;j<m;j++)
		{
			for(k=0;k<n;k++)
				st[i][j][k]=0;
		}
		bfs();
	}
	return 0;
}