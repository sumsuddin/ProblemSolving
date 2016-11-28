#include<stdio.h>
int main()
{
	int a,b,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d:%d",&a,&b);
		if(a==12 &&b==0)
			printf("%02ld:%02ld\n",a,b);
		else
		{
			a=23-a;

			if(!b)
				a++;
			else
				b=60-b;
			if(a>12)
				a-=12;
		printf("%02ld:%02ld\n",a,b);
		}
	}
	return 0;
}