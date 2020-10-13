#include <stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left,*right,*parent,*thread;
}N;
N *newNode(int item)
{
	N*temp=(N*)malloc(sizeof(N));
	temp->data=item;
	temp->left=temp->right=temp->thread=NULL;
	return temp;
}
void inorder(N*root)
{
	while(root->left!=NULL){
	root=root->left;
	}
	while(root!=NULL){
	printf("%d\t",root->data);
	root=root->thread;
	}
	printf("\n");
}
N* insert(N* root,int v) 
{ 	N *nu=newNode(v);
	if (root==NULL) return nu;
	if (nu->data < root->data &&root->left!=NULL)
	insert(root->left,v);
	else if (nu->data > root->data &&root->right!=NULL)
	insert(root->right,v);
	else
	{	if(nu->data<=root->data)
		{
			root->left=nu;
			nu->parent=root;
		}
		else{
			root->right=nu;
			nu->parent=root;
		}
	}
return root;
} 
N * minValueNode(N* node) 
{ 
	N* current = node; 
	while (current && current->left != NULL) 
		current = current->left; 
	return current; 
} 
N *createBST()
{
	N *root=NULL;int v,c;
	while(1){
		printf("\nEnter data:");
		scanf("%d",&v);
		root=insert(root,v);
		printf("Press 1 to conitnue 0 to stop:");
		scanf("%d",&c);
		if (c==0)
		break;
	}
	return root;
}
N *inSuc(N *root){
	if(root->right!=NULL)
		return minValueNode(root->right);
	N *uptrav=root->parent;
	while(uptrav &&root==uptrav->right)
	{
		root=uptrav;
		uptrav=uptrav->parent;
	}
	return uptrav;
}
void makeThreads(N *root){
	if (root){
	root->thread=inSuc(root);
	makeThreads(root->left);
	makeThreads(root->right);
	}
}
int main()
{
	N *root=NULL;
	root=createBST();
	makeThreads(root);
	printf("Inorder traversal of the given tree \n"); 
	inorder(root);
	return 0;
}
