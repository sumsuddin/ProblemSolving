#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
map<string,long>mp;

long i,p,dis[205][205],mdis[205][205],q,flag;
char st[300],cdis[105][105][100],sy[100],sr[100],path[100],x,y,t;


void prn(long x,long y)
{
	if(mdis[x][y])
	{
		prn(x,mdis[x][y]);
		prn(mdis[x][y],y);
	}
	else
		printf("%s",cdis[x][y]);
}


void warshall()
{
	for(i=1;i<t;i++)
		for(x=1;x<t;x++)
			for(y=1;y<t;y++)
			{
				if(dis[x][y]>dis[x][i]+dis[i][y])
				{
					dis[x][y]=dis[x][i]+dis[i][y];

					mdis[x][y]=i;
				}
			}
}


int main()
{
	for(i=0;i<101;i++)
	{
		for(p=0;p<101;p++)
		{
			dis[i][p]=1000000000;
			mdis[x][y]=0;
		}
	}

	t=1;

	while(gets(st) && st[0])
	{
		p=0;
		for(i=0;st[i];i++)
			if(st[i]==',')
			{
				sy[p]=0;
				break;
			}
			else
				sy[p++]=st[i];

		p=0;

		for(i=i+1;st[i];i++)
			if(st[i]==',')
			{
				sr[p]=0;
				break;
			}
			else
				sr[p++]=st[i];

		p=0;
		for(i=i+1;st[i];i++)
			if(st[i]==',')
			{
				path[p]=0;
				break;
			}
			else
				path[p++]=st[i];

		if(mp[sy]==0)
		{
			x=t;
			mp[sy]=t++;
		}
		else
			x=mp[sy];

		if(mp[sr]==0)
		{
			y=t;
			mp[sr]=t++;
		}
		else
			y=mp[sr];

		sscanf(st+i+1,"%ld",&q);
		if(dis[x][y]>q)
		{
			dis[y][x]=dis[x][y]=q;

			for(i=0;sy[i];i++)
			{
				cdis[x][y][i]=sy[i];
			}
			for(;i<21;i++)
			{
				cdis[x][y][i]=' ';
			}

			for(p=0;sr[p];p++,i++)
			{
				cdis[x][y][i]=sr[p];
				cdis[y][x][p]=sr[p];
			}
			for(;i<42;i++,p++)
			{
				cdis[x][y][i]=' ';
				cdis[y][x][p]=' ';
			}

			for(q=0;sy[q];q++,p++)
			{
				cdis[y][x][p]=sy[q];
			}
			for(;p<42;p++)
			{
				cdis[y][x][p]=' ';
			}

			for(p=0;path[p];p++,i++)
			{
				cdis[x][y][i]=path[p];
				cdis[y][x][i]=path[p];
			}
			for(;i<53;i++)
			{
				cdis[x][y][i]=' ';
				cdis[y][x][i]=' ';
			}

			sprintf(path,"%5ld\n",dis[x][y]);
			for(p=0;path[p];p++,i++)
			{
				cdis[x][y][i]=path[p];
				cdis[y][x][i]=path[p];
			}
			cdis[x][y][i]=0;
			cdis[y][x][i]=0;
		}
	}
	warshall();
	while(gets(st))
	{
		p=0;
		for(i=0;st[i];i++)
			if(st[i]==',')
			{
				sy[p]=0;
				break;
			}
			else
				sy[p++]=st[i];

		p=0;

		for(i=i+1;st[i];i++)
			sr[p++]=st[i];
		sr[p]=0;

		x=mp[sy];
		y=mp[sr];
		printf("\n\n");
		printf("From                 To                   Route      Miles\n-------------------- -------------------- ---------- -----\n");

		prn(x,y);

		printf("                                                     -----\n                                          Total%11ld\n",dis[x][y]);
	}
	return 0;
}
