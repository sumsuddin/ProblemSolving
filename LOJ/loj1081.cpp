/*
//Bristi Shikder..
//   My First 2-D Sparse Table


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define sz 505
using namespace std;
int n,q;
int a[sz][sz];
int mn[sz][sz][9];

inline void Sparse_Table()
{
    int i,j,k,len;

    for(i=0; i<n; i++)
        for(j = 0 ; j<n ; j++)
            mn[i][j][0] = a[i][j];

    for(k = 1 ; (1<<k)<=n; k++){
        for(i=0;i<n;i++){
            for(j = 0 ; j< n ; j++){
                len = 1<<k;
                if((i+len)>n || (j+len)>n)
                    continue;
                    int x;
                    x = k-1;
                len = 1<<x;
                mn[i][j][k]= max(max(mn[i][j][k-1],mn[i][j+len][k-1]),max(mn[i+len][j][k-1],mn[i+len][j+len][k-1]));
            }
        }
    }

    return;
}

int main()
{
    int t,tc,i,j,a1,a2,ans,l,tk;
    int s,len,i1,j1;

    scanf("%d",&tk);
    tc = 0;
    while(tc<tk)
    {
        tc++;
        scanf("%d %d",&n,&q);

        for(i=0;i<n;i++)
            for(j= 0; j<n;j++)
                scanf("%d",&a[i][j]);

        Sparse_Table();

        printf("Case %d:\n",tc);
        for(l= 0;l <q;l++)
        {
            scanf("%d %d %d",&i,&j,&s);
            i--;
            j--;
            if(s==1)
            {
                printf("%d\n",a[i][j]);
                continue;
            }

            t = 0;
            len = 1;
            while(1)
            {
                if(len>=s)
                    break;
                len = len*2;
                t++;
            }
            len = len/2;
            t--;
            i1 = i+s-len;
            j1 = j+s-len;

            a1 = max(mn[i][j][t],mn[i1][j][t]);
            a2 = max(mn[i][j1][t],mn[i1][j1][t]);

            ans  = max(a1,a2);

            printf("%d\n",ans);

        }
    }
    return 0;
}

*/

#include<stdio.h>
long tree[500000],t,n,q,i,j,d,a[505][505],cs=1;

struct ss
{
    long x1,x2,y1,y2;
}
info[500000];

long build(long x1,long y1,long x2,long y2,long pos)
{
    if(x1>x2 || y1>y2)
    return 0;

    info[pos].x1=x1;
    info[pos].x2=x2;
    info[pos].y1=y1;
    info[pos].y2=y2;

    if(x1==x2 && y1==y2)
    {
        tree[pos]=a[x1][y1];
        return a[x1][y1];
    }
    long x=(x1+x2)/2;
    long y=(y1+y2)/2;
    long mx,l;
    mx=build(x1,y1,x,y,pos*4+1);
    l=build(x+1,y1,x2,y,pos*4+2);
    if(mx<l)
    mx=l;
    l=build(x1,y+1,x,y2,pos*4+3);
    if(mx<l)
    mx=l;
    l=build(x+1,y+1,x2,y2,pos*4+4);
    if(mx<l)
    mx=l;
    return tree[pos]=mx;
}

long range(long x1,long y1,long x2,long y2,long pos)
{
    if(x1>x2 || y1>y2)
    return 0;
    if(info[pos].x2<x1 || info[pos].y2<y1 || info[pos].x1>x2 || info[pos].y1>y2)
    return 0;

    if(x1<=info[pos].x1 && y1<=info[pos].y1 && x2>=info[pos].x2 && y2>=info[pos].y2)
    return tree[pos];

    long l,mx;
    mx=range(x1,y1,x2,y2,pos*4+1);
    l=range(x1,y1,x2,y2,pos*4+2);

    if(mx<l)
    mx=l;
    l=range(x1,y1,x2,y2,pos*4+3);
    if(mx<l)
    mx=l;
    l=range(x1,y1,x2,y2,pos*4+4);
    if(mx<l)
    mx=l;

    return mx;
}

int main()
{
    scanf("%ld",&t);
    long x,y;
    while(t--)
    {
        scanf("%ld%ld",&n,&q);

        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%ld",&a[i][j]);

        build(1,1,n,n,0);

        printf("Case %ld:\n",cs++);

        while(q--)
        {
            scanf("%ld%ld%ld",&i,&j,&d);
            x=i+d-1;
            y=j+d-1;
            if(x>n)
            x=n;
            if(y>n)
            y=n;

            printf("%ld\n",range(i,j,x,y,0));
        }
    }
    return 0;
}
