#include<stdio.h>

int main()
{
	long int n,m,a,i,j;
	char st[100005],sy[1005];

	gets(sy);
	sscanf(sy,"%ld",&n);
	while(n--)
	{
		gets(st);
		gets(sy);
		sscanf(sy,"%ld",&m);

		while(m--)
		{
			gets(sy);

			a=j=0;
			for(i=0;st[i];i++)
			{
				if(st[i]==sy[j])
				{
					j++;
					if(sy[j]==0)
					{
						a=1;
						break;
					}
				}
				else
				{
					a=0;
					break;
				}
			}
			if(a)
				printf("y\n");
			else
				printf("n\n");
		}
	}
	return 0;
}
