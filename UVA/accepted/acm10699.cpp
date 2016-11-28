#include<stdio.h>
#include<math.h>
int main()
{
	long a,n,i,d,ans,p;
	while(scanf("%ld",&n),n)
	{
		p=n;
		a=(long)sqrt(n)+1;
		i=2;ans=0;
		while(n!=1)
		{
			if(!(n%i))
			{
				if(d!=i)
					ans++;
				n/=i;
				d=i;
			}
			else
				i++;
		}
		printf("%ld : %ld\n",p,ans);
	}
	return 0;
}