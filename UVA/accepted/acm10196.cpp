#include<stdio.h>

char st[10][10];
long bl,wh,cs=1;

bool tst(long x,long y)
{
    if(x<8 && x>=0 && y<8 && y>=0)
    return 1;
    else
    return 0;
}

void chkprn(long clr,long r,long c)
{
    long x,y;
    if(clr==0)
    {
        x=r-1,y=c-1;

        if(tst(x,y) && st[x][y]=='p')
        wh=1;
        y=c+1;
        if(tst(x,y) && st[x][y]=='p')
        wh=1;
    }
    else
    {
        x=r+1,y=c-1;

        if(tst(x,y) && st[x][y]=='P')
        bl=1;
        y=c+1;
        if(tst(x,y) && st[x][y]=='P')
        bl=1;
    }
}

void chkrook(long clr,long r,long c)
{
    long i,j,x,y;
    long h[]={1,-1,0,0};
    long v[]={0,0,1,-1};

    for(j=0;j<4;j++)
    {
        x=r,y=c;
        for(i=1;i<20;i++)
        {
            x=x-h[j],y=y-v[j];
            if(tst(x,y))
            {
                if((clr==1 && (st[x][y]=='R'|| st[x][y]=='Q')) || (clr==0 && (st[x][y]=='r'|| st[x][y]=='q')))
                if(clr==0)
                wh=1;
                else
                bl=1;
                else if(st[x][y]!='.')
                break;
            }
            else
            break;
        }
    }
}

void chkbishop(long clr,long r,long c)
{
    long i,j,x,y;
    long h[]={1,1,-1,-1};
    long v[]={1,-1,1,-1};

    for(j=0;j<4;j++)
    {
        x=r,y=c;
        for(i=1;i<20;i++)
        {
            x=x-h[j],y=y-v[j];
            if(tst(x,y))
            {
                if((clr==1 && (st[x][y]=='B'|| st[x][y]=='Q')) || (clr==0 && (st[x][y]=='b'|| st[x][y]=='q')))
                if(clr==0)
                wh=1;
                else
                bl=1;
                else if(st[x][y]!='.')
                break;
            }
            else
            break;
        }
    }
}

void chkknight(long clr,long r,long c)
{
    long h[]={1,1,-1,-1,2,-2,2,-2};
    long v[]={-2,2,-2,2,1,-1,-1,1};
    long i,x,y;

    for(i=0;i<8;i++)
    {
        x=r+h[i];
        y=c+v[i];
        if(tst(x,y))
        {
            if((clr==0 && st[x][y]=='n') || (clr==1 && st[x][y]=='N'))
            if(clr==0)
            wh=1;
            else
            bl=1;
        }
    }
}

void check(long clr,long r,long c)
{
    long i,j;

    chkprn(clr,r,c);
    chkrook(clr,r,c);
    chkbishop(clr,r,c);
    chkknight(clr,r,c);
}

int main()
{
    long i,j,fl;
    while(~scanf("%s",&st[0]))
    {
        bl=wh=fl=0;
        for(i=1;i<8;i++)
        scanf("%s",st[i]);

        for(i=0;i<8;i++)
        for(j=0;j<8;j++)
        if(st[i][j]=='k')
        check(1,i,j),fl=1;
        else if(st[i][j]=='K')
        check(0,i,j),fl=1;

        if(fl==0)
        break;

        if(wh)
        printf("Game #%ld: white king is in check.\n",cs++);
        else if(bl)
        printf("Game #%ld: black king is in check.\n",cs++);
        else
        printf("Game #%ld: no king is in check.\n",cs++);
    }

    return 0;
}
