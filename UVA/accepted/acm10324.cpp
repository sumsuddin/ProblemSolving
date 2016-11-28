#include<stdio.h>
#define swap(m,n)m^=n^=m^=n
int main()
{
	
//	freopen("d://acm//in//494.in", "r", stdin);
//	freopen("d://acm//out//494.out", "w", stdout);
	long int a,b,p=1,d,n;
	char st[1000005],sy[100];

	while(gets(st))
	{
		if(st[0]==0)
			break;

le:
		gets(sy);
		if(sy[0]==0)
			goto le;
		sscanf(sy,"%ld",&n);
		printf("Case %ld:\n",p++);
		while(n--)
		{
li:
			gets(sy);
			if(sy[0]==0)
				goto li;

			sscanf(sy,"%ld%ld",&a,&b);
			if(a>b)
				swap(a,b);
			d=1;

			for(a;a<=b;a++)
			{
				if(st[a]!=st[b])
				{
					printf("No\n");
					d=0;
					break;
				}
			}
			if(d)
				printf("Yes\n");
		}
	}
	return 0;
}