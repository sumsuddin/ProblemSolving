#include<stdio.h>
#include<string.h>

long i,j,k,n,p,la,lb;
char st[400],sy[200][400],sr[200][400],ss[400];
bool flag;

void replace()
{
	for(k=0;k<j;k++)
		ss[k]=st[k];
	la=k+p;
	for(lb=0;sr[i][lb];lb++)
		ss[k++]=sr[i][lb];

	while(st[la])
		ss[k++]=st[la++];
	ss[k]=0;
	strcpy(st,ss);
}

int main()
{
	while(gets(st))
	{
		sscanf(st,"%ld",&n);
		if(n==0)
			break;

		for(i=0;i<n;i++)
		{
			gets(sy[i]);
			gets(sr[i]);
		}
		gets(st);

		for(i=0;i<n;i++)
		{
			flag=1;
			while(flag)
			{
				flag=0;
				for(j=0;st[j];j++)
				{
					p=0;
					while(st[j+p]==sy[i][p] )
					{
						p++;
						if(sy[i][p]==0)
						{
							flag=1;
							
							replace();
							j=0;
							break;
						}
					}
				}
			}
		}
		puts(st);
	}
	return 0;
}