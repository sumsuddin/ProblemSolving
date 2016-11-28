#include<stdio.h>
#include<string.h>
char st[100],str[100];
bool fil[100];
typedef long long lll;
lll i,j,a,div,fact[50],l,t,ind[100],cs=1;
int main()
{
	scanf("%lld",&t);

	fact[0]=1;
	for(i=1;i<22;i++)
		fact[i]=fact[i-1]*i;

	while(t--)
	{
		scanf("%s",st);
		scanf("%lld",&a);

		l=strlen(st);
		for(i=1;i<=l;i++)
			fil[i]=0,ind[i]=i;

		for(i=0;i<l;i++)
		{
			if(a%fact[l-i]==0)
			{
				for(j=1,div=l-1;i<=div;j++)
					str[ind[j]]=st[div--];
				break;
			}
			else
			{
				if(a%fact[l-i-1])
					div=1;
				else
					div=0;
				div+=a/fact[l-i-1];
				fil[ind[div]]=1;
				str[ind[div]]=st[i];
				j=1;
				for(div=1;div<=l;div++)
					if(fil[div]==0)
						ind[j++]=div;
				a%=fact[l-i-1];
			}
		}
		str[l+1]=0;
		strcpy(str,str+1);
		printf("Case %lld: ",cs++);
		puts(str);
	}
	return 0;
}