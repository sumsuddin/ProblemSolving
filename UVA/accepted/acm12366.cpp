#include<stdio.h>
#include<algorithm>
using namespace std;
long a[10];
int main()
{
	while(scanf("%ld%ld%ld",&a[0],&a[1],&a[2]) && (a[0]|| a[1]||a[2]))
	{
		sort(a,a+3);
		if(a[0]==a[1] && a[1]==a[2])
		{
			if(a[0]==13)
				printf("*\n");
			else
				printf("%ld %ld %ld\n",a[0]+1,a[0]+1,a[0]+1);
		}
		else
			if(a[0]!=a[1] && a[1]!=a[2])
				printf("1 1 2\n");
		else
			if(a[0]==a[1] || a[1]==a[2])
			{
				if(a[0]==a[1])
				{
					if(a[2]==13)
						printf("%ld %ld %ld\n",1,a[0]+1,a[1]+1);
					else
						printf("%ld %ld %ld\n",a[0],a[1],a[2]+1);
				}
				else
				{
					if(a[1]==a[2])
					{
						if(a[0]+1==a[1])
						{
							if(a[1]==13)
								printf("1 1 1\n");
							else
								printf("%ld %ld %ld\n",a[1],a[2],a[0]+2);
						}
						else
							printf("%ld %ld %ld\n",a[0]+1,a[1],a[2]);
					}
				}
			}
	}
	return 0;
}
