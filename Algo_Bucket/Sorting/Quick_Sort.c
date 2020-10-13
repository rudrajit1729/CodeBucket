#include<stdio.h>
#include<stdlib.h>


void swap(int*, int*) ;
void qsort(int *, int, int);

int main()
{
	int *ar,n,i=0;
	printf("\nEnter Capacity:  ");
	scanf("%d",&n);
	ar=(int*)malloc(sizeof(int));
	printf("\nEnter elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	printf("\nSorted Array:\t");
	qsort(ar,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\t",ar[i]);
}


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void qsort(int *ar,int low,int high)
{
	int i=low,j=high,temp,pivot=ar[low];
	while(i<=j)
	{
		while(ar[i]<pivot)
			i++;
		while(ar[j]>pivot)
			j--;
		if(i<=j)
		{
			swap(&ar[i], &ar[j]);
			i++;
			j--;
		}
	}
	if(low<j)
		qsort(ar,low,j);
	if(i<high)
		qsort(ar,i,high);
}
