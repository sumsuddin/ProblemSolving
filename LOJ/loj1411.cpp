#include<stdio.h>
#define S 250005
long long ml[4*S],tree[4*S],cnta[4*S],cntb[4*S],x[4*S];
bool setx[4*S];

void build(long long l,long long h,long long pos)
{
    if(l==h)
    {
        setx[pos]=1;//determines x is set or not here
        x[pos]=0LL;// given x value for the range.
        tree[pos]=0LL;// update of x in upward flow.
        ml[pos]=0LL;// extra value of 1 to n series .. eg. 3+4+5 which means 2*3+(1+2+3) here ml[pos]=2*3 to make the series 1 to n..
        cnta[pos]=0LL;// number of 1 to n series..
        cntb[pos]=0LL;
        return;
    }

    build(l,(l+h)/2,pos*2);
    build((l+h)/2+1,h,pos*2+1);

    setx[pos]=0;
    x[pos]=0LL;
    tree[pos]=tree[pos*2]+tree[pos*2+1];
    ml[pos]=0LL;
    cnta[pos]=cntb[pos]=0LL;
}

void flow(long long posl,long long posh,long long pos)
{
    if(setx[pos])
    {
        setx[pos*2]=setx[pos*2+1]=1,x[pos*2]=x[pos*2+1]=x[pos],setx[pos]=0;

        ml[pos*2]=ml[pos*2+1]=0LL;
        cnta[pos*2]=cnta[pos*2+1]=0LL;
        cntb[pos*2]=cntb[pos*2+1]=0LL;
    }
        ml[pos*2]+=ml[pos];
        ml[pos*2+1]+=ml[pos];
        ml[pos]=0;

        cntb[pos*2]+=cntb[pos];
        cntb[pos*2+1]+=cntb[pos];
        ml[pos*2]+=cntb[pos]*(posh-((posh+posl)/2));
        cntb[pos]=0;

        cnta[pos*2]+=cnta[pos];
        cnta[pos*2+1]+=cnta[pos];
        ml[pos*2+1]+=cnta[pos]*(((posh+posl)/2)+1-posl);
        cnta[pos]=0;
}

long long upA(long long dir,long long l,long long h,long long posl,long long posh,long long pos)
{
    long long n,nn;
    n=(posh-posl)+1LL;
    nn=(n*(n+1))/2LL;

    if(l<=posl && h>=posh)
    {
        if(dir==0)
        cnta[pos]++;
        else
        cntb[pos]++;

        if(dir==0)
        ml[pos]+=(posl-l);
        else
        ml[pos]+=(h-posh);

        if(setx[pos])
        return x[pos]*n+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
        else
        return tree[pos]+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
    }
    else if(l>posh || h<posl)
    {
        if(setx[pos])
        return x[pos]*n+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
        else
        return tree[pos]+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
    }

    flow(posl,posh,pos);

    tree[pos]=upA(dir,l,h,posl,(posl+posh)/2,pos*2)+upA(dir,l,h,(posl+posh)/2+1,posh,pos*2+1);

    return tree[pos]+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
}

long long upC(long long l,long long h,long long posl,long long posh,long long pos,long long xy)
{
    long long n,nn;
    n=(posh-posl)+1LL;
    nn=(n*(n+1))/2LL;

    if(l<=posl && h>=posh)
    {
        setx[pos]=1,x[pos]=xy;
        ml[pos]=cnta[pos]=cntb[pos]=0LL;
        return x[pos]*n;
    }
    else if(l>posh || h<posl)
    {
        if(setx[pos])
        return x[pos]*n+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
        else
        return tree[pos]+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
    }

    flow(posl,posh,pos);

    tree[pos]=upC(l,h,posl,(posl+posh)/2,pos*2,xy)+upC(l,h,(posl+posh)/2+1,posh,pos*2+1,xy);

    return tree[pos]+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
}

long long pclean(long long l,long long h,long long posl,long long posh,long long pos)
{
    long long n,nn;
    n=(posh-posl)+1LL;
    nn=(n*(n+1))/2LL;

    if((l<=posl && h>=posh) || (l>posh || h<posl))
    {
        if(setx[pos])
        return x[pos]*n+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
        else
        return tree[pos]+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
    }

    flow(posl,posh,pos);

    return tree[pos]=pclean(l,h,posl,(posl+posh)/2,pos*2)+pclean(l,h,(posl+posh)/2+1,posh,pos*2+1);
}

long long prin(long long l,long long h,long long posl,long long posh,long long pos)
{
    if(l<=posl && h>=posh)
    {
        long long n,nn;
        n=(posh-posl)+1LL;
        nn=(n*(n+1))/2LL;

        if(setx[pos])
        return x[pos]*n+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
        else
        return tree[pos]+nn*(cnta[pos]+cntb[pos])+ml[pos]*n;
    }
    else if(l>posh || h<posl)
    return 0LL;

    return prin(l,h,posl,(posl+posh)/2,pos*2)+prin(l,h,(posl+posh)/2+1,posh,pos*2+1);
}

int main()
{
    long long q,t,l,h,xx,cs=1;
    char st[3];

    scanf("%lld",&t);
    while(t--)
    {
        printf("Case %lld:\n",cs++);
        build(0,S,1);
        scanf("%lld",&q);

        while(q--)
        {
            scanf("%s",&st);

            if(st[0]=='A')
            {
                scanf("%lld%lld",&l,&h);
                upA(0,l,h,0,S,1);
            }
            else if(st[0]=='B')
            {
                scanf("%lld%lld",&l,&h);
                upA(1,l,h,0,S,1);
            }
            else if(st[0]=='C')
            {
                scanf("%lld%lld%lld",&l,&h,&xx);
                upC(l,h,0,S,1,xx);
            }
            else
            {
                scanf("%lld%lld",&l,&h);
                pclean(l,h,0,S,1);
                printf("%lld\n",prin(l,h,0,S,1));
            }
        }
    }
    return 0;
}
