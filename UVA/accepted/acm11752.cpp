#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;

long i,j,p=1;
unsigned long long a,st[1000000];
bool bu[100000];
map<unsigned long long,bool>mp;

unsigned long long powr(unsigned long long b,unsigned long long p)
{
    if(p==0)
    return 1;
    unsigned long long d=pow(b,p>>1);
    d*=d;
    if(p&1)
    d*=b;
    return d;
}

int main()
{
	bu[0]=1;
	bu[1]=1;
	st[0]=1;

	for(i=4;i<=65536;i+=2)
		bu[i]=1;

	for(i=3;i<=65536;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<=65536;j+=i)
				bu[j]=1;
		}
	}
	for(i=2;i<=65536;i++)
	{
		if(mp[i]==0)
		{
		    a=i;
			for(j=4;j<=63 && ((log((double)a)/log(2.0))+(log((double)i)/log(2.0))+1e-9<64.0);j++)
			{
			    a=powr(i,j);
				if(bu[j])
				{
					if(mp[a]==1)
					continue;

					st[p++]=a;
					mp[a]=1;
				}
			}
		}
	}
	sort(st,st+p);
	for(i=0;i<p;i++)
		printf("%llu\n",st[i]);

	return 0;
}
