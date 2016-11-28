#include<stdio.h>
#include<vector>
using namespace std;
vector<long>vc[100050];
long tree[4*100050],up[4*100050],t,m,n,a,i,j;

void build(long l,long h,long pos)
{
    if(l==h)
    {
        tree[pos]=0;
        up[pos]=-1;
        return;
    }
    build(l,(l+h)/2,pos*2);
    build((l+h)/2+1,h,pos*2+1);
    tree[pos]=0;
    up[pos]=-1;
}

void update(long l,long h,long pos,long v,long now)
{
    if(l==h)
    {
        if(l==v && up[pos]!=now)
        tree[pos]++,up[pos]=now;
        return;
    }
    if(v<=(l+h)/2)
    update(l,(l+h)/2,pos*2,v,now);
    else
    update((l+h)/2+1,h,pos*2+1,v,now);

    if(up[pos]!=now)
    tree[pos]++,up[pos]=now;
}

long range(long ll,long hh,long l,long h,long pos)
{
    if(ll<=l && h<=hh)
    return tree[pos];
    else if(ll>h || hh<l)
    return 0;

    return range(ll,hh,l,(l+h)/2,pos*2)+range(ll,hh,(l+h)/2+1,h,pos*2+1);
}

int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&n,&m);

        for(i=1;i<=n;i++)
        scanf("%ld",&a),vc[a].push_back(i);

        build(1,n,1);

        for(i=0;i<=100000;i++)
        {
            for(j=0;j<vc[i].size();j++)
            update(1,n,1,vc[i][j],i);

            vc[i].clear();
        }

        while(m--)
        {
            scanf("%ld%ld",&a,&i);

            printf("%ld\n",range(a,i,1,n,1));
        }
    }
    return 0;
}
