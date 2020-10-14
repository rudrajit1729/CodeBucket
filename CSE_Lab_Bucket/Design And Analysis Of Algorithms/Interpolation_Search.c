#include<stdio.h>
#include<stdlib.h>

int interpolation_search(int *ar, int bottom, int top, int item)
{
    int mid;
    while (bottom <= top) {
        mid = bottom + (top - bottom)*((item-ar[bottom])/(ar[top]-ar[bottom]));
        if (item == ar[mid])
            return mid;
        if (item < ar[mid])
            top = mid - 1;
        else
            bottom = mid + 1;
    }
    return -1;
}

int main() 
{ 
	int i, n, s, result, *ar;
	printf("\nEnter size of array : ");
	scanf("%d",&n);
	ar = (int*)malloc(sizeof(int));
	printf("\nEnter data items\n");
    for(i=0;i<n;i++)
		scanf("%d", &ar[i]);
	printf("\nEnter search data item : ");
	scanf("%d", &s);
    result = interpolation_search(ar,0, n-1, s); 
    if (result == -1)
		printf("Element is not present in array");
	else
        printf("Element is present at position %d",result+1); 
    return 0; 
}
