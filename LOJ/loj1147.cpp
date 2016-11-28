#include<stdio.h>
#inclulde<vector>
using namespace std;

int main()
{
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld",&n);

        for(i=0;i<n;i++)
        scanf("%ld",&wt[i]);

        mx=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=mx;j++)
            {
                if(mx<j+wt[i])
                mx=j+wt[i];
            }
        }
    }

    return 0;
}
