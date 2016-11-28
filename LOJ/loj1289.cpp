#include<stdio.h>
#include<math.h>

unsigned int n,t,sq,i,j,lst,com[1000050],sum,prm[1000050],cs=1,ls,a,pm[2000000],comp[4000000],ll;

long long tan1;

int main()
{
	scanf("%u",&t);
	sq=10000 ;

	lst=1 ,prm[0]=2 ;
	
	for(i=3 ;i<=sq;i+=2)
	{
		if(((pm[i/64]>>((i%64)>>1)) & 1)==0)
		{
			if(i<=sq)
				prm[lst++]=i;

			for(j=i*3 ;j<=100000000;j+=2 *i)
				pm[j/64] |= (1<<((j%64)>>1));
		}
	}
	
	for(i=0 ;i<=1000000 ;i++)
		com[i]=1 ;

	for(i=0 ;i<lst;i++)
	{
		tan1=prm[i] ;
		j=prm[i];
		while(tan1*prm[i]<=100000000LL)
		{
			j*=prm[i];
            tan1*=prm[i];
			ls=tan1/100;
			if(tan1%100)
				ls++;
			comp[tan1/32]|=(1<< tan1%32);
			com[ls]*=prm[i];
        }
	}
	com[0]=1;
	com[1]*=2;
	ls=1 ;
	for(i=3 ;i<=100000000 ;i+=2 )
	{   
        if((i-1)%100==0)
            ls++;
		if( (( pm[i/64]>> ((i%64)>>1) ) & 1)==0 )
        	com[ls]*=i;
    }

	for(i=1;i<=1000000;i++)
		com[i]=com[i]*com[i-1];

	while(t--)
	{
		scanf("%u",&n);
		sum=com[n/100 ];
		a=n/100 ;
		sq=n%100 ;
		for(i=1;i<=sq;i++)
		    if( ( comp[(i+a*100)/32] >> (i+a*100)%32 ) & 1 )
            {
                ll=(unsigned long)sqrt(i+(a*100));
				ls=i+a*100;
                for(j=0;j<lst && prm[j]<=ll;j++)
                if((i+a*100)%prm[j]==0)
                {
                    ls=prm[j];
                    break;
                }
                sum*=ls;
            }
			else if(((i+a*100)%2 || (i+a*100)==2) && (( pm[(i+a*100)/64] >> ( ((i+a*100)%64)>>1) ) & 1 )==0)
				sum*=(i+a*100);
		printf("Case %u: %u\n",cs++,sum);
	}
	return 0;
}

		
