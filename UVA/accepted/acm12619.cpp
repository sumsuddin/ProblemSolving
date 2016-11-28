#include<stdio.h>
#include<math.h>

long long t,ind[1000050],go[50],ggo[50],lst,i,a,sq,id,flag,n,Mod=1000000007,sum,ans,cs=1,last,prm[1000050];
bool bu[1000050];

void sieve()
{
    last=0;
    prm[last++]=2;

    for(int i=3;i<1000000;i+=2)
    {
        if(bu[i]==0)
        {
            prm[last++]=i;
            for(int j=i*3;j<1000000;j+=i*2)
            bu[j]=1;
        }
    }
}

long long powr(long long b,long long p)
{
    if(p==0)
    return 1LL;

    long long d=powr(b,p>>1);

    d=(d*d)%Mod;

    if(p&1)
    d=(d*b)%Mod;

    return d;
}

int main()
{
    sieve();
    scanf("%lld",&t);

    while(t--)
    {
        flag=sum=0LL;
        ans=1LL;
        scanf("%lld",&n);
        for(i=0;i<1000001;i++)
        ind[i]=0LL;

        while(n--)
        {
            scanf("%lld",&a);

            if(a<0)
            {
                lst=0;
                a=-a;
                if(a>1)
                {
                    sq=sqrt(a);
                    for(i=0;prm[i]<=sq;i++)
                    {
                        if(a%prm[i]==0)
                        {
                            id=0LL;
                            while(a%prm[i]==0)
                            a/=prm[i],id++;
                            sq=sqrt(a);

                            if(ind[prm[i]]>=0 && ind[prm[i]]-id<0)
                            flag++;

                            ggo[lst]=ind[prm[i]]-id;
                            go[lst++]=prm[i];
                        }
                    }
                    if(a>1)
                    {
                        id=1LL;
                        if(ind[a]>=0 && ind[a]-id<0)
                        flag++;
                        ggo[lst]=ind[a]-id;
                        go[lst++]=a;
                        a=1LL;
                    }
                }
                if(flag==0)
                {
                    for(i=0;i<lst;i++)
                    {
                        if(ind[go[i]]>0)
                        ans=(ans*powr(ind[go[i]]+1,Mod-2))%Mod;

                        ans=(ans*(ggo[i]+1))%Mod;
                    }
                    sum=(sum+ans)%Mod;
                }
                for(i=0;i<lst;i++)
                ind[go[i]]=ggo[i];
            }
            else
            {
                lst=0LL;
                if(a>1)
                {
                    sq=sqrt(a);
                    for(i=0;prm[i]<=sq;i++)
                    {
                        if(a%prm[i]==0)
                        {
                            id=0LL;
                            while(a%prm[i]==0)
                            a/=prm[i],id++;
                            sq=sqrt(a);

                            if(ind[prm[i]]<0 && ind[prm[i]]+id>=0)
                            flag--;

                            ggo[lst]=ind[prm[i]]+id;
                            go[lst++]=prm[i];
                        }
                    }
                    if(a>1)
                    {
                        id=1LL;
                        if(ind[a]<0 && ind[a]+id>=0)
                        flag--;
                        ggo[lst]=ind[a]+id;
                        go[lst++]=a;
                        a=1LL;
                    }
                }
                if(flag==0)
                {
                    for(i=0;i<lst;i++)
                    {
                        if(ind[go[i]]>0)
                        ans=(ans*powr(ind[go[i]]+1,Mod-2))%Mod;

                        ans=(ans*(ggo[i]+1))%Mod;
                    }
                    sum=(sum+ans)%Mod;
                }
                for(i=0;i<lst;i++)
                ind[go[i]]=ggo[i];
            }
        }
        printf("Case %lld: %lld\n",cs++,sum);
    }
    return 0;
}
