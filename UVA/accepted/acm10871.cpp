#include<stdio.h>

long prm[4000000],i,j,flag,t,n,a,com[10050],ans;

void bitsieve()
{
    long i,j;

    for(i=3;i<10000;i+=2)
    {
        if((prm[(i>>5)] & (1<<(i%(1<<5))))==0)
        for(j=i*3;j<100000000;j+=i*2)
        prm[(j>>5)]|=(1<<(j%(1<<5)));
    }
}
int main()
{
    bitsieve();
    long x;

    scanf("%ld",&t);
    com[0]=0;

    while(t--)
    {
        scanf("%ld",&n);

        for(i=1;i<=n;i++)
        scanf("%ld",&a),com[i]=com[i-1]+a;
        flag=1;

        for(i=2;i<=n && flag;i++)
        for(j=i;j<=n && flag;j++)
        {
            x=com[j]-com[j-i];

            if((x&1 || x==2) && (prm[(x>>5)] & (1<<(x%(1<<5))))==0)
            flag=0,ans=i,x=j-i+1;
        }

        if(flag)
        printf("This sequence is anti-primed.\n");
        else
        {
            printf("Shortest primed subsequence is length %ld:",ans);
            for(i=x;i<x+ans;i++)
            printf(" %ld",com[i]-com[i-1]);

            printf("\n");
        }
    }
    return 0;
}
