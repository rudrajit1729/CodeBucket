#include<stdio.h>

/*void sort(int arr[] , int n)
{
	int i , j ,temp;
	for(i = 0 ; i < n-1 ; i++)
	{
		for(j = 0 ; j < n-i-1 ; j++)
		{
			if(arr[j] < arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}*/
void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}

int main()
{
	int no_bins = 1 , max , n , i , j ,p = 0;
	printf("Enter the maximum capacity of each bin\n");
	scanf("%d",&max);
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int elements[n];
	printf("Enter the elements\n");
	for(i = 0 ; i < n ; i++)
	scanf("%d",&elements[i]);
	//sort(elements , n);
	quicksort(elements,0,n-1);
	int binarr[n];
	for(i = 0 ; i < n ; i++)
	binarr[i] = 0;
	binarr[no_bins] += elements[0];
	printf("\n%d added to bin %d \n",elements[0],no_bins);
	for(i = 1 ; i < n ; i++)
	{
		for(j = 1 ; j <= no_bins ; j++)
		{
			if(elements[i] <= (max - binarr[j]))
			{
				binarr[j] += elements[i];
				printf("%d added to bin %d \n" , elements[i],j);
				p=0;
				break;
			}
			else
			{
				p++;
			}
	    }
	    if(p>0)
	    {
	    	no_bins += 1;
	    	binarr[no_bins] += elements[i];
	    	printf("%d added to bin %d \n",elements[i],no_bins);
	    	p=0;
		}
	}
	printf("The bins contain the following \n");
	for(i = 1 ; i <= no_bins ; i++)
	printf("%d\t",binarr[i]);
	printf("\nNo of bins required is %d ",no_bins);
	return 0;
}
