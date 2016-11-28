#include<stdio.h>
#include<math.h>
#define swap(m,n) m^=n^=m^=n
struct 
{
	long p,q;
	double dis;
}st[1000000];

struct
{
	long p,q;
}nd[1000];

long x,y,n,i,j,pos,l,a[1000],rank[1000],m,p1,p2,ram[1000][1000],t,xx[100],yy[100];
bool flag;

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
				  st[900000]=st[r];
				  st[r]=st[pos];
				  st[pos]=st[900000];
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
				  st[900000]=st[l];
				  st[l]=st[pos];
				  st[pos]=st[900000];
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

void qsort(long numbers[], long left, long right)
{
  long pos,l,r;
  l=left;
  r=right;
  pos=left;

	while(l<r)
	  {
		  while(l<r)
		  {
			  if(numbers[r]>numbers[pos])
				  r--;
			  else if(numbers[r]<numbers[pos] || (numbers[r]==numbers[pos] && yy[l]<yy[pos]))
			  {
				swap(numbers[r],numbers[pos]);
				swap(yy[r],yy[pos]);
				pos=r;
				break;
			  }
			  else
				  r--;
		  }		      
		  while(l<r)
		  {
			  if(numbers[l]<numbers[pos])
				  l++;			
			  else if(numbers[l]>numbers[pos] || (numbers[l]==numbers[pos] && yy[l]>yy[pos]))
			  {
				swap(numbers[l],numbers[pos]);
				swap(yy[l],yy[pos]);
				pos=l;
				break;
			  }
			  else
				  l++;
		  }	
	  
	  }
	if(left<pos-1)
	  qsort(numbers,left,pos-1);
	if(pos+1<right)
		qsort(numbers,pos+1,right);
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
		scanf("%ld",&n);
		init();

		for(i=0;i<n;i++)
			scanf("%ld%ld",&nd[i].p,&nd[i].q);

		i=0;

		for(x=0;x<n;x++)
			for(y=x+1;y<n;y++)
			{
				st[i].dis=sqrt((nd[x].p-nd[y].p)*(nd[x].p-nd[y].p)+(nd[x].q-nd[y].q)*(nd[x].q-nd[y].q));
				st[i].p=x;
				st[i].q=y;
				ram[x][y]=i++;
			}

		scanf("%ld",&m);

		while(m--)
		{
			scanf("%ld%ld",&x,&y);

			x--,y--;

			if(x>y)
			{
				pos=x;
				x=y;
				y=pos;
			}

			p1=parent(x);
			p2=parent(y);
			if(p1!=p2)
			{
				st[ram[x][y]].dis=-5;
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
			}
		}
		quicksort(0,i-1);

		pos=0;

		flag=1;

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
					xx[pos]=st[x].p+1;
					yy[pos++]=st[x].q+1;
					flag=0;
				}
			}
		}

		if(flag)
			printf("No new highways need\n");
		else
		{
			qsort(xx,0,pos-1);
			p1=-5;
			for(i=0;i<pos;i++)
			{
				if(xx[i]==p1)
				{
					swap(xx[i],yy[i]);
					flag=1;
				}
				p1=xx[i];
			}
			if(flag)
				qsort(xx,0,pos-1);

			for(i=0;i<pos;i++)
				printf("%ld %ld\n",xx[i],yy[i]);
		}
		
		if(t)
			printf("\n");
	}
	return 0;
}