#include<stdio.h>
#include<string.h>
#include<math.h>

bool flag;
long i,sum,mx,a,la;
char st[1000010];

int main()
{
	while(gets(st))
	{
		sum=0;
		mx=1;flag=1;
		la=strlen(st);

		for(i=0;i<la;i++)
		{
			if(st[i]>47 && st[i]<58)
				st[i]-=48;
			else
				if(st[i]>64 && st[i]<91)
					st[i]-=55;
				else
					if(st[i]>='a' && st[i]<='z')
						st[i]-=61;
					else
						continue;
				
			sum+=st[i];
				
			if(st[i]>mx)
				mx=st[i];
		}

		while(mx<62)
		{
			if(sum%mx==0)
			{
				printf("%ld\n",mx+1);
				flag=0;
				break;
			}
			else
				mx++;

		}
		if(flag)
			printf("such number is impossible!\n");
	}
	return 0;
}