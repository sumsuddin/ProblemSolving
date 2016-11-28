#include<stdio.h>
long max(long a,long b)
{
    return a>b?a:b;
}

long min(long a,long b)
{
    return a<b?a:b;
}

//long tree[2000050],rht[2000050],lft[2000050]
long ind[11][100010],ls[11],n,d,lst,i,ll,j;
char ar[100050],arr[100050];
/*
void build(long l,long r,long pos)
{
    lft[pos]=l;
    rht[pos]=r;

    if(l==r)
    {
        tree[pos]=ar[l];
        return;
    }
    build(l,(l+r)/2,pos*2);
    build((l+r)/2+1,r,pos*2+1);
    tree[pos]=max(tree[pos*2] , tree[pos*2+1]);
}

long rmq(long l,long r,long pos)
{
    if(l<=lft[pos] && r>=rht[pos])
    return tree[pos];
    else if(l>rht[pos] || r<lft[pos])
    return -1;

    return max(rmq(l,r,pos*2),rmq(l,r,pos*2+1));
}

long place(long l,long r,long pos)
{
    if(lft[pos]==rht[pos])
    {
        if(tree[pos]==ar[lst])
        return lft[pos];
        else
        return 10000006;
    }
    else if(l>rht[pos] || r<lft[pos])
    return 10000006;

    if(rmq(l,r,pos*2)>=ar[lst])
    return place(l,r,pos*2);
    else
    return place(l,r,pos*2+1);
}
*/

long srch(long l,long sl,long sr,long r,long nw)
{
    if(l>r)
    return -1;
    long mid=(l+r)>>1;

    if(l==r)
    {
        if(ind[nw][mid]>=sl && ind[nw][mid]<=sr)
        return ind[nw][mid];
        else
        return -1;
    }

    if(ind[nw][mid]>=sl)
    return srch(l,sl,sr,mid,nw);
    else
    return srch(mid+1,sl,sr,r,nw);
}

int main()
{
    while(~scanf("%ld%ld",&n,&d) && (n|| d))
    {
        scanf("%s",&ar);

        for(i=0;i<10;i++)
        ls[i]=0;

        for(i=0;ar[i];i++)
        ind[ar[i]-'0'][ls[ar[i]-'0']++]=i;

        lst=ll=0;

        for(i=d;i<n;i++)
        {
            for(j=9;j>=0;j--)
            {
                d=srch(0,ll,i,ls[j]-1,j);
                if(d>=0)
                {
                    ll=d+1,arr[lst++]=ar[d];
                    break;
                }
            }
            //ar[lst++]=srch(ll,i,1);
            //ll=place(ll,i,1)+1;
            //lst++;
        }
        arr[lst]=0;
        printf("%s\n",arr);
    }
    return 0;
}
