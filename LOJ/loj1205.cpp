#include<stdio.h>
long long t,a,b,ans,len,cs=1;
long long powr(long long b,long long x)
{
	if(x<0)
		return 0;
	long long t=1;
	while(x--)
		t*=b;
	return t;
}

bool chk(long long ans)
{
	if(ans==1)
		return 0;

	while(ans>0 && ans%10==0)
		ans/=10;
	if(ans==1)
		return 1;
	else
		return 0;
}

long long make9(long long bit)
{
	if(bit<=0)
		return 0;
	long long t=9;
	while(--bit)
		t=t*10+9;
	return t;
}

long long makepl(long long n,long long len)
{
	if(n==0)
		return 0;
	long long l=0,d=n;
	while(d)
	{
		d/=10;
		l++;
	}
	if(l!=len)
		return makepl(n/10,len-2)*10;

	if(l==1)
		return n;
	else if(l==2)
	{
		if((n/10)>(n%10))
			return (n/10-1)*10+(n/10-1);
		else
			return (n/10)*10+(n/10);
	}
	else
	{
		d=powr(10,l-1);
		long long t=(long long)(n/d);

		if(t*d+t<=n)
		{
			if((n%10)<t)
				return t*d+10*makepl((n%d)/10-1,len-2)+t;
			else
				return t*d+10*makepl((n%d)/10,len-2)+t;
		}
		else
			return (t-1)*d+10*make9(l-2)+(t-1);
	}
}

long long recall(long long n,long long bit)
{
    if(bit==1)
        return n+1;
    else if(bit==2)
		return n/10+1;
	long long d=powr(10,bit-1);

	return (n/d)*powr(10,(bit-1)/2)+recall((n%d)/10,bit-2);
}

long long rec(long long n)
{
	if(n<10)
		return n+1;

	if(n<100)
		return 10+n/10;

	long long bit=1,x,ret=1,d;
	x=make9(bit);
	while(x<=n)
	{
		ret+=9*powr(10,(bit-1)/2);
		bit++;
		x=make9(bit);
	}
	x=powr(10,bit-1);
	d=n/x;
	d--;
	if(d<0)
		return ret;

	ret+=d*powr(10,(bit-1)/2);
	n=(n%x)/10;

	ret+=recall(n,bit-2);

	return ret;
}

int main()
{
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld",&a,&b);

		if(a>b)
		{
			ans=a;
			a=b;
			b=ans;
		}
		if(a)
		{
    		a--;
    		if(chk(a))
    			a--;
    		len=0;	
    		ans=a;
    		while(ans)
    			ans/=10,len++;
    		a=makepl(a,len);
            a=rec(a);    			
        }
        else
            a=0;
		if(chk(b))
			b--;
		len=0;
		ans=b;
		while(ans)
			ans/=10,len++;
		b=makepl(b,len);

		b=rec(b);
		printf("Case %lld: %lld\n",cs++,b-a);
	}
	return 0;
}
