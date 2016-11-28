#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
using namespace std;
map<string,long>mp;
long i,n,t,a[20],vm;
char st[300],ss[300];
bool fl;
void rec(long p,long vs,long in)
{
	if(p>t)
		return;
	long i;

	bool flag;
	if(p==t)
	{
		st[0]=0;
		ss[0]=0;

		flag=0;
		for(i=0;i<n;i++)
			if((vs>>i) & 1)
			{
				if(flag)
					sprintf(st,"+%ld",a[i]),strcat(ss,st);
				else
				{
					sprintf(st,"%ld",a[i]),strcat(ss,st);
					flag=1;
				}
			}
		if(mp[ss]==0)
			printf("%s\n",ss),mp[ss]=1,fl=0;
	}

	for(i=in;i<n;i++)
		if((vs>>i & 1)==0)
			rec(p+a[i],vs|(1<<i),i);
}

int main()
{
	long z;
	while(scanf("%ld%ld",&t,&n) && (t|| n))
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]),a[i]=-a[i];

		sort(a,a+n);
		vm=z=0;
		for(i=0;i<n;i++)
		{
			a[i]=-a[i];
			if(a[i]==0)
				z++;
		}
		
		fl=1;
		printf("Sums of %ld:\n",t);
		for(i=0;i<n;i++)
			rec(a[i],1<<i,i);

		if(fl)
			printf("NONE\n");
		mp.clear();

	}
	return 0;
}