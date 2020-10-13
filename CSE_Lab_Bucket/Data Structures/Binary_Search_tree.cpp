/*
Binary search tree 
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}N;
void inorder(N*);
void postorder(N*);
void preorder(N*);
int search(N*,int);
N* createT(N*);
N*insert(N*,N*);

int main()
{
	N *root=NULL;int ch;
	printf("\nCreate the tree...\n");
	root=createT(root);
	N *ptr=root;
	while(1)
	{
		printf("\nPress 1/2/3/4 for inorder/preorder/postorder/exit...\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nInorder:");
				inorder(root);
				break;
			case 2:
				printf("\nPreorder:");
				preorder(root);
				break;
			case 3:
				printf("\nPostorder:");
				postorder(root);
				break;
			case 4:
				printf("\nThank you!!!\n");
				return 0;
			default:
				printf("\nEnter correct choice!!!");
				
		}
	}
}
void inorder(N *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);	
	}
}
void preorder(N *root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(N *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int search(N *root,int v)
{
	if(root!=NULL)
	{
		if (v==root->data)
			return 1;
		else if(v<root->data)
			return search(root->left,v);
		else 
			return search(root->right,v);
	}
	return 0;
}
N *createT(N*root)
{
	char ch='y';int n; N *nu;
	while(ch=='y')
	{
		printf("\nEnter element:");
		scanf("%d",&n);
		if(search(root,n)==0)
		{
		    nu=(N*)malloc(sizeof(N));
			nu->data=n;
			nu->left=nu->right=NULL;
			root=insert(root,nu);
		}
		printf("\nPress y to continue");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch!='y')
		break;
	}
	return root;
}
N *insert(N *root,N *nu)
{
	if(root!=NULL)
	{
		if(nu->data<root->data)
			root->left=insert(root->left,nu);
		else
		root->right=insert(root->right,nu);
			return root;
	}
	return nu;
}

