#include<stdio.h>
#include<stdlib.h>

int search(int *arr, int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
int main(void) 
{ 
	int i,n,s,result,*ar;
	printf("\nEnter size of array : ");
	scanf("%d",&n);
	ar = (int*)malloc(sizeof(int));
	printf("\nEnter data items\n");
    for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	printf("\nEnter search data item : ");
	scanf("%d",&s);
    result = search(ar, n, s); 
    if (result == -1)
		printf("Element is not present in array");
	else
        printf("Element is present at position %d",result+1); 
    return 0; 
} 
