#include<stdio.h>
#include<math.h>
struct 
{
	long p,q;
	double dis;
}st[1000500];

struct
{
	long p,q;
}nd[1010];

long x,y,n,i,j,pos,l,a[1010],rank[1010],m,p1,p2,ram[1010][1010],t,ne,number,cs=1;
double road,train;

void quicksort(long left, long right)
{
  long pos,l,r;
  l=left;
  r=right;
  pos=left;

	while(l<r)
	  {
		  while(l<r)
		  {
			  if(st[r].dis>st[pos].dis)
				  r--;
			  else
			  {
				  st[1000005]=st[r];
				  st[r]=st[pos];
				  st[pos]=st[1000005];
				  pos=r;
				  break;
			  }
		  }		      
		  while(l<r)
		  {
			  if(st[l].dis<=st[pos].dis)
				  l++;
			  else
			  {
				  st[1000005]=st[l];
				  st[l]=st[pos];
				  st[pos]=st[1000005];
				pos=l;
				break;
			  }
		  }	  
	  }
	if(left<pos-1)
	  quicksort(left,pos-1);
	if(pos+1<right)
		quicksort(pos+1,right);
}

void init()
{
	for(i=0;i<=n;i++)
	{
		a[i]=i;
		rank[i]=0;
	}
}

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&ne);
		init();

		for(i=0;i<n;i++)
			scanf("%ld%ld",&nd[i].p,&nd[i].q);

		i=0;

		for(x=0;x<n;x++)
			for(y=x+1;y<n;y++)
			{
				st[i].dis=sqrt((nd[x].p-nd[y].p)*(nd[x].p-nd[y].p)+(nd[x].q-nd[y].q)*(nd[x].q-nd[y].q));
				st[i].p=x;
				st[i++].q=y;
			}

		quicksort(0,i-1);

		number=1;
		train=road=0;

		for(x=0;x<i;x++)
		{
			p1=parent(st[x].p);
			p2=parent(st[x].q);
			if(p1!=p2)
			{
				if(st[x].dis>=0)
				{
					if(rank[p1]>rank[p2])
					{
						a[p2]=p1;
						rank[p1]++;

					}
					else
					{
						a[p1]=p2;
						rank[p2]++;
					}
					if(st[x].dis>ne)
					{
						number++;
						train+=st[x].dis;
					}
					else
						road+=st[x].dis;

				}
			}
		}
		printf("Case #%ld: %ld %.0lf %.0lf\n",cs++,number,road,train);
	}
	return 0;
}