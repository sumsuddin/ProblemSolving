#include<stdio.h>
long i,fb[100],t,n,lst,mx,cs=1;

long maxv (long a,long b)
{
	return a>b?a:b;
}

bool bu[100];
void call(long n)
{
	i=0;
	while(fb[i+1]<=n)
		i++;
	mx=maxv(mx,i);
	bu[i]=1;
	if(n>fb[i])
		call(n-fb[i]);
}

int main()
{
	fb[0]=0;
	fb[1]=1;
	fb[2]=2;
	lst=45;
	for(i=3;i<lst;i++)
		fb[i]=fb[i-1]+fb[i-2];

	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<50;i++)
			bu[i]=0;
		call(n);
		printf("Case %ld: ",cs++);
		while(mx)
		{
			printf("%d",bu[mx--]);
			if(mx==0)
				break;
		}
		printf("\n");
	}
	return 0;
}
