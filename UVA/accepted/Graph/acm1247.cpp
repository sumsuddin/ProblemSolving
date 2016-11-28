#include<stdio.h>
long i,x,dis[100][100],mdis[100][100],m,n,y,fdis[100][100],ls,path[100],mn;
bool vst[100];
char c1[10],c2[10];
void prn(long x,long y)
{
	if(mdis[x][y])
	{
		prn(x,mdis[x][y]);
		prn(mdis[x][y],y);
		vst[ls]=1;
		path[ls++]=mdis[x][y];
	}
}

void warshall()
{
	for(i=1;i<=n;i++)
		for(x=1;x<=n;x++)
			for(y=1;y<=n;y++)
			{
				if(dis[x][y]>dis[x][i]+dis[i][y] || (dis[x][y]==dis[x][i]+dis[i][y] && fdis[x][y]>(fdis[x][i]+fdis[i][y])))
				{
					dis[x][y]=dis[x][i]+dis[i][y];

					fdis[x][y]=fdis[x][i]+fdis[i][y]+1;

					mdis[x][y]=i;
				}
			}
}

int main()
{
	while(~scanf("%ld%ld",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			for(x=1;x<=n;x++)
			{
				dis[i][x]=1000000000;
				fdis[i][x]=0;
				mdis[i][x]=0;
			}
			dis[i][i]=0;
		}
		while(m--)
		{
			scanf("%s %s %ld",&c1,&c2,&x);
			dis[c1[0]-'A'+1][c2[0]-'A'+1]=x;
			dis[c2[0]-'A'+1][c1[0]-'A'+1]=x;
		}
		warshall();
		scanf("%ld",&m);

		while(m--)
		{
			ls=0;
			scanf("%s%s",&c1,&c2);
			printf("%c",c1[0]);
			prn(c1[0]-'A'+1,c2[0]-'A'+1);
			for(x=0;x<ls;x++)
			{
				mn=100;
				for(i=0;i<ls;i++)
				{
					if(vst[i] && dis[c1[0]-'A'+1][path[i]]<mn)
					{
						mn=dis[c1[0]-'A'+1][path[i]];
						y=i;
					}
				}
				printf(" %c",path[y]+'A'-1);
				vst[y]=0;
			}
			printf(" %c\n",c2[0]);
		}
	}
	return 0;
}