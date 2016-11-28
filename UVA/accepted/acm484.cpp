#include<stdio.h>
#include<string.h>
	
char st[100005][25];

int main()
{
	long i=0,j,k,p=0,sum;

	while(scanf("%s",st[i++])==1);
	i--;
	for(k=0;k<i;k++)
	{
		if(!st[k][0])
			continue;

		sum=0;
		for(j=0;j<i;j++)
			if(!strcmp(st[k],st[j]))
			{
				sum++;
				if(k!=j)
				st[j][0]=0;
			}
		printf("%s %ld\n",st[k],sum);
	}

	return 0;
}