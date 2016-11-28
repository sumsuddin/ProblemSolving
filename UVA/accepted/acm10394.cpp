#include<stdio.h>
bool bu[20000000];
int main()
{
	long n,i,j;
	int st[100001];

	bu[0]=1;
	bu[1]=1;

	for(i=4;i<20000000;i+=2)
		bu[i]=1;

	for(i=3;i<20000000;i+=2)
	{
		if(bu[i]==0)
		{
			for(j=2*i;j<20000000;j+=i)
				bu[j]=1;
		}
	}

	n=1;
	for(i=3;n<100001;i+=2)
	{
		if(bu[i]==0 && bu[i+2]==0)
			st[n++]=i;
	}

	while(scanf("%ld",&n)==1)
		printf("(%ld, %ld)\n",st[n],st[n]+2);

	return 0;
}