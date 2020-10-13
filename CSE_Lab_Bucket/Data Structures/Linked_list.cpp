#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}N;
N *start;

void insert_at_end(int v)
{
	N *nu=(N*)malloc(sizeof(N)),*ptr;
	nu->data=v;
	nu->link=NULL;
	if(start==NULL)
	{
		start=nu;
		return;	
	}
	for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
	ptr->link=nu;
}


void insert_at_beg(int v)
{
	N *nu=(N*)malloc(sizeof(N));
	nu->data=v;
	nu->link=start;
	start=nu;
}


void insert_at_posi(int p,int v)
{
	N *nu=(N*)malloc(sizeof(N)),*ptr=start,*prev=start;int c=0;
	nu->data=v;
	if(p==1)
	{
		nu->link=start;
		start=nu;
		return;
	}
	while(ptr!=NULL)
	{
		c++;
		if(c==p)
		break;
		prev=ptr;
		ptr=ptr->link;
	}
	if(p>c+1)
	{
		printf("\nInvalid position");
		return;
	}
	nu->link=ptr;
	prev->link=nu;
}



void del_from_end()
{
	N *ptr,*prev;
	if(start==NULL)
	{
		printf("\nEmpty");
		return;
	}
	ptr=prev=start;
	while(ptr->link!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	printf("\nDeleted item =%d",ptr->data);
	if(ptr==start)
	start=NULL;
	else
	prev->link=NULL;
	free(ptr);
}



void del_from_beg()
{
	N *ptr;
	if(start==NULL)
	{
		printf("\nEmpty");
		return;
	}
	ptr=start;
	printf("\nDeleted item =%d",ptr->data);
	start=start->link;
	free(ptr);
}



void del_from_posi(int p)
{
	N *ptr,*prev;int c=0;
	if(start==NULL)
	{
		printf("\nEmpty");
		return;
	}
	ptr=prev=start;
	while(ptr!=NULL)
	{
		c++;
		if(c==p)
		break;
		prev=ptr;
		ptr=ptr->link;
	}
	if(p>c)
	{
		printf("\nInvalid position");
		return;
	}
	if (ptr==start)
	start=start->link;
	else
	prev->link=ptr->link;
	printf("\nDeleted item =%d",ptr->data);
	free(ptr);
}


void display()
{
	N *ptr=start;
	printf("\nThe linked list:\n");
	if(start==NULL)
	{
		printf("Empty");
		return;
	}
	while (ptr->link!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("%d\n",ptr->data);
}

int search(int v)
{
	N *ptr;int i=1;
	for(ptr=start;ptr!=NULL;ptr=ptr->link)
	{
		if(v==ptr->data)
		return i;
		i++;
	}
	return -1;
}

int main()
{
	int v,ch,ch2,p,s,result;
	while(1)
	{
		printf("\nPress 1/2/3/4/5 for insert/delete/display/search/exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nPress 1/2/3 to insert at end/beginning/position\n");
				scanf("%d",&ch2);
				printf("\nEnter value:");
				scanf("%d",&v);
				switch(ch2)
				{
					case 1:
						insert_at_end(v);
						display();
						break;
					case 2:
						insert_at_beg(v);
						display();
						break;
					case 3:
						printf("\nEnter the position:");
						scanf("%d",&p);
						insert_at_posi(p,v);
						display();
						break;
					default:
						printf("\nEnter correct choice");
				}
				break;
				case 2:
					printf("\nPress 1/2/3 to delete from end/beginning/position\n");
					scanf("%d",&ch2);
					switch(ch2)
				{
					case 1:
						del_from_end();
						display();
						break;
					case 2:
						del_from_beg();
						display();
						break;
					case 3:
						printf("\nEnter the position:");
						scanf("%d",&p);
						del_from_posi(p);
						display();
						break;
					default:
						printf("\nEnter correct choice");
				}
				break;
				case 3:
					display();
					break;
				case 4:
					printf("\nEnter search value:");
					scanf("%d",&s);
					result=search(s);
					if(result>=0)
					printf("\nFound at position %d",result);
					else
					printf("\nValue not found");
					break;
				case 5:
					printf("\nThank You!!!Visit Again!!!");
					return 0;
				default:
					printf("\nEnter correct choice");
				}
			}
}
					
					
				
				
				
		
	
	
	
	


		
		
		
		
		
		
		

