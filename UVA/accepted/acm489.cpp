#include<stdio.h>
#include<string.h>
long i,bu[150],cu[150],cs,ans,flag;
char st[100000];
int main()
{
	while(~scanf("%ld",&cs) && cs>=0)
	{
		for(i=97;i<123;i++)
			bu[i]=0,cu[i]=1;

		scanf("%s",st);
		for(i=0;st[i];i++)
			bu[st[i]]=1;

		scanf("%s",st);

		flag=1;
		ans=0;
		for(i=0;st[i];i++)
		{
			if(cu[st[i]])
			{
				cu[st[i]]=0;
				if(bu[st[i]])
					bu[st[i]]=0;
				else
					ans++;

			}
			if(ans>6)
			{
				flag=0;
				break;
			}
		}
		ans=0;
		for(i=97;i<123;i++)
			ans+=bu[i];
		if(ans==0)
			printf("Round %ld\nYou win.\n",cs);

		else if(flag==0)
			printf("Round %ld\nYou lose.\n",cs);
		else
			printf("Round %ld\nYou chickened out.\n",cs);
			
	}
	return 0;
}
