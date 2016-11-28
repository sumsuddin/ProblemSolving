#include<stdio.h>
#include<queue>
using namespace std;
queue<long>que;
long i,sum,pp,mp,j,s;
bool vst[1100010];
struct 
{
	long a,b,c,d,e,f,x,y;
}
nd[1100010];
void make()
{
	sum=2;i=0;

	for(mp=0;i<=1000000;mp++)
	{
		i=sum+=6*mp;

		nd[sum-1].a=sum;
		nd[sum].d=sum-1;

		nd[nd[sum-1].b].f=sum;
		nd[sum].c=nd[sum-1].b;
		i++;

		pp=sum+mp;
		for(j=sum+1;mp && j<pp;j++)
		{
			nd[j].e=j-1;
			nd[j-1].b=j;

			nd[j].d=nd[j-1].c;
			nd[nd[j-1].c].a=j;

			nd[j].c=nd[nd[j-1].c].b;
			nd[nd[nd[j-1].c].b].f=j;
			i++;
		}

		if(mp)
		{
			nd[i].e=i-1;
			nd[i-1].b=i;

			nd[i].d=nd[i-1].c;
			nd[nd[i-1].c].a=i++;
		}

		pp=i+mp;
		for(j=i;mp && j<pp;j++)
		{
			nd[j-1].c=j;
			nd[j].f=j-1;

			nd[j].e=nd[j-1].d;
			nd[nd[j-1].d].b=j;

			nd[j].d=nd[nd[j-1].d].c;
			nd[nd[nd[j-1].d].c].a=j;
			i++;
		}

		nd[i-1].c=i;
		nd[i].f=i-1;

		nd[i].e=nd[i-1].d;
		nd[nd[i-1].d].b=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].a=j-1;
			nd[j-1].d=j;

			nd[j].f=nd[j-1].e;
			nd[nd[j-1].e].c=j;

			nd[j].e=nd[nd[j-1].e].d;
			nd[nd[nd[j-1].e].d].b=j;
			i++;
		}
		nd[i].a=i-1;
		nd[i-1].d=i;

		nd[i].f=nd[i-1].e;
		nd[nd[i-1].e].c=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].b=j-1;
			nd[j-1].e=j;

			nd[j].a=nd[j-1].f;
			nd[nd[j-1].f].d=j;

			nd[j].f=nd[nd[j-1].f].e;
			nd[nd[nd[j-1].f].e].c=j;
			i++;
		}
		nd[i].b=i-1;
		nd[i-1].e=i;

		nd[i].a=nd[i-1].f;
		nd[nd[i-1].f].d=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].c=j-1;
			nd[j-1].f=j;

			nd[j].b=nd[j-1].a;
			nd[nd[j-1].a].e=j;

			nd[j].a=nd[nd[j-1].a].f;
			nd[nd[nd[j-1].a].f].d=j;
			i++;
		}
		nd[i].c=i-1;
		nd[i-1].f=i;

		nd[i].b=nd[i-1].a;
		nd[nd[i-1].a].e=i++;

		pp=i+mp;

		for(j=i;mp && j<pp;j++)
		{
			nd[j].d=j-1;
			nd[j-1].a=j;

			nd[j].c=nd[j-1].b;
			nd[nd[j-1].b].f=j;

			nd[j].b=nd[nd[j-1].b].a;
			nd[nd[nd[j-1].b].a].e=j;
			i++;
		}
		nd[i].d=i-1;
		nd[i-1].a=i;

		nd[i].c=nd[i-1].b;
		nd[nd[i-1].b].f=i;

		nd[i].b=nd[nd[i-1].b].a;
		nd[nd[nd[i-1].b].a].e=i;
	}
}

int main()
{
	make();
	nd[0].a=nd[0].b=nd[0].c=nd[0].d=nd[0].e=nd[0].f=0;
	
	for(i=0;i<1000001;i++)
	vst[i]=1;

	que.push(1);
	vst[1]=0;

	while(!que.empty())
	{
		s=que.front();
		que.pop();

		if(vst[nd[s].a])
		{
			nd[nd[s].a].x=nd[s].x;
			nd[nd[s].a].y=nd[s].y+1;
			que.push(nd[s].a);
			vst[nd[s].a]=0;
		}
		if(vst[nd[s].b])
		{
			nd[nd[s].b].x=nd[s].x-1;
			nd[nd[s].b].y=nd[s].y+1;
			que.push(nd[s].b);
			vst[nd[s].b]=0;
		}
		if(vst[nd[s].c])
		{
			nd[nd[s].c].x=nd[s].x-1;
			nd[nd[s].c].y=nd[s].y;
			que.push(nd[s].c);
			vst[nd[s].c]=0;
		}
		if(vst[nd[s].d])
		{
			nd[nd[s].d].x=nd[s].x;
			nd[nd[s].d].y=nd[s].y-1;
			que.push(nd[s].d);
			vst[nd[s].d]=0;
		}
		if(vst[nd[s].e])
		{
			nd[nd[s].e].x=nd[s].x+1;
			nd[nd[s].e].y=nd[s].y-1;
			que.push(nd[s].e);
			vst[nd[s].e]=0;
		}
		if(vst[nd[s].f])
		{
			nd[nd[s].f].x=nd[s].x+1;
			nd[nd[s].f].y=nd[s].y;
			que.push(nd[s].f);
			vst[nd[s].e]=0;
		}
	}

	while(~scanf("%ld",&i))
		printf("%ld %ld\n",nd[i].x,nd[i].y);

	return 0;
}
