#include<stdio.h>
long i,a[1000000],p[1000000],q[1000000],w[1000000],rank[1000000],eg,p1,p2,mx,n,sw,t,j,cs=1;

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
	scanf("%ld",&t);
	while(t--)
	{

		scanf("%ld",&n);
		init();
		eg=0;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%ld%*c",&sw);
				if(sw)
				{
					p[eg]=i;q[eg]=j;
					w[eg++]=sw;
				}
				
			}

		quicksort(w,0,eg-1);
		printf("Case %ld:\n",cs++);

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
				if(p[i]>q[i])
					swap(&p[i],&q[i]);
				printf("%c-%c %ld\n",p[i]+65,q[i]+65,w[i]);
			}
		}
	}
	return 0;
}