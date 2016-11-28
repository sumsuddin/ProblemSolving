#include<stdio.h>
#include<algorithm>
#include<math.h>
typedef long long lng;
#define MAX (lng)pow(10,12)
using namespace std;
bool bu[1000050];
lng vc[1000050],ln,i,j,t,l,h,sum,lw,hi;

long bsearch(lng st[],lng n)
{
	lng l=0,u=ln-1;
	while(u>=l)
	{
		i=(u+l)/2;

		if(st[i]==n)
			return i;
		else
			if(st[i]<n)
				l=i+1;	
			else
				if(st[i]>n)
					u=i-1;
	}
	return l;
}

int main()
{
	bu[0]=1;
	bu[1]=1;
	ln=0;

	for(i=4;i<=MAX;i*=2)
		vc[ln++]=i;

	for(i=3;i<1000001;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=i*i;j<=MAX;j*=i)
				vc[ln++]=j;

			for(j=3*i;j<1000001;j+=(2*i))
				bu[j]=1;
		}
	}
	sort(vc,vc+ln);
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&l,&h);
		sum=0;
		lw=bsearch(vc,l);
		hi=bsearch(vc,h);
		while(vc[lw]>l)
			lw--;
		while(vc[lw]<l)
			lw++;

		while(vc[hi]>=h)
			hi--;
		while(vc[hi]<=h)
			hi++;
		printf("%lld\n",hi-lw);
	}
	return 0;
}
