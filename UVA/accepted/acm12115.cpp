#include<stdio.h>
#include<string.h>
long i,j,r1,r2,c1,c2,sl,n,p,q,t,cs=1,cd;
char st[50010];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s%ld",st,&n);
		sl=strlen(st);
		cd=1;

		printf("Square %ld:\n",cs++);

		while(n--)
		{
			scanf("%ld%ld%ld%ld",&r1,&c1,&r2,&c2);
			printf("Query %ld:\n",cd++);

			for(i=r1;i<=r2;i++)
			{
				if(i>sl)
					p=2*sl-i;
				else
					p=i;

				for(j=c1;j<=c2;j++)
				{
					if(j>sl)
						q=2*sl-j;
					else
						q=j;

					if(q>p)
						q=p;

					printf("%c",st[q-1]);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}