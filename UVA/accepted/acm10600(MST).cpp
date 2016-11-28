#include<stdio.h>
#include<vector>
using namespace std;
vector<long> vc;

long i,a[1000000],p[1000000],q[1000000],w[1000000],rank[1000000],eg,p1,p2,n,sw,t,j,sum,ll,k,mxi,dilam,tot;
bool vst[1000000];

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
		vst[i]=1;
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

		scanf("%ld%ld",&n,&eg);
		init();

		for(i=0;i<eg;i++)
			scanf("%ld%ld%ld",&p[i],&q[i],&w[i]);

		quicksort(w,0,eg-1);

		sum=0;
		for(i=0;i<eg;i++)
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
				sum+=w[i];
				vc.push_back(i);
			}
		}
		printf("%ld ",sum);
		dilam=sum;
		mxi=1000000000;

		ll=vc.size();
		for(k=0;k<ll;k++)
		{
			init();
			sum=tot=0;
			for(i=0;i<eg;i++)
			{
				if(vc[k]==i)
					continue;

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
					sum+=w[i];

					tot++;
				}
			}
			if(sum<mxi && tot==n-1)
				mxi=sum;
		}
		if(mxi==1000000000)
			mxi=dilam;
		printf("%ld\n",mxi);
		vc.clear();
	}
	return 0;
}