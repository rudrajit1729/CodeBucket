#include <stdio.h>
#include <stdlib.h>
int f=-1,r=-1,cap,*p;
void insert(int v)
{
	if((f-r==1)||(f==0 &&r==cap-1))
	{
		printf("\nCircular queue is filled\n");
		return;
	}
	if(f==-1)
	f=0;
	r=(r+1)%cap;
	p[r]=v;
}
void Delete()
{
	if(f==-1)
	{
		printf("\nCircular queue is empty\n");
		return;
	}
	printf("\nDeleted item =%d",p[f]);
	if(f==r)
	f=r=-1;
	else
	f=(f+1)%cap;
}
void display()
{
	int i=f;
	if(f==-1)
	{
		printf("\nCircular queue is empty\n");
		return;
	}
	printf("\nThe Circular Queue\n");
	while(i!=r)
	{
		printf("%3d",p[i]);
		i=(i+1)%cap;
	}
	printf(" %d",p[r]);
}
int main()
{
	int v,ch;
	printf("\nEnter the capacity\n");
	scanf("%d",&cap);
	p=(int*)malloc(cap*sizeof(int));
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
		
