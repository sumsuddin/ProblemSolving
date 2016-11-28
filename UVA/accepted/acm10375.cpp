#include<stdio.h>
#include<algorithm>
using namespace std;

long aa[10010],bb[10010],a[10],b[10],sw,sr;
long i,j,p,q,r,s;
long double ans;

void swap(long *a,long *b)
{
	sw=*a;
	*a=*b;
	*b=sw;
}

int main()
{
	while(~scanf("%ld%ld%ld%ld",&p,&q,&r,&s))
	{
		a[0]=p;
		a[1]=s;
		a[2]=r-s;
		b[0]=q;
		b[1]=p-q;
		b[2]=r;

		for(i=0;i<3;i++)
			for(j=i+1;j<3;j++)
				if(a[i]<a[j])
					swap(&a[i],&a[j]);

		for(i=0;i<3;i++)
			for(j=i+1;j<3;j++)
				if(b[i]<b[j])
					swap(&b[i],&b[j]);
		p=q=0;
		ans=1;

		for(i=0;i<3;i++)
		{
			if(a[i]>b[i])
			{
				for(j=b[i]+1;j<=a[i];j++)
					aa[p++]=j;
			}
			else if(a[i]<b[i])
			{
				for(j=a[i]+1;j<=b[i];j++)
					bb[q++]=j;
			}
		}
		sort(aa,aa+p);
		sort(bb,bb+q);
		for(i=0;i<p && i<q;i++)
		{
			if(aa[i]==0)
				aa[i]=1;
			if(bb[i]==0)
				bb[i]=1;

			ans*=(long double)aa[i]/(long double)bb[i];
		}
		while(i<p)
			ans*=(long double)aa[i++];
		while(i<q)
			ans/=(long double)bb[i++];
		printf("%.5llf\n",ans);
	}
	return 0;
}