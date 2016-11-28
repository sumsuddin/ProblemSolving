#include<stdio.h>
#include<math.h>
long i,j,dist[1050][1050],wt[1050][1050],large,hp,p,t,q,x,y,r,c,eg;
bool vst[1050][1050];
int h[]={0,0,1,-1},v[]={1,-1,0,0};
struct 
{
	long cost,ndx,ndy;
}
node[1000050],sw;

void minheap(long i,long n)
{
	large=i;
	if(i*2<=n && node[i*2].cost<node[large].cost)
		large=i*2;
	if(i*2+1<=n && node[i*2+1].cost<node[large].cost)
		large=i*2+1;

	if(large!=i)
	{
        sw=node[i];
        node[i]=node[large];
        node[large]=sw;
		minheap(large,n);
	}
}

void dijk()
{
	hp=1;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			vst[i][j]=1,dist[i][j]=(long)pow(10,9);

	dist[0][0]=node[0].cost=wt[0][0];
	node[hp].cost=wt[0][0];
	node[hp].ndx=0;
	node[hp].ndy=0;

	minheap(1,hp++);
	while(hp>1)
	{
		p=node[1].ndx;
		q=node[1].ndy;
		vst[p][q]=0;
		node[0]=node[1];

		node[1]=node[--hp];

		minheap(1,hp-1);

		for(j=0;j<4;j++)
		{
			x=p+h[j];
			y=q+v[j];
			if(x<r && x>=0 && y<c && y>=0 && node[0].cost+wt[x][y]<dist[x][y])
			{
				dist[x][y]=node[0].cost+wt[x][y];
				if(vst[x][y])
				{
					node[hp].cost=dist[x][y];
					node[hp].ndx=x;
					node[hp].ndy=y;
					eg=hp++;					
					while(eg>1 && node[eg/2].cost>node[eg].cost)
					{
						sw=node[eg];
						node[eg]=node[eg/2];
						node[eg/2]=sw;
						eg/=2;
					}
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
			for(j=0;j<c;j++)
				scanf("%ld",&wt[i][j]);
		}

		dijk();
		printf("%ld\n",dist[r-1][c-1]);
	}
	return 0;
}
