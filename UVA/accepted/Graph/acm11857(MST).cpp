#include<stdio.h>
long i,a[1000000],p[1000000],q[1000000],w[1000000],rank[1000000],eg,p1,p2,mx,n,sw,m;

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

long parent(long p)
{
	while(a[p]!=p)
		p=a[p];
	return p;
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

int main()
{
	while(scanf("%ld%ld",&n,&eg) && ( n || m))
	{
		init();
		mx=0;

		for(i=0;i<eg;i++)
			scanf("%ld%ld%ld",&p[i],&q[i],&w[i]);

		quicksort(w,0,eg-1);

		for(i=0;i<eg;i++)
		{
			p1=parent(p[i]);
			p2=parent(q[i]);
			if(p1!=p2)
			{
				if(mx<w[i])
					mx=w[i];

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
		eg=0;
		for(i=0;i<n;i++)
			if(parent(i)==i)
			{
				eg++;
				if(eg>=2)
					break;
			}

		if(eg==1)
			printf("%ld\n",mx);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}