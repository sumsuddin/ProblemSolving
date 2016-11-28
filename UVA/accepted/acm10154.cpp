#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

struct ss
{
    long st,w;
}
sr[100050];
priority_queue<long>pq;

bool cmp(ss a,ss b)
{
    if(a.st==b.st)
    return a.w<b.w;
    else
    return a.st<b.st;
}

int main()
{
    long i,n,h,ww;
    i=0;
    while(~scanf("%ld%ld",&sr[i].w,&sr[i].st))
    {
        sr[i].st-=sr[i].w;
        i++;
    }
    n=i;
    sort(sr,sr+i,cmp);

    ww=sr[0].w;
    h=1;
    pq.push(sr[0].w);

    for(i=1;i<n;i++)
    {
        if(ww<=sr[i].st)
        ww+=sr[i].w,pq.push(sr[i].w),h++;
        else
        {
            if(pq.top()>sr[i].w)
            ww=ww-pq.top()+sr[i].w,pq.pop(),pq.push(sr[i].w);
        }
    }
    printf("%ld\n",h);

    return 0;
}
