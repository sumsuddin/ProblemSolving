#include<stdio.h>
#include<math.h>

long long c,x,y,i,j,t,n,ans,d,lst,prm[1000050],m,sq,cs=1;
bool bu[1000050];

long long bigmod(long long b,long long p,long long m) 
{
	if (p == 0)
	return 1LL;
	else if (p%2 == 0)
	return (bigmod(b,p/2,m)*bigmod(b,p/2,m)) % m;
	else
	return ((b % m) * bigmod(b,p-1,m)) % m;
}
void ext(long long a, long long b){
    long long x1;
    if(b>a)
    {
        x1=a; //if b>a so I used this if condition
        a=b; // result is ok but x and y swaped
        b=x1;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    ext(b,a%b);
    x1 = x-(a/b) * y;
    x = y;
    y = x1;
}
int main()
{
	bu[0]=1;
	bu[1]=1;

	for(i=4;i<1000000;i+=2)
		bu[i]=1;

	lst=0;
	prm[lst++]=2;
	for(i=3;i<1000000;i+=2)
	{
		if(bu[i]==0)
		{
			prm[lst++]=i;
			for(j=3*i;j<1000000;j+=(2*i))
				bu[j]=1;
		}
	}

	c=1000000007;
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&n,&m);

		sq=(long long)sqrt(n);
		
		ans=1;
		
		for(i=0;i<lst && prm[i]<=sq;i++)
		{
            if(n%prm[i]==0)
            {
                d=0;
                while(n%prm[i]==0)
                {
                    n/=prm[i];
                    d++;
                }
                d*=m;
                d=bigmod(prm[i],d+1,c)-1;
                if(d<0)
                d+=c;
                ans=(ans*d)%c;
                d=(prm[i]-1)%c;
                if(d<0)
                d+=c;
                ext(d,c);
                ans=(ans*y)%c;
                if(ans<0)
                ans+=c;
                sq=(long long)sqrt(n);
            }
        }
        if(n>1)
        {
            d=bigmod(n,m+1,c)-1;
            if(d<0)
            d+=c;            
            ans=(ans*d)%c;
            n--;
            n%=c;
            if(n<0)
            n+=c;
            ext(n,c);
            ans=(ans*y)%c;
            if(ans<0)
            ans+=c;
        }
        printf("Case %lld: %lld\n",cs++,ans);
	}
	return 0;
}
