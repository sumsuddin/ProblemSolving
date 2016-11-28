#include<stdio.h>
#include<queue>
using namespace std;
#define inf 1000000000

long all,chk[100],i,j,mat[10][10],t,h[]={0,0,1,1,1,-1,-1,-1},v[]={1,-1,1,-1,0,1,-1,0},dp[1000050],lst;
char st[10][10];


struct ss
{
    long x,y,dis;
}
mp[20],pp;
long mm[20][20],cs=1,dist[9][9];
bool vis[9][9];

queue<ss>que;

long minv(long a,long b)
{
    return a<b?a:b;
}

void backtrk(long vst,long ud,long ld,long sum,long col)
{
	long k;
	if(vst==255)
	{
		chk[all++]=sum;
		return;
	}

	for(k=0;k<8;k++)
	{
		if((ud>>k & 1)==0  && (vst>>k & 1)==0 && (ld>>k & 1)==0)
		{
			backtrk((vst | 1<<k),(ud | 1<<k)>>1,(ld | 1<<k)<<1,sum*10+mat[k][col],col+1);
		}
	}
}

long rec(long vs)
{
    if(dp[vs]>=0)
    return dp[vs];

    if(vs==65280)
    return dp[vs]=0;

    long i,j,x,y,xx,yy,l=inf,dis,dd[9];
    for(i=0;i<8;i++)
    {
        if(((vs>>i) & 1)==0)
        continue;

        mp[i].dis=0;
        que.push(mp[i]);

        for(j=0;j<8;j++)
        for(y=0;y<8;y++)
        vis[j][y]=1,dist[j][y]=inf;
        vis[mp[i].x][mp[i].y]=0;

        while(!que.empty())
        {
            pp=que.front();
            que.pop();
            xx=pp.x;
            yy=pp.y;
            dis=pp.dis;
            dist[xx][yy]=dis;

            for(j=0;j<8;j++)
            {
                x=xx;
                y=yy;

                while(1)
                {
                    x+=h[j];
                    y+=v[j];

                    if(x<0 || x>7 || y<0 || y>7)
                    break;

                    if(vis[x][y]==0)
                    continue;

                    if(st[x][y]=='q' && ((vs>>mm[x][y]) & 1))
                    break;

                    if(mm[x][y] && ((vs>>mm[x][y]) & 1 ))
                    break;

                    pp.x=x;
                    pp.y=y;
                    pp.dis=dis+1;
                    vis[x][y]=0;
                    que.push(pp);
                }
            }
        }

        for(j=8;j<16;j++)
        dd[j-8]=dist[mp[j].x][mp[j].y];

        for(j=8;j<16;j++)
        {
            if(((vs>>j) &1)==0)
            {
                long v;
                v=vs|(1<<j);
                v-=(1<<i);
                l=minv(l,dd[j-8]+rec(v));
            }
        }
    }
    return dp[vs]=l;
}

int main()
{
    long d,mn;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			mat[i][j]=i+1;

	all=0;
	backtrk(0,0,0,0,0);

 //   for(i=0;i<all;i++)
 //   printf("%ld\n",chk[i]);

	scanf("%ld",&t);

	while(t--)
	{
	    mn=inf;
	    for(i=0;i<8;i++)
	        scanf("%s",st[i]);
        lst=0;
        for(i=0;i<8;i++)
        for(j=0;st[i][j];j++)
        if(st[i][j]=='q')
        mp[lst].x=i,mp[lst].y=j,mm[i][j]=lst++;
        for(j=0;j<all;j++)
        {
            for(i=0;i<(1<<17);i++)
            dp[i]=-1;
            lst=8;
            d=chk[j];
            for(i=0;i<8;i++)
            mp[lst].x=i,mp[lst].y=d%10-1,mm[i][d%10-1]=lst++,d/=10;

            mn=minv(mn,rec(255));

        }
        printf("Case %ld: %ld\n",cs++,mn);
	}

    return 0;
}
