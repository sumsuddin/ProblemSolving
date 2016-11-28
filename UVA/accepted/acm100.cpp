#include<stdio.h>
int main()
{
	long int  a,i,k,n,max,l,p,q;
		
	while(scanf("%ld%ld",&n,&l)==2)
	{
		max=0;
		if(n>l)
		{
			p=l;
			q=n;
		}
		else
		{
			p=n;
			q=l;
		}
		for(k=p;k<=q;k++)
	
		{	a=k;
								
			for(i=1;a!=0;i++)
			{

				if(a==1)
					break;

	
				if(a%2==1)
					a=3*a+1;
				else
					a=a/2;

			}
			
			if(i>max)
				max=i;
		}
			printf("%ld %ld %ld\n",n,l,max);
	}
	return 0;
}