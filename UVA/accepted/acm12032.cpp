#include<stdio.h>
long t,n,a,b,d,i,p,q,cs=1,e;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		d=0;
		scanf("%ld",&n);

		scanf("%ld",&q);
		d=q;
		e=q-1;

		for(i=1;i<n;i++)
		{
			scanf("%ld",&p);
			a=p-q;
			if(a>d)
			{
				d=a;
				e=d-1;
			}
			else
				if(a>e)
				{
					d++;
					e=d;
				}
				else
					if(a==e)
						e--;

			q=p;
		}
		printf("Case %ld: %ld\n",cs++,d);
	}
	return 0;
}



/*
#include<stdio.h>
#include<algorithm>
using namespace std;
long t,n,a[100100],d,i,p,q,cs=1;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		d=0;
		scanf("%ld",&n);

		scanf("%ld",&q);
		a[0]=q;

		for(i=1;i<n;i++)
		{
			scanf("%ld",&p);
			a[i]=p-q;
			q=p;
		}

		sort(a,a+n);

		d=a[0];

		for(i=1;i<n;i++)
			if(a[i]==d)
				d++;
			else
				d=a[i];
		printf("Case %ld: %ld\n",cs++,d);
	}
	return 0;
}
*/