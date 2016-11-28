#include<stdio.h>
#include<set>
using namespace std;
set<long long>sst;
set<long long>::iterator it;

long long lim=10000000000LL,i,a,b,t,lst,array[300000],l,h,mid,x,y,fac[20000],cs=1;

long long src(long long p)
{
    l=0;h=lst-1;
    while(l<h)
    {
        mid=(l+h)/2;
        if(array[mid]==p)
            return mid;
        else if(array[mid]<p)
            l=mid+1;
        else
            h=mid-1;
    }
    return (l+h)/2+1;
}

void Ext(long long a, long long b)
{
    long long x1;
    if(b>a)
    {
        x1=a;
        a=b;
        b=x1;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    Ext(b,a%b);
    x1 = x-(a/b) * y;
    x = y;
    y = x1;
}

int main()
{
    fac[0]=1;
    for(i=1;i<20000;i++)
        fac[i]=(fac[i-1]*i)%100000007;
	for(i=2;i<100001;i++)
	{
		a=i;
		while(a*i<=lim)
		{
			a*=i;
			sst.insert(a);
		}
	}
	
	array[0]=0;
	lst=1;
	for(it=sst.begin();it!=sst.end();it++)
	    array[lst++]=*it;
	array[lst]=lim+1;
	
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		
		i=src(a-1);
		while(array[i]>=a && i)
		  i--;
		a=i;
		i=src(b);
		while(array[i]>b && i)
		  i--;
        b=i-a;
        
        if(b)
        {
            a=(fac[b]*fac[b+1])%100000007;
            Ext(a,100000007);
            b=(fac[2*b]*y)%100000007;
            if(b<0)
                b+=100000007;
        }
        
        printf("Case %lld: %lld\n",cs++,b);
	}
	return 0;
}
