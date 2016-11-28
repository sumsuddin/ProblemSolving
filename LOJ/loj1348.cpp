#include<stdio.h>
#include<vector>
using namespace std;
struct ss
{
    int l,h,lvl,vst,ar;
}
sr[50050];

vector<int>vc[50050];
int lst,t,n,tree[500050],a,b,q,dir,ans,lpar[50050][20],i,cs=1;
void rec(int n,int par,int lvl)
{
    int i;
    sr[n].vst=0;
    sr[n].lvl=lvl;
    sr[n].l=++lst;
    lpar[n][0]=par;

    for(i=1;i<19;i++)
    lpar[n][i]=-1;
    for(i=1;i<19;i++)
    {
        if(lpar[n][i-1]==-1)
        break;
        lpar[n][i]=lpar[lpar[n][i-1]][i-1];
    }

    for(i=0;i<vc[n].size();i++)
    {
        if(sr[vc[n][i]].vst)
        rec(vc[n][i],n,lvl+1);
    }
    sr[n].h=++lst;
}

void build(int l,int h,int pos)
{
    tree[pos]=0;
    if(l==h)
    return ;
    build(l,(l+h)/2,pos<<1);
    build((l+h)/2+1,h,(pos<<1)+1);
}

void update(int l,int h,int posl,int posh,int pos,int v)
{
    if(l<=posl && posh<=h)
    {
        tree[pos]+=v;
        return;
    }
    else if(posl>h || posh<l)
    return;

    update(l,h,posl,(posl+posh)/2,pos*2,v);
    update(l,h,(posl+posh)/2+1,posh,pos*2+1,v);
}

void find_ans(int ml,int v,int posl,int posh,int pos,int sum)
{
    if(posl>v || posh<v)
    return;
    sum+=tree[pos];

    if(posl==posh)
    {
        ans+=ml*sum;
        return;
    }

    find_ans(ml,v,posl,(posl+posh)/2,pos*2,sum);
    find_ans(ml,v,(posl+posh)/2+1,posh,pos*2+1,sum);
}

int find_par(int n,int p)
{
    if(p==0)
    return n;
    int i,x=1;

    for(i=0;i<19;i++)
    {
        if(p<x*2)
        break;
        x<<=1;
    }
    return find_par(lpar[n][i],p-x);
}

int find_lca(int a,int b)
{
    int i;
    if(sr[a].lvl>sr[b].lvl)
    {
        i=a;
        a=b;
        b=i;
    }

    b=find_par(b,sr[b].lvl-sr[a].lvl);

    if(a==b)
    return a;

    for(i=18;i>=0;i--)
    if(lpar[a][i]!=lpar[b][i])
    break;

    if(i<0)
    return lpar[a][0];
    return find_lca(lpar[a][i],lpar[b][i]);
}

int main()
{
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        scanf("%d",&sr[i].ar),sr[i].vst=1,vc[i].clear();

        for(i=1;i<n;i++)
        scanf("%d%d",&a,&b),vc[a].push_back(b),vc[b].push_back(a);

        for(i=lst=0;i<n;i++)
        if(sr[i].vst)
        rec(i,-1,0);

        build(1,lst,1);

        for(i=0;i<n;i++)
        update(sr[i].l,sr[i].h,1,lst,1,sr[i].ar);

        printf("Case %d:\n",cs++);

        scanf("%d",&q);

        while(q--)
        {
            scanf("%d%d%d",&dir,&a,&b);

            if(dir==0)
            {
                dir=find_lca(a,b);

                ans=0;
                find_ans(1,sr[a].l,1,lst,1,0);
                find_ans(1,sr[b].l,1,lst,1,0);
                find_ans(-2,sr[dir].l,1,lst,1,0);


                printf("%d\n",ans+sr[dir].ar);
            }
            else
            update(sr[a].l,sr[a].h,1,lst,1,b-sr[a].ar),sr[a].ar=b;
        }
    }
    return 0;
}
