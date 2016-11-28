#include<stdio.h>
long tree[800000],n,l,h,t,cs=1,c,q,ans,ll[800000],rr[800000],a[800000],i;
struct ss
{
    long v,fr;
}
mid[800000],lft[800000],rht[800000];

void build(long l,long h,long pos)
{
    if(l==h)
    {
        ll[pos]=rr[pos]=l;

        tree[pos]=1;

        mid[pos].v=a[l];
        mid[pos].fr=1;

        lft[pos]=mid[pos];
        rht[pos]=mid[pos];
    }
    else
    {
        ll[pos]=l;
        rr[pos]=h;

        build(l,(l+h)/2,pos*2);
        build((l+h)/2+1,h,pos*2+1);

        if(mid[pos*2].v==mid[pos*2+1].v && mid[pos*2].v>=0 && mid[pos*2+1].v>=0)
        {
            mid[pos].v=mid[pos*2].v;
            mid[pos].fr=mid[pos*2].fr+mid[pos*2+1].fr;

            lft[pos]=mid[pos];
            rht[pos]=mid[pos];

            tree[pos]=mid[pos].fr;
        }
        else
        {
            mid[pos].v=-1;

            tree[pos]=tree[pos*2]>tree[pos*2+1]?tree[pos*2]:tree[pos*2+1];

            if(rht[pos*2].v==lft[pos*2+1].v)
            {
                if(tree[pos]<rht[pos*2].fr+lft[pos*2+1].fr)
                tree[pos]=rht[pos*2].fr+lft[pos*2+1].fr;

                if(mid[pos*2].v>=0)
                {
                    lft[pos].v=mid[pos*2].v;
                    lft[pos].fr=rht[pos*2].fr+lft[pos*2+1].fr;
                }
                else
                lft[pos]=lft[pos*2];

                if(mid[pos*2+1].v>=0)
                {
                    rht[pos].v=mid[pos*2+1].v;
                    rht[pos].fr=rht[pos*2].fr+lft[pos*2+1].fr;
                }
                else
                rht[pos]=rht[pos*2+1];
            }
            else
            {
                lft[pos]=lft[pos*2];
                rht[pos]=rht[pos*2+1];
            }
        }
    }
}

long range(long l,long h,long pos)
{
    if(l<=ll[pos] && h>=rr[pos])
    return tree[pos];
    else if(l>rr[pos] || h<ll[pos])
    return 0;
    else
    {
        long a=range(l,h,pos*2);
        long b=range(l,h,pos*2+1);

        if(b>a)
        a=b;

        if(rht[pos*2].v==lft[pos*2+1].v)
        {
            long c,d;
            c=(rr[pos]+ll[pos])/2;
            d=(c-l+1)<rht[pos*2].fr?(c-l+1):rht[pos*2].fr;
            c=(h-c)<lft[pos*2+1].fr?(h-c):lft[pos*2+1].fr;
            if(a<d+c)
            a=d+c;
        }
        return a;
    }
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld%ld",&n,&c,&q);

        for(i=0;i<n;i++)
        scanf("%ld",&a[i]);

        build(0,n-1,1);

        printf("Case %ld:\n",cs++);
        while(q--)
        {
            scanf("%ld%ld",&l,&h);
            printf("%ld\n",range(l-1,h-1,1));
        }
    }
    return 0;
}
