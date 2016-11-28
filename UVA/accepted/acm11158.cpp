#include<stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;

long l,r,ans1,ans2,n,a[100],i,t,cs=1;
void calc(long aa, long bb ,long posl, long *sum,int flag)
{
	if(l<r)
	{
		(*sum)=(*sum)+abs(aa-a[posl]);
		aa=a[posl];
	}
	if(flag==1 && l<r)
	{
		l=posl+flag;
		*sum=*sum+abs(bb-a[l]);
		bb=a[l];
		calc(aa,bb,r-=1,sum,-1);
	}
	else if (flag==-1 && l<r)
	{
		r=posl+flag;
		*sum=*sum+abs(bb-a[r]);
		bb=a[r];
		calc(aa,bb,l+=1,sum,1);
	}
}



int main()
{
	scanf("%ld",&t);


	while(t--)
	{
		scanf("%ld",&n);
		ans1=ans2=0;

		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		sort(a,a+n);
		l=0;r=n-1;
		calc(a[0],a[0],r,&ans1,-1);

		l=0;r=n-1;
		calc(a[n-1],a[n-1],l,&ans2,1);

		if(ans1<ans2)
			printf("Case %ld: %ld\n",cs++,ans2);
		else
			printf("Case %ld: %ld\n",cs++,ans1);
	}
	return 0;
}