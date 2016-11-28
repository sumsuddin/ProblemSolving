#include<stdio.h>
#define swap(m,n) m^=n^=m^=n
bool gt(long a,long b,bool pn)
{
	bool flag,flaf;
	if(a<b)
		swap(a,b);

	if(b==0)
		return !pn;
	else
	{
		flag=gt(b,a%b,!pn);
		if((a%b)+b<a && (a%b)!=0)
		{
			flaf=!flag;
			if(pn)
				return flag||flaf;
			else
				return (flag&&flaf);
		}
		else
			return flag;
	}
}

int main()
{
	long a,b;
	while(scanf("%ld%ld",&a,&b)&& (a||b))
	{
		if(gt(a,b,1))
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}