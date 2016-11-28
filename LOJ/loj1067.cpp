    #include<cstdio>
    #include<cmath>
    typedef __int64 ind;

    ind fact[1000006];
    ind d,xx,y,m,p;

    void Exxtended_Euclid(ind a, ind b)
    {
        ind k;
        if(b>a)
        {
            k=a;
            a=b;
            b=k;
        }
        if(b==0)
        {
            d=a;
            xx=1;
            y=0;
            return;
        }
        Exxtended_Euclid(b,a%b);
        d = d;
        k = xx-(a/b) * y;
        xx = y;
        y = k;
    }

    int main()
    {
        long i,n,r,t,cs=1;

        m=1000003;
        fact[0]=1;
        for(i=1;i<=1000000;i++)
            fact[i]=(fact[i-1]*i)%m;
        scanf("%ld",&t);
        while(t--)
        {
            scanf("%ld%ld",&n,&r);
            p=(fact[r]*fact[n-r])%m;

            Exxtended_Euclid(p,m);

            p=(fact[n]*y)%m;
            if(p<0)
                p+=m;
            printf("Case %ld: %lld\n",cs++,p);
        }
        return 0;
    }
