#include<stdio.h>
#include<string.h>
char st[150],sy[150];
long pr[15],b,ex,i,ans;

long bg(char a[],long b)
{
	long i,ex;
	for(i=0,ex=0;a[i];i++)
	{
		ex=ex*10+(a[i]-48);
		a[i]=ex/ b+'0';
		ex=ex%b;
	}
	return ex;
}

int main()
{
	pr[0]=pr[1]=pr[5]=pr[6]=1;
	pr[2]=pr[3]=pr[7]=pr[8]=4;
	pr[4]=pr[9]=2;

	while(~scanf("%s%s",st,sy) && !(st[0]=='0' && sy[0]=='0'))
	{
		b=st[strlen(st)-1]-'0';

		if(strcmp(sy,"0")==0)
		{
			printf("1\n");
			continue;
		}
		if(pr[b]==1)
		{
			printf("%ld\n",b);
			continue;
		}

		ex=bg(sy,pr[b]);
		if(ex==0)
			ex=pr[b];
		ans=1;
		for(i=1;i<=ex;i++)
			ans*=b;
		printf("%ld\n",ans%10);
	}
	return 0;
}