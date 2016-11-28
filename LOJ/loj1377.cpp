#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,j,p,q,cnt,lst,vcx[40005],vcy[40005],x,y,h[]={0,0,-1,1},v[]={-1,1,0,0},t,r,c,par[250][250],cs=1,tmp[250][250];
bool flag,vst[250][250];
char st[250][250];
void bfs()
{
	long i;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		q=que.front();
		que.pop();

		if(st[p][q]=='*' && cnt>0)
		{
			if(cnt)
			{
				for(i=0;i<lst && cnt>0;i++)
					if(vst[vcx[i]][vcy[i]] && (vcx[i]!=p || vcy[i]!=q))
					{
						cnt--;
						tmp[vcx[i]][vcy[i]]=par[p][q]+1;
						if(par[vcx[i]][vcy[i]]>par[p][q]+1)
							par[vcx[i]][vcy[i]]=par[p][q]+1;

						vst[vcx[i]][vcy[i]]=0;
						que.push(vcx[i]);
						que.push(vcy[i]);
					}
			}

		}

		if(st[p][q]!='*' || (st[p][q]=='*' && vst[p][q]==0))
		{
			for(i=0;i<4;i++)
			{
				x=p+h[i];
				y=q+v[i];

				if(x>=0 && x<r && y>=0 && y<c && vst[x][y] && st[x][y]!='#')
				{
					if(st[x][y]!='*')
						vst[x][y]=0;
					
					if(st[p][q]=='*')
						par[x][y]=tmp[p][q]+1;
					else
						par[x][y]=par[p][q]+1;
					
					if(st[x][y]=='D')
					{
						while(!que.empty())
							que.pop();
						flag=1;
						break;
					}
					que.push(x);
					que.push(y);
				}
			}
		}
	}
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&r,&c);

		for(i=0;i<r;i++)
		{
			scanf("%s",st[i]);
			for(j=0;j<c;j++)
				vst[i][j]=1,par[i][j]=tmp[i][j]=1000000000;
		}

		lst=0;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(st[i][j]=='P')
				{
					par[i][j]=0;
					que.push(i);
					que.push(j);
					vst[i][j]=0;
				}
				else if(st[i][j]=='*')
				{
					vcx[lst]=i;
					vcy[lst++]=j;
				}
		cnt=lst;

		flag=0;
		bfs();

		if(flag)
			printf("Case %ld: %ld\n",cs++,par[x][y]);
		else
			printf("Case %ld: impossible\n",cs++);
	}
	return 0;
}