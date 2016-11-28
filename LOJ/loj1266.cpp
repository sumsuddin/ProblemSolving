#include<stdio.h>
struct ss
{
    long x,y;
}
lft[8000000],rht[8000000];
long tree[8000000],q,t,dir,x1,y1,x2,y2;

void build(long x1,long y1,long x2,long y2,long pos)
{
    lft[pos].x=x1,lft[pos].y=y1;
    rht[pos].x=x2;rht[pos].y=y2;

    long x=(x1+x2)/2;
    long y=(y1+y2)/2;

    if(x1==x2 && y1==y2)
    {
        tree[pos]=0;
        return;
    }

    build(x1,y1,x,y,pos*4);
    build(x+1,y+1,x2,y2,pos*4+1);
    build(x+1,y1,x2,y,pos*4+2);
    build(x1,y+1,x+1,y2,pos*4+3);

    tree[pos]=tree[pos*4]+tree[pos*4+1]+tree[pos*4+2]+tree[pos*4+3];
}

void update(long x,long y,long pos)
{
    if(x>rht[pos].x || x<lft[pos].x || y>rht[pos].y || y<lft[pos].y)
    return;

    if(lft[pos].x==rht[pos].x && lft[pos].y==rht[pos].y && lft[pos].x==x && lft[pos].y==y)
    {
        tree[pos]=1;
    }
    update(x,y,pos*4);
    update(x,y,pos*4+1);
    update(x,y,pos*4+2);
    update(x,y,pos*4+3);

    tree[pos]=tree[pos*4]+tree[pos*4+1]+tree[pos*4+2]+tree[pos*4+3];
}

long range(long x1,long y1,long x2,long y2,long pos)
{
    if(lft[pos].x>x2 || lft[pos].y>y2 || rht[pos].x<x1 || rht[pos].y<y1)
        return 0;

    if(lft[pos].x<=x1 && lft[pos].y<=y1 && rht[pos].x>=x2 && rht[pos].y>=y2)
        return tree[pos];

    long a=range(x1,y1,x2,y2,pos*4);
    a+=range(x1,y1,x2,y2,pos*4+1);
    a+=range(x1,y1,x2,y2,pos*4+2);
    a+=range(x1,y1,x2,y2,pos*4+3);
    return a;
}

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&q);

        build(0,0,500,500,1);

        while(q--)
        {
            scanf("%ld",&dir);
            if(dir)
            {
                scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
                printf("%ld\n",range(x1,y1,x2,y2,1));
            }
            else
            {
                scanf("%ld%ld",&x1,&y1);
                update(x1,y1,1);
            }
        }
    }
    return 0;
}
