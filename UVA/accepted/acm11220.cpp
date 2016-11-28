#include<stdio.h>
int main()
{
	long p=1,i,j,q,n;
	char st[1000];

	gets(st);
	sscanf(st,"%ld",&n);
	getchar();
	for(p=1;p<=n;p++)
	{

		if(p-1)
			printf("\n");
		printf("Case #%ld:\n",p);

		while(gets(st)&&st[0]!=0)
		{
			i=0;
			printf("%c",st[0]);
			for(j=1;st[i+j]!=' ' && st[i+j]!=0;j++);
			if(st[i+j]==0)
			{
				printf("\n");
				continue;
			}
			q=2;

			i+=j;
			while(i)
			{
				j=1;
				for(j=1;st[i+j]!=' ' && st[i+j]!=0;j++);
				

				if(q<j)
				{
					printf("%c",st[i+q]);
					q++;
				}
				if(st[i+j]==0)
					break;
				i+=j;
			}

			printf("\n");

		}
	}
	return 0;
}