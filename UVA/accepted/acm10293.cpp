#include<stdio.h>
#include<string.h>
long i,sum,la,leng[50];
char st[100];

int main()
{
	while(gets(st))
	{
		if(st[0]=='#')
		{
			for(i=1;i<31;i++)
			{
				if(leng[i])
					printf("%ld %ld\n",i,leng[i]);
				leng[i]=0;
			}
			printf("\n");
		}
		else
		{
			la=strlen(st)+1;

			for(i=0;i<la;i++)
			{
				if((st[i]>64 && st[i]<91) || (st[i]>96 && st[i]<123))
					sum++;
				else 
					if(st[i]=='-')
					{
						if(st[i+1]==0)
							i++;
					}
					else
						if(st[i]=='\'')
							continue;
						else
						{
							leng[sum]++;
							sum=0;
						}
			}
		}
	}
	return 0;
}