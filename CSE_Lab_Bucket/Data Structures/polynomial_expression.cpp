#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coef,exp;
	struct node *link;
}N;

N *Create(N *);
N *insert(N *,int,int);
void display(N *);

int  main()
{
	N *start=NULL;
	start=Create(start);
	display(start);
}

N *Create( N *start)
{
	int a,b;char ch;
	while(1)
	{
		printf("\nenter coefficient and exponent:");
		scanf("%d %d",&a,&b);
		start=insert(start,a,b);
		printf("\nPress y to continue any other button to exit:");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch!='y')
		break;
	}
	return start;
	
}

N *insert(N *start,int a,int b)
{
	N *nu=(N*)malloc(sizeof(N));N *ptr,*prev;
	nu->coef=a;
	nu->exp=b;
	nu->link=NULL;
	if(start==NULL)
	return nu;
	prev=ptr=start;
	while(ptr!=NULL)
	{
		if(nu->exp>=ptr->exp)
		break;
		prev=ptr;
		ptr=ptr->link;
	}
	if(ptr==NULL)
	prev->link=nu;
	else if(ptr->exp==nu->exp)
	ptr->coef+=nu->coef;
	else if(ptr==start)
	{
		nu->link=start;
		start=nu;
	}
	else
	{
		nu->link=ptr;
		prev->link=nu;
	}
	return start;
}

void display(N *start)
{
	N *ptr;
	printf("\nThe polynomial expression:\n");
	for(ptr=start;ptr->link!=NULL;ptr=ptr->link)
	printf("%dx^%d + ",ptr->coef,ptr->exp);
	if(ptr->exp==0)
	printf("%d\n",ptr->coef);
	else
	printf("%dx^%d\n",ptr->coef,ptr->exp);
}
