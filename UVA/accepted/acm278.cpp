#include<stdio.h>
long i,j,r,c,k,ans,n;
char ch,st[50];
int main()
{
	gets(st);
	sscanf(st,"%ld",&n);
	while(n--)
	{
		gets(st);
		sscanf(st,"%c%ld%ld",&ch,&r,&c);
		ans=0;

		if(ch=='Q' || ch=='r')
		{
			if(r<c)
				ans=r;
			else
				ans=c;
		}
		else
			if(ch=='K')
			{
				i=(long)(r/2);
				i+=(r%2);

				j+=(long)(c/2);
				j+=(c%2);
				ans=i*j;
			}
			else
				if(ch=='k')
					ans=(r*c)/2+(r*c)%2;
	printf("%ld\n",ans);
	}
	return 0;
}