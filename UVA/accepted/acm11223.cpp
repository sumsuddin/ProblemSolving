#include<stdio.h>
#include<string.h>

long int n,i,j,k,p=1;
char sy[500],c;

int main()
{
	scanf("%ld",&n);
	getchar();

	while(n--)
	{
		printf("Message #%ld\n",p++);
		i=0;
		c='a';
        while(1)
        {
			for(i=0;;i++)
			{
				scanf("%c",&c);
				if(c==' ' || c=='\n')
				{
					sy[i]=0;
					break;
				}
				else
					sy[i]=c;
			}
			if(sy[0]==0 && c!='\n')
				printf(" ");

            else if(strcmp(sy,".-")==0)
                printf("A");
           
            else if(strcmp(sy,"-...")==0)
                printf("B");
           
            else if(strcmp(sy,"-.-.")==0)
                printf("C");
           
            else if(strcmp(sy,"-..")==0)
                printf("D");
           
            else if(strcmp(sy,".")==0)
                printf("E");
           
            else if(strcmp(sy,"..-.")==0)
                printf("F");
           
            else if(strcmp(sy,"--.")==0)
                printf("G");

            else if(strcmp(sy,"....")==0)                   
                printf("H");          
           
            else if(strcmp(sy,"..")==0)         
                printf("I");
           
            else if(strcmp(sy,".---")==0)
                printf("J");
           
            else if(strcmp(sy,"-.-")==0)
                printf("K");
           
            else if(strcmp(sy,".-..")==0)
                printf("L");
           
            else if(strcmp(sy,"--")==0)
                printf("M");
           
            else if(strcmp(sy,"-.")==0)
                printf("N");
           
            else if(strcmp(sy,"---")==0)
                printf("O");
           
            else if(strcmp(sy,".--.")==0)
                printf("P");
           
            else if(strcmp(sy,"--.-")==0)
                printf("Q");
           
            else if(strcmp(sy,".-.")==0)
                printf("R");
           
            else if(strcmp(sy,"...")==0)
                printf("S");
           
            else if(strcmp(sy,"-")==0)
               printf("T");
           
            else if(strcmp(sy,"..-")==0)
                printf("U");
           
            else if(strcmp(sy,"...-")==0)
                printf("V");
           
            else if(strcmp(sy,".--")==0)
                printf("W");
           
            else if(strcmp(sy,"-..-")==0)
                printf("X");
           
            else if(strcmp(sy,"-.--")==0)
                printf("Y");
           
            else if(strcmp(sy,"--..")==0)
                printf("Z");
           
            else if(strcmp(sy,"-----")==0)
                printf("0");
           
            else if(strcmp(sy,".----")==0)
                printf("1");
           
            else if(strcmp(sy,"..---")==0)
                printf("2");
           
            else if(strcmp(sy,"...--")==0)
                printf("3");
           
            else if(strcmp(sy,"....-")==0)
                printf("4");
           
            else if(strcmp(sy,".....")==0)
                printf("5");
           
            else if(strcmp(sy,"-....")==0)
                printf("6");
           
            else if(strcmp(sy,"--...")==0)
                printf("7");
           
            else if(strcmp(sy,"---..")==0)
                printf("8");
           
            else if(strcmp(sy,"----.")==0)
                printf("9");
           
            else if(strcmp(sy,".-.-.-")==0)
                printf(".");
           
            else if(strcmp(sy,"--..--")==0)
                printf(",");
           
            else if(strcmp(sy,"..--..")==0)
                printf("?");
           
            else if(strcmp(sy,".----.")==0)
                printf("%c",39);
           
            else if(strcmp(sy,"-.-.--")==0)
                printf("!");
           
            else if(strcmp(sy,"-..-.")==0)
                printf("/");
           
            else if(strcmp(sy,"-.--.")==0)                   
                printf("(");           
           
            else if(strcmp(sy,"-.--.-")==0)                   
                printf(")");
           
            else if(strcmp(sy,".-...")==0)
                printf("&");
           
            else if(strcmp(sy,"---...")==0)
                printf(":");
           
            else if(strcmp(sy,"-.-.-.")==0)
                printf(";");
           
            else if(strcmp(sy,"-...-")==0)
                printf("=");
           
            else if(strcmp(sy,".-.-.")==0)
                printf("+");
           
            else if(strcmp(sy,"-....-")==0)
                printf("-");
           
            else if(strcmp(sy,"..--.-")==0)
                printf("_");
           
            else if(strcmp(sy,".-..-.")==0)
                printf("%c",34);
           
            else if(strcmp(sy,".--.-.")==0)
                printf("@");
		
			if(c=='\n')
				break;
    }
		printf("\n");
		if(n)
			printf("\n");
	}
	return 0;
}