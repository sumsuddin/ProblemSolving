#include<stdio.h>
#include<math.h>
#include<string.h>
long long i,j,k,l,flag,ret,mxa,mxb;
char st[100],sy[100],sl[100],c;
long long base(char st[],long long bs)
{
	ret=0;
	strcpy(sl,st);
	for(k=0,l=strlen(sl)-1;k<l;k++,l--)
	{
		c=sl[k];
		sl[k]=sl[l];
		sl[l]=c;
	}
	for(k=0;sl[k];k++)
		ret+=((sl[k]>='A')?sl[k]-'A'+10:sl[k]-'0')*(long long)pow(bs,k);
	return ret;
}

int main()
{
	while(~scanf("%s%s",st,sy))
	{
		mxa=mxb=1;
		for(k=0;st[k];k++)
			if(((st[k]>='A')?st[k]-'A'+10:st[k]-'0')>mxa)
				mxa=((st[k]>='A')?st[k]-'A'+10:st[k]-'0');

		for(k=0;sy[k];k++)
			if(((sy[k]>='A')?sy[k]-'A'+10:sy[k]-'0')>mxb)
				mxb=((sy[k]>='A')?sy[k]-'A'+10:sy[k]-'0');

		flag=1;
		for(i=mxa+1;i<37 && flag;i++)
		{
			for(j=mxb+1;j<37;j++)
			{
				if(base(st,i)==base(sy,j))
				{
					printf("%s (base %lld) = %s (base %lld)\n",st,i,sy,j);
					flag=0;
					break;
				}
			}
		}
		if(flag)
			printf("%s is not equal to %s in any base 2..36\n",st,sy);
	}
	return 0;
}
