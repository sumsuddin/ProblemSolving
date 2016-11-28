#include<stdio.h>
#include<queue>
using namespace std;
queue<long>xx;
queue<long>yy;
queue<char>ch;
int x[]={0,0,1,-1},y[]={1,-1,0,0};
long i,j,pa,qa,p,q,r,c,t,k,par[1005][1005];
char st[1005][1005],cc;
bool flag;

void bfs()
{
	while(!xx.empty())
	{
		cc=ch.front();
		ch.pop();
		p=xx.front();
		xx.pop();
		q=yy.front();
		yy.pop();

		if(cc=='J')
		{
			for(i=0;i<4;i++)
			{
				pa=p+x[i];
				qa=q+y[i];
				if(st[pa][qa]=='.')
				{
					par[pa][qa]=par[p][q]+1;
					if(pa==0 || qa==0 || pa==r-1 || qa==c-1)
					{
						flag=0;
						printf("%ld\n",par[pa][qa]+1);
						while(!xx.empty())
						{
							yy.pop();
							xx.pop();
							ch.pop();
						}
						break;
					}
					else if(pa>=0 && pa<r && qa>=0 && qa<c)
					{
						st[pa][qa]='J';
						ch.push('J');
						xx.push(pa);
						yy.push(qa);
					}
				}
			}
		}
		else
		{
			for(i=0;i<4;i++)
			{
				pa=p+x[i];
				qa=q+y[i];

				if(st[pa][qa]=='.' && pa>=0 && pa<r && qa>=0 && qa<c)
				{
					st[pa][qa]='#';
					ch.push('F');
					xx.push(pa);
					yy.push(qa);
				}
			}
		}
	}
	if(flag)
		printf("IMPOSSIBLE\n");
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		flag=1;
		scanf("%ld%ld",&r,&c);

		for(i=0;i<r;i++)
			scanf("%s",st[i]);

		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(st[i][j]=='F')
				{
					ch.push('F');
					xx.push(i);
					yy.push(j);
				}
			}
		}

		pa=1;
		for(i=0;i<r && pa;i++)
			for(j=0;j<c;j++)
			{
				if(st[i][j]=='J')
				{
					if(i==0 || i==r-1 ||j==0 || j==c-1)
					{
						printf("1\n");
						flag=0;
					}
					else
					{
						par[i][j]=0;
						ch.push('J');
						xx.push(i);
						yy.push(j);
					}
					pa=0;
					break;
				}
			}
		if(flag)
			bfs();
	}
	return 0;
}