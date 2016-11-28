#include<string.h>
#include<stdio.h>
long long aa,bb,cc,i,j,flag,t,mx;
char a[20],b[20],c[20];
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s + %s = %s",&a,&b,&c);
        flag=1;
        mx=0;
        for(i=0;a[i];i++)
        {
            if(a[i]!='1')
            flag=0;
            if(a[i]>mx)
            mx=a[i];
        }

        for(i=0;b[i];i++)
        {
            if(b[i]!='1')
            flag=0;
            if(b[i]>mx)
            mx=b[i];
        }

        for(i=0;c[i];i++)
        {
            if(c[i]!='1')
            flag=0;
            if(c[i]>mx)
            mx=c[i];
        }

        if(flag && strlen(a)+strlen(b)==strlen(c))
        {
            printf("1\n");
            continue;
        }


        for(i=mx-'0'+1<2?2:mx-'0'+1;i<51;i++)
        {
            aa=bb=cc=0;
            for(j=0;a[j];j++)
            aa=aa*i+(a[j]-'0');

            for(j=0;b[j];j++)
            bb=bb*i+(b[j]-'0');

            for(j=0;c[j];j++)
            cc=cc*i+(c[j]-'0');

            if(aa+bb==cc)
            break;
        }

        if(i==51)
        printf("0\n");
        else
        printf("%lld\n",i);
    }
    return 0;
}
