#include <stdio.h>
#include<stdlib.h>
typedef struct{
	int f=-1,r=-1,cap,*p;
}queue;
queue Q;
void Delete()
{
	if(Q.f==-1)
	{
		printf("\nQueue is Empty\n");
		return ;
	}
	printf("\nDeleted item=%d",Q.p[Q.f]);
	if(Q.f==Q.r)
		Q.f=Q.r=-1;
	else
		Q.f++;
}
void insert(int v)
{
	if (Q.r==Q.cap-1)
	{
		printf("\nQueue is Filled\n");
		return;
	}
	if (Q.f==-1)
	Q.f=0;
	Q.p[++Q.r]=v;
}

void display()
{
	int i;
	if(Q.f==-1)
	{
		printf("\nQueue is Empty\n");
		return;
	}
	printf("\nThe Queue");
	for (i=Q.f;i<=Q.r;i++)
	printf("\n%d",Q.p[i]);
}
int main()
{
	int v,ch;
	printf("\nEnter the capacity\n");
	scanf("%d",&Q.cap);
	Q.p=(int*)malloc(Q.cap*sizeof(int));
	while(1)
	{
		printf("\nPress 1/2/3/4 for insertion/deletion/display/Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\nEnter value:-");
			scanf("%d",&v);
			insert(v);
			break;
			case 2:
			Delete();
			break;
			case 3:
			display();
			break;
			case 4:
			return 0;
			default:
			printf("\nEnter correctly\n");
		}
	}
}
	
