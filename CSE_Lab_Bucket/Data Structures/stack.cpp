#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int top=-1,cap,*p;
}stack;
stack s;
void push(int v)
{
	if(s.top==s.cap-1)
	{
		printf("\nStack Overflow!!!");
		return;
	}
	s.p[++s.top]=v;
}
void pop()
{
	if(s.top==-1)
	{
		printf("\nStack Underflow!!!");
		return;
	}
	printf("\nDeleted item=%d",s.p[s.top]);
	s.top--;
}
void peep()
{
	int i;
	if (s.top==-1)
	{
		printf("\nStack Underflow!!!");
		return;
	}
	printf("\nThe Stack!!!");
	for(i=s.top;i>=0;i--)
	printf("\n%d",s.p[i]);
}
int main()
{
	int ch,v;
	printf("\nEnter capacity\n");
	scanf("%d",&s.cap);
	s.p=(int*)malloc(s.cap*(sizeof(int)));
	while(1)
	{
		printf("\nPress 1/2/3/4 for push/pop/peep/exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter value\n");
				scanf("%d",&v);
				push(v);
				break;
			case 2:
				pop();
				break;
			case 3:
				peep();
				break;
			case 4:
				return 0;
			default:
				printf("\nPlease enter correct choice\n");
				
		}
	}
}

















