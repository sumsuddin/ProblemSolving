#include<stdio.h>
#include<string.h>

int main()
{
	char st[100],sy[100];
	long int a,b,n,i,k,j,len,ans;

	scanf("%ld ",&n);

	for(i=0;i<n;i++)
	{
		gets(st);

		for(ans=0;;ans++)
		{
			b=0;
			len=strlen(st);

			a=len/2;
			for(j=0,k=len-1;j<=a;j++,k--)
			{
				if(st[j]!=st[k])
				{
					b=1;
					break;
				}
			}

			if(!b)
				break;

			a=0;
			for(j=0,k=len-1;j<len;j++,k--)
			{
				sy[j]=st[j];
				sy[j]+=st[k];
				sy[j]+=a;
				sy[j]-=48;

				if(sy[j]>57)
				{
					sy[j]-=10;
					a=1;
				}
				else
					a=0;
			}
			if(a==1)
			{
				sy[len]='1';
				sy[len+1]=0;
			}
			else
				sy[len]=0;


			len=strlen(sy);

			for(j=0,k=len-1;j<len;j++,k--)
			{
				st[k]=sy[j];
			}
			st[len]=0;
		}
		printf("%ld ",ans);
		puts(st);
	}
	return 0;
}