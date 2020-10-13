#include <stdio.h>
#include<stdlib.h>
void bubble_sort(int *ar, int n)
{
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++)
    {   
        for (j = 0; j < n - i - 1; j++) 
	{
            if (ar[j] > ar[j + 1])
	    {  
                tmp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = tmp;
            }
        }
    }
}
int main() 
{
  int *ar, n, i, d, swap;
  printf("Enter number of elements in the array:\n");
  scanf("%d", &n); 
  ar = (int*)malloc(sizeof(int));
  printf("Enter Elements\n");
  for (i = 0; i < n; i++)
    scanf("%d", &ar[i]);
  bubble_sort(ar, n);
  printf("Sorted Array:\n");
  for (i = 0; i < n; i++)
     printf("%d\t", ar[i]);
  return 0;
}
