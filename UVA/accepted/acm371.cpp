#include<stdio.h>
int main()
{
	long int  a,i,k,n,max,l,num;
		
	while(scanf("%ld%ld",&n,&l)==2 &&(n || l))
	{
		if(l<n)
		{
			a=l;
			l=n;
			n=a;
		}
		max=num=0;
		for(k=n;k<=l;k++)
	
		{
			if(k==0)
				continue;
			a=k;
		
			for(i=0;;i++)
			{
				if(a==1 && i!=0)
					break;
				if(a%2)
					a=3*a+1;
				else
					a/=2;

			}
			
			if(i>max)
			{
				max=i;
				num=k;
			}
		}
			printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",n,l,num,max);
	}
	return 0;
}