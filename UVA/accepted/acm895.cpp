#include<stdio.h>
long i,j,n,sum,ss[130],sm[1010][130];
char st[1010][130],sy[130];
bool cmp()
{
	for(j='a';j<='z';j++)
		if(ss[j]<sm[i][j])
			return 0;

	return 1;
}
int main()
{
	while(gets(st[i]) && st[i][0]!='#')
	{
		for(j=0;st[i][j];j++)
			sm[i][st[i][j]]++;
		i++;
	}
	n=i;

	while(gets(sy) && sy[0]!='#')
	{
		sum=0;
		for(i='a';i<='z';i++)
			ss[i]=0;
		for(i=0;sy[i];i++)
			if(sy[i]>='a' && sy[i]<='z')
				ss[sy[i]]++;
		for(i=0;i<n;i++)
			if(cmp())
				sum++;
		printf("%ld\n",sum);
	}
	return 0;
}