#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}N;
N *start;
void insert(int v)
{
	N *nu=(N*)malloc(sizeof(N));
	nu->data=v;
	nu->link=start;
	start=nu;
}
void reverselist()
{
	N *curr=start,*prev=NULL,*next=NULL;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	start=prev;
}
void display()
{
	N *ptr;
	printf("\nThe linked list:\n");
	if(start==NULL)
	{
		printf("\nEmpty\n");
		return;
	}
	for(ptr=start;ptr->link!=NULL;ptr=ptr->link)
	printf("%d->",ptr->data);
	printf("%d\n",ptr->data);
}
void revprinting(N *start)
{
	if(start!=NULL)
	{
		revprinting(start->link);
		printf("%d->",start->data);
	}
}
void removeduplicates()
{
	N *ptr=start,*curr,*prev;int v;
	while(ptr->link!=NULL)
	{
	
		prev=curr=ptr;
		v=ptr->data;
		for(;curr!=NULL;prev=curr,curr=curr->link)
		{
			if(v==curr->data)
			prev->link=curr->link;
		}
		ptr=ptr->link;
	}
}
	
int main()
{
	int ar[]={2,1,2,3,4,4,5,6,6,7};int i;
	for(i=0;i<10;i++)
	insert(ar[i]);
	display();
	removeduplicates();
	display();
}
