#include<stdio.h>
#include<math.h>
bool bu[50];
long i,k;
unsigned long double j,sum,d[50],t,n,sq;
int main()
{
/*	bu[0]=1;
	bu[1]=1;

	for(i=4;i<35;i+=2)
		bu[i]=1;

	for(i=3;i<35;i+=2)
	{
		if(bu[i]==0)
		{
			for(k=2*i;k<35;k+=i)
				bu[k]=1;
		}
	}

	for(i=2;i<32;i++)
	{
		t=n=(long double)pow(2,2*i-1)-(long double)pow(2,i-1);
		sq=(long double)sqrt(n);
		sum=1;
		for(j=2;j<=sq && sum<=t;j++)
		{
			if((floor)(n/j)==n/j)
				sum+=j+n/j;
		}
		if(sum==t)
			d[i]=sum;
		else
		{
			if(bu[i]==0)
				d[i]=-1;
			else
				d[i]=-2;
		}
		printf("d[%ld]=%.0llf;\n",i,d[i]);
	}*/

d[2]=6;
d[3]=28;
d[4]=-2;
d[5]=496;
d[6]=-2;
d[7]=8128;
d[8]=-2;
d[9]=-2;
d[10]=-2;
d[11]=-1;
d[12]=-2;
d[13]=33550336;
d[14]=-2;
d[15]=-2;
d[16]=-2;
d[17]=8589869056;
d[18]=-2;
d[19]=137438691328;
d[20]=-2;
d[21]=-2;
d[22]=-2;
d[23]=-1;
d[24]=-2;
d[25]=-2;
d[26]=-2;
d[27]=-2;
d[28]=-2;
d[29]=-1;
d[30]=-2;
d[31]=(long double)pow(2,2*31-1)-(long double)pow(2,31-1);

	while(scanf("%ld",&i),i)
	{
		if(d[i]==-1.0)
			printf("Given number is prime. But, NO perfect number is available.\n");
		else if(d[i]==-2.0)
			printf("Given number is NOT prime! NO perfect number is available.\n");
		else
			printf("Perfect: %.0llf!\n",d[i]);
	}
	return 0;
}
