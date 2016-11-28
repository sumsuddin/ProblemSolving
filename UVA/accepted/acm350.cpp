#include<stdio.h>
int main()
{
	long int z,i,m,l,ans,j=1,c;
	while(scanf("%ld%ld%ld%ld",&z,&i,&m,&l),z,i,m,l)
	{
		c=l=(z*l+i)%m;
		ans=0;
		do
		{
			ans++;
			l=(z*l+i)%m;
		}while(l!=c);
		printf("Case %ld: %ld\n",j++,ans);

	}
	return 0;
}