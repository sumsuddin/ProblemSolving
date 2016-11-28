#include<stdio.h>
#include<string.h>
long flag,i,j,n,m,mx,cs=1;
char st[50000],sy[300],c;

int main()
{
	while(~scanf("%ld",&n),n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			gets(sy);
			strcat(st,sy);
		}
		mx=strlen(st);
		scanf("%ld",&m);
		getchar();
		flag=0;j=0;
		if(m!=n)
			flag=1;
		for(i=0;i<m;i++)
		{
			while(scanf("%c",&c) && c!=10)
			{
				if(flag<2)
				{
					if(j>=mx)
					{
						if(c>47 && c<58)
							flag=2;
						else
							flag=1;
						continue;
					}

					if(c==st[j])
					{
						j++;
						continue;
					}
					else
						if(c>47 && c<58)
						{
							while(j<mx && (st[j]<48 || st[j]>57))
								j++;
							if(st[j]!=c)
								flag=2;
							else
								flag=1;
							j++;
						}
						else
							if(st[j]>47 && st[j]<58)
							{
								flag=1;
								continue;
							}
							else
								if(c!=st[j])
								{
									j++;
									flag=1;
								}	
				}
			}
		}
		if(j<mx)
		{
			for(j;j<mx;j++)
				if(st[j]>47 && st[j]<58)
				{
					flag=2;
					break;
				}
				else
					flag=1;
		}
		if(flag==0)
			printf("Run #%ld: Accepted\n",cs++);
		else
			if(flag==2)
				printf("Run #%ld: Wrong Answer\n",cs++);
			else
				printf("Run #%ld: Presentation Error\n",cs++);
		st[0]=0;
	}
	return 0;
}