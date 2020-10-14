#include<stdio.h>
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = (l + r) / 2; 
 
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
 
        return binarySearch(arr, mid + 1, r, x); 
    } 

    return -1; 
}
int main() 
{ 
	int i, n, s, result, ar[100];
	printf("\nEnter size of array : ");
	scanf("%d",&n);
	printf("\nEnter data items\n");//array should be in ascending order
    for(i = 0;i < n; i++)
		scanf("%d", &ar[i]);
	printf("\nEnter search data item : ");
	scanf("%d", &s);
    result = binarySearch(ar,0, n-1, s); 
    if (result == -1)
		printf("Element is not present in array");
	else
        printf("Element is present at position %d",result+1); 
    return 0; 
}

