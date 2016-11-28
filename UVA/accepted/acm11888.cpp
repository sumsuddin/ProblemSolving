#include<stdio.h>
#include<string.h>
long i,ll,l,mid,flag,t;
char st[200050];
bool pel(long in,long end)
{
	long i,mid=(in+end)/2;
	for(i=in;i<=mid;i++)
		if(st[i]!=st[end--])
			return 0;
	return 1;
}
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		flag=1;
		scanf("%s",&st);

		ll=strlen(st);
		l=ll/2;

		for(i=0;i<ll-1;i++)
		{
			if(pel(0,i))
			{
				if(pel(i+1,ll-1))
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==0)
			printf("alindrome\n");
		else
		{
			if(pel(0,ll-1))
				printf("palindrome\n");
			else
				printf("simple\n");
		}
	}
	return 0;
}