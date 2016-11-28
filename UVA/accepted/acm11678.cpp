#include<stdio.h>
#include<algorithm>
using namespace std;
long p,q,i,d,n,m,a,st[10005],sy[10005];
int main()
{
	while(scanf("%ld%ld",&m,&n) && (m && n))
	{
		for(i=0;i<m;i++)
			scanf("%ld",&st[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&sy[i]);
		sort(st,st+m);
		sort(sy,sy+n);
		for(i=0,p=0;i<m;i++)
		{
			if(st[p]==st[i])
				;
			else
				st[++p]=st[i];
		}
		for(i=0,q=0;i<n;i++)
		{
			if(sy[q]==sy[i])
				;
			else
				sy[++q]=sy[i];
		}
		p++;q++;
		a=0;
		for(i=0;i<p;i++)
		{
			for(d=0;d<q;d++)
			{
				if(st[i]==sy[d])
				{
					a++;
				}
			}
		}
		if(p>q)
			printf("%ld\n",q-a);
		else
			printf("%ld\n",p-a);
	}
	return 0;
}