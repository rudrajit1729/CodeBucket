#include<stdio.h>

void findMinAndMax(int arr[], int low, int high, int *min, int *max)
{
  if (low == high)      
  {
    if (*max < arr[low])   
      *max = arr[low];
    if (*min > arr[high])  
      *min = arr[high];

    return;
  }

  if (high - low == 1)      
  {
    if (arr[low] < arr[high])  
    {
      if (*min > arr[low])   
        *min = arr[low];
      if (*max < arr[high])  
        *max = arr[high];
    }
    else
    {
      if (*min > arr[high]) 
        *min = arr[high];
      if (*max < arr[low])   
        *max = arr[low];
    }
    return;
  }

  int mid = (low + high) / 2;

  findMinAndMax(arr, low, mid, min, max);

  findMinAndMax(arr, mid + 1, high, min, max);
}

int main()
{
  int arr[] = { 7, 2, 9, 3, 1, 6, 7, 8, 4 };
  int n = sizeof(arr) / sizeof(arr[0]);

  int max = 0, min = 100;

  findMinAndMax(arr, 0, n - 1, &min, &max);

  printf("The minimum element in the array is  : %d",min);
  printf("The maximum element in the array is  : %d",max);
  return 0;
}
