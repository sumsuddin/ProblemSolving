#include<stdio.h>
long com[100050],sum,a,l1,l2,l3,fl[100050],n,ans,i;

long bsearch(long sum,long dust,long l,long h)
{
    long mid;
    while(l<=h)
    {
        mid=(l+h)/2;

        if(com[mid]-dust==sum)
        return mid;
        if(com[mid]-dust<sum)
        l=mid+1;
        else
        h=mid-1;
    }
    return mid;
}

long chk(long a)
{
    long b;
    if(com[n]-com[a]<sum)
    {
        b=bsearch(sum-com[n]+com[a],0,1,n);
        if(b>a || com[b]+com[n]-com[a]!=sum)
        return -1;
    }
    else
    {
        b=bsearch(sum,com[a],a+1,n);
        if(com[b]-com[a]!=sum)
        return -1;
    }

    return b;
}

int main()
{
    while(~scanf("%ld",&n))
    {
        com[0]=sum=0;
        for(i=1;i<=n;i++)
        scanf("%ld",&a),com[i]=com[i-1]+a,sum+=a,fl[i]=0;

        ans=0;

        if(sum%3==0)
        {
            sum/=3;
            for(i=0;i<n;i++)
            {
                if(fl[i])
                continue;

                l2=chk(i);
                if(l2<0)
                continue;

                l3=chk(l2);
                if(l3<0)
                continue;

                l1=chk(l3);
                if(l1!=i)
                continue;

                ans++;
                fl[l1]=fl[l2]=fl[l3]=1;
            }
        }
        printf("%ld\n",ans);
    }
    return 0;
}
