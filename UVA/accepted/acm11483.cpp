#include<stdio.h>

int main()
{
	int a=1,n,i,k;
	char st[105][105],sy[10];

	while(gets(sy))
	{
		if(sy[0]==0)
			continue;
		sscanf(sy,"%d",&n);

		if(n)
		{
			for(k=0;k<n;k++)
			{
				gets(st[k]);

				if(st[k][0]==0)
				{
					k--;
					continue;
				}
			}

			printf("Case %d:\n",a++);
			printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
			for(k=0;k<n;k++)
			{

				printf("printf(\"");
				for(i=0;st[k][i];i++)
				{
					if(st[k][i]==34 || st[k][i]==92)
						printf("\\");

					printf("%c",st[k][i]);
				}
				printf("\\n\");\n");
			}
			printf("printf(\"\\n\");\nreturn 0;\n}\n");
		}
		else
			break;
	}
	return 0;
}