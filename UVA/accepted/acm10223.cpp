#include<stdio.h>
typedef long long lng;
lng i,num[50],j;
int main()
{
	num[0]=num[1]=1;
	for(i=2;i<21;i++)
	{
		for(j=i-1;j>=i/2;j--)
		{
			num[i]+=(num[j]*num[i-j-1]*2);
		}
		if(i%2)
			num[i]-=(num[i/2]*num[i/2]);
	}
	num[0]=0;
	while(scanf("%lld",&j)==1)
	{
        for(i=0;i<21;i++)
            if(num[i]>=j)
            break;
           printf("%lld\n",i);
    }
	return 0;
}
