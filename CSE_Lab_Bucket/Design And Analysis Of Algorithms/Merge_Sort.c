#include<stdio.h>
#include<stdlib.h>


void merge(int *, int , int, int);
void split(int *, int , int);

void split(int *ar, int l, int h)
{
	int mid;
	if(l<h)
	{
		mid = (l+h)/2;
		split( ar, l, mid);
		split(ar, mid+1, h);
		merge(ar, l , mid, h);
	}
}


void merge(int *ar, int l, int mid, int h)
{
	int i = l, j = mid+1, k=0;
	int temp[h-l+1];
	while( i <= mid && j <= h)
	{
		if(ar[i]<=ar[j])
			temp[k++]=ar[i++];
		else
			temp[k++]=ar[j++];
	}
	while(i<=mid)
		temp[k++] = ar[i++];
	
	while(j<=h)
		temp[k++] = ar[j++];
		 	
	for(i =l, k=0 ; i<=h ; i++,k++)
		ar[i] = temp[k];
}

int main()
{
	int *ar, i, n;
	printf("Enter capacity:\t");
	scanf("%d", &n);
	ar = (int*)malloc(sizeof(int));
	printf("\nEnter elements in array : \n");
	for(i=0;i<n;i++)
		scanf("%d", &ar[i]);
	split(ar, 0, n-1);
	printf("THE SORTED ARRAY IS : \t");
	for(i=0;i<n;i++)
		printf("%d\t", ar[i]);
}



