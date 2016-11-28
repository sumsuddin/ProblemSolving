#include<stdio.h>
long a,n,i,t,mile,juce,cs=1;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		mile=juce=0;
		scanf("%ld",&n);

		for(i=0;i<n;i++)
		{
			scanf("%ld",&a);
			mile+=((a/30+1)*10);
			juce+=((a/60+1)*15);
		}
		if(mile<juce)
			printf("Case %ld: Mile %ld\n",cs++,mile);
		else if(mile>juce)
			printf("Case %ld: Juice %ld\n",cs++,juce);
		else
			printf("Case %ld: Mile Juice %ld\n",cs++,juce);
	}
	return 0;
}