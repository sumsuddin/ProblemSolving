#include<stdio.h>
#include<math.h>
typedef long long lng;
lng x,y,n;
lng fn(lng d)
{
	if(d==0)
		return 0;
	else if(d==1)
		return 1;
	else if(d==2)
	    return 2;
	else if(d==3)
		return 3;

	lng n=(((lng)sqrt(4*d + 1))-1)/2,i;
	for(i=n-1;i<n+2;i++)
	{
		if(((i+1)*(i+2))>d)
			break;
	}
	if(d-(i*(i+1))>i+1)
		return i*2+2;
	else if(d-(i*(i+1))==0)
		return i*2;
	else
		return i*2+1;

}

int main()
{
	scanf("%lld",&n);

	while(n--)
	{
		scanf("%lld%ld",&x,&y);
		printf("%lld\n",fn((x-y)<0?y-x:x-y));
	}
	return 0;
}
