#include<stdio.h>
#include<math.h>
#include<string.h>
char st[100],get[1000];
long long a[10],t,cs=1,i,j,l;
bool flag;
long long create(char st[100])
{
	long long i,sum,j;
	for(i=0,sum=0,j=strlen(st)-1;st[i];i++,j--)
		sum+=(st[i]-'0')*(long long)pow(2,j);
	return sum;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld.%lld.%lld.%lld",&a[0],&a[1],&a[2],&a[3]);

		scanf("%s",get);

		flag=1;
		for(i=0,j=0,l=0;;i++)
			if(get[i]=='.' || get[i]==0)
			{
				st[j]=0;
				if(a[l]!=create(st))
				{
					flag=0;
					break;
				}
				else
				{
					l++;
					j=0;
				}
				if(get[i]==0)
					break;
			}
			else
				st[j++]=get[i];


		if(flag)
			printf("Case %lld: Yes\n",cs++);
		else
			printf("Case %lld: No\n",cs++);
	}
	return 0;
}