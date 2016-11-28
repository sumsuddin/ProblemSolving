#include<stdio.h>

long sw,large,a[100000],w[100000],p[100000],q[100000],i,t,rank[100000],n,edge,ac,p1,p2,sum,ans,cs=1;

void swap(long *m,long *n)
{
	sw=*m;
	*m=*n;
	*n=sw;
}

void init()
{
	for(i=0;i<=n;i++)
	{
		a[i]=i;
		rank[i]=0;
	}
}

void quicksort(long numbers[], long left, long right)
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
			  else
			  {
				swap(&numbers[r],&numbers[pos]);
				swap(&p[r],&p[pos]);
				swap(&q[r],&q[pos]);
				pos=r;
				break;
			  }
		  }		      
		  while(l<r)
		  {
			  if(numbers[l]<=numbers[pos])
				  l++;
			  else
			  {
				swap(&numbers[l],&numbers[pos]);
				swap(&p[l],&p[pos]);
				swap(&q[l],&q[pos]);
				pos=l;
				break;
			  }
		  }	
	  
	  }
	if(left<pos-1)
	  quicksort(numbers,left,pos-1);
	if(pos+1<right)
		quicksort(numbers,pos+1,right);
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
		scanf("%ld%ld%ld",&n,&edge,&ac);

		init();
		sum=ans=0;

		for(i=0;i<edge;i++)
			scanf("%ld%ld%ld",&p[i],&q[i],&w[i]);

		quicksort(w,0,edge-1);

		for(i=0;i<edge;i++)
		{
			p1=parent(p[i]);
			p2=parent(q[i]);
			if(p1!=p2 && w[i]<ac)
			{
				sum+=w[i];
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

		for(i=1;i<=n;i++)
		{
			p1=parent(i);
			if(p1==i)
			{
				sum+=ac;
				ans++;
			}
		}
		printf("Case #%ld: %ld %ld\n",cs++,sum,ans);
	}
	return 0;
}