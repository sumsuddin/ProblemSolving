#include<stdio.h>
long a[1010],b[1010],sum,mx,n,i,cs=1,p;

void swap(long *a,long *b)
{
	p=*a;
	*a=*b;
	*b=p;
}

void quicksort( long left, long right)
{
  long pos,l,r;
  l=left;
  r=right;
  pos=left;

	while(l<r)
	  {
		  while(l<r)
		  {
			  if(b[r]>b[pos])
				  r--;
			  else
			  {
				swap(&a[r],&a[pos]);
				swap(&b[r],&b[pos]);
				pos=r;
				break;
			  }
		  }		      
		  while(l<r)
		  {
			  if(b[l]<=b[pos])
				  l++;
			  else
			  {
				swap(&a[l],&a[pos]);
				swap(&b[l],&b[pos]);
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
int main()
{
	while(scanf("%ld",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%ld%ld",&a[i],&b[i]);

		quicksort(0,n-1);

		mx=sum=0;

		while(n--)
		{
			sum+=a[n];
			if(sum+b[n]>mx)
				mx=sum+b[n];
		}
		printf("Case %ld: %ld\n",cs++,mx);
	}
	return 0;
}