#include<stdio.h>
#include<string.h>
#define swap(m,n) m^=n^=m^=n
int main()
{
	char st[1000];
	long i,j,n,m,la;

	while(gets(st))
	{
		for(i=0;st[i];i++)
		{
			for(j=i+1;st[j];j++)
			{
				if(st[i]<st[j])
					swap(st[i],st[j]);
			}

		}
		n=0;
		for(i=0;st[i];i++)
			n=10*n+(st[i]-48);
		la=strlen(st);
		for(i=0,j=la-1;i<la/2;i++,j--)
			swap(st[i],st[j]);


		if(st[0]=='0')
		{
			for(j=0;st[j];j++)
				if(st[j]!='0')
				{
					swap(st[0],st[j]);
					break;
				}
		}
		m=0;
		for(i=0;st[i];i++)
			m=10*m+(st[i]-48);

		la=n-m;
		i=la/9;

		printf("%ld - %ld = %ld = 9 * %ld\n",n,m,la,i);
	}

	return 0;
}