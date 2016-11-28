#include<stdio.h>
long n,a[1000050],lft[1000050],rht[1000050],tree[1000050],sum,i;
void build(long l,long h,long pos)
{
    if(l==h)
    {
        tree[pos]=1;
        lft[pos]=rht[pos]=l;
    }
    else
    {
        build(l,(l+h)/2,pos*2);
        build((l+h)/2+1,h,pos*2+1);
        lft[pos]=l;
        rht[pos]=h;
        tree[pos]=tree[pos*2]+tree[pos*2+1];
    }
}

void update(long vlu,long pos)
{
    if(vlu==lft[pos] && lft[pos]==rht[pos])
    {
        tree[pos]=0;
    }
    else
    {
        if(vlu<=(lft[pos]+rht[pos])/2)
        update(vlu,pos*2);
        else
        update(vlu,pos*2+1);
        tree[pos]=tree[pos*2]+tree[pos*2+1];
    }
}

void cal(long vlu,long pos)
{
    if(lft[pos]==rht[pos])
    return;
    else
    {
        if(vlu<=(lft[pos]+rht[pos])/2)
        cal(vlu,pos*2);
        else
        sum+=tree[pos*2],cal(vlu,pos*2+1);
    }
}

int main()
{
    while(~scanf("%ld",&n) && n)
    {
        for(i=1;i<=n;i++)
        scanf("%ld",&a[i]);

        build(1,n,1);

        sum=0;
        for(i=1;i<n;i++)
        {
            update(a[i],1);
            cal(a[i],1);
        }

        if(sum%2)
        printf("Marcelo\n");
        else
        printf("Carlos\n");
    }

    return 0;
}
