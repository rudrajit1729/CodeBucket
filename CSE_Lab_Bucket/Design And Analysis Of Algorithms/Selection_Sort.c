#include<stdio.h>
#include<stdlib.h>


void swap(int* a, int* b);
void selection_sort(int *ar, int n);


int main()
{
	int *ar, i, n;
	printf("Enter capacity:\t");
	scanf("%d", &n);
	ar = (int*)malloc(sizeof(int));
	printf("\nEnter elements in array : \n");
	for(i=0;i<n;i++)
		scanf("%d", &ar[i]);
	selection_sort(ar, n);
	printf("THE SORTED ARRAY IS : \t");
	for(i=0;i<n;i++)
		printf("%d\t", ar[i]);
}


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


void selection_sort(int *ar, int n)
{
	int i, j;
	for(i=0;i<n-1;i++)
	{
		int index = ar[i];
		for(j=i+1;j<n;j++)
		{
			if(ar[j]<ar[index])
				index =j;
		}
		swap(&ar[index], &ar[i]);
			
	}
}




