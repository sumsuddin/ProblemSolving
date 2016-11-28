#include<stdio.h>
int main()
{
	long int  a,i,n,max,l,p=1;
		
	while(scanf("%ld%ld",&a,&l) && (a>=0 && l>=0))
	{
		max=0;
		n=a;
		for(i=1;a!=0;i++)
		{

			if(a==1)
				break;

	
			if(a%2==1)
			{
				a=3*a+1;
				if(a>l)
					break;
			}
			else
				a=a/2;

		}
		printf("Case %ld: A = %ld, limit = %ld, number of terms = %ld\n",p++,n,l,i);
	}
	return 0;
}