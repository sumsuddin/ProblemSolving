#include<stdio.h>
long h,m,stx,sty,endx,endy,cs=1,n;
int main()
{
 	scanf("%ld",&n);
 	
 	while(n--)
 	{
        scanf("%ld:%ld",&h,&m);
        stx=h*60+m;
        scanf("%ld:%ld",&h,&m);
        sty=h*60+m;
        
        scanf("%ld:%ld",&h,&m);
        endx=h*60+m;
        scanf("%ld:%ld",&h,&m);
        endy=h*60+m;  
		
		if((stx<=endx && sty>=endx) ||  (stx<=endy && sty>=endy) || (stx>endx && sty<endy))
		printf("Case %ld: Mrs Meeting\n",cs++);
		else
		printf("Case %ld: Hits Meeting\n",cs++);
    }
    return 0;
}
