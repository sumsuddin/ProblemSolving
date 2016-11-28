#include<stdio.h>
#include<algorithm>
using namespace std;
long i,a[5010],n,mn,sum,s;

void minheap(long i,long n)
{
	mn=i;
	if(i*2<=n && a[i*2]<a[mn])
		mn=i*2;
	if(i*2+1<=n && a[i*2+1]<a[mn])
		mn=i*2+1;

	if(mn!=i)
	{
		swap(a[i],a[mn]);
		minheap(mn,n);
	}
}

int main()
{
 	while(scanf("%ld",&n),n)
 	{
		for(i=1;i<=n;i++)
		   scanf("%ld",&a[i]);
		
		for(i=n/2;i>0;i--)
             minheap(i,n);
        sum=0;
        while(n>1)
        {
		    swap(a[1],a[n]);
		    minheap(1,n-1);
		    s=a[n--]+a[1];
		    
		    a[1]=s;
		    minheap(1,n-1);	
			sum+=s;	    
		}
		printf("%ld\n",sum);	    
    }
    return 0;
}
