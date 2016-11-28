#include<stdio.h>
#include<string.h>
long i,j,k,t,l,cs=1,d;
bool flag;
char st[100050];
int main()
{
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%s",st);
		l=strlen(st)-1;
		st[l]++;
		flag=0;
		while(st[l]>'9')
		{
			st[l]='0';
			if(l)
				st[l-1]++;
			else
				flag=1;
			l--;
		}
		if(flag)
		{
			l=strlen(st);
			st[l+1]=0;
			for(i=l-1;i>=0;i--)
				st[i+1]=st[i];
			st[0]='1';
		}

		for(i=strlen(st)-1,j=0;i>=0;i--,j++)
		{
			d=i;
			while(st[d]>'9')
				st[d]='0',st[--d]++;
			if(i>j)
			{
				if(st[i]>st[j])
					st[i]=st[j],st[i-1]++;
				else 
					st[i]=st[j];
			}
			else if(st[i]>st[j])
				st[j]=st[i];
		}

		printf("Case %ld: %s\n",cs++,st);
	}
	return 0;
}