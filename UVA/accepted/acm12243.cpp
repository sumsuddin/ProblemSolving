#include<stdio.h>
#include<string.h>
long flag;;
char c,cm,st[50];
int main()
{
 	while(scanf("%s%c",st,&c) && strcmp(st,"*"))
 	{
        cm=st[0];
        if(cm>96)
        cm-=32;
        flag=1;
        if(c!='\n')
	 	{
		 		while(scanf("%s%c",st,&c))
		 		{
				 	if(st[0]>96)
				 	st[0]-=32;
			       if(st[0]!=cm)
			 		{
	 			        flag=0;
					}
				    if(c=='\n')
				       break;
			    }
	    }
	    if(flag)
	    printf("Y\n");
	    else
	    printf("N\n");			 
    }
    return 0;
}
