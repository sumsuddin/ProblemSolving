#include<stdio.h>
#include<math.h>
long i,n,ng,sq,a,prm[100050],last,v,j;
bool bu[100050];
int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<100000;i+=2)
		bu[i]=1;
	prm[0]=2;last=1;
	for(i=3;i<100000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[last++]=i;
			for(j=2*i;j<100000;j+=i)
				bu[j]=1;
		}
	}


	while(scanf("%ld",&n),n)
	{
		a=n;

		sq=(long)sqrt(a);

		ng=0;

		for(i=0;prm[i]<=sq && i<last;i++)
		{
			if(a%prm[i]==0)
			{
				v=(a-ng)/prm[i];
				ng+=v;
				while(n%prm[i]==0)
					n/=prm[i];
			}
		}
		if(n>1)
		{
			v=(a-ng)/n;
			ng+=v;
		}
		if(a==1)
			printf("0\n");
		else
			printf("%ld\n",a-ng);
	}
	return 0;
}