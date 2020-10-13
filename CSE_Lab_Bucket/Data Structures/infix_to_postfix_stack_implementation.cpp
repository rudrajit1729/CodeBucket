#include <stdio.h>
#include <stdlib.h>
/*
Rules for conversion of infix to postfix
1)alphanumeric char are directly printed
2)operators are stacked
3)when new operator is scanned we check with stack to find if some operator has equal or higher precedence than current one.
while this is true we pop those operators out and finally push the new operator
4)when bracket encountered it is stored in stack and same rule followed for operators in bracket and when closing bracket encountered 
all operators inside bracket popped out
*/
char stack[80];
int top=-1;
void push(char x)
{
	stack[++top]=x;
}
char pop()
{
	if(top==-1)
	return -1;
	return stack[top--];
}
int prec(char x)
{
	if(x=='(')
	return 0;
	else if(x=='+'||x=='-')
	return 1;
	else if(x=='*'||x=='/')
	return 2;
}
int isalpnum(char x)
{
	if((x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>='0'&&x<='9'))
	return 1;
	else 
	return 0;	
}
int main()
{
	char *e,exp[80],x;
	printf("\nEnter the expression\n");
	scanf("%s",exp);
	e=exp;
	//stack=(char*)malloc(sizeof(exp));
	while(*e!='\0')
	{
		if(isalpnum(*e))
		printf("%c",*e);
		else if(*e=='(')
		push(*e);
		else if(*e==')')
		{
			while((x=pop())!='(')
			printf("%c",x);
		}
		else
		{
			while(prec(stack[top])>=prec(*e))
			printf("%c",pop());
			push(*e);
		}
		e++;
	}
		while(top!=-1)
		printf("%c",pop());
}

