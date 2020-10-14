#include<stdio.h>
#include<stdlib.h> 
#include<limits.h> 

void printParenthesis(int i, int j, int n, int *bracket, char *name)
{ 
	if (i == j) 
	{ 
		printf("%c",*(name));
		*name=*name+1; 
		return; 
	} 
	printf("("); 
	printParenthesis(i, *((bracket+i*n)+j), n, bracket, name); 
	printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name); 
	printf(")"); 
} 
void matrixChainOrder(int p[], int n) 
{ 
	int m[n][n],i,L,k,j;
	int bracket[n][n]; 
	for (i=1; i<n; i++) 
		m[i][i] = 0; 
	for (L=2; L<n; L++) 
	{ 
		for (i=1; i<n-L+1; i++) 
		{ 
			int j = i+L-1; 
			m[i][j] = 999999; 
			for (k=i; k<=j-1; k++) 
			{ 
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
				if (q < m[i][j]) 
				{ 
					m[i][j] = q; 
					bracket[i][j] = k; 
				} 
			} 
		} 
	} 
	char name = 'A'; 
	printf("Optimal Parenthesization is : ");
	printParenthesis(1, n-1, n, (int *)bracket, &name); 
	printf("\nOptimal Cost is :\n %d ",m[1][n-1]);
    printf("\ncost matrix :\n");
    for(i=1;i<n;i++ )
    {
    for(j=1; j<n;j++){
		if(i>j)
		printf("X\t");
		else
		printf("%d\t",m[i][j]);
	}
	printf("\n");
	
} 
printf("\nk matrix:\n");
for(i=1;i<n;i++){
	for(j=1;j<n;j++){
		if(i==j)
		printf("0\t");
		else if(i>j)
		printf("X\t");
		else
		printf("%d\t",bracket[i][j]);
	}
	printf("\n");
	
	}
}
int main() {
	int *ar,n,i;
		printf("enter no of order : ");
		scanf("%d",&n);
		ar=(int*)malloc(n*sizeof(int));
		printf("enter order : ");
		for(i=0;i<n;i++)
			scanf("%d",&ar[i]);
		matrixChainOrder(ar,n);
		return 0;
} 
	

