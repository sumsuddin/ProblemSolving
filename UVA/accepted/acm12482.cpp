#include<stdio.h>
#include<string.h>
long l,n,c,i,d,p,ll;
char st[1050][100];

int main()
{
    while(~scanf("%ld%ld%ld",&n,&l,&c))
    {
        for(i=0;i<n;i++)
        scanf("%s",&st[i]);

        i=d=p=0;
        while(1)
        {
            d++;
            ll=strlen(st[i]);
            i++;
            while(i<n && ll+strlen(st[i])+1<=c)
            ll+=strlen(st[i])+1,i++;
            if(d>=l)
            p++,d=0;
            if(i>=n)
            break;
        }
        if(d)
        p++;
        printf("%ld\n",p);
    }
    return 0;
}
