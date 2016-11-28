#include<stdio.h>
long i,d,c,p,a,b,t;
bool flag;
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&c,&d);

		flag=1;
		for(i=31;i>=0;i--)
			if(((d>>i) &1)!=((c>>i) &1) && ((c>>i) &1))
			{
				flag=0;
				break;
			}
		if(flag)
		{
			p=0;a=b=0;
			for(i=31;i>=0;i--)
				if(((d>>i) &1)!=((c>>i) &1))
				{
					if(p)
					{
						a=a|(1<<i);
					}
					else
					{
						b=b|(1<<i);
					}
					p++;
				}
				else
					a=a|(((d>>i) &1)<<i),b=b|(((d>>i) &1)<<i);

			printf("%ld %ld\n",a,b);
		}
		else
			printf("-1\n");
	}
	return 0;
}