#include<stdio.h>
#include<queue>
#define inf 1000000000
using namespace std;
queue<long>que;

long i,j,mx,ind[100][100],mat[1000][1000],p,q,cs=1,t,n,par[100],temp[1000][1000],hh[]={0,0,1,-1},v[] = {1,-1,0,0 },l,h,lst,mid,k,H,now;
bool vis[100][100],vs[100],flag;
char st[100][100];
void bfs(long x,long y,long dis)
{
	que.push(x);
	que.push(y);
	que.push(0);

	mx=ind[x][y];

	mat[0][mx]=0;

	vis[x][y]=0;

	long i;
	while(!que.empty())
	{
		x=que.front();
		que.pop();
		y=que.front();
		que.pop();
		dis=que.front();
		que.pop();

		for(i=0;i<4;i++)
		{
			p=x+hh[i];
			q=y+v[i];

			if(p<0 || p>=n || q<0 || q>=n)
				continue;

			if(vis[p][q])
			{
				vis[p][q]=0;
				if(st[p][q]=='#')
					continue;
				que.push(p);
				que.push(q);
				que.push(dis+1);
				if(st[p][q]=='H')
				{
					mat[mx][ind[p][q]]=dis+1;
					mat[ind[p][q]][lst-1]=0;
				}
			}
		}
	}
}

void update(long p)
{
	if(par[p]==-1)
		return;

	if(temp[par[p]][p]<mx)
		mx=temp[par[p]][p];
	update(par[p]);
}

void rec(long p)
{
	if(par[p]==-1)
		return ;

	temp[par[p]][p]-=mx;
	temp[p][par[p]]+=mx;

	rec(par[p]);
}

void call()
{
	long i;

	for(i=0;i<lst;i++)
		vs[i]=1;

	que.push(0);
	vs[0]=0;
	par[0]=-1;

	flag=0;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		
		if(p==lst-1)
		{
			while(!que.empty())
				que.pop();
			flag=1;
			break;
		}

		for(i=0;i<lst;i++)
		{
			if(vs[i] && temp[p][i]>0)
			{
				vs[i]=0;
				par[i]=p;
				que.push(i);
			}
		}
	}
	mx=inf;
	if(flag)
	{
		update(lst-1);
		rec(lst-1);
	}
	if(flag)
		now++,call();
}

int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		H=0;
		scanf("%ld",&n);

		lst=1;
		for(i=0;i<n;i++)
		{
			scanf("%s",&st[i]);
			for(j=0;j<n;j++)
			{
				if(st[i][j]=='G' || st[i][j]=='H')
					ind[i][j]=lst++;
				if(st[i][j]=='H')
					H++;
			}

		}
		lst++;

		for(i=0;i<lst;i++)
			for(j=0;j<lst;j++)
				mat[i][j]=inf;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(st[i][j]=='G')
				{
					for(k=0;k<n;k++)
						for(l=0;l<n;l++)
							vis[k][l]=1;
					bfs(i,j,0);
				}
			}

		mid=inf-1;

		for(i=0;i<lst;i++)
		{
			vs[i]=1;
			for(j=0;j<lst;j++)
				if(mat[i][j]<=mid)
					temp[i][j]=1;
				else
					temp[i][j]=0;
		}
		now=0;
		call();
		if(now>=H)
		{
			l=0;h=inf-1;
			while(l<h)
			{
				mid=(l+h)/2;

				for(i=0;i<lst;i++)
				{
					vs[i]=1;
					for(j=0;j<lst;j++)
						if(mat[i][j]<=mid)
							temp[i][j]=1;
						else
							temp[i][j]=0;
				}
				now=0;
				call();

				if(now>=H)
					flag=0,h=mid;
				else
					l=mid+1;
			}
			printf("Case %ld: %ld\n",cs++,h*2+2);
		}
		else
			printf("Case %ld: Vuter Dol Kupokat\n",cs++);
	}
	return 0;
}
