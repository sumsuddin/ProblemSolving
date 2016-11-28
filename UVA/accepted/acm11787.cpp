#include<stdio.h>
#include<string.h>
char st[500],c;
long value[100],i,j,p,sum,l,n,ans;
bool flag;

int main()
{
	value['B']=1;
	value['U']=10;
	value['S']=100;
	value['P']=1000;
	value['F']=10000;
	value['T']=100000;
	value['M']=1000000;

	gets(st);
	sscanf(st,"%ld",&n);

	while(n--)
	{
		ans=0;
		gets(st);
		l=strlen(st);

		if(value[st[0]]<value[st[l-1]])
		{
			for(i=0,j=l-1;i<l/2;i++,j--)
			{
				c=st[i];
				st[i]=st[j];
				st[j]=c;
			}
		}
		c=st[0];
		sum=p=0;
		flag=0;
		for(i=0;st[i];i++)
		{
			if(st[i]==c)
				sum++;
			else
				if(value[st[i]]<value[c])
				{
					if(sum<10)
					{
						ans+=value[c]*sum;
					    sum=1;
						c=st[i];
					}
					else
					{
						flag=1;
						break;
					}
				}
				else
				{
					flag=1;
					break;
				}
		}
		if(flag)
			printf("error\n");
		else
		{
			if(sum<10)
			{
				ans+=value[c]*sum;
				printf("%ld\n",ans);
			}
			else
				printf("error\n");
		}
	}
	return 0;
}