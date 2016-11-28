#include<stdio.h>
#include<algorithm>
using namespace std;
long i,j,a[100000],b[100000],sec,p,q;
char c;

int main()
{
	while(~scanf("%ld",&a[0]))
	{
		i=1;
		scanf("%c",&c);
		if(c!='\n')
			while(scanf("%ld%c",&a[i++],&c) && c!='\n');

		j=0;
		while(scanf("%ld%c",&b[j++],&c) && c!='\n');

		sort(a,a+i);
		sort(b,b+j);

		p=q=sec=0;

		while(p<i && q<j)
		{
			if(a[p]==b[q])
			{
				p++;
				q++;
				sec++;
			}
			else
				if(a[p]>b[q])
					q++;
				else
					p++;
		}
		if(sec==i && sec==j)
			printf("A equals B\n");
		else
			if(sec==i)
				printf("A is a proper subset of B\n");
			else
				if(sec==j)
					printf("B is a proper subset of A\n");
				else
					if(sec==0)
						printf("A and B are disjoint\n");
					else
						printf("I'm confused!\n");
	}
	return 0;
}