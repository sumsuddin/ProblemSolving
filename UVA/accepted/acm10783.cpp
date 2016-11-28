#include<stdio.h>
int main()
{
	int a,b,n,i,ans;

	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{

		scanf("%d%d",&a,&b);
		if(!(a%2))
			a++;
		if(!(b%2))
			b--;
		
		a=(a-1)/2;
		b=(b+1)/2;
		ans=b*b-a*a;
		printf("Case %d: %d\n",i,ans);

	}
	return 0;
}