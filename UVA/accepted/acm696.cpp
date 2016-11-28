#include<stdio.h>
long sum,r,c,pc,pr;
int main()
{
	while(~scanf("%ld%ld",&r,&c) && (r||c))
	{
		pc=c;
		pr=r;
		sum=0;
		if(r<c)
			r^=c^=r^=c;
		if(c==1)
		{
			sum=r;
		}
		else if(c==2)
		{
			sum=(r/4)*4;
			if(r%4<2)
				sum+=(r%4)*2;
			else
				sum+=4;
		}
		else
		{
			sum=((c/2+c%2)+c/2)*(r/2);
			if(r%2)
				sum+=c/2+c%2;
		}
		printf("%ld knights may be placed on a %ld row %ld column board.\n",sum,pr,pc);
	}
	return 0;
}
