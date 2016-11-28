#include<stdio.h>

long sw,a[100000],w[100000],p[100000],q[100000],i,rank[100000],n,edge,p1,p2,flag;

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
	while(scanf("%ld%ld",&n,&edge),(n || edge))
	{
		init();
		flag=1;

		for(i=0;i<edge;i++)
			scanf("%ld%ld%ld",&p[i],&q[i],&w[i]);

		quicksort(w,0,edge-1);

		for(i=0;i<edge;i++)
		{
			p1=parent(p[i]);
			p2=parent(q[i]);
			if(p1!=p2)
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
			}
			else
			{
				if(flag==0)
					printf(" %ld",w[i]);
				else
				{
					flag=0;
					printf("%ld",w[i]);
				}
			}

		}
		if(flag)
			printf("forest\n");
		else
			printf("\n");
	}
	return 0;
}