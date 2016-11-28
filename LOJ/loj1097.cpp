#include<stdio.h>

int i,j,t,tree[4200000],rht[4200000],lft[4200000],lst,cs=1;
bool ind[4200000];

void build(long l,long h,long pos)
{
    if(l==h)
    {
        tree[pos]=1;
        ind[l]=1;
        lft[pos]=rht[pos]=l;
        return;
    }

    build(l,(l+h)/2,pos*2);
    build((l+h)/2+1,h,pos*2+1);

    lft[pos]=l;
    rht[pos]=h;

    tree[pos]=tree[pos*2]+tree[pos*2+1];
}

void eleminate(long x,long pos,long key)
{
    if(lft[pos]==rht[pos])
    {
        tree[pos]=0;
        ind[lft[pos]]=0;
        return;
    }

    if(key+tree[pos*2]>=x)
    eleminate(x,pos*2,key);
    else
    eleminate(x,pos*2+1,key+tree[pos*2]);

    tree[pos]=tree[pos*2]+tree[pos*2+1];
}

void range(long x,long pos,long key)
{
    if(lft[pos]==rht[pos])
    {
        printf("%d\n",lft[pos]);
        return;
    }

    if(key+tree[pos*2]>=x)
    range(x,pos*2,key);
    else
    range(x,pos*2+1,key+tree[pos*2]);
}

int main()
{
    build(1,1429481,1);
    scanf("%d",&t);

    for(i=2;i<1429440;i++)
    if(ind[i])
    {
        for(j=i;j<1429440;j+=(i-1))
        eleminate(j,1,0);
    }

    while(t--)
    {
        scanf("%d",&i);
        printf("Case %d: ",cs++);
        range(i,1,0);
    }
    return 0;
}
