#include<stdio.h>
#include<algorithm>
using namespace std;
long cs=1,pr,n,m,st[100],a[10050],b,d,i;
bool flag;
int main()
{
	while(~scanf("%ld%ld",&n,&m) && (n||m))
	{
		for(i=0;i<n;i++)
			scanf("%ld",a+i);

		sort(a,a+n);

		for(i=0;i<70;i++)
			st[i]=0;

		for(i=0;i<m;i++)
			scanf("%ld",&b),st[b]++;

		for(i=n-1;i>=0;i--)
		{
			flag=0;
			if(st[a[i]])
				st[a[i]]--;
			else
			{
				d=flag=1;
				while(flag && d<61)
				{
					if(a[i]+d<61 && st[a[i]+d])
						st[a[i]+d]--,flag=0;
					else if(a[i]-d>1 && st[a[i]-d])
						st[a[i]-d]--,flag=0;
					else
						d++;
				}
				if(flag)
					break;
			}
		}

		if(flag==0)
			printf("Case %ld: 0\n",cs++);
		else
			printf("Case %ld: %ld %ld\n",cs++,i+1,a[0]);
	}
	return 0;
}
