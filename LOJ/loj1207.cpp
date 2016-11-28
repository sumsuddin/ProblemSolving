#include<stdio.h>

long n,l,cs=1,r,i,t,ind[1000000],tree[1000000],lft[1000000],rht[1000000];

void build(long l,long h,long pos)
{
    if(l==h)
    tree[pos]=0,lft[pos]=rht[pos]=l;
    else
    {
        build(l,(l+h)/2,pos*2);
        build((l+h)/2+1,h,pos*2+1);
        lft[pos]=l;
        rht[pos]=h;
        tree[pos]=0;
    }
}

void update(long l,long h,long pos,long key)
{
    if(key==0)
    key=tree[pos];

    if(l<=lft[pos] && h>=rht[pos])
    {
        tree[pos]=i;
        return;
    }

    if(l>rht[pos] || r<lft[pos])
    {
        tree[pos]=key;
        return;
    }

    update(l,h,pos*2,key);
    update(l,h,pos*2+1,key);
    tree[pos]=0;
}

void range(long l,long h,long pos,long key)
{
    if(key==0)
    key=tree[pos];

    if(lft[pos]==i && lft[pos]==rht[pos])
    {
        ind[key]=1;
        return;
    }

    if(i<lft[pos] || i>rht[pos])
    return;

    if(i<lft[pos*2+1])
    range(l,h,pos*2,key);
    else
    range(l,h,pos*2+1,key);
    return;
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);

        build(1,2*n,1);

        for(i=1;i<=n;i++)
        {
            scanf("%ld%ld",&l,&r);
            update(l,r,1,0);
        }
        for(i=0;i<=2*n;i++)
        ind[i]=0;
        for(i=1;i<=2*n;i++)
        range(1,2*n,1,0);

        l=0;
        for(i=1;i<=2*n;i++)
        l+=ind[i];
        printf("Case %ld: %ld\n",cs++,l);
    }
    return 0;
}
