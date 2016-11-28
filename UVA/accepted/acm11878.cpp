#include<stdio.h>
main()
{
char k,l,m[10];
int i,j,n,f;
f=0;
while(scanf("%d%c%d%c",&i,&k,&j,&l)!=EOF)
{

gets(m);
if(k=='?')
continue;
else
{
sscanf(m,"%d",&n);
if(k=='+')
if(i+j==n)f++;
if(k=='-')
if((i-j)==n)
f++;
}
}
printf("%d\n",f);
return 0;
}
