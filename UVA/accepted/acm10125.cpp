#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
map<long,long>mp;
struct ss
{
    long long a,b,sum,dif;
}
sr[1100050];
long long a[1100050],i,j,x,ans,lst,n,l,h,mid;

bool cmp(ss p,ss q)
{
    return p.sum<q.sum;
}

long long srch(long long vlu)
{
    l=0;h=lst-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(sr[mid].sum>=vlu)
        h=mid-1;
        else
        l=mid+1;
    }
    return mid;
}

bool tst(long long p,long long q)
{
    bool tru=1;
    mp[sr[p].a]--,mp[sr[p].b]--,mp[sr[q].a]--,mp[sr[q].b]--;

    if(mp[sr[p].a]<0 ||mp[sr[p].b]<0 ||mp[sr[q].a]<0 ||mp[sr[q].b]<0)
    tru=0;

    mp[sr[p].a]++,mp[sr[p].b]++,mp[sr[q].a]++,mp[sr[q].b]++;
    return tru;
}

int main()
{
    while(~scanf("%lld",&n) && n)
    {
        mp.clear();
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]),mp[a[i]]++;

        lst=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            sr[lst].a=a[i];
            sr[lst].b=a[j];
            sr[lst].sum=a[i]+a[j];
            sr[lst++].dif=a[i]-a[j];
        }
        sort(sr,sr+lst,cmp);

        ans=-1000000000;

        for(i=0;i<lst;i++)
        {
            x=srch(sr[i].dif);
            while(x<lst && sr[x].sum<sr[i].dif)
            x++;
            while(x<lst && sr[x].sum==sr[i].dif)
            {
                if(tst(i,x))
                {
                    if(ans<sr[i].a)
                    ans=sr[i].a;
                }
                x++;
            }

            x=srch(-sr[i].dif);
            while(x<lst && sr[x].sum<-sr[i].dif)
            x++;
            while(x<lst && sr[x].sum==-sr[i].dif)
            {
                if(tst(i,x))
                {
                    if(ans<sr[i].b)
                    ans=sr[i].b;
                }
                x++;
            }
        }

        if(ans==-1000000000)
        printf("no solution\n");
        else
        printf("%lld\n",ans);
    }

    return 0;
}
