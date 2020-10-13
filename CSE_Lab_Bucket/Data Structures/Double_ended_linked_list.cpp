#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}N;
N *start=NULL,*rear=NULL;
void insert_at_rear(int v)
{
	N *nu=(N*)malloc(sizeof(N));
	nu->data=v;
	nu->left=nu->right=NULL;
	if(start==NULL)
	start=rear=nu;
	else
	{
		rear->right=nu;
		nu->left=rear;
		rear=nu;
	}
}
void insert_at_beg(int v)
{
	N *nu=(N*)malloc(sizeof(N));
	nu->data=v;
	nu->left=nu->right=NULL;
	if(start==NULL)
	start=rear=nu;
	else
	{
		start->left=nu;
		nu->right=start;
		start=nu;
	}
}
	void insert_at_posi(int p,int v)
	{
		N *nu=(N*)malloc(sizeof(N)),*ptr;int c=0;
		nu->data=v;
		nu->left=nu->right=NULL;
		if(start==NULL)
		{
			start=rear=nu;
			return;
		}
		ptr=start;
		while(ptr!=NULL)
		{
			c++;
			if(c==p)
			break;
			ptr=ptr->right;
		}
		if(p>c+1)
		{
			printf("\nInvalid position");
			return;
		}
		if(ptr==start)
		{
			nu->right=start;
			start->left=nu;
			start=nu;
			return;
		}
		if(ptr==NULL)
		{
			rear->right=nu;
			nu->left=rear;
			rear=nu;
			return;
			
		}
		nu->left=ptr->left;
		nu->right=ptr;
		ptr->left->right=nu;
		ptr->left=nu;
	}
	
void del_from_end()
{
	N *ptr;
	if(start==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	ptr=rear;
	if(start==rear)
	start=rear=NULL;
	else
	{
		rear=rear->left;
		rear->right=NULL;
	}
	printf("Deleted item is %d",ptr->data);
	free(ptr);
}
void del_from_beg()
{
	N *ptr;
	if (start==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	ptr=start;
	if(start==rear)
	start=rear=NULL;
	else
	{
		start=start->right;
		start->left=NULL;
	}
	printf("\nDeleted item is %d",ptr->data);
	free(ptr);
}
	void del_from_posi(int p)
	{
		N *ptr;int c=0;
		if(start==NULL)
		{
			printf("\nEmpty");
			return;
		}
		ptr=start;
		while(ptr!=NULL)
		{
			c++;
			if(c==p)
			break;
			ptr=ptr->right;
		}
		if(p>c)
		{
			printf("\nInvalid position");
			return;
		}
		if(ptr==start)
		{
			start=start->right;
			start->left=NULL;
		}
		else if(ptr==rear)
		{
			rear=rear->left;
			rear->right=NULL;
		}
		else
		{
			ptr->left->right=ptr->right;
			ptr->right->left=ptr->left;
		}
		printf("\nDeleted item =%d",ptr->data);
		free(ptr);
	}
void display_from_left_to_right()
{
	N *ptr=start;
	if(start==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	do
	{
		printf("%d\t",ptr->data);
		ptr=ptr->right;
	}while(ptr!=NULL);
}
void reverselist()
{
	N *temp=NULL,*curr=start;
	rear=start;
	while(curr!=NULL)
	{
		temp=curr->left;
		curr->left=curr->right;
		curr->right=temp;
		curr=curr->left;
	}
	if(temp!=NULL)
	start=temp->left;
}/*
void reverselist()
{
	int t;N *p1=start,*p2=rear;
	while(p1!=p2)//odd no of inputs
	{
		t=p1->data;
		p1->data=p2->data;
		p2->data=t;
		p1=p1->right;
		if(p1==p2)//even no of inputs taken care of
		break;
		p2=p2->left;
	}
}*/
int main()
{
	int ch,ch2,v,p;
	while(1)
	{
		printf("\nPress 1/2/3/4/5 for insertion/deletion/display/reverse/exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nPress 1/2/3 for inserting at end/beginning/posi\n");
				scanf("%d",&ch2);
				printf("\nEnter value to be inserted\n");
				scanf("%d",&v);
				switch(ch2)
				{
					case 1:
						insert_at_rear(v);
						break;
					case 2:
						insert_at_beg(v);
						break;
					case 3:
						printf("\nEnter position:");
						scanf("%d",&p);
						insert_at_posi(p,v);	
						break;
					default:
						printf("\nEnter correcct choice\n");
				}
				break;
			case 2:
				printf("\nPress 1/2 for deleting from end/beginning/position\n");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						del_from_end();
						break;
					case 2:
						del_from_beg();
						break;
					case 3:
						printf("\nEnter position:");
						scanf("%d",&p);
						del_from_posi(p);	
						break;
					default:
						printf("\nEnter correct choice\n");
				}
				break;
			case 3:
				printf("The linked list:\n");
				display_from_left_to_right();
				break;
			case 4:
				reverselist();
				display_from_left_to_right();
				printf("\nrear=%d\nstart=%d\n",rear->data,start->data);
				break;
			case 5:
				printf("Thank You!!!Visit Again!!!");
				return 0;
			default:
				printf("\nEnter correct choice\n");
			}
		}
	}

		
	

	
	
	
	
	
	
	

