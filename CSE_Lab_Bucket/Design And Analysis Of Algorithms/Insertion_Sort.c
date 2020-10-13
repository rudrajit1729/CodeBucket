  
#include<stdio.h>
#include<stdlib.h>


void insertionSort(int *, int ); 


int main()
{
	int *ar, i, n;
	printf("Enter capacity:\t");
	scanf("%d", &n);
	ar = (int*)malloc(sizeof(int));
	printf("\nEnter elements in array : \n");
	for(i=0;i<n;i++)
		scanf("%d", &ar[i]);
	insertionSort(ar, n);
	printf("THE SORTED ARRAY IS : \t");
	for(i=0;i<n;i++)
		printf("%d\t", ar[i]);
}


void insertionSort(int *ar, int n) 
{ 
    int i, c, j; 
    for (i = 1; i < n; i++)
	{ 
        c = ar[i]; 
        j = i - 1; 
        while (j >= 0 && ar[j] > c)
		{ 
            ar[j + 1] = ar[j]; 
            j = j - 1; 
        } 
        ar[j + 1] = c; 
    } 
}

