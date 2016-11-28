#include<stdio.h>
int main()
{
	char st[1005];
	long i,sum;
	while(gets(st))
	{
		if(st[0]==0)
			printf("\n");
		else
		{
			sum=0;
			for(i=0;st[i];i++)
			{
				if(st[i]>47 && st[i]<58)
					sum+=(st[i]-48);
				else
				{
					if(st[i]=='b')
						st[i]=' ';
					else
						if(st[i]=='!')
						{
							printf("\n");
							continue;
						}

					while(sum--)
						printf("%c",st[i]);
					sum=0;
				}
			}
			printf("\n");
		}
	}
	return 0;
}