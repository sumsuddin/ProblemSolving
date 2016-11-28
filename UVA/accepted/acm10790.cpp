#include<stdio.h>
long i,n,m,st[30005];
int main()
{
	st[1]=0;
	for(i=0;i<20001;i++)
	{
		st[i+2]=(long)((double)(i+1)*(double)(i+2)*.5);
	}
	i=1;
	while(scanf("%ld%ld",&n,&m) && (m || n))
	{
		printf("Case %ld: %ld\n",i++,st[n]*st[m]);
	}

	return 0;
}