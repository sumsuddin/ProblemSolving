#include<stdio.h>
#include<math.h>
typedef long lng;
lng i,l,c[1010],x,sum,j;
char ch;
bool flag;
int main()
{
	while(~scanf("%ld%c",&c[0],&ch))
	{
		i=1;
		if(ch!='\n')
		{
			while(scanf("%ld%c",&c[i++],&ch))
				if(ch=='\n')
					break;
		}
		flag=0;
		while(scanf("%ld%c",&x,&ch))
		{
			sum=0;
			if(flag)
				printf(" ");
			else
				flag=1;
			l=i-1;
			for(j=0;j<i;j++)
				sum+=((lng)(pow(x,l--))*c[j]);
			printf("%ld",sum);
			if(ch=='\n')
				break;
		}
		printf("\n");
	}
	return 0;
}