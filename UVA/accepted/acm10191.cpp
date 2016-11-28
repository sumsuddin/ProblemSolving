#include<stdio.h>
#define swap(m,n)m^=n^=m^=n

long n,h1,h2,m1,m2,t1[200],t2[200],st,max,i,j,cs=1;
char ss[500];

int main()
{
	while(scanf("%ld",&n)==1)
	{
		getchar();
		if(n==0)
		{
			printf("Day #%ld: the longest nap starts at 10:00 and will last for 8 hours and 0 minutes.\n",cs++);
			continue;
		}
		gets(ss);
		sscanf(ss,"%ld:%ld%ld:%ld",&h1,&m1,&h2,&m2);
		t1[0]=h1*60+m1;
		t2[0]=h2*60+m2;

		for(i=1;i<n;i++)
		{
			gets(ss);
			sscanf(ss,"%ld:%ld%ld:%ld",&h1,&m1,&h2,&m2);
			t1[i]=h1*60+m1;
			t2[i]=h2*60+m2;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
				if(t1[i]>t1[j])
				{
					swap(t1[i],t1[j]);
					swap(t2[i],t2[j]);
				}
		}
		max=t1[0]-600;
		st=600;
		i=1;
		for(;i<n;i++)
		{
			if(max<t1[i]-t2[i-1])
			{
				max=t1[i]-t2[i-1];
				st=t2[i-1];
			}
		}
		if(max<1080-t2[i-1])
		{
			max=1080-t2[i-1];
			st=t2[i-1];
		}
		printf("Day #%ld: the longest nap starts at %ld:%02ld and will last for ",cs++,(long)(st/60),(st%60));
		if(max/60)
			printf("%ld hours and ",(long)(max/60));
		printf("%ld minutes.\n",(max%60));
	}
	return 0;
}