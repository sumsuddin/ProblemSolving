#include<stdio.h>
#include<set>
using namespace std;
set<long long>sat;
set<long long>::iterator it,jt;
long long b,d,array[1000000],lim=1000000000000LL;
long long i,j,t,lst,cs=1;
void gen(long long a)
{
    if(a<=lim)
    {
        sat.insert(a);
        gen(a*10+4);
        gen(a*10+7);
    }
}

long long src(long long p)
{
    long long l,h,mid;
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

int main()
{
    long long l,h;
	gen(4);
	gen(7);
	
	for(it=sat.begin();*it<=1000000;it++)
	{
            for(jt=sat.begin();jt!=sat.end();jt++)
            {
                if(*jt**it>lim)
                    break;
                sat.insert(*jt**it);
            }
    }
    
    array[0]=-1;
    lst=1;
    for(it=sat.begin();it!=sat.end();it++)
        array[lst++]=*it;
    array[lst]=10000000000000000LL;

	scanf("%lld",&t);

	while(t--)
	{
        scanf("%lld%lld",&l,&h);
		i=src(l);
		while(array[i]>=l && i)
		  i--;
		b=i;
		i=src(h);
		while(array[i]>h && i)
		  i--;
        b=i-b;
        printf("Case %lld: %lld\n",cs++,b);
	}
	return 0;
}
