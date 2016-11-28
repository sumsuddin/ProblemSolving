#include<stdio.h>
#include<string.h>
#include<malloc.h>

char st[1000050];
long i,j,la;
bool flag;

struct node
{
	long st,end;
	struct node *next;
}*p,*q,*r,*nl;

int main()
{
	while(gets(st))
	{
		flag=0;j=0;

		p=(struct node*)malloc(sizeof(struct node));
		p->next=NULL;
		r=p;
		p->st=0;
		nl=p;
		flag=1;
		for(i=0;st[i];i++)
		{
			if(st[i]=='[')
			{
				q=(struct node*)malloc(sizeof(struct node));
				p->end=j;
				q->next=r;
				r=q;
				q->st=i+1;
				p=q;
			    j=0;
				flag=0;
			}
			else if(st[i]==']')
			{
				q=(struct node*)malloc(sizeof(struct node));
				p->end=j;
				nl->next=q;
				nl=q;
				nl->next=NULL;
				q->st=i+1;
				p=nl;
				flag=1;
				j=0;
			}
			else
				j++;
		}
		if(flag)
			{
				q=(struct node*)malloc(sizeof(struct node));
				p->end=j;
				nl->next=q;
				nl=q;
				nl->next=NULL;
				q->st=i+1;
				p=nl;
			}			
		else
		{		
			q=(struct node*)malloc(sizeof(struct node));
			p->end=j;
			r=q;
			q->next=p;
			q->st=i+1;
			p=q;
		}
		while(r->next!=NULL)
		{
			for(i=0;i<r->end;i++)
				printf("%c",st[r->st+i]);
			r=r->next;
		}
		for(i=0;i<r->end;i++)
			printf("%c",st[r->st+i]);
		printf("\n");
	}
	return 0;
}