#include<stdio.h>
#include<string.h>
int main()
{
	char st[1005];
	long a,i,sum;
	while(gets(st))
	{
		if(st[0]==0)
			continue;
		else if(st[0]=='0')
			break;

		if(strcmp(st,"9")==0)
			printf("9 is a multiple of 9 and has 9-degree 1.\n");
		else
		{
			sum=0;
			for(i=0;st[i];i++)
				sum+=(st[i]-48);

			if(sum%9==0)
			{
				a=0;

				for(i=2;;i++)
				{
					while(sum)
					{
						a+=sum%10;
						sum/=10;
					}
					if(a==9)
					{
						printf("%s is a multiple of 9 and has 9-degree %ld.\n",st,i);
						break;
					}
					sum=a;
					a=0;
				}
			}
			else
				printf("%s is not a multiple of 9.\n",st);
		}
	}
	return 0;
}