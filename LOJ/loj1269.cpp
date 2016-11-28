#include<stdio.h>

long n,t,a[50050],comx[50050],i,mx,mn,cs=1;


int main()
{
	scanf("%ld",&t);
	
	while(t--)
	{
		scanf("%ld",&n);
		comx[0]=comx[n+1]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			comx[i]=comx[i-1]^a[i];
		}
		
		mx=0;mn=a[1];
		for(i=1;i<=n;i++)
		{
			if(comx[i]>mx)
				mx=comx[i];
			if((comx[n]^comx[i])>mx)
				mx=comx[n]^comx[i];
				
			if(comx[i]<mn)
			mn=comx[i];
			
			if((comx[n]^comx[i])<mn && n!=i)
			mn=(comx[n]^comx[i]);
		}
		
		printf("Case %ld: %ld %ld\n",cs++,mx,mn);
	}
	return 0;
}
