#include<stdio.h>
int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld",&n,&m);

        for(i=0;i<n;i++)
        vc[i].clear();

        while(m--)
        {
            scanf("%ld%ld",&a,&b);
            vc[a].push_back(b);
        }


    }
    return 0;
}
