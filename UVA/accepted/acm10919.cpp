#include<stdio.h>
long a,b,sum,m,n,i,j;
bool ind[10050];
int main()
{
	while(scanf("%ld",&n) && n)
	{
		scanf("%ld",&m);

		for(i=0;i<10000;i++)
			ind[i]=0;

		for(i=0;i<n;i++)
			scanf("%ld",&a),ind[a]=1;
		sum=0;
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&n,&a);
			for(j=0;j<n;j++)
				scanf("%ld",&b),a-=ind[b];
			if(a<=0)
				sum++;
		}
		if(sum>=m)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}