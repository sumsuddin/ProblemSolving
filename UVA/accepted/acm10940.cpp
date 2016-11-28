#include<stdio.h>
#include<math.h>
long i,n,get,st,d;
int main()
{
	while(scanf("%ld",&n) && n)
	{
		get=i=d=0;
		st=1;

		while(n>1 || (n==1 && d))
		{
			if(get==0)
				st=st+(long)pow(2,i);

			if((get==0 && n%2==0))
				get=0;
			else if(get==1 && n%2)
			{
				get=0;
				n++;
			}
			else
				get=1;
			d=n%2;
			n/=2;
			i++;
		}
	    printf("%ld\n",st);
	}
	return 0;
}